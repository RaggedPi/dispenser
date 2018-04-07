#ifndef DISPENSER_H
#define DISPENSER_H

#if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#include <Servo.h>

/* Constants */
#define HOPPER_OPEN 120
#define HOPPER_CLOSE 20
#define DISPENSE_TIME 300
#define DEFAULT_SERVO_PIN 4

class Dispenser {
    public:
        // Constructors
        Dispenser();
        Dispenser(Servo servo);
        Dispenser(int servoPin);
        // Dispense
        void dispense();
        long getLastDispenseTime();
    private:
        Servo           _dispenser;
        unsigned long   _lastDispenseTime;
};
#endif
