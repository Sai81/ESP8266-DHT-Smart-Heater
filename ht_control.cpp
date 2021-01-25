//#include "Arduino.h"
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11

#define dht_dpin 2
#define heater 13

static float temp_limit,tmp,hmdty;
static unsigned long  htc_last_used;
static unsigned long  DELTA_MS=10*1000;//5*60*1000;

DHT dht(dht_dpin, DHTTYPE);

void setupHtControl()
{
  dht.begin();
}

float get_temp()
{
  return(dht.readTemperature());
}

float get_humidity()
{
  return(dht.readHumidity());
}

void display_temp()
{
  tmp = get_temp();
  Serial.print("temperature = ");
  Serial.print(tmp); 
  Serial.println("C  ");
  
}

void display_humidity()
{ 
  hmdty = get_humidity();
  Serial.print("humidity = ");
  Serial.print(hmdty);
  Serial.println("%  ");
}

void set_temp_limit(float temp)
{
  temp_limit = temp;
}

void update_heater()
{
  if(tmp<=temp_limit)
  {
    digitalWrite(heater, HIGH);
    Serial.println("Heater is turned ON");
  }
  else
  {
    digitalWrite(heater, LOW);
    Serial.println("Heater is turned OFF");
  }
}

static void do_handle_htc(){
  // get temp and humidity
  
}

void handleHtControl(){
  unsigned long  now = millis();
  unsigned long delta = now - htc_last_used;
  if  (delta >= DELTA_MS ){
    Serial.printf("time:%d, delta:%d, htc_last_used:%d\n",now,DELTA_MS,htc_last_used);
    do_handle_htc();
    htc_last_used=now;
  }
}
