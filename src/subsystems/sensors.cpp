#include "sensors.h"
#include <Wire.h>
#include <Adafruit_BNO055.h>

// COnstructor for SensorStack
SensorStack::SensorStack(double seaLevelPressure)
{
    // Sets local sea level pressure
    this->seaLevelPressure = seaLevelPressure;

    // Begins I2C
    Wire.begin();
    Wire1.begin();

    Wire.setClock(400000);
    Wire1.setClock(400000);

    // Begins 3 IMUs
    if(!bno1.begin())
        Serial.print("BNO055 Unit 1 failed to begin!");

    if(!bno2.begin())
        Serial.print("BNO055 Unit 2 failed to begin!");

    if(!bno3.begin())
        Serial.print("BNO055 Unit 3 failed to begin!");

    // Begins barometer
    if(!bmp.begin_I2C(0x77, &Wire1)) // Begin Altimeter
        Serial.print("BMP390 failed to begin!");

    // Configures IMUs
    bno1.setExtCrystalUse(true);
    bno2.setExtCrystalUse(true);
    bno3.setExtCrystalUse(true);
}

// Update measured sensor values
void SensorStack::update()
{
    // Retrieve angular velocity vectors
    imu::Vector<3> angVels[3] = {
        bno1.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE),
        bno2.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE),
        bno3.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE)
    };

    // Retrieve attitude quaternions
    imu::Quaternion quats[3] = 
    {
        bno1.getQuat(),
        bno2.getQuat(),
        bno3.getQuat()
    };

    // update all values
    for(int i = 0; i < 3; i++)
    {
        this->rollVel[i] = angVels[i].x();
        this->pitchVel[i] = angVels[i].y();
        this->yawVel[i] = angVels[i].z();

        this->quat[i][0] = quats[i].w();
        this->quat[i][1] = quats[i].x();
        this->quat[i][2] = quats[i].y();
        this->quat[i][3] = quats[i].z();
    }


    yAcc[0] = bno1.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER).y();
    yAcc[1] = bno2.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER).y();
    yAcc[2] = bno3.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER).y();

    // read and update altitude
    bmp.performReading();
    altitude = bmp.readAltitude(this->seaLevelPressure);
}

// Getter functions for SensorStack class
double * SensorStack::getPitchVel()
{
    return this->pitchVel;
}
double * SensorStack::getYawVel()
{
    return this->yawVel;
}
double * SensorStack::getRollVel()
{
    return this->rollVel;
}
double * SensorStack::getYAcc()
{
    return this->yAcc;
}
double SensorStack::getAltitude()
{
    return this->altitude;
}