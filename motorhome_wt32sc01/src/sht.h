#include <Wire.h>
#include "SHT85.h"
#include <switchpage.h>

#define SHT85_ADDRESS 0x44

uint32_t start;
uint32_t stop;

uint16_t count = 0;
uint32_t last = 0;

SHT85 sht;

// float shttemp = sht.getTemperature();

void read_sht(lv_obj_t *tempvalue_obj)
{
    start = micros();
    sht.read(); // default = true/fast       slow = false
    stop = micros();

    if (millis() - last >= 5000)
    {
      Serial.print("Temp:  ");
      Serial.print(sht.getTemperature(), 1);
      Serial.print("Humidity:  ");
      Serial.println(sht.getHumidity(), 1);

      float temp = sht.getTemperature();
      float hum = sht.getHumidity();
      char tmpbuffer[100];
      char humbuffer[100];
      snprintf(tmpbuffer, 100, "Temp: %.1f °C", temp);
      snprintf(humbuffer, 100, "Humidity: %.1f %%", hum);
      lv_label_set_text(tempvalue_obj, tmpbuffer);
      lv_label_set_text(humvalue_obj, humbuffer);

      // if (millis() - last >= 5000)
      // {
      last = millis();
      count = 0;
    }
  }


void sht_setup()
{
  Serial.begin(115200);
  //  Serial.println(__FILE__);
  //  Serial.print("SHT_LIB_VERSION: \t");
  //  Serial.println(SHT_LIB_VERSION);

  Wire.begin(18, 19);
  sht.begin(SHT85_ADDRESS);
  Wire.setClock(100000);

  //  uint16_t stat = sht.readStatus();
  //  Serial.print(stat, HEX);
  //  Serial.println();
  Serial.println("count\t time\t temp\t hum");
}
