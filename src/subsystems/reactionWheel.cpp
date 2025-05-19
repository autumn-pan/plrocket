#include "reactionWheel.h"
#include "Arduino.h"
ReactionWheel::ReactionWheel(int pin1, int pin2, int writerPin)
{
    this->pin1 = pin1;
    this->pin2 = pin2;
    this->writerPin = writerPin;
}

void ReactionWheel::spin(int dir, int speed)
{
    if(dir < 0)
    {
        digitalWrite(this->pin1, HIGH);
        digitalWrite(this->pin2, LOW);
    }
    else if(dir > 0)
    {
        digitalWrite(this->pin1, LOW);
        digitalWrite(this->pin2, HIGH);
    }
    this->direction = dir;
    analogWrite(writerPin, speed);
}

void ReactionWheel::stop()
{
    this->direction = 0;
    analogWrite(writerPin, 0);

}

int ReactionWheel::getDirection()
{
    return this->direction;
}