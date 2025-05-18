#include "rocket.h"
#include <Arduino.h>
#include "../subsystems/sensors.h"

Rocket::Rocket()
{
    this->time = 0;
    this->altitude = 0;
    this->yVel = 0;
}

// Set mark the rocket as launched
void Rocket::launch()
{
    this->state = ASCENT_BURN;
}

void Rocket::update(double altitude, double yVel, double yAcc)
{
    this->altitude = altitude;
    this->yVel = yVel;
    this->yAcc = yAcc;

    this->time = millis();

    // State Machine
    switch(state)
    {
        case GROUNDED:
            break;
        case ASCENT_BURN:
            break;
        case ASCENT_BURNOUT:
            break;
        case DESCENT_PREBURN:
            break;
        case DESCENT_BURN:
            break;
        case DESCENT_LEGS_DEPLOYED:
            break;
        case LANDED:
            break;
    }
}

unsigned int Rocket::getTime()
{
    return this->time;
}