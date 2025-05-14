#include <Arduino.h>
#include "rocket/rocket.h"
#include "subsystems/propulsion.h"

Rocket * rocket = new Rocket();

Igniter * reigniter = new Igniter(rocket, 3, 700);
Igniter * legDeployer = new Igniter(rocket, 4, 700);

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, world!");

  // outpit pin setup
  pinMode(3, OUTPUT);
  reigniter->reignite();


}

void loop() {
  reigniter->update();
}


