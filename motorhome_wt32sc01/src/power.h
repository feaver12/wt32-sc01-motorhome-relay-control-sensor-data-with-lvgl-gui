#include <Wire.h>
#include <INA3221.h>
#include <sht.h>

//#define SERIAL_SPEED     115200  // serial baud rate
#define PRINT_DEC_POINTS 3       // decimal points to print

// Set I2C address to 0x41 (A0 pin -> VCC)
INA3221 ina3221(INA3221_ADDR40_GND);


uint16_t count2 = 0;
uint32_t last2 = 0;



void inasetup() {
    Serial.begin(115200);

    while (!Serial) {
        delay(1);
    }

    ina3221.begin();
    ina3221.reset();

    // Set shunt resistors to 10 mOhm for all channels
    ina3221.setShuntRes(10, 10, 10);

    // Set series filter resistors to 10 Ohm for all channels.
    // Series filter resistors introduce error to the current measurement.
    // The error can be estimated and depends on the resitor values and the bus
    // voltage.
    ina3221.setFilterRes(10, 10, 10);
}

void readina()
{
    if (millis() - last2 >= 5000)
    {

        float current[3];
        float voltage[3];

        current[0] = ina3221.getCurrent(INA3221_CH1);
        voltage[0] = ina3221.getVoltage(INA3221_CH1);

        current[1] = ina3221.getCurrent(INA3221_CH2);
        voltage[1] = ina3221.getVoltage(INA3221_CH2);

        current[2] = ina3221.getCurrent(INA3221_CH3);
        voltage[2] = ina3221.getVoltage(INA3221_CH3);

        Serial.print("Channel 1: \n Current: ");
        Serial.print(current[0], PRINT_DEC_POINTS);
        Serial.print("\n Voltage: ");
        Serial.print(voltage[0], PRINT_DEC_POINTS);
        Serial.println("V");

        Serial.print("Channel 2: \n Current: ");
        Serial.print(current[1], PRINT_DEC_POINTS);
        Serial.print("\n Voltage: ");
        Serial.print(voltage[1], PRINT_DEC_POINTS);
        Serial.println("V");

        Serial.print("Channel 3: \n Current: ");
        Serial.print(current[2], PRINT_DEC_POINTS);
        Serial.print("\n Voltage: ");
        Serial.print(voltage[2], PRINT_DEC_POINTS);
        Serial.println("V\n");

        float ch1volts = ina3221.getVoltage(INA3221_CH1);
        float ch1amps = ina3221.getCurrent(INA3221_CH1);
        char volt1buffer[100];
        char amps1buffer[100];
        snprintf(volt1buffer, 100, "CH1 Volts: %.1f v", ch1volts);
        snprintf(amps1buffer, 100, "CH1 Amps: %.1f a", ch1amps);
        lv_label_set_text(CH1volts_obj, volt1buffer);
        lv_label_set_text(CH1amps_obj, amps1buffer);

        last2 = millis();
        count2 = 0;
    }
}
