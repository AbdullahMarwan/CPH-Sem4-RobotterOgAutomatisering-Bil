#ifndef SIMPLELED_H
#define SIMPLELED_H

class SimpleLED
{
    public:
        SimpleLED(int pin, bool ledON, long onTime, long offTime);
        void setup(long startTime);
        void update(long now);
    private:
        int _pin;
        bool _ledON;
        long _onTime;
        long _offTime;
        long _nextChange;
        bool _state;
};

#endif