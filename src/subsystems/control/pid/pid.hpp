#ifndef PID_HPP
#define PID_HPP

class PID
{
    public:
        PID(float kP, float kI, float kD, float limit);

        void calculate(float pos);

    private:
        float reference = 0.0;
        float delta;
        float limit;

        float proportion = 0;
        float integral = 0;
        float derivative = 0;

        float sum = 0;

        float kP;
        float kI;
        float kD;

        float prevError = 0;
        float prevTime = 0;
};

#endif