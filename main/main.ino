#include "PS_Coeur.h"
#include "PS_Input.h"


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.setTimeout(5000);  //le tps des input
  TYPE_VAGUE vague = getTypeVague();

  TYPE_TIR tir = getTypeTir() ;


  Serial.setTimeout(0); //pas d'attende pour les input
  chronoTir(tir,vague);
}



