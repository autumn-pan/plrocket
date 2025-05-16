#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
enum States {
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
#endif
