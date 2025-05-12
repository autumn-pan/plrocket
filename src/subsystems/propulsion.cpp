#include <Arduino.h>
#include "propulsion.h"
#include "../rocket/rocket.h"

// send out a voltage to reignite the rocket thruster
Igniter::Igniter(Rocket * rocket, int pin, unsigned int duration)
{
    this->rocket = rocket;
    this->pin = pin;
    this->state = false;
    this->duration = duration; // 1 second
}

void Igniter::reignite()
{
    this->state = true;
    this->initialTime = millis();

    digitalWrite(this->pin, HIGH);
    Serial.println("Igniter activated");
}

boolean Igniter::update()
{
    if(this->state)
    {
        if(millis() - this->initialTime > this->duration)
        {
            digitalWrite(this->pin, LOW);
            Serial.println("Igniter deactivated");
            this->state = false;
            return false;
        }
        else
        {
            return true;
        }
    }
    return false;
}


// Thrust Reverser code

ThrustReverser::ThrustReverser(Rocket * rocket, int pin1, int pin2, float initialAngle)
{
    this->rocket = rocket;
    this->pin1 = pin1;
    this->pin2 = pin2;

    this->servo1.attach(pin1);
    this->servo2.attach(pin2);

    this->angle = initialAngle;

    this->servo1.write(initialAngle);
    this->servo2.write(180 - initialAngle);
}

void ThrustReverser::initReverse()
{
    this->isActive = true;
}

float ThrustReverser::getAngle()
{
    return this->angle;
}

void ThrustReverser::stopReverse()
{
    this->isActive = false;
}

void ThrustReverser::update(float angle)
{
    if(!this->isActive)
        return;
    this->angle = angle;
    this->servo1.write(this->angle);
    this->servo2.write(180 - this->angle);

}

// TVC class
