#ifndef SENSORS_H
#define SENSORS_H

#include <Wire.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_BMP3XX.h>

class SensorStack
{
    public:
        SensorStack(double seaLevelPressure);

        void update();
        double* getYAcc();
        double* getRollVel();
        double* getYawVel();
        double* getPitchVel();
        double getAltitude();
    private:
        Adafruit_BNO055 bno1 = Adafruit_BNO055(0, 0x28, &Wire);
        Adafruit_BNO055 bno2 = Adafruit_BNO055(1, 0x29, &Wire);
        Adafruit_BNO055 bno3 = Adafruit_BNO055(2, 0x28, &Wire1);
        Adafruit_BMP3XX bmp;

        double yAcc[3]; //X Acceleration array (3 measured values)

        double seaLevelPressure;
        double altitude;

        double * rollVel;
        double * pitchVel;
        double * yawVel;

        double quat[3][4]; // Orientation quaternion
};

#endif