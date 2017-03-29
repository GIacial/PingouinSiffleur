#include <Arduino.h>
#include <Wire.h>

#include "PS_Input.h"
#define DEVICE 42

byte prog = 254;
char button = 'a';
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
TYPE_TIR getTypeTir(){
	bool ok = false;
	TYPE_TIR tir = TIR_EXT ;

   Serial.print("1=Ext ou 3=Int ou 5=Alt\n");
	while (!ok){
    int progV = Serial.parseInt();
	  switch(progV){
      case 1: case 0:
        tir = TIR_EXT;
	    	ok = true;
        Serial.print("choix => EXT \n");
	    break;
      
	    case 3:case 2:  
	      tir = TIR_INT;
	    	ok = true;
        Serial.print("choix => INT \n");
	    break;

      case 4 : case 5:
        tir = TIR_ALT;
        ok = true;
        Serial.print("choix => ALT \n");
       break;
       
	    default : 
	    break;
  		}
     delay(100);
	}
 
	return tir;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
TYPE_VAGUE getTypeVague(){
	Serial.print("1=AB_CD ou 3=ABC\n");
  bool ok = false;
  TYPE_VAGUE vague = VAGUE_AB_CD;
  
    while (!ok){
      int progV = Serial.parseInt();
      switch(progV){
      case 1: case 0:case 2:
        vague = VAGUE_AB_CD;
        ok = true;
        Serial.print("choix => AB_CD \n");
      break;
      case 3 :case 4:case 5:
        vague = VAGUE_ABC;
        ok = true;
        Serial.print("choix => ABC \n");
      break;

      default : 
      break;
      }
      delay(100);
    }
  return vague;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
TYPE_BUTTON getButton(){
	int numButton = Serial.parseInt();
	TYPE_BUTTON button ;
	switch(numButton){
		case 1 : button = BUTTON_TIR;
		break;
		case 2 : button = BUTTON_STOP;
		break;
		case 3 : button = BUTTON_SCORE;
		break;
		default : button = BUTTON_NONE;
		break;
	}
	return button;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
void receiveEvent(int howMany){
  Serial.println("CC");
  button = Wire.read();
  if(Wire.available()>0){
    prog = Wire.read();
  }
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void inputSetUp(){
  Wire.begin(DEVICE);
  Wire.onReceive(receiveEvent);
}

