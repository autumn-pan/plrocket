#ifndef PROPULSION_H
#define PROPULSION_H
#include "../rocket/rocket.h"
#include <Servo.h>

class Reigniter
{
    public:
        Reigniter(Rocket * rocket, int pin);
        void reignite();
        boolean update();

    private:
        Rocket * rocket;
        boolean state;

        unsigned int initialTime;
        int pin;
        unsigned int duration;
};


// Uses a bucket-type thrust reverser as a braking mechanism for the SRMs
// Works by blocking the exhaust with two servos
class ThrustReverser
{
    public:
        ThrustReverser(Rocket * rocket, int pin1, int pin2, float initialAngle);
        // Activates TR
        void initReverse();
        // Update TR angle; to be run every iteration
        void update(float angle);
        // Deactivates TR
        void stopReverse();

        // boolean isActive();
        float getAngle(); // Returns TR angle

    private:
        Rocket * rocket;
        unsigned int initialTime;
        int pin1;
        int pin2;
        float angle;
        boolean isActive;

        Servo servo1;
        Servo servo2;
};

#endif