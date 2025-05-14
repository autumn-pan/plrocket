#include "sensors.h"
#include <Wire.h>
#include <Adafruit_BNO055.h>


SensorStack::SensorStack(double seaLevelPressure)
{
    this->seaLevelPressure = seaLevelPressure;

    Wire.begin();
    Wire1.begin();

    Wire.setClock(400000);
    Wire1.setClock(400000);

    if(!bno1.begin())
        Serial.print("BNO055 Unit 1 failed to begin!");

    if(!bno2.begin())
        Serial.print("BNO055 Unit 2 failed to begin!");

    if(!bno3.begin())
        Serial.print("BNO055 Unit 3 failed to begin!");

    if(!bmp.begin_I2C()) // Begin Altimeter
        Serial.print("BMP390 failed to begin!");
    // Configure altimeter        
    bno1.setExtCrystalUse(true);
    bno2.setExtCrystalUse(true);
    bno3.setExtCrystalUse(true);
}

// Update measured sensor values
void SensorStack::update()
{
    imu::Vector<3> angVels[3] = {
        bno1.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE),
        bno2.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE),
        bno3.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE)
    };

    imu::Quaternion quats[3] = 
    {
        bno1.getQuat(),
        bno2.getQuat(),
        bno3.getQuat()
    };

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

    altitude = bmp.readAltitude(this->seaLevelPressure);
}

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