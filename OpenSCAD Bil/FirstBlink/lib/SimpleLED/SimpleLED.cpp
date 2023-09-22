#include "SimpleLED.h"
#include <Arduino.h>

SimpleLED::SimpleLED(int pin, bool ledOn, long onTime, long offTime)
        : _pin(pin), _ledON(ledOn), _onTime(onTime), _offTime(offTime), _nextChange(0), _state(false)
        {
        }

void SimpleLED::setup(long startTime)
{
    pinMode(_pin, OUTPUT);
    _nextChange = startTime + _offTime;
    _state = false;
    digitalWrite(_pin, !_ledON);
}

void SimpleLED::update(long now)
{
    if (now < _nextChange) return;
    _state = !_state;
    digitalWrite(_pin, _state == _ledON);
    _nextChange += (_state ? _onTime : _offTime);   
}
 