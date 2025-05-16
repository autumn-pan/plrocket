#include "rocket.h"
#include <Arduino.h>

Rocket::Rocket()
{
    this->time = 0;
    this->altitude = 0;
    this->yVel = 0;
}

void Rocket::update(double altitude, double yVel, double yAcc)
{
    this->altitude = altitude;
    this->yVel = yVel;
    this->yAcc = yAcc;

    this->time = millis();
}

unsigned int Rocket::getTime()
{
    return this->time;
}