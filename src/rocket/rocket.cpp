#include "rocket.h"
#include <Arduino.h>
#include "../subsystems/sensors.h"

Rocket::Rocket()
{
    this->time = 0;
    this->altitude = 0;
    this->yVel = 0;

    this->sensors = new SensorStack(SEA_LEVEL_PRESSURE); // local sea level pressure (tune at launch time)

    this->reigniter = new Igniter(REIGNITER_PIN, IGNITER_DURATION);
    this->landingLegs = new Igniter(LANDING_LEGS_PIN, IGNITER_DURATION);

    this->clamps = new ThrustReverser(CLAMP_LEFT_PIN, CLAMP_RIGHT_PIN, 90);
    this->gimbal = new TVC(TVC_PITCH_PIN, TVC_YAW_PIN);
}

// Mark the rocket as launched
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
        case LANDING_ABORTED:
            break;
    }
}

unsigned int Rocket::getTime()
{
    return this->time;
}