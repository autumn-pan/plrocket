#include <Arduino.h>
#include "pins.h"
#include "rocket/rocket.h"
#include "subsystems/propulsion.h"

Rocket * rocket = new Rocket();
Reigniter * reigniter = new Reigniter(rocket, 3);

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


