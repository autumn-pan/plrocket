#ifndef SENSORS_H
#define SENSORS_H

#include <Wire.h>
#include <Adafruit_BNO055.h>

class IMUHandler
{
    public:
        IMUHandler();

        double* getXAcc();
        double* getRollVel();
        double* getYawVel();
        double* getPitchVel();
        
    private:
        Adafruit_BNO055 bno1 = Adafruit_BNO055(0, 0x28, &Wire);
        Adafruit_BNO055 bno2 = Adafruit_BNO055(1, 0x29, &Wire);
        Adafruit_BNO055 bno3 = Adafruit_BNO055(2, 0x28, &Wire1);

        double * xAcc; //X Acceleration array (3 measured values)
        double * rollVel;
        double * pitchVel;
        double * yawVel;
        double * quat; // Orientation quaternion
};

#endif