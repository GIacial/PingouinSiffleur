#include "PS_Coeur.h"
#include "PS_Input.h"
#include "PS_Output.h"

TYPE_VAGUE vague;
TYPE_TIR tir;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  inputSetUp();
  outputSetUp();
  Serial.setTimeout(10000);  //le tps des input
   vague = getTypeVague();

   tir = getTypeTir() ;

  Serial.setTimeout(0); //pas d'attende pour les input
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0 ; i<10 ; i++){
    Serial.println(i);
    afficheOnHardware(i);
    delay(1000);
  }
  for(int i=10 ; i<100 ; i+=10){
    Serial.println(i);
    afficheOnHardware(i);
    delay(1000);
  }
   for(int i=100 ; i<1000 ; i+=100){
    Serial.println(i);
    afficheOnHardware(i);
    delay(1000);
  }
   
    chronoTir(tir,vague);
  
}



