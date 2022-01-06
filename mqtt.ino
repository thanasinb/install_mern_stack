#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#define WIFI_STA_NAME "Thanasin_2.4G"
#define WIFI_STA_PASS "0869851715"
#define MQTT_SERVER   "192.168.1.115"
#define MQTT_PORT     1883
#define MQTT_USERNAME "user1"
#define MQTT_PASSWORD "user1"
#define MQTT_NAME     "esp8266"
WiFiClient client;
PubSubClient mqtt(client);
int num=0;

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
}

void setup() {
   Serial.begin(115200);
   pinMode(LED_BUILTIN, OUTPUT);
   WiFi.mode(WIFI_STA); 
   while (!Serial); 
   delay(250);
   Serial.println(WIFI_STA_NAME); 
   Serial.println("WIFI Connecting");
   WiFi.begin(WIFI_STA_NAME, WIFI_STA_PASS);
   while (num<20) {
    delay(500);
    Serial.print(".");
    num++;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("\n WiFi Connected. \n");
  }
  else{
    Serial.print("\n WIFI Connect fail. ");
  }
  mqtt.setServer(MQTT_SERVER, MQTT_PORT);
  mqtt.setCallback(callback);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  if (mqtt.connect(MQTT_NAME, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print("\n Publish message: ");
    if (mqtt.publish("test","Arduino Test MQTT") == true) { 
      //Send "Arduino Test MQTT" via topic = "test"
      Serial.println("Success sending");
    }else{
      Serial.println("Fail sending");
    }
  }
  delay(5000);
}
