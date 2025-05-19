#ifndef ROCKET_H
#define ROCKET_H

#define SEA_LEVEL_PRESSURE 1013.25
#define IGNITER_DURATION 1000

#include "../subsystems/sensors.h"
#include "../subsystems/propulsion.h"
// Pin numbers for each component
enum PINS {
    TVC_PITCH_PIN = 3,
    TVC_YAW_PIN = 4,
    REIGNITER_PIN = 5,
    LANDING_LEGS_PIN = 6,
    CLAMP_LEFT_PIN = 7,
    CLAMP_RIGHT_PIN = 8,
    REACTION_WHEEL_PIN1 = 9,
    REACTION_WHEEL_PIN2 = 10,
    REACTION_WHEEL_PIN3 = 11
};

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
        // Sensor Stack
        SensorStack * sensors;
        // Components
        Igniter * reigniter; // Reignites rocket before DESCENT_BURN
        Igniter * landingLegs; /* Deploys the landing legs before LANDING_LEGS_DEPLOYED:
        Burns through an elastic band which allows the spring loaded legs to deploy*/
        TVC * gimbal; // Pretty straightforward: gimbals the rocket motor
        ThrustReverser * clamps; // Blocks rocket exhaust, cutting about 80% of thrust

        unsigned int time;
};
#endif        
