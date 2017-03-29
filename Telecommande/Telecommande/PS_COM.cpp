#include <Arduino.h>
#include <Wire.h>
#include "PS_COM.h"

void envoi( byte c , int device){
  Wire.beginTransmission(device);
  Wire.write(c);
  Wire.endTransmission();
}


void envoiSetUp(){
  Wire.begin();
}

