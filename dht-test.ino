#include "Adafruit_DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
int led = D7;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(9600); 
	pinMode(led, OUTPUT);
	Serial.println("DHTxx test!");

	dht.begin();
}

void loop() {
    
    
    float temp = dht.getTempCelcius();
    digitalWrite(led, LOW);
	delay(30s);
    
	if(!isnan(temp)){
	    Particle.publish("temp", String::format("%.1f",temp),PRIVATE);
	    digitalWrite(led, HIGH);
	    Serial.print("Temp: ");
	    Serial.println(temp);
	}
	
}

