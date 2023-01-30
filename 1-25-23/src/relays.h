#include <pins.h>
#include <stdio.h>
#include "driver/gpio.h"


void turnonfrontlights() {
    digitalWrite(frontlightspin, HIGH); // Send high signal to turn on relay
    Serial.println("front lights turned on");
}

void turnofffrontlights() {
    digitalWrite(frontlightspin, LOW); // Send low signal to turn off relay
    Serial.println("front lights turned off");
}

void turnoncentrelights() {
    digitalWrite(centrelightspin, HIGH); // Send high signal to turn on relay
    Serial.println("centre lights turned on");
}

void turnoffcentrelights() {
    digitalWrite(centrelightspin, LOW); // Send low signal to turn off relay
    Serial.println("centre lights turned off");
}

void turnonrearlights() {
    digitalWrite(rearlightspin, HIGH); // Send high signal to turn on relay
    Serial.println("rear lights turned on");
}

void turnoffrearlights() {
    digitalWrite(rearlightspin, LOW); // Send low signal to turn off relay
    Serial.println("rear lights turned off");
}

void turnonexteriorlights() {
    digitalWrite(exteriorlightspin, HIGH); // Send high signal to turn on relay
    Serial.println("exterior lights turned on");
}

void turnoffexteriorlights() {
    digitalWrite(exteriorlightspin, LOW); // Send low signal to turn off relay
    Serial.println("exterior lights turned off");
}

void turnonbootlights() {
    digitalWrite(bootlightspin, HIGH); // Send high signal to turn on relay
    Serial.println("boot lights turned on");
}

void turnoffbootlights() {
    digitalWrite(bootlightspin, LOW); // Send low signal to turn off relay
    Serial.println("exterior lights turned off");
}

void turnontv() {
    digitalWrite(tvpowerpin, HIGH); // Send high signal to turn on relay
    Serial.println("tv turned on");
}

void turnofftv() {
    digitalWrite(tvpowerpin, LOW); // Send low signal to turn off relay
    Serial.println("tv turned off");
}

void turnonfridge() {
    digitalWrite(fridgepin, HIGH); // Send high signal to turn on relay
    Serial.println("fridge turned on");
}

void turnofffridge() {
    digitalWrite(fridgepin, LOW); // Send low signal to turn off relay
    Serial.println("fridge turned off");
}