#include <Arduino.h>
#include "SimpleTrafficLight.h"

SimpleTrafficLight::SimpleTrafficLight(int redPin1, int yellowPin1, int greenPin1, int redPin2, int yellowPin2, int greenPin2, long stateTime[])
        : _redPin1(redPin1), _yellowPin1(yellowPin1), _greenPin1(greenPin1),_redPin2(redPin2), _yellowPin2(yellowPin2), _greenPin2(greenPin2), _pStateTime(stateTime), _nextChange(0), _state(0)
        {
        }

void SimpleTrafficLight::setup(long startTime)
{
    pinMode(_redPin1, OUTPUT);
    pinMode(_yellowPin1, OUTPUT);
    pinMode(_greenPin1, OUTPUT);
    pinMode(_redPin2, OUTPUT);
    pinMode(_yellowPin2, OUTPUT);
    pinMode(_greenPin2, OUTPUT);
    _nextChange = startTime + _pStateTime[_state];
    digitalWrite(_redPin1, HIGH);
    digitalWrite(_yellowPin1, LOW);
    digitalWrite(_greenPin1, LOW);
    digitalWrite(_redPin2, HIGH);
    digitalWrite(_yellowPin2, LOW);
    digitalWrite(_greenPin2, LOW);
}

void SimpleTrafficLight::update(long now)
{
    if (now < _nextChange) return;
    _state = (_state + 1) % 8;
    digitalWrite(_redPin1, _state == 0 || _state == 1 || _state == 4 || _state == 5 || _state == 6 || _state == 7);
    digitalWrite(_yellowPin1, _state == 1 || _state == 3);
    digitalWrite(_greenPin1, _state == 2);
    digitalWrite(_redPin2, _state == 0 || _state == 1 || _state == 2 || _state == 3 || _state == 4 || _state == 5);
    digitalWrite(_yellowPin2, _state == 5 || _state == 7);
    digitalWrite(_greenPin2, _state == 6);
    _nextChange += _pStateTime[_state];   
}