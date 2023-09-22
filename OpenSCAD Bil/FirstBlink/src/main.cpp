#include <Arduino.h>
#include "SimpleTrafficLight.h"

SimpleTrafficLight trafficLight(D3, D1, D2, D5, D6, D7, (long[]){1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000});

void setup()
{
    trafficLight.setup(millis());
}

void loop()
{
    trafficLight.update(millis());
}