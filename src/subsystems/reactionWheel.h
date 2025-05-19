#ifndef REACTION_WHEEL_H
#define REACTION_WHEEL_H

class ReactionWheel
{
    public:
        ReactionWheel(int pin1, int pin2, int pin3);
    private:
        int pin1;
        int pin2;
        int pin3;
};

#endif