#include <Wire.h>
#include <MCP23017.h>
#define MCP_ADDRESS 0x27 // (A2/A1/A0 = LOW)
/* A hardware reset is performed during init(). If you want to save a pin you can define a dummy 
 * reset pin >= 99 and connect the reset pin to HIGH. This will trigger a software reset instead 
 * of a hardware reset. 
 */
#define RESET_PIN 99  

/* There are several ways to create your MCP23017 object:
 * MCP23017 myMCP = MCP23017(MCP_ADDRESS) -> uses Wire / no reset pin 
 * MCP23017 myMCP = MCP23017(MCP_ADDRESS, RESET_PIN) -> uses Wire / RESET_PIN
 * MCP23017 myMCP = MCP23017(&Wire, MCP_ADDRESS) -> passing a TwoWire object / no reset pin
 * MCP23017 myMCP = MCP23017(&Wire, MCP_ADDRESS, RESET_PIN) -> "all together"
 */
MCP23017 myMCP = MCP23017(MCP_ADDRESS);

//int wT = 1000; // wT = waiting time
#define frontlightspin 7 //2 // Pin the relay is connected to
#define centrelightspin 6 //34 // Pin the relay is connected to
#define rearlightspin  5//33 // Pin the relay is connected to
#define bootlightspin 4//13
#define exteriorlightspin  3//12 // Pin the relay is connected to
#define fridgepin  2//32 // Pin the relay is connected to
#define tvpowerpin  1//27 // Pin the relay is connected to
#define mainrelaypin 0

void mcpsetup() {
  Serial.begin(115200);
  Wire.begin(18, 19);
  myMCP.Init();
  if(!myMCP.Init()){
    Serial.println("Not connected!");
    while(1){} 
  }
  myMCP.setPinMode(frontlightspin, A, OUTPUT);
  myMCP.setPinMode(centrelightspin, A, OUTPUT);
  myMCP.setPinMode(rearlightspin, A, OUTPUT);
  myMCP.setPinMode(exteriorlightspin, A, OUTPUT);
  myMCP.setPinMode(bootlightspin, A, OUTPUT);
  myMCP.setPinMode(tvpowerpin, A, OUTPUT);
  myMCP.setPinMode(fridgepin, A, OUTPUT);
  myMCP.setPinMode(mainrelaypin, A, OUTPUT);

  myMCP.setAllPins(A, HIGH);

  Serial.println("MCP OK...");
}



void turnonfrontlights() {
    myMCP.setPinX(frontlightspin, A, OUTPUT, LOW); // A7 switched off; // Send high signal to turn on relay
    Serial.println("front lights turned on");
}

void turnofffrontlights() {
    myMCP.setPinX(frontlightspin, A, OUTPUT, HIGH); // Send low signal to turn off relay
    Serial.println("front lights turned off");
}

void turnoncentrelights() {
    myMCP.setPinX(centrelightspin, A, OUTPUT, LOW); // Send high signal to turn on relay
    Serial.println("centre lights turned on");
}

void turnoffcentrelights() {
    myMCP.setPinX(centrelightspin, A, OUTPUT, HIGH); // Send low signal to turn off relay
    Serial.println("centre lights turned off");
}

void turnonrearlights() {
    myMCP.setPinX(rearlightspin, A, OUTPUT, LOW); // Send high signal to turn on relay
    Serial.println("rear lights turned on");
}

void turnoffrearlights() {
    myMCP.setPinX(rearlightspin, A, OUTPUT, HIGH); // Send low signal to turn off relay
    Serial.println("rear lights turned off");
}

void turnonexteriorlights() {
    myMCP.setPinX(exteriorlightspin, A, OUTPUT,  LOW); // Send high signal to turn on relay
    Serial.println("exterior lights turned on");
}

void turnoffexteriorlights() {
    myMCP.setPinX(exteriorlightspin, A, OUTPUT, HIGH); // Send low signal to turn off relay
    Serial.println("exterior lights turned off");
}

void turnonbootlights() {
    myMCP.setPinX(bootlightspin, A, OUTPUT, LOW); // Send high signal to turn on relay
    Serial.println("boot lights turned on");
}

void turnoffbootlights() {
    myMCP.setPinX(bootlightspin, A, OUTPUT, HIGH); // Send low signal to turn off relay
    Serial.println("exterior lights turned off");
}

void turnontv() {
    myMCP.setPinX(tvpowerpin, A, OUTPUT, LOW); // Send high signal to turn on relay
    Serial.println("tv turned on");
}

void turnofftv() {
    myMCP.setPinX(tvpowerpin, A, OUTPUT, HIGH); // Send low signal to turn off relay
    Serial.println("tv turned off");
}

void turnonfridge() {
    myMCP.setPinX(fridgepin, A, OUTPUT, LOW); // Send high signal to turn on relay
    Serial.println("fridge turned on");
}

void turnofffridge() {
    myMCP.setPinX(fridgepin, A, OUTPUT,  HIGH); // Send low signal to turn off relay
    Serial.println("fridge turned off");
}

void turnonmainrelay() {
    myMCP.setPinX(mainrelaypin, A, OUTPUT, LOW); // Send high signal to turn on relay
    Serial.println("main relay turned on");
}

void turnoffmainrelay() {
    myMCP.setPinX(mainrelaypin, A, OUTPUT, HIGH); // Send low signal to turn off relay
    Serial.println("main relay turned off");
}