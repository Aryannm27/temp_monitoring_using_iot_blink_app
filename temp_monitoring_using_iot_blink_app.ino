#define BLYNK_TEMPLATE_ID "TMPLcsm1Xb_T"
#define BLYNK_DEVICE_NAME "DHT"
#define BLYNK_AUTH_TOKEN "CorUad4azhtcVRdGMsuJ2RQvrAWLsdPE"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#define DHTPIN 5 
#define DHTTYPE DHT11
char auth[] = "CorUad4azhtcVRdGMsuJ2RQvrAWLsdPE";
char ssid[] = "DESKTOP123";
char pass[] = "Ldceam123";
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
float h;
float t;
void sendSensor()
{
  h = dht.readHumidity();
  t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
}


void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
  Serial.print("humidity:- ");
  Serial.print(h);
  Serial.print(" temperature:- ");
  Serial.println(t);
  
}
