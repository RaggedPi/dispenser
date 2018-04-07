#include "Dispenser.h"

/**
 * Constructor
 */
Dispenser::Dispenser() {
    _dispenser = Servo();
    _dispenser.attach(DEFAULT_SERVO_PIN);
}

/**
 * Constructor
 */
Dispenser::Dispenser(Servo servo) {
    _dispenser = servo;
}

/**
 * Constructor
 */
Dispenser::Dispenser(int servoPin) {
    _dispenser = Servo();
    _dispenser.attach(servoPin);
}

/**
 * Get last dispense time
 * @return long
 */
long Dispenser::getLastDispenseTime() {
    return _lastDispenseTime;
}
/**
 * Dispense
 */
void Dispenser::dispense() {
    _dispenser.write(HOPPER_OPEN);
    delay(DISPENSE_TIME);
    _dispenser.write(HOPPER_CLOSE);
    _lastDispenseTime = millis();
}