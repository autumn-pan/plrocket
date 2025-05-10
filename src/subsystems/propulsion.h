#ifndef PROPULSION_H
#define PROPULSION_H
#include "../rocket/rocket.h"
class Reigniter
{
    public:
        Reigniter(Rocket * rocket, int pin);
        void reignite();
        boolean update();

    private:
        Rocket * rocket;
        boolean state;

        int initialTime;
        int pin;
        int duration;
};

#endif