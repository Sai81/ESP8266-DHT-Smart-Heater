#ifndef _HT_CONTROL_H_
#define _HT_CONTROL_H_



void setupHtControl();
void handleHtControl();

float get_temp();
float get_humidity();
void display_temp();
void display_humidity();

void set_temp_limit(float temp);

void update_heater();

bool is_heater_on();


void setLoopTimeInMs(int ms);


#endif
