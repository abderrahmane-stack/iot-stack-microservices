#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#define wifi_ssid "your_ssid_address"
#define wifi_password "your_password_address"
float hum = 0; 
// serveur mqtt
const char* mqtt_server = "your_ip_address"; //  broker on docker in raspberry pi
#define sensor_topic "sensor/temp" //Topic light

//les topic de souscription coté wemos sur le broker 
#define led_topic "home/led"
int led=D2;

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup() {
pinMode(D2, OUTPUT); // intitialisation du pin pour activer la LED
Serial.begin(115200);

WiFi.begin(wifi_ssid, wifi_password);

while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}

Serial.println("");
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
client.setServer(mqtt_server, 8883);
}

void reconnect() {
// Loop until we're reconnected
while (!client.connected()) {
Serial.print("Attempting MQTT connection...");
String clientId = "SensorClient";
clientId += String(random(0xffff), HEX);
if (client.connect(clientId.c_str())) {
Serial.println("connected");
} else {
Serial.print("failed, rc=");
Serial.print(client.state());
Serial.println(" try again in 5 seconds");

delay(5000);
}
}
}



void loop() {
   hum +=0.5;
    Serial.println(hum);
delay(2000);
if (!client.connected()) {
reconnect();
}
client.loop();
client.publish(sensor_topic, String(hum).c_str(), true);

}
