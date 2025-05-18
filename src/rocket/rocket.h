#ifndef ROCKET_H
#define ROCKET_H
#include "../subsystems/sensors.h"

enum STATE {
    //If all goes to plan
    GROUNDED,
    ASCENT_BURN,
    ASCENT_BURNOUT,
    // Apogee here
    DESCENT_PREBURN,
    DESCENT_BURN,
    DESCENT_LEGS_DEPLOYED,
    LANDED,

    // FAILURES
    LANDING_ABORTED // idk how you would even handle this
};

class Rocket
{
    public:
        Rocket();
        void update(double altitude, double yVel, double yAcc);
        unsigned int getTime();
        void launch();

    private:
        float altitude;
        float yVel;
        float yAcc;
        STATE state;

        unsigned int time;
};
#endif        
