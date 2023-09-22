#ifndef SIMPLETRAFFICLIGHT_H
#define SIMPLETRAFFICLIGHT_H

class SimpleTrafficLight
{
    public:
        SimpleTrafficLight(int redPin1, int yellowPin1, int greenPin1, int redPin2, int yellowPin2, int greenPin2, long stateTime[]);
        void setup(long startTime);
        void update(long now);
    private:
        int _redPin1;
        int _yellowPin1;
        int _greenPin1;
        int _redPin2;
        int _yellowPin2;
        int _greenPin2;
        long* _pStateTime;
        long _nextChange;
        int _state;
};

#endif