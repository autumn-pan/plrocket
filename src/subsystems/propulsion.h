#ifndef PROPULSION_H
#define PROPULSION_H
#include <Servo.h>

class Igniter
{
    public:
        Igniter(int pin, unsigned int duration);
        void reignite();
        boolean update();

    private:
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
        ThrustReverser(int pin1, int pin2, float initialAngle);
        // Activates TR
        void initReverse();
        // Update TR angle; to be run every iteration
        void update(float angle);
        // Deactivates TR
        void stopReverse();

        // boolean isActive();
        float getAngle(); // Returns TR angle

    private:
        unsigned int initialTime;
    

        int pin1;
        int pin2;
        float angle;
        boolean isActive;

        Servo servo1;
        Servo servo2;
};

// TVC Class
class TVC
{
    public:
        TVC(int pinPitch, int pinYaw);

        double getPitch();
        double getYaw();

        void setPitch(double pitch);
        void setYaw(double yaw);

        void update();

    private:
        // Max Angle: 10 degrees, pi/18 rad

        // TODO: upload quaternion lib and integrate
        double servoInitialAngles = 0;

        // TVC angles
        double pitch;
        double yaw;
        // Teensy pins
        int pinPitch;
        int pinYaw;
        // Servos
        Servo servoPitch;
        Servo servoYaw;

};
#endif
