#include <Arduino.h>
#include "propulsion.h"
#include "../rocket/rocket.h"

// send out a voltage to reignite the rocket thruster
Reigniter::Reigniter(Rocket * rocket, int pin)
{
    this->rocket = rocket;
    this->pin = pin;
    this->state = false;
    this->duration = 1000; // 1 second
}

void Reigniter::reignite()
{
    this->state = true;
    this->initialTime = millis();

    digitalWrite(this->pin, HIGH);
    Serial.println("Reigniter activated");
}

boolean Reigniter::update()
{
    if(this->state)
    {
        if(millis() - this->initialTime > this->duration)
        {
            digitalWrite(this->pin, LOW);
            Serial.println("Reigniter deactivated");
            this->state = false;
            return false;
        }
        else
        {
            return true;
        }
    }
}
