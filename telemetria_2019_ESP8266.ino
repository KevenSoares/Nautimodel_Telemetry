
#include <ESP8266WiFi.h>
#include <PubSubClient.h>


// Update these with values suitable for your network.

const char* ssid = "JaraquiTelemetria";
const char* password = "jaratop2019";
const char* mqtt_server = "192.168.137.1";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
char dado[8];
uint8_t payload[3];
uint8_t payload2[4];
uint8_t payload3[3];
uint8_t payload4[4];
uint8_t payload5[3];
int value = 0;
void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
  } else {
    digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
  }

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Jaraqui-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  payload4[2] = '.';
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

//  long now = millis();
//  if (now - lastMsg > 2000) {
//    lastMsg = now;
//    ++value;
   // snprintf (msg, 50, "Conectado #%ld", value);
   // Serial.print("Publish message: ");
   // Serial.println(msg);
   // client.publish("outTopic", msg);
   Serial.flush();
    if(Serial.available())
   {
    int i = 0;
    while(Serial.available())
    {
      delay(10);
      char aux = Serial.read();
      if(i < 3 )              //temperatura
      {  
       payload[i] = aux;
      }
      else if (i>=3 && i < 7) //Rotação
      {
         payload2[i-3] = aux;
      }
      else if (i>=7 && i < 10) //Lux
      {
         payload3[i-7] = aux;
      }
      else if (i>=10 && i < 14) // Tensão da Bateria
      {
          payload4[i-10] = aux;
         
      }
      else if (i>=14) // Nível d'agua
      {
         payload5[i-14] = aux;
      }
      else 
      Serial.flush();
      i++;
    }
    client.publish("temperatura", payload,3,1);
    client.publish("rotac",payload2,4,1);
    client.publish("lux",payload3,3,1);
    client.publish("vbat",payload4,4,1);
    client.publish("nagua",payload5,1,1);
   } 
  }
