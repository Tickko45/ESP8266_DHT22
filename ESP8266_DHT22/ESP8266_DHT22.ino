#include "DHT.h"
DHT dht;
void setup()
{
Serial.begin(115200);
dht.setup(D4); // Pin D4
}
 
void loop()
{
delay(dht.getMinimumSamplingPeriod());
float humidity = dht.getHumidity(); // ดึงค่าความชื้น
float temperature = dht.getTemperature(); // ดึงค่าอุณหภูมิ

Serial.println(" ");
Serial.print(dht.getStatusString());

// ค่าความชื้น
Serial.print("\t");
Serial.print("Humidity : ");
Serial.print(humidity, 1);
Serial.print(" %");

// ค่าอุณหภูมิ
Serial.print("\t");
Serial.print("Temperature : ");
Serial.print(temperature, 1);
Serial.print(" °C");

// ค่าฟาเรนไฮต์
Serial.print("\t");
Serial.print("Fahrenheit : ");
Serial.print(dht.toFahrenheit(temperature), 1);
Serial.print(" °F");

delay(1000);
}
