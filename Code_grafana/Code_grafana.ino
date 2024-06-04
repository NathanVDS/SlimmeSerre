#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <SPI.h>      //RFID TAG
#include <MFRC522.h>  //RFID TAG
#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include <PubSubClient.h>

#define DHTPIN 33          //
#define DHTTYPE DHT11      // DHT 11
#define LEDSTRIPPIN 14     //good
#define BODEMSENSORPIN 34  // good
#define LIGHTPIN 32        //good
#define trigPIN 15         //good
#define echoPIN 4          //35         //good
#define POMPPIN 27         //good
#define SS_PIN 5           //RFID tag                       //good
#define RST_PIN 17         //RFID tag                     //good
#define ONE_WIRE_BUS 2
#define SOUND_SPEED 0.034

const char* ssid = "embed";
const char* password = "weareincontrol";
const char* mqttServer = "192.168.1.242";
const int mqttPort = 1883;
const char* mqttUser = "nathan";
const char* mqttPassword = "Nat101han";
const char* clientID = "esp_serre_nathan";  // MQTT client ID
String payload{};
WiFiClient espClient;
PubSubClient client(espClient);


OneWire oneWire(ONE_WIRE_BUS);
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Address 0x27, 16 columns, 2 rows
DHT dht(DHTPIN, DHTTYPE);
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
byte nuidPICC[4];
DallasTemperature sensors(&oneWire);

byte tag3[] = { 0x73, 0x93, 0xE2, 0x0D };
byte tag2[] = { 0xB3, 0xAA, 0xBB, 0x19 };
byte tag1[] = { 0x73, 0x53, 0xC8, 0x19 };

float humidity{};
float currenthumidity{};
float temperature{};
float currenttemperature{};
float belichting{};
float currentlight{};
bool ledstate{};
float bodemvochtigheid{ 3900 };
float currentbodemvochtigheid{};
float watervolume{};
long duration;
float distanceCm;
float totalCM{ 20 };
int currentRFID{};

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  setupwifi();
  setupLCD();
  setupRFID();
  setupDHT();
  setupdallassensor();
  setupALLPIN();
  pomp_off();
}

void loop() {
    if (!client.connected()) {
    reconnect();
  }

  readRFID();
  displayRFID();
  delay(2000);
  readbodemvochtigheid();
  displaybodemvochtigheid();
  delay(2000);
  readbelichting();
  displaybelichting();
  delay(2000);
  readDHT();
  displayDHT();
  delay(2000);
  readvolume();
  displayvolume();
  delay(2000);

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(clientID, mqttUser, mqttPassword)) {
      Serial.println("Connected to MQTT");
      // Once connected, resubscribe to necessary topics
      client.subscribe("serre/rfid");
      client.subscribe("serre/bodemvochtigheid");
      client.subscribe("serre/ldr");
      client.subscribe("serre/temperature");
      client.subscribe("serre/humidity");
      client.subscribe("serre/volume");
    } else {
      Serial.print("Failed to connect to MQTT, rc=");
      Serial.print(client.state());
      Serial.println(" Retrying in 5 seconds...");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setupLCD() {
  lcd.init();       // Initialize the LCD
  lcd.backlight();  // Turn on the backlight
  lcd.setCursor(0, 0);
}

void setupDHT() {
  dht.begin();
}

void setupRFID() {
  SPI.begin();      // Init SPI bus
  rfid.PCD_Init();  // Init MFRC522
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
  Serial.println(F("This code scan the MIFARE Classsic NUID."));
  Serial.print(F("Using the following key:"));
  printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
}

void setupdallassensor() {
  sensors.begin();
}

void setupALLPIN() {
  pinMode(LIGHTPIN, INPUT);
  pinMode(BODEMSENSORPIN, INPUT);
  pinMode(LEDSTRIPPIN, OUTPUT);
  pinMode(trigPIN, OUTPUT);  // Sets the trigPIN as an Output
  pinMode(echoPIN, INPUT);   // Sets the echoPIN as an Input
  pinMode(DHTPIN, INPUT);
  pinMode(POMPPIN, OUTPUT);
}

void setupwifi() {
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  client.setServer(mqttServer, mqttPort);
    while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect(clientID, mqttUser, mqttPassword)) {
      Serial.println("Connected to MQTT");
    } else {
      Serial.print("Failed to connect to MQTT, rc=");
      Serial.print(client.state());
      delay(5000);
    }
  }
}

