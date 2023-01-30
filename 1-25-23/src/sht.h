#include <Wire.h>
#include "ClosedCube_SHT31D.h"

ClosedCube_SHT31D sht3xd;


unsigned long lastRead = 0;
unsigned long interval = 10000; // read temperature every 10 seconds

void printResult(String text, SHT31D result);

void printtemp() {
    void printResult(String text, SHT31D result);
}


void read_sht() {
    unsigned long currentTime = millis();
    if (currentTime - lastRead >= interval) {
        SHT31D result = sht3xd.periodicFetchData();
        if (result.error == SHT3XD_NO_ERROR) {
            Serial.print("Periodic Mode: T=");
            Serial.print(result.t);
            Serial.print("C, RH=");
            Serial.print(result.rh);
            Serial.println("%");
        } else {
            Serial.print("Periodic Mode: [ERROR] Code #");
            Serial.println(result.error);
        }
        lastRead = currentTime;
    }
}




void sht()
{

	Wire.begin(18, 19);

	Serial.begin(115200);
	Serial.println("ClosedCube SHT3X-D Single Shot Mode Example");
	Serial.println("supports SHT30-D, SHT31-D and SHT35-D");

	sht3xd.begin(0x44); // I2C address: 0x44 or 0x45

	Serial.print("Serial #");
	Serial.println(sht3xd.readSerialNumber());
}


void printResult(String text, SHT31D result) {
	if (result.error == SHT3XD_NO_ERROR) {
		Serial.print(text);
		Serial.print(": T=");
		Serial.print(result.t);
		Serial.print("C, RH=");
		Serial.print(result.rh);
		Serial.println("%");
	} else {
		Serial.print(text);
		Serial.print(": [ERROR] Code #");
		Serial.println(result.error);
	}
}