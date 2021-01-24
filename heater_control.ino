#include "ht_control.h"

void setup(void)
{
  setupHtControl();
  set_temp_limit(30.0);
  Serial.begin(115200);
  Serial.println("Humidity and temperature\n\n");
  delay(700);

}
void loop() {
    handleHtControl();
    /*x
    // prints temperature and humidity in serial monitor after every 1 second
    display_temp();
    display_humidity();
    update_heater();
    Serial.println("");
    
    delay(1000);
    */
}
