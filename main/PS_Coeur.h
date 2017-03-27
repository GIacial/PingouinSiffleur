#ifndef PS_COEUR_H
#define PS_COEUR_H
  #include "PS_Def.h"
  void chrono(int temps ,bool preTir = false);
  void chronoTir(TYPE_TIR tir ,TYPE_VAGUE vague);
  
  void choixCouleur(bool preTir);
  void choixCouleur(int temps ,bool preTir);

  void pauseScore();
  
#endif
