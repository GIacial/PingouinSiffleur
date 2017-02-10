#include <Arduino.h>
#include "PS_Coeur.h"
#include "PS_Input.h"


void chrono (int temps) {

  unsigned long debut, debutCpt, finCpt;
  int tempsAttente;
  bool actif = true;

  debutCpt = millis();
  while (temps > 0) {
    debut = millis();     //on chronometre le temps qu'on va metre
    Serial.println(temps);
    TYPE_BUTTON button = getButton();
    switch(button){
      case BUTTON_STOP : actif =false;
      Serial.println("STOP");
      break;
      case BUTTON_START : actif =true;
                          temps--;
                          Serial.println("START");
      break;
      case BUTTON_NEXT :temps =0;
      Serial.println("NEXT");
      break;
      default: if(actif){
                temps--;
               }
      break;
    }

    tempsAttente = 1000 - (millis() - debut); //on cacule le temps qui reste jusqu'a la prochaine seconde
    if (tempsAttente > 0) {
      delay(tempsAttente);    //on attends
    }
  }

  finCpt = millis();  //recup le temps qu'on a mis a finir
  // afficheTemps(0);    //affiche un 0 pour la forme
  Serial.print("Temps d'execution : ");    //verif qu'on a bien mis temps seconde
  Serial.print((double)(finCpt - debutCpt) / 1000);
  Serial.println(" seconde");

}

void chronoTir(TYPE_TIR tir ,TYPE_VAGUE vague){
  for(int i = 0 ; i<2 ; i++){
    switch(vague){
      case VAGUE_AB_CD :  if(i%2 ==0){
                              Serial.print("AB\n");
                          }
                          else{
                            Serial.print("CD\n");
                          }
      break;
      case VAGUE_ABC : Serial.print("ABC\n");
      break;
      default:Serial.print("Vague inconnu");
      break;
    }
    chrono ((int)tir);
  }
}


