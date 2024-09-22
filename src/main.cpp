#include "Arduino.h"
#include "config.h"


#define BAUD        115200
#define RED_PIN     16   
#define GREEN_PIN   17
#define BLUE_PIN    18

const uint8_t RGB[3] = { 224, 10, 151 };


void init_led(uint8_t pr, uint8_t pg, uint8_t pb);
void set_led(uint8_t r, uint8_t g, uint8_t b);


void setup()
{
    Serial.begin(BAUD);

    init_led(RED_PIN, GREEN_PIN, BLUE_PIN);
}


void loop()
{
    set_led(RGB[0], RGB[1], RGB[2]);
    delay(500);
}


void init_led(uint8_t pr, uint8_t pg, uint8_t pb)
{
    ledcAttachPin(pr, 0);
    ledcSetup(0, 1000, 8);

    ledcAttachPin(pg, 1);
    ledcSetup(1, 1000, 8);

    ledcAttachPin(pb, 2);
    ledcSetup(2, 1000, 8);
}


void set_led(uint8_t r, uint8_t g, uint8_t b)
{
#if COMMON
    ledcWrite(0, 255 - r);   
    ledcWrite(1, 255 - g);   
    ledcWrite(2, 255 - b);
#else 
    ledcWrite(0, r);   
    ledcWrite(1, g);   
    ledcWrite(2, b);
#endif
}
