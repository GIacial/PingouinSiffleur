#include "PS_Coeur.h"
#include "PS_Input.h"

TYPE_VAGUE vague;
TYPE_TIR tir;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

    
  Serial.setTimeout(5000);  //le tps des input
   vague = getTypeVague();

   tir = getTypeTir() ;

  Serial.setTimeout(0); //pas d'attende pour les input
}

void loop() {
  // put your main code here, to run repeatedly:

    chronoTir(tir,vague);
  
}



