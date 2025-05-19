#ifndef REACTION_WHEEL_H
#define REACTION_WHEEL_H

class ReactionWheel
{
    public:
        ReactionWheel(int pin1, int pin2, int writerPin);
        void spin(int dir, int speed);
        void stop();
        int getDirection();

    private:
        int pin1;
        int pin2;
        int writerPin;

        int direction;
};

#endif