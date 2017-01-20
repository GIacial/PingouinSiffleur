#include <Arduino.h>
#include "PS_Coeur.h"


void chrono (int temps) {

  unsigned long debut, debutCpt, finCpt;
  int tempsAttente;

  debutCpt = millis();
  while (temps > 0) {
    debut = millis();     //on chronometre le temps qu'on va metre
    //afficheTemps(temps);
    temps--;

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
