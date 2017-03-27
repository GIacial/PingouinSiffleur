#include <Arduino.h>

#include "PS_Output.h"

void afficheTemps(int tps){
   Serial.println(tps);
}
void afficheCouleur(COULEUR c){
  switch(c){
    case VERT :  Serial.println("VERT");
    break;
    case ORANGE :  Serial.println("ORANGE");
    break;
    case ROUGE :  Serial.println("ROUGE");
    break;
    default: Serial.println("Error coul");
    break;
  }
}

