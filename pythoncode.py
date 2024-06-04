import paho.mqtt.client as mqtt
from influxdb import InfluxDBClient

# WiFi credentials
ssid = "embed"
password = "weareincontrol"

# MQTT credentials
mqttServer = "192.168.1.242"
mqttPort = 1883
mqttUser = "nathan"
mqttPassword = "Nat101han"
clientID = "rasp_nathan"

# Topics
MQTT_TOPIC_TEMPERATURE = "serre/temperature"
MQTT_TOPIC_HUMIDITY = "serre/humidity"
MQTT_TOPIC_RFID = "serre/rfid"
MQTT_TOPIC_BODEMVOCHTIGHEID = "serre/bodemvochtigheid"
MQTT_TOPIC_LDR = "serre/ldr"
MQTT_TOPIC_VOLUME = "serre/volume"

# InfluxDB Settings
INFLUXDB_HOST = "192.168.1.242"
INFLUXDB_PORT = 8086
INFLUXDB_DATABASE = "serre"

# Callback function for MQTT
def on_message(client, userdata, message):
    topic = message.topic
    payload = message.payload.decode()
    print(f"Received message on topic '{topic}': {payload}")
    if topic == MQTT_TOPIC_TEMPERATURE:
        save_to_influxdb("temperature", float(payload))
    elif topic == MQTT_TOPIC_HUMIDITY:
        save_to_influxdb("humidity", float(payload))
    elif topic == MQTT_TOPIC_RFID:
        save_to_influxdb("rfid", payload)
    elif topic == MQTT_TOPIC_BODEMVOCHTIGHEID:
        save_to_influxdb("bodemvochtigheid", float(payload))
    elif topic == MQTT_TOPIC_LDR:
        save_to_influxdb("ldr", float(payload))
    elif topic == MQTT_TOPIC_VOLUME:
        save_to_influxdb("volume", float(payload))

# Save data to InfluxDB
def save_to_influxdb(measurement, value):
    client = InfluxDBClient(host=INFLUXDB_HOST, port=INFLUXDB_PORT)
    client.switch_database(INFLUXDB_DATABASE)
    data = [
        {
            "measurement": measurement,
            "fields": {
                "value": value
            }
        }
    ]
    client.write_points(data)

# MQTT Client Setup
mqtt_client = mqtt.Client(clientID)
mqtt_client.username_pw_set(mqttUser, mqttPassword)
mqtt_client.on_message = on_message

# Connect to MQTT broker
mqtt_client.connect(mqttServer, mqttPort)
mqtt_client.subscribe([(MQTT_TOPIC_TEMPERATURE, 0),
                       (MQTT_TOPIC_HUMIDITY, 0),
                       (MQTT_TOPIC_RFID, 0),
                       (MQTT_TOPIC_BODEMVOCHTIGHEID, 0),
                       (MQTT_TOPIC_LDR, 0),
                       (MQTT_TOPIC_VOLUME, 0)])
print("Connected to MQTT broker")

# Start the MQTT loop
try:
    mqtt_client.loop_forever()
except KeyboardInterrupt:
    print("Interrupted")
    mqtt_client.disconnect()
