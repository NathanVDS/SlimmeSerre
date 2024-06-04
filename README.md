2023 - 2024

| IOT project               |
|---------------------------|
| Slimme serre              |
| Door Nathan Van der Sande |

Inhoud

[1. Inleiding [4](#inleiding)](#inleiding)

[1.1. Beschrijving [4](#beschrijving)](#beschrijving)

[1.2. Doelstellingen van het project
[4](#doelstellingen-van-het-project)](#doelstellingen-van-het-project)

[1.3. Overzicht van de vereisten en beperkingen
[4](#overzicht-van-de-vereisten-en-beperkingen)](#overzicht-van-de-vereisten-en-beperkingen)

[2. Gebruikte Hardware [4](#gebruikte-hardware)](#gebruikte-hardware)

[2.1. Behuizing [4](#behuizing)](#behuizing)

[2.2. Elektronica Componenten
[5](#elektronica-componenten)](#elektronica-componenten)

[2.2.1. ESP32 Microcontroller
[5](#esp32-microcontroller)](#esp32-microcontroller)

[2.2.2. RFID Reader [5](#rfid-reader)](#rfid-reader)

[2.2.3. DS18B20 Temperatuursensor
[5](#ds18b20-temperatuursensor)](#ds18b20-temperatuursensor)

[2.2.4. Bodemvochtigheidssensor
[5](#bodemvochtigheidssensor)](#bodemvochtigheidssensor)

[2.2.5. Vochtigheidssensor (DHT11)
[5](#vochtigheidssensor-dht11)](#vochtigheidssensor-dht11)

[2.2.6. Pomp Motor [6](#pomp-motor)](#pomp-motor)

[2.2.7. LED Transistor [6](#led-transistor)](#led-transistor)

[2.2.8. Lichtsensor [6](#lichtsensor)](#lichtsensor)

[2.2.9. Ultrasone Sensor [6](#ultrasone-sensor)](#ultrasone-sensor)

[2.2.10. LCD Display [6](#lcd-display)](#lcd-display)

[2.2.11. Overzicht van de Aansluitingen
[7](#overzicht-van-de-aansluitingen)](#overzicht-van-de-aansluitingen)

[2.3. Schema's en PCB [8](#schemas-en-pcb)](#schemas-en-pcb)

[3. Software Architectuur
[9](#software-architectuur)](#software-architectuur)

[3.1. Sensoren [9](#sensoren)](#sensoren)

[3.1.1. DHT11 Sensor (Temperatuur en Vochtigheid):
[9](#dht11-sensor-temperatuur-en-vochtigheid)](#dht11-sensor-temperatuur-en-vochtigheid)

[3.1.2. Bodemvochtigheid Sensor:
[10](#bodemvochtigheid-sensor)](#bodemvochtigheid-sensor)

[3.1.3. Lichtsensor: [10](#lichtsensor-1)](#lichtsensor-1)

[3.1.4. Ultrasone Sensor (Waterniveau):
[11](#ultrasone-sensor-waterniveau)](#ultrasone-sensor-waterniveau)

[3.2. Actuatoren [11](#actuatoren)](#actuatoren)

[3.2.1. Waterpomp: [11](#waterpomp)](#waterpomp)

[3.2.2. LED-verlichting: [12](#led-verlichting)](#led-verlichting)

[3.3. Data doorsturen naar de server (MQTT)
[12](#data-doorsturen-naar-de-server-mqtt)](#data-doorsturen-naar-de-server-mqtt)

[3.3.1. Implementatie van MQTT-protocol
[12](#implementatie-van-mqtt-protocol)](#implementatie-van-mqtt-protocol)

[3.3.2. MQTT Verbinding: [12](#mqtt-verbinding)](#mqtt-verbinding)

[3.3.3. Data Publicatie: [13](#data-publicatie)](#data-publicatie)

[3.4. Data opslag op de server
[14](#data-opslag-op-de-server)](#data-opslag-op-de-server)

[3.5. Data visualisatie met Grafana
[14](#data-visualisatie-met-grafana)](#data-visualisatie-met-grafana)

[3.5.1. MQTT [14](#mqtt)](#mqtt)

[3.5.2. Grafana [15](#grafana)](#grafana)

[4. 5. Implementatie [17](#implementatie)](#implementatie)

[4.1. Ontwerpen van het Prototype
[17](#ontwerpen-van-het-prototype)](#ontwerpen-van-het-prototype)

[4.1.1. Keuze van componenten
[17](#keuze-van-componenten)](#keuze-van-componenten)

[4.1.2. Uitwerken van het Schema en PCB
[20](#uitwerken-van-het-schema-en-pcb)](#uitwerken-van-het-schema-en-pcb)

[5. Gebruikershandleiding
[20](#gebruikershandleiding)](#gebruikershandleiding)

[5.1. Installatie van de Smart Greenhouse Module
[20](#installatie-van-de-smart-greenhouse-module)](#installatie-van-de-smart-greenhouse-module)

[5.2. Bediening van de Module
[20](#bediening-van-de-module)](#bediening-van-de-module)

[5.3. Interactie met Grafana-dashboard
[21](#interactie-met-grafana-dashboard)](#interactie-met-grafana-dashboard)

[5.4. Onderhoud en Probleemoplossing
[21](#onderhoud-en-probleemoplossing)](#onderhoud-en-probleemoplossing)

[6. Toekomstig Werk [21](#toekomstig-werk)](#toekomstig-werk)

[6.1. Mogelijke uitbreidingen en verbeteringen
[21](#mogelijke-uitbreidingen-en-verbeteringen)](#mogelijke-uitbreidingen-en-verbeteringen)

[6.1.1. Ventilator [21](#ventilator)](#ventilator)

[6.1.2. Warmtemat [21](#warmtemat)](#warmtemat)

[6.1.3. Bodemtemperatuurmeter
[21](#bodemtemperatuurmeter)](#bodemtemperatuurmeter)

[6.1.4. Uitbreidingsplan [22](#uitbreidingsplan)](#uitbreidingsplan)

[7. Code uitgelegd [22](#code-uitgelegd)](#code-uitgelegd)

[7.1. Vereiste bibliotheken
[22](#vereiste-bibliotheken)](#vereiste-bibliotheken)

[7.2. Definitie van constanten en variabelen
[23](#definitie-van-constanten-en-variabelen)](#definitie-van-constanten-en-variabelen)

[7.3. Setup-functie [27](#setup-functie)](#setup-functie)

[7.4. De loop-functie [27](#de-loop-functie)](#de-loop-functie)

[7.5. Eigen Functies [29](#eigen-functies)](#eigen-functies)

[7.5.1. Reconnect functie [29](#reconnect-functie)](#reconnect-functie)

[7.5.2. SetupLCD [31](#setuplcd)](#setuplcd)

[7.5.3. setupDHT() [31](#setupdht)](#setupdht)

[7.5.4. setupRFID [31](#setuprfid)](#setuprfid)

[7.5.5. setupdallassensor [32](#setupdallassensor)](#setupdallassensor)

[7.5.6. SetupALLPIN [32](#setupallpin)](#setupallpin)

[7.5.7. Setup wifi [33](#setup-wifi)](#setup-wifi)

[7.5.8. LoopRFID [34](#looprfid)](#looprfid)

[7.5.9. Readultrasensor [36](#readultrasensor)](#readultrasensor)

[7.5.10. light_on [37](#light_on)](#light_on)

[7.5.11. light_off [38](#light_off)](#light_off)

[7.5.12. pomp_on() [38](#pomp_on)](#pomp_on)

[7.5.13. pomp_off() [38](#pomp_off)](#pomp_off)

[7.5.14. ReadRFID [39](#readrfid)](#readrfid)

[7.5.15. DisplayRFID [40](#displayrfid)](#displayrfid)

[7.5.16. readbodemvochtigheid
[42](#readbodemvochtigheid)](#readbodemvochtigheid)

[7.5.17. displaybodemvochtigheid
[42](#displaybodemvochtigheid)](#displaybodemvochtigheid)

[7.5.18. Read belichting [43](#read-belichting)](#read-belichting)

[7.5.19. displaybelichting [44](#displaybelichting)](#displaybelichting)

[7.5.20. ReadDHT [45](#readdht)](#readdht)

[7.5.21. DisplayDHT [46](#displaydht)](#displaydht)

[7.5.22. readvolume [47](#readvolume)](#readvolume)

[7.5.23. Displayvolume [48](#displayvolume)](#displayvolume)

[7.6. Volledige code [49](#volledige-code)](#volledige-code)

# Inleiding

## Beschrijving

We hebben een zeer grote serre die onderverdeeld is in meerdere
kweekbakken met verschillende

soorten kruiden. Omdat de kweekbakken geregeld van kruid veranderen wil
de eigenaar graag een

modulair systeem om deze te automatiseren en monitoren.

Elke kweekbak regelt afzonderlijk de ideale kweekomgeving voor het
gekozen kruid. Zo zal een

kweekbak voor basilicum andere temperatuur, vochtigheid en
belichtingsperiodes hebben dan een

kweekbak voor dille.

Elke kweekbak zal dus sensoren nodig hebben die de grondvochtigheid en
temperatuur monitoren.

Indien een vooraf bepaalde grenswaarde overschreden wordt zal er een
bepaalde

automatisatie/actie ondernomen worden. (te warm -\> vensters open, te
droog -\> water pompen,

voedingstoffen toevoegen?, ...) De belichting gebeurd ook via een
automatisch programma.

De data van deze sensoren en de bijhorende acties worden opgeslagen in
een database en kunnen

worden weergegeven met grafana.

Om te voorkomen dat de kweker zijn kweekbakken opnieuw moet programmeren
bij elke

kruidwisseling zal hij door middel van een RFID tag de bak automatisch
kunnen instellen op de

gewenste kruiden. Deze instellingen kunnen worden weergegeven op een LCD
scherm.

## Doelstellingen van het project

\- Modulair ontwerp

\- Uitlezen van sensoren

\- Doorsturen van de data naar een server dmv MQTT

\- Opslagen van de data op een server

\- Weergeven van de data dmv Grafana

\- Acties uitvoeren adhv bepaalde sensorwaarden

\- LCD en RFID om de module in te stellen

## Overzicht van de vereisten en beperkingen

# Gebruikte Hardware

## Behuizing

- Materialen en ontwerp

- Productiebestanden en 3D-prints

## Elektronica Componenten

### ESP32 Microcontroller

De ESP32 is een krachtige en veelzijdige microcontroller met ingebouwde
WiFi en Bluetooth, geschikt voor IoT-toepassingen. Het beschikt over
meerdere GPIO-pinnen, ADC's, DAC's en andere interface opties die nodig
zijn voor het aansluiten van sensoren en actuatoren.

### RFID Reader

De RFID reader wordt gebruikt voor het identificeren van de kruiden in
de kweekbakken. Hiermee kan de kweker eenvoudig de instellingen per
kweekbak aanpassen door middel van een RFID tag.

Aansluitingen:

VCC: 3.3V (ESP32 pin 3.3V)

GND: GND (ESP32 pin GND)

IRQ: Niet gebruikt

MISO: ESP32 pin 19

MOSI: ESP32 pin 23

SCK: ESP32 pin 18

SDA (SS): ESP32 pin 5

RST: ESP32 pin 17

### DS18B20 Temperatuursensor

De DS18B20 is een digitale temperatuursensor die een nauwkeurige
temperatuurmeting mogelijk maakt. Deze sensor wordt gebruikt om de
temperatuur in de kweekbak te monitoren.

Aansluitingen:

DATA: Aangesloten op een datapin (configuratie in software)

### Bodemvochtigheidssensor

De bodemvochtigheidssensor meet het vochtgehalte van de grond in de
kweekbakken. Deze informatie wordt gebruikt om de waterpompen aan te
sturen.

Aansluitingen:

VCC: 3.3V (ESP32 pin 3.3V)

GND: GND (ESP32 pin GND)

A0: ESP32 pin 34 (analoge uitlezing)

### Vochtigheidssensor (DHT11)

De DHT11 sensor meet zowel de temperatuur als de luchtvochtigheid in de
kweekbakken. Deze sensor helpt bij het handhaven van een optimaal
klimaat.

Aansluitingen:

VCC: 3.3V (ESP32 pin 3.3V)

GND: GND (ESP32 pin GND)

DATA: ESP32 pin 35

### Pomp Motor

De pomp motor zorgt voor de irrigatie van de planten in de kweekbakken.
Deze wordt aangestuurd via een GPIO-pin van de ESP32.

Aansluitingen:

VCC: 3.3V (ESP32 pin 3.3V)

GND: GND (ESP32 pin GND)

IN: ESP32 pin 27

### LED Transistor

Een transistor wordt gebruikt om de LED-verlichting in de kweekbakken
aan te sturen. De basis van de transistor is verbonden met een GPIO-pin
van de ESP32.

Aansluitingen:

BASE: ESP32 pin 14

### Lichtsensor

De lichtsensor meet de hoeveelheid licht in de kweekbakken. Deze
gegevens worden gebruikt om de verlichting aan te passen en te
optimaliseren.

Aansluitingen:

Signal: ESP32 pin 32

VCC: 3.3V (ESP32 pin 3.3V)

GND: GND (ESP32 pin GND)

### Ultrasone Sensor

De ultrasone sensor wordt gebruikt om de afstand te meten, bijvoorbeeld
voor het detecteren van waterniveaus in tanks.

Aansluitingen:

VCC: 3.3V (ESP32 pin 3.3V)

GND: GND (ESP32 pin GND)

TRIG: ESP32 pin 15

ECHO: ESP32 pin 33

### LCD Display

Het LCD-scherm wordt gebruikt om informatie weer te geven, zoals de
huidige instellingen van de kweekbakken. Het wordt aangestuurd via I2C.

Aansluitingen:

VCC: 3.3V (ESP32 pin 3.3V)

GND: GND (ESP32 pin GND)

SDA: ESP32 pin 21

SCL: ESP32 pin 22

### Overzicht van de Aansluitingen

| **Component**               | **ESP32 Pin**  | **Component Pin** |
|-----------------------------|----------------|-------------------|
| **RFID Reader**             |                |                   |
| VCC                         | 3.3V           | VCC               |
| GND                         | GND            | GND               |
| MISO                        | 19             | MISO              |
| MOSI                        | 23             | MOSI              |
| SCK                         | 18             | SCK               |
| SDA (SS)                    | 5              | SDA               |
| RST                         | 17             | RST               |
| **DS18B20**                 |                |                   |
| DATA                        | (configuratie) | DATA              |
| **Vochtigheidssensor**      |                |                   |
| VCC                         | 3.3V           | VCC               |
| GND                         | GND            | GND               |
| **Bodemvochtigheidssensor** |                |                   |
| VCC                         | 3.3V           | VCC               |
| GND                         | GND            | GND               |
| A0                          | 34             | A0                |
| **Pomp Motor**              |                |                   |
| VCC                         | 3.3V           | VCC               |
| GND                         | GND            | GND               |
| IN                          | 27             | IN                |
| **LED Transistor**          |                |                   |
| BASE                        | 14             | BASE              |
| **Lichtsensor**             |                |                   |
| Signal                      | 32             | Signal            |
| VCC                         | 3.3V           | VCC               |
| GND                         | GND            | GND               |
| **DHT11**                   |                |                   |
| VCC                         | 3.3V           | VCC               |
| GND                         | GND            | GND               |
| DATA                        | 35             | DATA              |
| **Ultrasone Sensor**        |                |                   |
| VCC                         | 3.3V           | VCC               |
| GND                         | GND            | GND               |
| TRIG                        | 15             | TRIG              |
| ECHO                        | 33             | ECHO              |
| **LCD**                     |                |                   |
| VCC                         | 3.3V           | VCC               |
| GND                         | GND            | GND               |
| SDA                         | 21             | SDA               |
| SCL                         | 22             | SCL               |

## Schema's en PCB

- Elektronische schema's

<img src="./media/image1.png" style="width:6.29861in;height:4.63333in"
alt="Afbeelding met tekst, diagram, Plan, schematisch Automatisch gegenereerde beschrijving" />

- PCB-ontwerpen en productiebestanden

<img src="./media/image2.png" style="width:6.05315in;height:4.79316in"
alt="Afbeelding met tekst, schermopname, kaart, diagram Automatisch gegenereerde beschrijving" />

# Software Architectuur

## Sensoren

> De sensoren worden periodiek uitgelezen om de huidige staat van de
> kweekomgeving te monitoren.

### **DHT11 Sensor (Temperatuur en Vochtigheid)**:

<img src="./media/image3.png" style="width:4.90693in;height:1.36477in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

### **Bodemvochtigheid Sensor**:

<img src="./media/image4.png" style="width:5.78206in;height:2.62537in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

### **Lichtsensor**:

<img src="./media/image5.png" style="width:4.29227in;height:3.19836in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

### **Ultrasone Sensor (Waterniveau)**:

<img src="./media/image6.png" style="width:4.56314in;height:2.86498in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

## Actuatoren

Actuatoren worden aangestuurd op basis van de gemeten sensorwaarden.

### **Waterpomp**:

<img src="./media/image7.png" style="width:3.26087in;height:2.61495in"
alt="Afbeelding met tekst, schermopname, Lettertype, ontwerp Automatisch gegenereerde beschrijving" />

### **LED-verlichting**:

<img src="./media/image8.png" style="width:3.70885in;height:2.21906in"
alt="Afbeelding met tekst, Lettertype, schermopname, ontwerp Automatisch gegenereerde beschrijving" />

## Data doorsturen naar de server (MQTT)

### Implementatie van MQTT-protocol

De sensorwaarden worden via MQTT naar een centrale server gestuurd, waar
ze worden opgeslagen en gevisualiseerd.

### **MQTT Verbinding**:

<img src="./media/image9.png" style="width:4.32352in;height:3.8547in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

<img src="./media/image10.png" style="width:4.22976in;height:3.82345in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

### **Data Publicatie**:

<img src="./media/image11.png" style="width:4.22976in;height:4.52146in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

## Data opslag op de server

De data die wordt verzameld door de sensoren in het "Smart Greenhouse"
project, wordt opgeslagen in een InfluxDB database. InfluxDB is een
krachtige tijdreeksdatabase die specifiek is ontworpen voor het
verwerken van grote hoeveelheden tijdgestempelde data, zoals de metingen
van sensoren in ons project. Deze database biedt een efficiënte en
schaalbare oplossing voor het opslaan en opvragen van de gegevens die
door de ESP32 worden verzonden.

## Data visualisatie met Grafana

### MQTT

#### Beschrijving

MQTT is een handig protocol voor het Internet of Things (IoT). Het laat
apparaten berichten uitwisselen door ze te 'publiceren' naar bepaalde
'topics' en door zich te 'abonneren' op die topics om berichten te
ontvangen. Dit maakt het gemakkelijk voor apparaten om met elkaar te
praten zonder directe verbindingen te hebben. Het helpt ook bij het
besparen van bandbreedte en energie, wat belangrijk is voor
IoT-apparaten. Met MQTT kunnen apparaten betrouwbaar berichten verzenden
en ontvangen, zelfs als er storingen zijn in het netwerk.

#### Installeren van MQTT op raspberry pi

1.  Download het besturingssysteem:

Ga naar de officiële website van de Raspberry Pi Foundation
(https://www.raspberrypi.org/) en download het gewenste
besturingssysteem.

2.  Sluit de Raspberry Pi aan:

Steek de microSD-kaart in de daarvoor bestemde sleuf op de Raspberry Pi.

Sluit een voedingsadapter aan op de micro-USB-poort van de Raspberry Pi
en steek de adapter in het stopcontact.

3.  Start de Raspberry Pi op:

Nadat alles is aangesloten, wordt de Raspberry Pi automatisch opgestart.

Nadat de Raspberry Pi volledig is opgestart, kun je via de opdrachtregel
(command prompt) op een computer die is verbonden met hetzelfde
wifi-netwerk, verbinding maken met de Raspberry Pi via SSH (Secure
Shell).

4.  Update en upgrade het systeem:

Open een terminalvenster en voer de volgende commando's uit om het
systeem bij te werken en te upgraden:

<span class="mark">sudo apt update</span>

<span class="mark">sudo apt upgrade</span>

5.  Installeer MQTT-broker (Mosquitto)

Mosquitto is een populaire MQTT-broker die we op de Raspberry Pi kunnen
installeren. Voer het volgende commando uit:

<span class="mark">sudo apt install mosquitto mosquitto-clients</span>

6.  Start de Mosquitto-service

Nadat Mosquitto is geïnstalleerd, wordt de service automatisch gestart.
Als dit niet het geval is, kun je het handmatig starten met:

<span class="mark">sudo systemctl start mosquitto</span>

7.  Controleer of Mosquitto draait

Je kunt controleren of de Mosquitto-service correct draait door het
statuscommando te gebruiken:

<span class="mark">sudo systemctl status mosquitto</span>

### Grafana

#### Beschrijving

Grafana is een platform voor het monitoren en visualiseren van data,
waar gebruikers gegevens uit databases zoals InfluxDB kunnen halen,
analyseren en presenteren op aanpasbare dashboards. Met MQTT-integratie
kunnen IoT-apparaten naadloos communiceren met Grafana, wat efficiënte
monitoring en datavisualisatie mogelijk maakt.

#### Installeren van grafana op raspberry pi

1.  Voeg de APT-sleutel toe voor het verifiëren van pakketten:

- Maak een map aan voor de APT-sleutel die wordt gebruikt om pakketten
  te verifiëren:

<span class="mark">sudo mkdir -p /etc/apt/keyrings/</span>

- Download en voeg de APT-sleutel van Grafana toe aan de sleutelring:

  <span class="mark">wget -q -O - https://apt.grafana.com/gpg.key \| gpg
  --dearmor \| sudo tee /etc/apt/keyrings/grafana.gpg \>
  /dev/null</span>

2.  Voeg de Grafana APT-repository toe aan het bronnenbestand:

<span class="mark">echo "deb \[signed-by=/etc/apt/keyrings/grafana.gpg\]
https://apt.grafana.com stable main" \| sudo tee
/etc/apt/sources.list.d/grafana.list</span>

3.  Installeer Grafana:

- Werk de pakketlijsten bij:

<span class="mark">sudo apt-get update</span>

- Installeer Grafana:

<span class="mark">sudo apt-get install -y grafana</span>

4.  Start Grafana:

- Grafana is nu geïnstalleerd, maar nog niet actief. Om ervoor te zorgen
  dat Grafana automatisch start bij het opstarten van de Raspberry Pi,
  moeten we de Grafana Systemctl-service inschakelen en starten.

- Schakel de Grafana-server in:

<span class="mark">sudo /bin/systemctl enable grafana-server</span>

- Start de Grafana-server:

<span class="mark">sudo /bin/systemctl start grafana-server</span>

Nu draait Grafana op de machine en is toegankelijk vanaf elk apparaat in
het lokale netwerk.

#### Installeren van InfluxDB

1.  Installeer InfluxDB:

InfluxDB kan op een Raspberry Pi worden geïnstalleerd via de officiële
InfluxData repository. Hier volgt hoe je dat doet:

- Download en installeer de repositorysleutel van InfluxDB:

<span class="mark">wget -qO- https://repos.influxdata.com/influxdb.key
\| sudo apt-key add –</span>

- Voeg de InfluxDB repository toe aan de softwarebronnen van je
  Raspberry Pi:

<span class="mark">echo "deb https://repos.influxdata.com/debian buster
stable" \| sudo tee /etc/apt/sources.list.d/influxdb.list</span>

- Werk de pakketlijsten bij en installeer InfluxDB:

<span class="mark">sudo apt update</span>

<span class="mark">sudo apt install influxdb</span>

2.  Start InfluxDB en laat het opstarten bij het systeem:

Nadat InfluxDB is geïnstalleerd, kun je de service starten en ervoor
zorgen dat deze automatisch wordt gestart bij het opstarten van het
systeem:

- Start de InfluxDB-service:

<span class="mark">sudo systemctl start influxdb</span>

- Zorg ervoor dat InfluxDB opstart bij het opstarten van het systeem:

<span class="mark">sudo systemctl enable influxdb</span>

3.  Controleer de installatie:

Je kunt controleren of InfluxDB correct draait door de status te
controleren:

<span class="mark">sudo systemctl status influxdb</span>

Als InfluxDB correct draait, zou je een bericht moeten zien dat aangeeft
dat de service actief en draaiend is.

- Installatie en configuratie van Grafana

- Integratie met de database

# 5. Implementatie

## Ontwerpen van het Prototype

### Keuze van componenten

#### Keuze van de RFID-RC522 Module

De keuze voor de RFID-RC522 module in dit project is gebaseerd op de
volgende overwegingen:

1)  **Kosten en Beschikbaarheid**: De module is betaalbaar en breed
    beschikbaar, ideaal voor budgetvriendelijke projecten.

2)  **Compatibiliteit met ESP32**: Werkt naadloos met de ESP32 via de
    SPI-bus, met goed gedocumenteerde bibliotheken.

3)  **Gebruiksvriendelijkheid**: Eenvoudig te implementeren en goed
    ondersteund door talrijke bronnen en voorbeelden.

4)  **Ondersteuning voor Diverse RFID-Tags**: Ondersteunt verschillende
    soorten RFID-tags, zoals MIFARE Classic, wat flexibiliteit biedt.

#### Keuze van de LM393 Bodemvocht Hygrometer

De keuze voor de LM393 bodemvocht hygrometer in dit project is gebaseerd
op de volgende overwegingen:

1)  **Kosten en Beschikbaarheid**: De sensor is betaalbaar en breed
    beschikbaar, wat hem geschikt maakt voor budgetvriendelijke
    projecten.

2)  **Compatibiliteit met ESP32**: Werkt eenvoudig samen met de ESP32
    door middel van analoge en digitale signalen.

3)  **Gebruiksvriendelijkheid**: Eenvoudig te installeren en kalibreren,
    met uitgebreide documentatie en voorbeelden beschikbaar.

4)  **Nauwkeurigheid en Betrouwbaarheid**: Biedt consistente en
    betrouwbare metingen van bodemvochtigheid, cruciaal voor
    plantbeheer.

5)  **Laag Vermogen**: Verbruikt weinig stroom, waardoor het ideaal is
    voor draadloze, batterijgevoede modules.

6)  **Compact Formaat**: Geschikt voor integratie in kweekbakken zonder
    veel ruimte in beslag te nemen

> .

#### Keuze van de Automatische Irrigatiemodule DIY Kit

De keuze voor de Automatische Irrigatiemodule DIY Kit van AliExpress
voor dit project is gebaseerd op verschillende overwegingen:

1.  **Volledige Kit**: Deze kit biedt een alles-in-één oplossing voor
    automatische irrigatie, inclusief een bodemvochtsensor,
    relaismodule, mini waterpomp en slang. Dit vereenvoudigt het
    aanschaf- en installatieproces.

<!-- -->

1)  **Betaalbaarheid**: De kit is betaalbaar en biedt een
    kosteneffectieve oplossing voor automatische irrigatie, waardoor het
    geschikt is voor projecten met een beperkt budget.

2)  **Eenvoudige Installatie**: Door de kit wordt de installatie
    vereenvoudigd, aangezien alle benodigde onderdelen bij elkaar worden
    geleverd. Dit bespaart tijd en moeite bij het zoeken naar
    afzonderlijke componenten.

3)  **Compatibiliteit met Arduino**: De kit is compatibel met Arduino,
    waardoor het gemakkelijk te integreren is met microcontrollers zoals
    de ESP32 voor verdere aanpassing en automatisering.

4)  **Flexibiliteit**: De kit biedt flexibiliteit in irrigatietiming en
    -hoeveelheid, waardoor het geschikt is voor verschillende
    plantbehoeften en omgevingen.

5)  **Gebruiksgemak**: Dankzij de mini waterpomp en de bijbehorende
    slang kan water efficiënt worden afgeleverd aan de planten, waardoor
    de groei en gezondheid van de planten worden bevorderd zonder
    handmatige interventie.

#### Keuze van de USB Phyto Lamp LED Grow Strip Licht

De keuze voor de USB Phyto Lamp LED Grow Strip Licht voor dit project is
gebaseerd op de volgende overwegingen:

1)  **Full Spectrum Verlichting**: De LED strip biedt een volledig
    spectrum aan licht, inclusief alle benodigde golflengtes voor
    optimale plantengroei. Dit zorgt voor gezonde en krachtige
    plantengroei gedurende alle groeistadia.

2)  **Energiezuinigheid**: De LED technologie zorgt voor een efficiënt
    energieverbruik, wat resulteert in lagere energiekosten op de lange
    termijn. Dit maakt het ideaal voor continu gebruik in een slimme
    kasomgeving.

3)  **Flexibiliteit in Installatie**: Dankzij het compacte en flexibele
    ontwerp van de LED strip kan het eenvoudig worden geïnstalleerd in
    verschillende configuraties, zoals boven de plantenrekken of langs
    de zijkanten van de kweekbakken.

4)  **USB Voeding**: De mogelijkheid om de LED strip via USB van stroom
    te voorzien biedt gemak en veelzijdigheid. Het kan worden
    aangesloten op een verscheidenheid aan voedingsbronnen, waaronder
    powerbanks, laptops, en USB-adapters.

5)  **Geschikt voor Hydrocultuur en Kasomgevingen**: De LED strip is
    speciaal ontworpen voor gebruik in hydrocultuursystemen en kassen,
    waar het zorgt voor een optimale lichtomgeving die bevorderlijk is
    voor gezonde plantengroei en opbrengst.

6)  **Duurzaamheid en Lange Levensduur**: LED verlichting staat bekend
    om zijn lange levensduur en duurzaamheid. De LED strip vereist
    weinig onderhoud en heeft een lange levensduur, waardoor het een
    kosteneffectieve investering is voor langdurig gebruik.

#### Keuze van de LDR Module voor Arduino

De keuze voor de LDR (Light Dependent Resistor) module voor Arduino in
dit project is gebaseerd op de volgende overwegingen:

1)  **Eenvoudige Detectie van Lichtniveaus**: De LDR module biedt een
    eenvoudige en effectieve manier om lichtniveaus te detecteren door
    middel van een lichtgevoelige weerstand. Dit maakt het ideaal voor
    het bewaken van de lichtomstandigheden in de kas.

2)  **Betaalbaarheid en Beschikbaarheid**: De module is betaalbaar en
    breed beschikbaar, waardoor het een kosteneffectieve oplossing is
    voor het meten van lichtintensiteit in het project.

3)  **Compatibiliteit met esp32**: De LDR module is compatibel met esp
    microcontrollers en kan eenvoudig worden geïntegreerd in het project
    met behulp van standaard analoge pinnen.

4)  **Brede Toepasbaarheid**: De module kan worden gebruikt voor
    verschillende toepassingen, zoals het regelen van de verlichting in
    de kas, het monitoren van daglichtniveaus, en het activeren van
    automatische systemen op basis van lichtcondities.

5)  **Eenvoudige Implementatie**: De LDR module vereist minimale
    hardware- en softwareconfiguratie, waardoor het snel en gemakkelijk
    kan worden geïmplementeerd in het project zonder ingewikkelde setup.

6)  **Real-time Monitoring**: Door gebruik te maken van de LDR module
    kunnen real-time metingen van lichtniveaus worden uitgevoerd,
    waardoor nauwkeurige en up-to-date informatie wordt verkregen over
    de omgevingslichtomstandigheden in de kas.

#### Keuze van de HC-SR04 Ultrasone Afstandssensor voor Arduino

De keuze voor de HC-SR04 Ultrasone Afstandssensor voor Arduino in dit
project is gebaseerd op de volgende overwegingen:

1)  **Nauwkeurige Afstandsmeting:** De HC-SR04 sensor biedt nauwkeurige
    en betrouwbare metingen van afstanden met behulp van ultrasone
    golven. Dit maakt het ideaal voor het monitoren van de afstand tot
    plantenbakken of andere objecten in de kas.

2)  **Groot Bereik**: De sensor heeft een groot bereik van enkele
    centimeters tot enkele meters, waardoor het geschikt is voor
    verschillende toepassingen in het project, zoals het detecteren van
    waterstanden, het meten van plantengroei en het vermijden van
    obstakels.

3)  **Eenvoudige Implementatie**: De HC-SR04 sensor is gemakkelijk te
    gebruiken en vereist minimale configuratie om te integreren met
    Arduino microcontrollers. Met behulp van slechts enkele pinnen
    kunnen afstandsmetingen worden uitgevoerd.

4)  **Betaalbaarheid en Beschikbaarheid**: De sensor is betaalbaar en
    wordt breed beschikbaar gesteld door verschillende leveranciers,
    waardoor het een kosteneffectieve en toegankelijke oplossing is voor
    het project.

5)  **Real-time Feedback**: Door de snelle meettijd van de HC-SR04
    sensor kunnen real-time feedback en reacties worden gegeven op
    veranderingen in afstanden, wat essentieel is voor het automatiseren
    van systemen in de kas.

6)  **Duurzaamheid en Betrouwbaarheid**: De HC-SR04 sensor is robuust en
    betrouwbaar in verschillende omgevingsomstandigheden, waardoor het
    geschikt is voor langdurig gebruik in de kasomgeving.

#### Keuze van de LCD1602 I2C Display Module voor Arduino

De keuze voor de LCD1602 I2C Display Module voor Arduino in dit project
is gebaseerd op de volgende overwegingen:

1)  **Gemakkelijke Interface**: De LCD1602 module maakt gebruik van de
    I2C-interface, waardoor het eenvoudig te verbinden is met
    Arduino-bordjes via slechts twee pinnen (SDA en SCL). Dit
    vereenvoudigt de bedrading en maakt snelle integratie mogelijk.

2)  **Groot Display**: Het 16x2 LCD-scherm biedt een ruimtebesparende en
    toch overzichtelijke weergave van gegevens. Hierdoor is het ideaal
    voor het tonen van sensorwaarden, statusinformatie en
    systeemmeldingen in het Smart Greenhouse-project.

3)  **Verlicht Display**: Het blauw-groene scherm van de LCD1602 module
    zorgt voor een goed leesbare en aantrekkelijke weergave, zelfs onder
    verschillende lichtomstandigheden in de kasomgeving.

4)  **Compatibiliteit met I2C-adapter**: De meegeleverde PCF8574
    I2C-adapter vereenvoudigt de communicatie tussen de Arduino en het
    LCD-scherm, waardoor de noodzaak van veel bedrading wordt
    geëlimineerd en de kans op fouten wordt verminderd.

5)  **Brede Ondersteuning**: De LCD1602 module wordt ondersteund door
    populaire Arduino-bibliotheken voor het aansturen van
    karakter-LCD's, waardoor het gemakkelijk is om de module te
    programmeren en aan te passen aan de behoeften van het project.

6)  **Kosteneffectief en Breed Beschikbaar**: De LCD1602 module is een
    betaalbare en wijdverbreide oplossing die gemakkelijk verkrijgbaar
    is bij verschillende leveranciers, waardoor het een toegankelijke
    keuze is voor het project.

#### Keuze van de DHT11 Module voor Temperatuur- en Vochtigheidsmeting

De keuze voor de DHT11 module voor temperatuur- en vochtigheidsmeting in
dit project is gebaseerd op de volgende overwegingen:

1)  **Geïntegreerde Functionaliteit**: De DHT11 module biedt zowel
    temperatuur- als vochtigheidsmetingen in één compacte behuizing. Dit
    maakt het een handige oplossing voor het bewaken van deze cruciale
    parameters in de kasomgeving.

2)  **Eenvoudige Implementatie**: De module communiceert via een enkele
    datalijn met de Arduino, wat de implementatie vereenvoudigt en de
    benodigde pinaansluitingen minimaliseert.

3)  **Nauwkeurige Metingen**: Ondanks zijn eenvoud biedt de DHT11 module
    redelijk nauwkeurige metingen van temperatuur en luchtvochtigheid,
    wat voldoende is voor de meeste toepassingen in het Smart
    Greenhouse-project.

4)  **Brede Compatibiliteit**: De DHT11 module is compatibel met
    verschillende microcontrollerplatforms, waaronder Arduino, waardoor
    het gemakkelijk kan worden geïntegreerd in het project zonder extra
    configuratie.

5)  **Betaalbaar en Beschikbaar**: De DHT11 module is een
    kosteneffectieve oplossing die wijdverspreid beschikbaar is bij
    verschillende leveranciers, waardoor het een toegankelijke keuze is
    voor het project met een beperkt budget.

6)  **Robuustheid**: De module is relatief robuust en kan goed presteren
    in verschillende omgevingsomstandigheden, wat belangrijk is voor een
    betrouwbare werking in de kasomgeving.

### Uitwerken van het Schema en PCB

Voor het uitwerken van het elektrisch schema is elke gebruikte component
verbonden met een vooraf gekozen pin van de ESP32. Het is echter van
cruciaal belang om voor analoge sensoren, zoals de DHT11 en
bodemvochtigheidssensoren, geen I2C-pinnen te gebruiken. Deze pinnen
kunnen namelijk niet meer analoog worden gebruikt zodra de
wifi-functionaliteit wordt ingeschakeld.

Bij het ontwerpen van de PCB is bewust gekozen voor het gebruik van
Wago-klemmen in plaats van het rechtstreeks monteren van hardware op de
printplaat. Deze benadering biedt flexibiliteit doordat sensoren en
actuatoren op strategische locaties kunnen worden geplaatst. Bovendien
worden de Wago-klemmen zoveel mogelijk langs de buitenkant van de
printplaat geplaatst, waardoor ze altijd gemakkelijk toegankelijk zijn
en er geen andere componenten in de weg zitten. Dit vergemakkelijkt
onderhoud en eventuele latere aanpassingen aan het systeem.

# Gebruikershandleiding

## Installatie van de Smart Greenhouse Module

1.  **Fysieke Installatie**: Plaats de Smart Greenhouse module in de kas
    op een strategische locatie waar een goede verbinding met de
    sensoren en actuatoren mogelijk is.

2.  **Stroomvoorziening**: Zorg voor een stabiele stroomvoorziening voor
    de module. Dit kan worden gedaan door de module aan te sluiten op
    een betrouwbare voedingsbron, zoals een netadapter of een batterij.

3.  **WiFi-connectiviteit**: Zorg ervoor dat de module verbinding kan
    maken met een draadloos netwerk. Configureer de WiFi-instellingen
    volgens de instructies in de gebruikershandleiding van de ESP32.

## Bediening van de Module

1.  **In- en Uitschakelen**: Schakel de Smart Greenhouse module in door
    de stroomtoevoer in te schakelen. Gebruik de aan/uit-knop of
    schakelaar van de voedingsbron om de module in- of uit te schakelen.

2.  **RFID-configuratie**: Gebruik de RFID-lezer om een specifiek kruid
    te selecteren voor elke kweekbak. Houd de RFID-tag van het gewenste
    kruid tegen de lezer om de instellingen automatisch aan te passen.

3.  **Waarnemen van Sensorwaarden**: Monitor de temperatuur,
    luchtvochtigheid, bodemvochtigheid, lichtniveaus en waterstand in de
    kas via het LCD-scherm van de module. De actuele sensorwaarden
    worden regelmatig bijgewerkt en weergegeven op het scherm.

## Interactie met Grafana-dashboard

1.  **Toegang tot Grafana**: Gebruik een webbrowser om toegang te
    krijgen tot het Grafana-dashboard. Voer het IP-adres of de URL van
    de Grafana-server in de adresbalk in en meld u aan met de juiste
    referenties.

2.  **Weergave van Gegevens**: Navigeer door de verschillende dashboards
    om de historische gegevens van de kas te bekijken, waaronder
    temperatuur, luchtvochtigheid, bodemvochtigheid, lichtniveaus en
    meer.

3.  **Analyse en Rapportage**: Maak gebruik van de analyse- en
    rapportagemogelijkheden van Grafana om trends te identificeren,
    patronen te analyseren en gedetailleerde rapporten te genereren over
    de kasomgeving.

## Onderhoud en Probleemoplossing

1.  **Regelmatig Onderhoud**: Voer regelmatig onderhoud uit aan de Smart
    Greenhouse module en controleer de werking van sensoren, actuatoren
    en andere componenten.

# Toekomstig Werk

## Mogelijke uitbreidingen en verbeteringen

### Ventilator

- Beschrijving: Een ventilator kan worden toegevoegd om de
  luchtcirculatie in de kas te verbeteren. Dit helpt bij het verspreiden
  van warmte, vochtigheid en lucht naar alle planten, waardoor een
  uniforme groeiomgeving wordt gecreëerd.

- Voorgestelde Hardware: Een DC-ventilator met variabele
  snelheidsregeling kan worden gebruikt. Een geschikte ventilatorgrootte
  hangt af van de grootte van de kas en de gewenste luchtcirculatie.

### Warmtemat

- Beschrijving: Een warmtemat kan worden geïntegreerd om de
  bodemtemperatuur in de kweekbakken te regelen. Dit is vooral handig
  tijdens koude periodes om de wortels van de planten warm te houden en
  de groei te stimuleren.

- Voorgestelde Hardware: Een waterdichte warmtemat met een geschikt
  vermogen en afmetingen voor de kweekbakken. De mat kan worden
  aangesloten op een temperatuurregelaar om de gewenste bodemtemperatuur
  te handhaven.

### Bodemtemperatuurmeter

- Beschrijving: Een bodemtemperatuurmeter kan worden toegevoegd om de
  temperatuur van de bodem in elke kweekbak nauwkeurig te meten. Dit
  helpt bij het monitoren van de ideale groeiomstandigheden voor
  verschillende soorten planten.

- Voorgestelde Hardware: Een waterdichte temperatuursensor die specifiek
  is ontworpen voor het meten van bodemtemperaturen. De sensor kan
  worden geïntegreerd in elke kweekbak en verbonden met de ESP32 voor
  gegevensverzameling.

### Uitbreidingsplan

1.  Onderzoek en Selectie van Hardware: Voer een grondig onderzoek uit
    naar geschikte ventilatoren, warmtematten en
    bodemtemperatuursensoren op basis van specificaties, compatibiliteit
    en prijs.

2.  Aanpassing van het Elektrisch Schema: Werk het elektrisch schema van
    de Smart Greenhouse module bij om de nieuwe hardwarecomponenten op
    te nemen en de vereiste verbindingen te definiëren.

3.  Ontwerp van de PCB: Pas het PCB-ontwerp aan om aansluitingen te
    bieden voor de ventilator, warmtemat en bodemtemperatuursensor. Zorg
    voor voldoende ruimte en isolatie om waterdichtheid te garanderen.

4.  Firmware-implementatie: Programmeer de ESP32 om de nieuwe
    hardwarecomponenten te ondersteunen, waaronder het regelen van de
    ventilatorsnelheid, het monitoren van de warmtemat en het verzamelen
    van gegevens van de bodemtemperatuursensor.

5.  Testen en Kalibratie: Voer uitgebreide tests uit om de
    functionaliteit en prestaties van de nieuwe hardwarecomponenten te
    valideren. Kalibreer indien nodig sensoren en controleer de
    betrouwbaarheid van de bediening.

6.  Documentatie en Training: Documenteer alle wijzigingen en
    toevoegingen aan het systeem, inclusief installatieprocedures,
    bedieningsinstructies en onderhoudsrichtlijnen. Zorg voor training
    van gebruikers om hen vertrouwd te maken met de nieuwe functies.

# Code uitgelegd

Deze code is ontworpen voor een project dat een slimme serre creëert.
Het doel van de code is om verschillende sensoren en actuatoren te
integreren en te bedienen via een microcontroller (in dit geval een
ESP32) en deze te koppelen aan een lokaal draadloos netwerk (Wi-Fi) en
een MQTT-broker voor gegevensuitwisseling. De code maakt gebruik van
verschillende bibliotheken om de functionaliteit te implementeren,
waaronder het lezen van sensorgegevens zoals bodemvochtigheid,
lichtniveaus, temperatuur en luchtvochtigheid, evenals het aansturen van
een waterpomp en LED-verlichting.

## Vereiste bibliotheken

De code maakt gebruik van verschillende externe bibliotheken die nodig
zijn voor de functionaliteit van de serre. Deze bibliotheken worden aan
het begin van het programma geïmporteerd. Enkele van deze bibliotheken
zijn:

- Wire.h: Voor communicatie via I2C.

- LiquidCrystal_I2C.h: Om een LCD-scherm met I2C-interface aan te
  sturen.

- DHT.h: Voor het lezen van gegevens van een DHT11-temperatuur- en
  vochtigheidssensor.

- MFRC522.h: Voor het lezen van RFID-tags.

- OneWire.h en DallasTemperature.h: Voor het lezen van temperaturen via
  een DS18B20 temperatuursensor.

- WiFi.h en PubSubClient.h: Voor het opzetten van een Wi-Fi-verbinding
  en communicatie met een MQTT-broker.

<img src="./media/image12.png" style="width:3.54216in;height:2.92749in"
alt="Afbeelding met tekst, schermopname, Lettertype, ontwerp Automatisch gegenereerde beschrijving" />

## Definitie van constanten en variabelen

In dit gedeelte van de code worden constanten gedefinieerd voor de
pinconfiguratie en andere parameters die nodig zijn voor de werking van
de sensoren en actuatoren. Dit omvat de pinnummers voor sensoren (zoals
DHT11, bodemvochtigheidssensor, lichtsensor), actuatoren (zoals
LED-strip en waterpomp), en RFID-configuratie (SS_PIN en RST_PIN). Er
worden ook variabelen gedeclareerd om sensorgegevens en andere
statusinformatie op te slaan.

Hier worden verschillende constanten gedefinieerd voor de
pinconfiguratie en andere parameters die nodig zijn voor het project:

- DHTPIN: Het pinnummer waaraan de DHT-sensor is verbonden.

- DHTTYPE: Het type DHT-sensor dat wordt gebruikt, in dit geval DHT11.

- LEDSTRIPPIN: Het pinnummer waaraan de LED-strip is verbonden.

- BODEMSENSORPIN: Het pinnummer waaraan de bodemvochtigheidssensor is
  verbonden.

- LIGHTPIN: Het pinnummer waaraan de lichtsensor is verbonden.

- trigPIN: Het pinnummer van de trigger-pin van de ultrasone sensor.

- echoPIN: Het pinnummer van de echo-pin van de ultrasone sensor.

- POMPPIN: Het pinnummer waaraan de waterpomp is verbonden.

- SS_PIN en RST_PIN: De pinnummers voor respectievelijk SS (Slave
  Select) en RST (Reset) van de RFID-lezer.

- ONE_WIRE_BUS: Het pinnummer voor de OneWire-bus, gebruikt voor de
  DS18B20-temperatuursensor.

- SOUND_SPEED: De snelheid van geluid, gebruikt voor het berekenen van
  afstanden met de ultrasone sensor.

<img src="./media/image13.png" style="width:6.29861in;height:3.54167in"
alt="Afbeelding met tekst, schermopname, Lettertype, ontwerp Automatisch gegenereerde beschrijving" />

Hier worden configuratieparameters gedefinieerd voor het verbinden met
Wi-Fi en de MQTT-broker:

- ssid: De naam van het draadloze netwerk (SSID) waarmee verbinding moet
  worden gemaakt.

- password: Het wachtwoord van het draadloze netwerk.

- mqttServer: Het IP-adres van de MQTT-broker.

- mqttPort: De poort van de MQTT-broker.

- mqttUser: De gebruikersnaam voor de MQTT-verbinding.

- mqttPassword: Het wachtwoord voor de MQTT-verbinding.

- clientID: Het client-ID voor de MQTT-verbinding.

- payload: Een string voor het opslaan van MQTT-payloads.

- espClient: Een WiFiClient-object voor de communicatie via Wi-Fi.

- client: Een PubSubClient-object voor communicatie met de MQTT-broker.

<img src="./media/image14.png" style="width:6.29861in;height:3.18472in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

Hier worden de objecten geïnstantieerd voor de verschillende sensoren en
actuatoren:

- oneWire: Een object voor de communicatie met de
  DS18B20-temperatuursensor via de OneWire-bus.

- lcd: Een object voor het aansturen van het LCD-scherm met het
  opgegeven adres, aantal kolommen en rijen.

- dht: Een object voor het lezen van gegevens van de DHT11-temperatuur-
  en vochtigheidssensor.

- rfid: Een object voor het lezen van RFID-tags via de MFRC522-lezer.

- key: Een sleutelobject voor de RFID-lezer.

- nuidPICC: Een array voor het opslaan van de unieke ID van een
  RFID-tag.

- sensors: Een object voor het lezen van temperaturen via de
  DS18B20-temperatuursensor.

- tag1, tag2, tag3: De unieke ID's van de RFID-tags die in het project
  worden gebruikt.

<img src="./media/image15.png" style="width:6.29861in;height:3.02778in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

Dit deel van de code definieert variabelen die worden gebruikt om
sensorgegevens en andere statusinformatie bij te houden tijdens de
werking van het systeem. Laten we elk van deze variabelen in meer detail
bekijken:

- float humidity{}; en float currenthumidity{};: Deze variabelen worden
  gebruikt om de luchtvochtigheid van de serre op te slaan. humidity
  wordt gebruikt voor het instellen van de gewenste luchtvochtigheid,
  terwijl currenthumidity de actuele luchtvochtigheid bijhoudt.

- float temperature{}; en float currenttemperature{};: Deze variabelen
  houden respectievelijk de gewenste en actuele temperatuur bij in de
  serre.

- float belichting{}; en float currentlight{};: Deze variabelen worden
  gebruikt voor het instellen en bijhouden van de gewenste en actuele
  lichtintensiteit in de serre.

- bool ledstate{};: Deze variabele houdt de status van de
  LED-verlichting bij, die wordt gebruikt om aan te geven of de
  verlichting is ingeschakeld of uitgeschakeld.

- float bodemvochtigheid{ 3900 }; en float currentbodemvochtigheid{};:
  Deze variabelen worden gebruikt voor het instellen en bijhouden van de
  gewenste en actuele bodemvochtigheid in de serre.

- float watervolume{};: Deze variabele wordt gebruikt om het volume
  water in de watertank bij te houden.

- long duration;: Deze variabele wordt gebruikt om de tijdsduur van
  ultrasone geluidsimpulsen op te slaan.

- float distanceCm;: Deze variabele wordt gebruikt om de afstand gemeten
  door de ultrasone sensor in centimeters op te slaan.

- float totalCM{ 20 };: Deze variabele wordt gebruikt om de totale
  diepte van het water in de watertank in centimeters op te slaan.

- int currentRFID{};: Deze variabele wordt gebruikt om de ID van de
  momenteel gedetecteerde RFID-tag op te slaan.

<img src="./media/image16.png" style="width:3.43798in;height:4.43812in"
alt="Afbeelding met tekst, schermopname, Lettertype, ontwerp Automatisch gegenereerde beschrijving" />

## Setup-functie

De setup()-functie wordt slechts één keer uitgevoerd bij het opstarten
van de microcontroller. In deze functie worden de initiële configuraties
uitgevoerd, zoals het instellen van de seriële communicatie, het
verbinden met Wi-Fi en MQTT-broker, het initialiseren van sensoren en
actuatoren, en het definiëren van de initiële toestand van de actuatoren
(bijvoorbeeld de waterpomp uitgeschakeld).

Laten we elke regel van deze functie bespreken:

- Serial.begin(115200);: Dit initialiseert de seriële communicatie met
  een baudsnelheid van 115200. Hiermee kan de microcontroller gegevens
  naar de seriële monitor sturen voor debugging en monitoringdoeleinden.

- WiFi.begin(ssid, password);: Dit begint met het verbinden met het
  draadloze netwerk met de opgegeven SSID (netwerknaam) en wachtwoord.

- setupwifi();: Dit is een aangepaste functie die de configuratie van de
  Wi-Fi-verbinding afhandelt. De details van deze functie zijn niet in
  dit deel van de code opgenomen.

- setupLCD();: Deze functie initialiseert het LCD-scherm en zorgt ervoor
  dat het klaar is voor gebruik. Het is waarschijnlijk dat deze functie
  wordt gedefinieerd elders in de code.

- setupRFID();: Deze functie initialiseert de RFID-lezer en bereidt deze
  voor om RFID-tags te kunnen lezen. Dit omvat het instellen van pinnen
  en het initialiseren van de RFID-bibliotheek.

- setupDHT();: Deze functie initialiseert de DHT-temperatuur- en
  vochtigheidssensor voor gebruik. Dit omvat het instellen van pinnen en
  het initialiseren van de DHT-bibliotheek.

- setupdallassensor();: Deze functie initialiseert de
  DS18B20-temperatuursensor voor gebruik. Dit omvat het instellen van
  pinnen en het initialiseren van de DallasTemperature-bibliotheek.

- setupALLPIN();: Deze functie initialiseert alle pinnen die in de code
  zijn gedefinieerd voor gebruik. Dit omvat het instellen van pinnen als
  invoer of uitvoer, afhankelijk van hun functie.

- pomp_off();: Deze functie zorgt ervoor dat de waterpomp uitgeschakeld
  is bij het opstarten van het systeem. Dit kan handig zijn om ervoor te
  zorgen dat de waterpomp niet onbedoeld begint te werken voordat de
  juiste omstandigheden zijn ingesteld.

<img src="./media/image17.png" style="width:3.12544in;height:3.46923in"
alt="Afbeelding met tekst, schermopname, Lettertype, ontwerp Automatisch gegenereerde beschrijving" />

## De loop-functie

Het hoofdprogramma wordt herhaaldelijk uitgevoerd in de loop()-functie.
In dit programma worden de verschillende taken uitgevoerd:

- Verbinding controleren: Er wordt gecontroleerd of de verbinding met de
  MQTT-broker actief is. Indien niet, wordt opnieuw verbonden.

- Lezen en weergeven van RFID-gegevens: RFID-tags worden gelezen,
  gecontroleerd en weergegeven op het LCD-scherm.

- Lezen en weergeven van bodemvochtigheid: De sensor voor
  bodemvochtigheid wordt uitgelezen en de gegevens worden weergegeven op
  het LCD-scherm.

- Lezen en weergeven van lichtniveaus: De lichtsensor wordt uitgelezen
  en de gegevens worden weergegeven op het LCD-scherm.

- Lezen en weergeven van temperatuur- en vochtigheidsgegevens: De
  DHT11-sensor wordt uitgelezen en de gegevens worden weergegeven op het
  LCD-scherm.

- Lezen en weergeven van watervolume: De ultrasone sensor wordt gebruikt
  om het watervolume te meten en weer te geven op het LCD-scherm.

Laten we de verschillende stappen in deze functie bespreken:

- if (!client.connected()) { reconnect(); }: Deze regels controleren of
  de MQTT-client verbonden is met de broker. Als de client niet
  verbonden is, wordt de functie reconnect() aangeroepen om opnieuw
  verbinding te maken.

<!-- -->

- readRFID();: Deze functie leest de RFID-tags die zich in de buurt van
  de RFID-lezer bevinden.

- displayRFID();: Deze functie geeft de gelezen RFID-tag op het
  LCD-scherm weer.

- delay(2000);: Dit zorgt voor een vertraging van 2 seconden voordat de
  volgende stap wordt uitgevoerd. Dit zorgt ervoor dat elke taak met
  tussenpozen wordt uitgevoerd.

- readbodemvochtigheid();: Deze functie leest de bodemvochtigheid met
  behulp van de bodemvochtigheidssensor.

- displaybodemvochtigheid();: Deze functie geeft de gemeten
  bodemvochtigheid weer op het LCD-scherm.

- readbelichting();: Deze functie leest de lichtintensiteit met behulp
  van de lichtsensor.

- displaybelichting();: Deze functie geeft de gemeten lichtintensiteit
  weer op het LCD-scherm.

- readDHT();: Deze functie leest de temperatuur en luchtvochtigheid met
  behulp van de DHT-sensor.

- displayDHT();: Deze functie geeft de gemeten temperatuur en
  luchtvochtigheid weer op het LCD-scherm.

- readvolume();: Deze functie leest het volume water in de watertank met
  behulp van een ultrasone sensor.

- displayvolume();: Deze functie geeft het gemeten volume water weer op
  het LCD-scherm.

<img src="./media/image18.png" style="width:3.22962in;height:6.87596in"
alt="Afbeelding met tekst, schermopname, Lettertype, menu Automatisch gegenereerde beschrijving" />

## Eigen Functies

### Reconnect functie

Deze code bevat de functie reconnect(), die verantwoordelijk is voor het
opnieuw verbinden met de MQTT-broker als de verbinding verloren gaat.
Laten we de verschillende stappen in deze functie bekijken:

- while (!client.connected()) { ... }: Deze regel start een while-lus
  die blijft draaien zolang de MQTT-client niet verbonden is met de
  broker. Hierdoor wordt geprobeerd om opnieuw verbinding te maken
  totdat de verbinding tot stand is gebracht.

- Serial.println("Attempting MQTT connection...");: Dit geeft een
  bericht weer op de seriële monitor om aan te geven dat er een poging
  wordt gedaan om verbinding te maken met de MQTT-broker.

- if (client.connect(clientID, mqttUser, mqttPassword)) { ... }: Deze
  regel probeert verbinding te maken met de MQTT-broker met behulp van
  de opgegeven client-ID, gebruikersnaam en wachtwoord. Als de
  verbinding succesvol is, wordt de code binnen de if-blok uitgevoerd.

- client.subscribe("serre/rfid");: Deze regel abonneert de MQTT-client
  op het topic "serre/rfid", wat betekent dat de client berichten zal
  ontvangen die naar dit topic worden gepubliceerd.

- Serial.print("Failed to connect to MQTT, rc=");: Als de verbinding met
  de MQTT-broker niet tot stand kan worden gebracht, wordt dit bericht
  weergegeven op de seriële monitor, samen met de teruggegeven foutcode.

- delay(5000);: Nadat een mislukte poging is gedaan om verbinding te
  maken, wordt er een vertraging van 5 seconden ingesteld voordat er
  opnieuw wordt geprobeerd verbinding te maken. Dit helpt om te
  voorkomen dat de microcontroller de MQTT-broker te vaak probeert te
  benaderen als de verbinding niet succesvol is.

<img src="./media/image19.png" style="width:5.6362in;height:6.58425in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

### SetupLCD

Deze code definieert de functie setupLCD(), die verantwoordelijk is voor
het initialiseren van het LCD-scherm. Laten we de verschillende stappen
in deze functie bekijken:

- lcd.init();: Deze regel roept de init()-functie aan op het LCD-object,
  waardoor het LCD-scherm wordt geïnitialiseerd voor gebruik. Dit omvat
  het instellen van de grootte van het scherm en andere interne
  instellingen.

- lcd.backlight();: Deze regel roept de backlight()-functie aan op het
  LCD-object, waardoor de achtergrondverlichting van het LCD-scherm
  wordt ingeschakeld. Dit zorgt ervoor dat de inhoud van het scherm goed
  zichtbaar is.

- lcd.setCursor(0, 0);: Deze regel stelt de cursorpositie in op het
  LCD-scherm. In dit geval wordt de cursor ingesteld op de eerste rij
  (rij 0) en de eerste kolom (kolom 0) van het scherm. Dit betekent dat
  de tekst die wordt geschreven vanaf deze positie op het scherm zal
  beginnen.

<img src="./media/image20.png" style="width:4.34436in;height:1.57314in"
alt="Afbeelding met tekst, Lettertype, schermopname Automatisch gegenereerde beschrijving" />

### setupDHT()

Deze functie initialiseert de DHT-sensor voor gebruik.

- dht.begin();: Deze regel roept de begin()-functie aan op het
  DHT-object, waardoor de DHT-sensor wordt geïnitialiseerd voor
  communicatie met de microcontroller. Dit omvat het instellen van de
  communicatiepin voor de sensor en het voorbereiden van de sensor om
  gegevens te kunnen lezen.

  <img src="./media/image21.png" style="width:1.77108in;height:0.87512in"
  alt="Afbeelding met Lettertype, tekst, schermopname, Graphics Automatisch gegenereerde beschrijving" />

### setupRFID

Deze functie initialiseert de RFID-lezer voor gebruik.

- SPI.begin();: Deze regel initialiseert de SPI-bus, die wordt gebruikt
  voor communicatie met de RFID-lezer. Dit is een vereiste stap om de
  RFID-lezer te kunnen gebruiken.

- rfid.PCD_Init();: Deze regel initialiseert de RFID-lezer met de
  geconfigureerde pinnen en instellingen. Dit omvat het opzetten van de
  lezer voor communicatie met RFID-tags en het configureren van de
  benodigde instellingen.

- for (byte i = 0; i \< 6; i++) { key.keyByte\[i\] = 0xFF; }: Deze lus
  initialiseert de RFID-sleutel met standaardwaarden. Dit is nodig omdat
  sommige RFID-functies een sleutel vereisen voor authenticatie.

- Serial.println(F("This code scan the MIFARE Classsic NUID."));: Dit is
  een diagnostisch bericht dat wordt afgedrukt op de seriële monitor.
  Het geeft informatie over de functionaliteit van de code met
  betrekking tot het scannen van RFID-tags.

- Serial.print(F("Using the following key:"));: Dit is een diagnostisch
  bericht dat wordt afgedrukt op de seriële monitor. Het informeert de
  gebruiker over het gebruik van de RFID-sleutel in de code.

<img src="./media/image22.png" style="width:5.94875in;height:2.84415in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

### setupdallassensor

Deze functie initialiseert de Dallas-temperatuursensor voor gebruik.

- sensors.begin();: Deze regel roept de begin()-functie aan op het
  sensors-object, waardoor de communicatie met de
  Dallas-temperatuursensor wordt gestart. Dit omvat het instellen van de
  communicatiepin voor de sensor en het voorbereiden van de sensor om
  temperatuurgegevens te kunnen lezen.

<img src="./media/image23.png" style="width:2.65662in;height:0.90638in"
alt="Afbeelding met tekst, Lettertype, schermopname, Graphics Automatisch gegenereerde beschrijving" />

### SetupALLPIN

Dit deel van de code bevat de functie setupALLPIN(), die
verantwoordelijk is voor het initialiseren van alle pinnen die worden
gebruikt in het project. Laten we elk van deze initialisaties bekijken:

- pinMode(LIGHTPIN, INPUT);: Deze regel initialiseert de pin waarop de
  lichtsensor is aangesloten als een invoerpin. Dit betekent dat de
  microcontroller gegevens van deze pin kan lezen, wat belangrijk is om
  de lichtintensiteit te meten.

- pinMode(BODEMSENSORPIN, INPUT);: Deze regel initialiseert de pin
  waarop de bodemvochtigheidssensor is aangesloten als een invoerpin.
  Dit betekent dat de microcontroller gegevens van deze pin kan lezen,
  wat belangrijk is om de bodemvochtigheid te meten.

- pinMode(LEDSTRIPPIN, OUTPUT);: Deze regel initialiseert de pin waarop
  de LED-strip is aangesloten als een uitvoerpin. Dit betekent dat de
  microcontroller signalen naar deze pin kan sturen om de LED-strip aan
  of uit te zetten.

- pinMode(trigPIN, OUTPUT);: Deze regel initialiseert de pin waarop de
  trig-pen van de ultrasone sensor is aangesloten als een uitvoerpin.
  Dit betekent dat de microcontroller signalen naar deze pin kan sturen
  om ultrasone pulsen te genereren voor afstandsmetingen.

- pinMode(echoPIN, INPUT);: Deze regel initialiseert de pin waarop de
  echo-pen van de ultrasone sensor is aangesloten als een invoerpin. Dit
  betekent dat de microcontroller gegevens van deze pin kan lezen, wat
  belangrijk is om de afstand tussen de sensor en een object te meten.

- pinMode(DHTPIN, INPUT);: Deze regel initialiseert de pin waarop de
  DHT-sensor is aangesloten als een invoerpin. Dit betekent dat de
  microcontroller gegevens van deze pin kan lezen, wat belangrijk is om
  de temperatuur en luchtvochtigheid te meten.

- pinMode(POMPPIN, OUTPUT);: Deze regel initialiseert de pin waarop de
  pomp is aangesloten als een uitvoerpin. Dit betekent dat de
  microcontroller signalen naar deze pin kan sturen om de pomp aan of
  uit te zetten.

<img src="./media/image24.png" style="width:5.74038in;height:2.78164in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

### Setup wifi

Dit deel van de code bevat de functie setupwifi(), die verantwoordelijk
is voor het opzetten van de WiFi-verbinding en de MQTT-clientverbinding.
Laten we de functie stap voor stap bekijken:

- while (WiFi.status() != WL_CONNECTED) { ... }: Deze lus wacht tot de
  ESP32 is verbonden met het WiFi-netwerk. De status van de
  WiFi-verbinding wordt gecontroleerd met de functie WiFi.status(), die
  WL_CONNECTED retourneert wanneer de verbinding is gemaakt.

- delay(500);: Deze regel zorgt ervoor dat er een korte pauze is van 500
  milliseconden tussen elke poging om verbinding te maken met het
  WiFi-netwerk.

- Serial.println("Connecting to WiFi..");: Dit bericht wordt afgedrukt
  op de seriële monitor om aan te geven dat de ESP32 bezig is met het
  maken van een WiFi-verbinding.

- Serial.println("Connected to the WiFi network");: Nadat de verbinding
  tot stand is gebracht, wordt dit bericht afgedrukt om aan te geven dat
  de ESP32 succesvol is verbonden met het WiFi-netwerk.

- client.setServer(mqttServer, mqttPort);: Hier wordt de MQTT-server
  ingesteld voor de MQTT-client. Dit stelt de client in staat om
  berichten naar de MQTT-server te publiceren en van de server te
  ontvangen.

- while (!client.connected()) { ... }: Deze lus probeert verbinding te
  maken met de MQTT-server totdat de verbinding is gemaakt.

- if (client.connect(clientID, mqttUser, mqttPassword)) { ... }: In deze
  if-voorwaarde wordt gecontroleerd of de MQTT-client met succes
  verbinding heeft gemaakt met de MQTT-server. Als de verbinding
  succesvol is, wordt het bericht "Connected to MQTT" afgedrukt.

- else { ... }: Als de verbinding niet succesvol is, wordt het bericht
  "Failed to connect to MQTT" afgedrukt, samen met de foutcode die wordt
  geretourneerd door client.state(). Vervolgens wordt er een vertraging
  van 5 seconden ingelast voordat er opnieuw verbinding wordt
  geprobeerd.

  <img src="./media/image25.png" style="width:5.53202in;height:5.13613in"
  alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

### LoopRFID

Deze functie controleert continu op RFID-tags met behulp van de MFRC522
RFID-lezer. Laten we het stap voor stap bekijken:

- Kaartdetectie:

De eerste stap binnen de loopRFID() functie is het controleren of er een
nieuwe RFID-kaart aanwezig is op de lezer. Dit wordt gedaan met de
functie rfid.PICC_IsNewCardPresent(). Als er geen nieuwe kaart wordt
gedetecteerd, wordt de rest van de functie overgeslagen.

- Lezen van de kaartgegevens:

Als er een nieuwe kaart wordt gedetecteerd, wordt geprobeerd de unieke
ID (NUID) van de kaart te lezen met behulp van
rfid.PICC_ReadCardSerial(). Als de NUID niet correct wordt gelezen,
wordt de rest van de functie overgeslagen.

- Type van de kaart controleren:

Nadat de NUID met succes is gelezen, wordt het type van de gedetecteerde
RFID-kaart bepaald met behulp van rfid.PICC_GetType(rfid.uid.sak). Hier
wordt gecontroleerd of de gedetecteerde kaart een MIFARE Classic-kaart
is. Als dat niet het geval is, wordt een bericht afgedrukt op de seriële
monitor en wordt de rest van de functie overgeslagen.

- Nieuwe kaart detecteren:

Als de gedetecteerde kaart van het type MIFARE Classic is en deze een
nieuwe kaart is (d.w.z. de NUID is anders dan de vorige gedetecteerde
kaart), wordt de NUID opgeslagen in een array genaamd nuidPICC en worden
de NUID-gegevens afgedrukt op de seriële monitor.

- Communicatie met de kaart beëindigen:

Na het verwerken van de kaartgegevens wordt de communicatie met de kaart
beëindigd om de lezer gereed te maken voor de volgende leesbewerking.
Dit wordt gedaan met de functies rfid.PICC_HaltA() en
rfid.PCD_StopCrypto1().

<img src="./media/image26.png" style="width:4.56314in;height:6.67802in"
alt="Afbeelding met tekst, schermopname, software, Besturingssysteem Automatisch gegenereerde beschrijving" />

### Readultrasensor

Laten we de functie readultrasensor() line-by-line bespreken:

- digitalWrite(trigPIN, LOW);: Deze regel zet de trigPIN (pin 15) laag,
  wat waarschijnlijk de triggerpin is van een ultrasone afstandssensor.
  Door deze pin laag te zetten, wordt de sensor voorbereid op het
  ontvangen van een nieuw trigger-signaal.

- delayMicroseconds(2);: Een korte vertraging van 2 microseconden wordt
  toegepast. Dit wordt gedaan om ervoor te zorgen dat de pin goed is
  ingesteld voordat het trigger-signaal wordt verzonden.

- digitalWrite(trigPIN, HIGH);: Vervolgens wordt de trigPIN hoog
  gemaakt, waardoor de ultrasone sensor wordt getriggerd om een
  ultrasoon geluidssignaal uit te zenden

- delayMicroseconds(10);: Er wordt een korte vertraging van 10
  microseconden toegepast na het hoog maken van de trigPIN. Dit voldoet
  aan de vereisten van de datasheet van de ultrasone sensor voor het
  genereren van een triggerpuls.

- digitalWrite(trigPIN, LOW);: Na het verzenden van het trigger-signaal
  wordt de trigPIN weer laag gemaakt, waardoor de triggerfrequentie
  eindigt.

- duration = pulseIn(echoPIN, HIGH);: Deze regel gebruikt de functie
  pulseIn() om de duur te meten van het signaal dat wordt ontvangen op
  de echoPIN (pin 4), dat afkomstig is van de ultrasone sensor nadat het
  signaal wordt gereflecteerd door een object.

- distanceCm = duration \* SOUND_SPEED / 2;: Met behulp van de gemeten
  duur wordt de afstand berekend in centimeters. De afstand wordt
  berekend door de tijd te vermenigvuldigen met de geluidssnelheid en te
  delen door 2, aangezien het geluid heen en terug reist.

- Serial.print("Distance (cm): "); en Serial.println(distanceCm);: Ten
  slotte worden de gemeten afstandswaarden afgedrukt op de seriële
  monitor voor weergavedoeleinden.

- delay(1000);: Een korte vertraging van 1 seconde wordt toegepast om
  ervoor te zorgen dat er voldoende tijd is tussen opeenvolgende
  metingen.

<img src="./media/image27.png" style="width:6.28213in;height:5.14655in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

### light_on

- void light_on() {: Dit definieert de functie light_on(), die geen
  parameters accepteert en geen terugkeerwaarde heeft.

- digitalWrite(LEDSTRIPPIN, HIGH);: Deze regel schakelt de LED-strip aan
  door de pin LEDSTRIPPIN op een hoge (HIGH) logische waarde te zetten,
  waardoor er stroom door de LED-strip gaat en deze gaat branden.

  <img src="./media/image28.png" style="width:3.00042in;height:0.82303in"
  alt="Afbeelding met tekst, Lettertype, schermopname, Graphics Automatisch gegenereerde beschrijving" />

### light_off

- void light_off() {: Dit definieert de functie light_off(), die geen
  parameters accepteert en geen terugkeerwaarde heeft.

- digitalWrite(LEDSTRIPPIN, LOW);: Deze regel schakelt de LED-strip uit
  door de pin LEDSTRIPPIN op een lage (LOW) logische waarde te zetten,
  waardoor de stroomtoevoer naar de LED-strip wordt afgesneden en deze
  uitgaat.

<img src="./media/image29.png" style="width:2.93791in;height:0.8647in"
alt="Afbeelding met tekst, Lettertype, schermopname, Graphics Automatisch gegenereerde beschrijving" />

### pomp_on()

- void pomp_on() {: Dit definieert de functie pomp_on(), die geen
  parameters accepteert en geen terugkeerwaarde heeft.

- digitalWrite(POMPPIN, LOW);: Deze regel schakelt de pomp aan door de
  pin POMPPIN op een lage (LOW) logische waarde te zetten, waardoor er
  stroom naar de pomp wordt gestuurd en deze begint te werken.

- Serial.println("POMP AAN");: Deze regel drukt een bericht af op de
  seriële monitor om aan te geven dat de pomp is ingeschakeld.

<img src="./media/image30.png" style="width:2.60453in;height:1.02098in"
alt="Afbeelding met tekst, Lettertype, schermopname, Graphics Automatisch gegenereerde beschrijving" />

### pomp_off()

- void pomp_off() {: Dit definieert de functie pomp_off(), die geen
  parameters accepteert en geen terugkeerwaarde heeft.

- digitalWrite(POMPPIN, HIGH);: Deze regel schakelt de pomp uit door de
  pin POMPPIN op een hoge (HIGH) logische waarde te zetten, waardoor de
  stroomtoevoer naar de pomp wordt afgesneden en deze stopt met werken.

- Serial.println("POMP uit");: Deze regel drukt een bericht af op de
  seriële monitor om aan te geven dat de pomp is uitgeschakeld.

<img src="./media/image31.png" style="width:2.60453in;height:1.2085in"
alt="Afbeelding met tekst, Lettertype, schermopname, Graphics Automatisch gegenereerde beschrijving" />

### ReadRFID

laten we dit deel van de code uitsplitsen en uitleggen:

De functie readRFID() controleert of er nieuwe RFID-kaarten zijn
gedetecteerd. Als er een nieuwe kaart wordt gedetecteerd en de kaart met
succes is gelezen, wordt de UID van de kaart afgedrukt en vergeleken met
de gedefinieerde tag-UID's. Afhankelijk van welke tag wordt
gedetecteerd, worden de sensorgegevens dienovereenkomstig bijgewerkt.
Hier is een gedetailleerde uitleg van elke regel:

- if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()):
  Controleert of er een nieuwe kaart aanwezig is en of deze correct is
  gelezen.

- Serial.print("Card UID: "): Drukt "Card UID: " af op de seriële
  monitor.

- for (byte i = 0; i \< rfid.uid.size; i++) { ... }: Doorloopt de
  UID-bytes van de gedetecteerde kaart en drukt deze af op de seriële
  monitor.

- if (compareTag(rfid.uid.uidByte, tag1)) { ... } else if (...) { ... }
  else if (...) { ... }: Vergelijkt de UID van de gedetecteerde kaart
  met de gedefinieerde tag-UID's en werkt de sensorgegevens
  dienovereenkomstig bij als er een overeenkomst is.

- delay(1000): Pauzeert de uitvoering van de code gedurende een seconde
  om te voorkomen dat dezelfde kaart meerdere keren wordt gedetecteerd.

<img src="./media/image32.png" style="width:4.44854in;height:5.99042in"
alt="Afbeelding met tekst, schermopname, software Automatisch gegenereerde beschrijving" />

### DisplayRFID

laten we het displayRFID()-deel van de code uitsplitsen en uitleggen:

Hier is een gedetailleerde uitleg van elke regel:

- lcd.clear(): Wist het LCD-scherm om nieuwe informatie weer te geven.

- lcd.setCursor(0, 0): Stelt de cursor in op de eerste regel en eerste
  positie van het LCD-scherm.

- lcd.print("RFID tag: "): Drukt de tekst "RFID tag: " af op het
  LCD-scherm.

- lcd.print(currentRFID): Drukt de waarde van currentRFID, wat de
  huidige RFID-tag is, af op het LCD-scherm.

- lcd.setCursor(0, 1): Stelt de cursor in op de tweede regel en eerste
  positie van het LCD-scherm.

- lcd.print("Plant: "): Drukt de tekst "Plant: " af op het LCD-scherm.

- switch (currentRFID) { ... }: Controleert de waarde van currentRFID en
  voert de overeenkomstige actie uit voor elke RFID-tag.

- client.publish("serre/rfid", "1"): Publiceert de RFID-tag naar het
  MQTT-onderwerp "serre/rfid".

<img src="./media/image33.png" style="width:6.29861in;height:5.47986in"
alt="Afbeelding met tekst, schermopname Automatisch gegenereerde beschrijving" />

<img src="./media/image34.png" style="width:6.29861in;height:2.52639in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

### readbodemvochtigheid

Laten we de functie readbodemvochtigheid() regel voor regel bekijken:

- currentbodemvochtigheid = analogRead(BODEMSENSORPIN): Hier wordt de
  huidige bodemvochtigheidssensorwaarde gelezen met behulp van de
  functie analogRead(). De gelezen waarde wordt opgeslagen in de
  variabele currentbodemvochtigheid.

- if (currentbodemvochtigheid \< bodemvochtigheid) { ... }: Hier wordt
  gecontroleerd of de huidige bodemvochtigheid lager is dan de
  ingestelde drempelwaarde bodemvochtigheid.

- pomp_on();: Als de bodemvochtigheid lager is dan de ingestelde
  drempelwaarde, wordt de functie pomp_on() aangeroepen om de pomp in te
  schakelen.

- delay(3000);: Er wordt een vertraging van 3 seconden ingevoegd om de
  pomp een bepaalde tijd actief te laten zijn.

- pomp_off();: Na de vertraging wordt de functie pomp_off() aangeroepen
  om de pomp uit te schakelen.

<img src="./media/image35.png" style="width:6.29861in;height:2.95625in"
alt="Afbeelding met tekst, schermopname, software, Lettertype Automatisch gegenereerde beschrijving" />

### displaybodemvochtigheid

Laten we de functie displaybodemvochtigheid() regel voor regel bekijken:

- lcd.clear();: Hiermee wordt het LCD-scherm gewist, zodat nieuwe
  gegevens op een schone lei kunnen worden weergegeven.

- lcd.setCursor(0, 0);: Dit stelt de cursorpositie in op de eerste regel
  (regel 0) en de eerste kolom (kolom 0) van het LCD-scherm.

- lcd.print("Bodemvochtigheid: ");: Hier wordt de tekst
  "Bodemvochtigheid: " afgedrukt op de eerste regel van het LCD-scherm.

- lcd.setCursor(0, 1);: Dit stelt de cursorpositie in op de tweede regel
  (regel 1) en de eerste kolom (kolom 0) van het LCD-scherm.

- lcd.print(currentbodemvochtigheid);: Dit drukt de huidige
  bodemvochtigheidswaarde af op de tweede regel van het LCD-scherm.

- payload = String(currentbodemvochtigheid);: Hier wordt de
  bodemvochtigheidswaarde omgezet naar een tekenreeks en opgeslagen in
  de variabele payload.

- client.publish("serre/bodemvochtigheid", payload.c_str());: Hier wordt
  de bodemvochtigheidswaarde gepubliceerd naar het MQTT-onderwerp
  "serre/bodemvochtigheid" zodat deze beschikbaar is voor andere
  apparaten of systemen die zijn geabonneerd op dat onderwerp.

<img src="./media/image36.png" style="width:6.29861in;height:3.58958in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

### Read belichting

Laten we eens kijken naar de functie readbelichting() en deze regel voor
regel bespreken:

- currentlight = analogRead(LIGHTPIN);: Hier wordt de huidige
  lichtwaarde gelezen van de analoge pin waarop de lichtsensor is
  aangesloten.

- if (currentlight \> 2000) { ... } else { ... }: Dit is een
  voorwaardelijke instructie die controleert of de huidige lichtwaarde
  hoger is dan 2000.

- light_on();: Als de huidige lichtwaarde hoger is dan 2000, worden de
  lichten ingeschakeld door de functie light_on() aan te roepen.

- ledstate = HIGH;: Hier wordt de variabele ledstate ingesteld op HIGH
  omdat de lichten aan zijn.

- light_off();: Als de huidige lichtwaarde lager is dan of gelijk is aan
  2000, worden de lichten uitgeschakeld door de functie light_off() aan
  te roepen.

- ledstate = LOW;: Hier wordt de variabele ledstate ingesteld op LOW
  omdat de lichten uit zijn.

<img src="./media/image37.png" style="width:6.29861in;height:3.68889in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

### displaybelichting

Hier is een lijn-voor-lijn uitleg van de functie displaybelichting():

- lcd.clear();: Hiermee wordt het LCD-scherm gewist, zodat er nieuwe
  informatie op kan worden weergegeven.

- lcd.setCursor(0, 0);: Dit stelt de cursorpositie in op de eerste regel
  en eerste kolom van het LCD-scherm.

- lcd.print("Light: "); lcd.print(currentlight);: Dit print de tekst
  "Light: " gevolgd door de huidige lichtwaarde op het LCD-scherm.

- lcd.setCursor(0, 1);: Dit stelt de cursorpositie in op de tweede regel
  en eerste kolom van het LCD-scherm.

- lcd.print("LED: ");: Dit print de tekst "LED: " op het LCD-scherm.

- payload = String(currentlight);: Hier wordt een string gemaakt van de
  huidige lichtwaarde.

- client.publish("serre/ldr", payload.c_str());: Dit publiceert de
  lichtwaarde naar het MQTT-onderwerp "serre/ldr".

- if (ledstate == 1) { lcd.print("ON"); } else { lcd.print("OFF"); }:
  Hier wordt gecontroleerd of de led aan of uit is, en wordt de
  bijbehorende tekst ("ON" of "OFF") op het LCD-scherm afgedrukt.

<img src="./media/image38.png" style="width:5.59453in;height:6.25087in"
alt="Afbeelding met tekst, schermopname Automatisch gegenereerde beschrijving" />

### ReadDHT

Hier is de uitleg voor de functie readDHT():

- currenthumidity = dht.readHumidity();: Dit leest de huidige
  luchtvochtigheid van de DHT-sensor en slaat de waarde op in de
  variabele currenthumidity.

- currenttemperature = dht.readTemperature();: Dit leest de huidige
  temperatuur van de DHT-sensor en slaat de waarde op in de variabele
  currenttemperature.

<img src="./media/image39.png" style="width:5.85498in;height:1.42728in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

### DisplayDHT

Hier is de uitleg voor de functie displayDHT():

- lcd.clear();: Hiermee wordt het LCD-scherm gewist.

- lcd.setCursor(0, 0);: Dit plaatst de cursor van de LCD op positie (0,
  0), wat de eerste regel en het eerste karakter betekent.

- lcd.print("Temp: ");: Dit print de tekst "Temp: " op het LCD-scherm.

- lcd.print(currenttemperature);: Dit print de huidige temperatuur
  (currenttemperature) op het LCD-scherm.

- lcd.print((char)223);: Dit voegt het gradensymbool (°) toe aan de
  temperatuurweergave op het LCD-scherm.

- lcd.print("C");: Dit geeft de eenheid Celsius aan op het LCD-scherm.

- lcd.setCursor(0, 1);: Dit plaatst de cursor op de tweede regel van het
  LCD-scherm.

- lcd.print("Humid: ");: Dit print de tekst "Humid: " op het LCD-scherm.

- lcd.print(currenthumidity);: Dit print de huidige luchtvochtigheid
  (currenthumidity) op het LCD-scherm.

- lcd.print("%");: Dit voegt het percentage-teken (%) toe aan de
  luchtvochtigheid op het LCD-scherm.

- payload = String(currenttemperature);: Dit creëert een payload-string
  met de huidige temperatuur voor het publiceren naar MQTT.

- client.publish("serre/temperature", payload.c_str());: Dit publiceert
  de temperatuurwaarde naar het MQTT-onderwerp "serre/temperature".

- payload = String(currenthumidity);: Dit creëert een payload-string met
  de huidige luchtvochtigheid voor het publiceren naar MQTT.

- client.publish("serre/humidity", payload.c_str());: Dit publiceert de
  luchtvochtigheidswaarde naar het MQTT-onderwerp "serre/humidity".

<img src="./media/image40.png" style="width:6.29861in;height:6.28819in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

### readvolume

Hier is de uitleg voor de functie readvolume():

- readultrasensor();: Deze regel roept de functie readultrasensor() aan
  om de ultrasone sensor uit te lezen en de variabele distanceCm in te
  stellen op de gemeten afstand in centimeters.

- watervolume = ((totalCM - distanceCm) / totalCM) \* 100;: Dit is een
  wiskundige berekening om het percentage van het watervolume te bepalen
  op basis van de gemeten afstand. totalCM is het totale volume water
  dat de tank kan bevatten. De formule berekent het verschil tussen het
  totale volume en de gemeten afstand, deelt dit door het totale volume
  en vermenigvuldigt het met 100 om het percentage te krijgen. De
  berekende waarde wordt opgeslagen in de variabele watervolume.

<img src="./media/image41.png" style="width:4.64648in;height:2.21906in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

### Displayvolume

Hier is de uitleg voor de functie displayvolume():

- lcd.clear();: Hiermee wordt het LCD-scherm gewist voordat nieuwe
  informatie wordt weergegeven.

- lcd.setCursor(0, 0);: Dit stelt de cursor in op de eerste regel en
  eerste positie van het LCD-scherm.

- lcd.print("Volume: ");: Hier wordt de tekst "Volume: " afgedrukt op
  het LCD-scherm.

- lcd.print(watervolume);: Dit drukt de waarde van de variabele
  watervolume af op het LCD-scherm.

- lcd.print("%");: Hier wordt het percentage symbool afgedrukt op het
  LCD-scherm naast de waarde van watervolume.

- payload = String(watervolume);: De waarde van watervolume wordt
  omgezet naar een string en opgeslagen in de variabele payload.

- client.publish("serre/volume", payload.c_str());: Dit publiceert de
  waarde van watervolume naar het MQTT-onderwerp "serre/volume". De
  waarde wordt gepubliceerd als een C-string met behulp van de methode
  c_str().

<img src="./media/image42.png" style="width:4.12558in;height:4.56314in"
alt="Afbeelding met tekst, schermopname, Lettertype Automatisch gegenereerde beschrijving" />

## Volledige code

\#include \<Wire.h\>

\#include \<LiquidCrystal_I2C.h\>

\#include \<DHT.h\>

\#include \<SPI.h\>      //RFID TAG

\#include \<MFRC522.h\>  //RFID TAG

\#include \<OneWire.h\>

\#include \<DallasTemperature.h\>

\#include \<WiFi.h\>

\#include \<PubSubClient.h\>

\#define DHTPIN 33          //

\#define DHTTYPE DHT11      // DHT 11

\#define LEDSTRIPPIN 14     //good

\#define BODEMSENSORPIN 34  // good

\#define LIGHTPIN 32        //good

\#define trigPIN 15         //good

\#define echoPIN 4          //35         //good

\#define POMPPIN 27         //good

\#define SS_PIN 5           //RFID tag                       //good

\#define RST_PIN 17         //RFID tag                     //good

\#define ONE_WIRE_BUS 2

\#define SOUND_SPEED 0.034

const char\* ssid = "embed";

const char\* password = "weareincontrol";

const char\* mqttServer = "192.168.1.242";

const int mqttPort = 1883;

const char\* mqttUser = "nathan";

const char\* mqttPassword = "Nat101han";

const char\* clientID = "esp_serre_nathan";  // MQTT client ID

String payload{};

WiFiClient espClient;

PubSubClient client(espClient);

OneWire oneWire(ONE_WIRE_BUS);

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Address 0x27, 16 columns, 2 rows

DHT dht(DHTPIN, DHTTYPE);

MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

byte nuidPICC\[4\];

DallasTemperature sensors(&oneWire);

byte tag3\[\] = { 0x73, 0x93, 0xE2, 0x0D };

byte tag2\[\] = { 0xB3, 0xAA, 0xBB, 0x19 };

byte tag1\[\] = { 0x73, 0x53, 0xC8, 0x19 };

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

  lcd.init();       // Initialize the LCD

  lcd.backlight();  // Turn on the backlight

  lcd.setCursor(0, 0);

}

void setupDHT() {

  dht.begin();

}

void setupRFID() {

  SPI.begin();      // Init SPI bus

  rfid.PCD_Init();  // Init MFRC522

  for (byte i = 0; i \< 6; i++) {

    key.keyByte\[i\] = 0xFF;

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

  pinMode(trigPIN, OUTPUT);  // Sets the trigPIN as an Output

  pinMode(echoPIN, INPUT);   // Sets the echoPIN as an Input

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

  // Reset the loop if no new card present on the sensor/reader. This
saves the entire process when idle.

  if (!rfid.PICC_IsNewCardPresent())

    return;

  // Verify if the NUID has been readed

  if (!rfid.PICC_ReadCardSerial())

    return;

  Serial.print(F("PICC type: "));

  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

  Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type

  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI && piccType !=
MFRC522::PICC_TYPE_MIFARE_1K && piccType !=
MFRC522::PICC_TYPE_MIFARE_4K) {

    Serial.println(F("Your tag is not of type MIFARE Classic."));

    return;

  }

  if (rfid.uid.uidByte\[0\] != nuidPICC\[0\] \|\| rfid.uid.uidByte\[1\]
!= nuidPICC\[1\] \|\| rfid.uid.uidByte\[2\] != nuidPICC\[2\] \|\|
rfid.uid.uidByte\[3\] != nuidPICC\[3\]) {

    Serial.println(F("A new card has been detected."));

    // Store NUID into nuidPICC array

    for (byte i = 0; i \< 4; i++) {

      nuidPICC\[i\] = rfid.uid.uidByte\[i\];

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

  sensors.requestTemperatures();  // Send the command to get
temperatures

  Serial.println("DONE");

  // After we got the temperatures, we can print them here.

  // We use the function ByIndex, and as an example get the temperature
from the first sensor only.

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

  // Reads the echoPIN, returns the sound wave travel time in
microseconds

  duration = pulseIn(echoPIN, HIGH);

  // Calculate the distance

  distanceCm = duration \* SOUND_SPEED / 2;

  // Prints the distance in the Serial Monitor

  Serial.print("Distance (cm): ");

  Serial.println(distanceCm);

  delay(1000);

}

void printHex(byte\* buffer, byte bufferSize) {

  for (byte i = 0; i \< bufferSize; i++) {

    Serial.print(buffer\[i\] \< 0x10 ? " 0" : " ");

    Serial.print(buffer\[i\], HEX);

  }

}

void printDec(byte\* buffer, byte bufferSize) {

  for (byte i = 0; i \< bufferSize; i++) {

    Serial.print(' ');

    Serial.print(buffer\[i\], DEC);

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

    for (byte i = 0; i \< rfid.uid.size; i++) {

      Serial.print(rfid.uid.uidByte\[i\] \< 0x10 ? "0" : "");

      Serial.print(rfid.uid.uidByte\[i\], HEX);

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

bool compareTag(byte tag1\[\], byte tag2\[\]) {

  for (int i = 0; i \< 4; i++) {

    if (tag1\[i\] != tag2\[i\]) {

      return false;

    }

  }

  return true;

}

void readbodemvochtigheid() {

  currentbodemvochtigheid = analogRead(BODEMSENSORPIN);

  if (currentbodemvochtigheid \< bodemvochtigheid) {

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

  if (currentlight \> 2000) {

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

  watervolume = ((totalCM - distanceCm) / totalCM) \* 100;

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

<table>
<colgroup>
<col style="width: 100%" />
</colgroup>
<thead>
<tr class="header">
<th><p>contact</p>
<p>Nathan Van der Sande | Student</p>
<p>xxx.xxx@thomasmore.be</p>
<p>Tel. + 32 xx xx xx xx</p>
<p>Volg ons</p>
<p>www.thomasmore.be</p>
<p>fb.com/ThomasMoreBE</p>
<p>#WeAreMore</p></th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td></td>
</tr>
</tbody>
</table>
