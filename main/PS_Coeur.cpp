#include <Arduino.h>
#include "PS_Coeur.h"
#include "PS_Input.h"
#include "PS_Output.h"


void chrono (int temps ,bool preTir) {

  unsigned long debut, debutCpt, finCpt;
  int tempsAttente;
  bool actif = true;
  choixCouleur(preTir);
  
  debutCpt = millis();
  while (temps > 0) {
    debut = millis();     //on chronometre le temps qu'on va metre
    choixCouleur(temps,preTir);
    afficheTemps(temps);
    TYPE_BUTTON button = getButton();
    switch(button){
      case BUTTON_STOP : actif =false;
      Serial.println("STOP");
      break;
      case BUTTON_TIR : actif =true;
                          temps--;
                          Serial.println("TIR");
      break;
      case BUTTON_SCORE :temps =0;
      Serial.println("SCORE");
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
  Serial.print("Temps d'execution : ");    //verif qu'on a bien mis temps seconde
  Serial.print((double)(finCpt - debutCpt) / 1000);
  Serial.println(" seconde");

}

void chronoTir(TYPE_TIR tir ,TYPE_VAGUE vague){
  for(int i = 0 ; i<(int)vague ; i++){
    switch(vague){
      case VAGUE_AB_CD : 
                          if(i%2 == (i>1)){ //verif si on a déjà fait une vague AB_CD pour mettre  CD_AB
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
    chrono((int)PRE_TIR , true);
    chrono ((int)tir);
    if(i == 1){ //pause va chercher les fleches pour AB_CD
      pauseScore();
    }
    
  }
  pauseScore();
}

void choixCouleur(int temps , bool preTir){
  if(!preTir){
    if(temps == 30){
      afficheCouleur(ORANGE);
    }
  }
}


void choixCouleur(bool preTir){
  if(preTir){
    afficheCouleur(ROUGE);    
  }
  else{
    afficheCouleur(VERT);
  }
}

void pauseScore(){
  Serial.println("Va chercher les fleches");
   while( getButton()!= BUTTON_TIR){
    delay(1000);
   }
}



