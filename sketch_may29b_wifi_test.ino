/*
   Simple HTTP get webclient test
*/

#include <ESP8266WiFi.h>

const char* ssid     = "VIZIO";
const char* password = "6878692616";

const char* host = "www.adafruit.com";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(100);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

int value = 0;

WiFiClient client;
char buf[1024] = {0};

void loop() {
  // listen for incoming clients
  if (!client) {
    client = server.available();
  }
  else {
//    Serial.println("Connected to client");
    //    server.write("data: ");
    while (client.connected() ){
      int i = 0;
      while ( client.available() > 0) {
        byte b = client.read();
        buf[i++] = (char)b;
        Serial.print((char)b);
      }
      if (i > 0) {
        client.write((const char*)buf, i);
      }
    }
    //    Serial.println();
    // close the connection:
  }
}
