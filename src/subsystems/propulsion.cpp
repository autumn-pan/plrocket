#include "Arduino.h"


// send out a voltage to reignite the rocket thruster
void reignite(int pin) {
    // activate the pin
    digitalWrite(pin, HIGH);
    // Wait for 1 second
    delay(700);
    // deactivate the pin
    digitalWrite(pin, LOW);
}