void loopRFID() {
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if (!rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if (!rfid.PICC_ReadCardSerial())
    return;

  Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI && piccType != MFRC522::PICC_TYPE_MIFARE_1K && piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  if (rfid.uid.uidByte[0] != nuidPICC[0] || rfid.uid.uidByte[1] != nuidPICC[1] || rfid.uid.uidByte[2] != nuidPICC[2] || rfid.uid.uidByte[3] != nuidPICC[3]) {
    Serial.println(F("A new card has been detected."));

    // Store NUID into nuidPICC array
    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }

    Serial.println(F("The NUID tag is:"));
    Serial.print(F("In hex: "));
    printHex(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();
    Serial.print(F("In dec: "));
    printDec(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();
  } else Serial.println(F("Card read previously."));

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
}

void loopdallassensor() {
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();  // Send the command to get temperatures
  Serial.println("DONE");
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  if (tempC != DEVICE_DISCONNECTED_C) {
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
  } else {
    Serial.println("Error: Could not read temperature data");
  }
}

void readultrasensor() {
  digitalWrite(trigPIN, LOW);
  delayMicroseconds(2);
  // Sets the trigPIN on HIGH state for 10 micro seconds
  digitalWrite(trigPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPIN, LOW);

  // Reads the echoPIN, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPIN, HIGH);

  // Calculate the distance
  distanceCm = duration * SOUND_SPEED / 2;

  // Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);

  delay(1000);
}


void printHex(byte* buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}


void printDec(byte* buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(' ');
    Serial.print(buffer[i], DEC);
  }
}

void light_on() {
  digitalWrite(LEDSTRIPPIN, HIGH);
}

void light_off() {
  digitalWrite(LEDSTRIPPIN, LOW);
}
void pomp_on() {
  digitalWrite(POMPPIN, LOW);
  Serial.println("POMP AAN");
}

void pomp_off() {
  digitalWrite(POMPPIN, HIGH);
  Serial.println("POMP uit");
}

void readRFID() {
  // Look for new RFID cards
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Check if the detected card matches one of the defined tags
    Serial.print("Card UID: ");
    for (byte i = 0; i < rfid.uid.size; i++) {
      Serial.print(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
      Serial.print(rfid.uid.uidByte[i], HEX);
      Serial.print(" ");
    }



    if (compareTag(rfid.uid.uidByte, tag1)) {
      // If tag 1 is detected, update sensor data accordingly
      bodemvochtigheid = 3800;
      belichting = 100;
      temperature = 25.5;
      humidity = 60.0;
      currentRFID = 1;
    } else if (compareTag(rfid.uid.uidByte, tag2)) {
      // If tag 2 is detected, update sensor data accordingly
      bodemvochtigheid = 20;
      belichting = 150;
      temperature = 27.0;
      humidity = 55.0;
      currentRFID = 2;
    } else if (compareTag(rfid.uid.uidByte, tag3)) {
      // If tag 3 is detected, update sensor data accordingly
      bodemvochtigheid = 30;
      belichting = 200;
      temperature = 28.5;
      humidity = 50.0;
      currentRFID = 3;
    }
    // Halt for a moment to avoid detecting the same card multiple times
    delay(1000);
  }
}

void displayRFID() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RFID tag: ");
  lcd.print(currentRFID);
  lcd.setCursor(0, 1);
  lcd.print("Plant: ");
  switch (currentRFID) {
    case 1:
      lcd.print("Tijm");
      client.publish("serre/rfid", "1");
      break;
    case 2:
      lcd.print("Basilicum");
      client.publish("serre/rfid", "2");
      break;
    case 3:
      lcd.print("Munt");
      client.publish("serre/rfid", "3");
      break;
    default:
      lcd.print("error");
      client.publish("serre/rfid", "4");
  }
}
// Function to compare two RFID tag IDs
bool compareTag(byte tag1[], byte tag2[]) {
  for (int i = 0; i < 4; i++) {
    if (tag1[i] != tag2[i]) {
      return false;
    }
  }
  return true;
}

void readbodemvochtigheid() {
  currentbodemvochtigheid = analogRead(BODEMSENSORPIN);
  if (currentbodemvochtigheid < bodemvochtigheid) {
    pomp_on();
    delay(3000);
    pomp_off();
  }
}

void displaybodemvochtigheid() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bodemvochtigheid: ");
  lcd.setCursor(0, 1);
  lcd.print(currentbodemvochtigheid);
  payload = String(currentbodemvochtigheid);
  client.publish("serre/bodemvochtigheid", payload.c_str());
}

void readbelichting() {
  currentlight = analogRead(LIGHTPIN);
  if (currentlight > 2000) {
    light_on();
    ledstate = HIGH;
  } else {
    light_off();
    ledstate = LOW;
  }
}

void displaybelichting() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Light: ");
  lcd.print(currentlight);
  lcd.setCursor(0, 1);
  lcd.print("LED: ");
  payload = String(currentlight);
  client.publish("serre/ldr", payload.c_str());
  if (ledstate == 1) {
    lcd.print("ON");
  } else {
    lcd.print("OFF");
  }
}

void readDHT() {
  currenthumidity = dht.readHumidity();
  currenttemperature = dht.readTemperature();
}

void displayDHT() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(currenttemperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humid: ");
  lcd.print(currenthumidity);
  lcd.print("%");
  payload = String(currenttemperature);
  client.publish("serre/temperature", payload.c_str());
  payload = String(currenthumidity);
  client.publish("serre/humidity", payload.c_str());
}
void readvolume() {
  readultrasensor();
  watervolume = ((totalCM - distanceCm) / totalCM) * 100;
}
void displayvolume() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Volume: ");
  lcd.print(watervolume);
  lcd.print("%");
  payload = String(watervolume);
  client.publish("serre/volume", payload.c_str());
}