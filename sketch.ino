#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

#define TRIG 13
#define ECHO 27
#define BUZZER 23

unsigned long t_sensor;
unsigned long t_mqtt;
unsigned long t_atuador;

long medirDistancia() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  return duration * 0.034 / 2;
}

void setup() {
  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando WiFi...");
  }

  client.setServer(mqtt_server, 1883);
}

void loop() {

  if (!client.connected()) {
    while (!client.connected()) {
      client.connect("ESP32Client");
    }
  }

  client.loop();

  t_sensor = millis();
  long distancia = medirDistancia();

  String msg = String(distancia) + " centimetros";
  client.publish("enchente/nivel", msg.c_str());


  t_mqtt = millis();

  if (distancia < 20) {
    digitalWrite(BUZZER, HIGH);
    client.publish("enchente/alerta", "CRITICO");
    t_atuador = millis();
  } else {
    digitalWrite(BUZZER, LOW);
  }

  Serial.print("Sensor->MQTT: ");
  Serial.println(t_mqtt - t_sensor);

  if (distancia < 20) {
    Serial.print("Sensor->Buzzer: ");
    Serial.println(t_atuador - t_sensor);
  }

  delay(1000);

}