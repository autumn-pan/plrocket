#include "pid.hpp"

PID::PID(float kP, float kI, float kD, float limit)
{
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
    this->limit = limit;
}

void PID::calculate(float pos)
{
    float currentTime = milis();
    float error = pos - reference;

    float delta = currentTime - prevTime;
    this->sum = 0;
    //Calculate PID terms
    this->proportion = error;
    this->integral += pos * delta;
    this->derivative = (error - prevError) / delta;

    this->sum += kP*proportion + kI*integral + kD*derivative;

    //Ensure new position in within limits
    if (sum > limit)
        sum = limit;
    else if (sum < -limit)
        sum = -limit;

    prevError = error;
    prevTime = currentTime;
    pos = sum;
}

