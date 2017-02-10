#include <Arduino.h>

#include "PS_Input.h"

TYPE_TIR getTypeTir(){
	bool ok = false;
	TYPE_TIR tir = TIR_EXT ;

   Serial.print("1=Ext ou 2=Int ou 3=Alt\n");
	while (!ok){
	  int tirName = Serial.parseInt();
	  switch(tirName){
	    case 1: tir = TIR_EXT;
	    	ok = true;
        Serial.print("choix => EXT \n");
	    break;
	    case 2: tir = TIR_INT;
	    	ok = true;
        Serial.print("choix => INT \n");
	    break;
	    case 3: tir = TIR_ALT; 
	    	ok = true;
        Serial.print("choix => ALT \n");
	    break;
	    default : 
	    break;
  		}
	}
 
	return tir;
}

TYPE_VAGUE getTypeVague(){
	Serial.print("1=AB_CD ou 2=ABC\n");
  bool ok = false;
  TYPE_VAGUE vague = VAGUE_AB_CD;
    while (!ok){
      int vagueName = Serial.parseInt();
      switch(vagueName){
      case 1: vague = VAGUE_AB_CD;
        ok = true;
        Serial.print("choix => AB_CD \n");
      break;
      case 2: vague = VAGUE_ABC;
        ok = true;
        Serial.print("choix => ABC \n");
      break;

      default : 
      break;
      }
    }
  return vague;
}

TYPE_BUTTON getButton(){
	int numButton = Serial.parseInt();
	TYPE_BUTTON button ;
	switch(numButton){
		case 1 : button = BUTTON_START;
		break;
		case 2 : button = BUTTON_STOP;
		break;
		case 3 : button = BUTTON_NEXT;
		break;
		default : button = BUTTON_NONE;
		break;
	}
	return button;
}
