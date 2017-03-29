#include <Arduino.h>
#include "PS_Output.h"

#define UNIT_DH   5
#define UNIT_DHG  6
#define UNIT_DHD  7
#define UNIT_DC   8
#define UNIT_DB   11
#define UNIT_DBG  9
#define UNIT_DBD  10

#define DIZ_DH    38
#define DIZ_DHG   39
#define DIZ_DHD   40
#define DIZ_DC    41
#define DIZ_DB    4
#define DIZ_DBG   2
#define DIZ_DBD   3

#define CENT_DH   31
#define CENT_DHG  32
#define CENT_DHD  33
#define CENT_DC   34
#define CENT_DB   37
#define CENT_DBG  35
#define CENT_DBD  36


typedef enum {UNITE , DIZAINE ,CENTAINE } DIGIT;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void afficheTemps(int tps){
   Serial.println(tps);
   afficheOnHardware(tps);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void outputSetUp(){
  pinMode(CENT_DH , OUTPUT);
  pinMode(CENT_DHG , OUTPUT);
  pinMode(CENT_DHD , OUTPUT);
  pinMode(CENT_DC , OUTPUT);
  pinMode(CENT_DB , OUTPUT);
  pinMode(CENT_DBG , OUTPUT);
  pinMode(CENT_DBD , OUTPUT);

  pinMode(UNIT_DH , OUTPUT);
  pinMode(UNIT_DHG , OUTPUT);
  pinMode(UNIT_DHD , OUTPUT);
  pinMode(UNIT_DC , OUTPUT);
  pinMode(UNIT_DB , OUTPUT);
  pinMode(UNIT_DBG , OUTPUT);
  pinMode(UNIT_DBD , OUTPUT);

  pinMode(DIZ_DH , OUTPUT);
  pinMode(DIZ_DHG , OUTPUT);
  pinMode(DIZ_DHD , OUTPUT);
  pinMode(DIZ_DC , OUTPUT);
  pinMode(DIZ_DB , OUTPUT);
  pinMode(DIZ_DBG , OUTPUT);
  pinMode(DIZ_DBD , OUTPUT);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void affiche_0(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd){
  digitalWrite(dc ,LOW);
  digitalWrite(dhg ,HIGH);
  digitalWrite(dhd ,HIGH);
  digitalWrite(dbg ,HIGH);
  digitalWrite(dbd ,HIGH);
  digitalWrite(db ,HIGH);
  digitalWrite(dh ,HIGH);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void affiche_1(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd){
  digitalWrite(dc ,LOW);
  digitalWrite(dhg ,LOW);
  digitalWrite(dhd ,HIGH);
  digitalWrite(dbg ,LOW);
  digitalWrite(dbd ,HIGH);
  digitalWrite(db ,LOW);
  digitalWrite(dh ,LOW);
} 
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void affiche_2(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd){
  digitalWrite(dc ,HIGH);
  digitalWrite(dhg ,LOW);
  digitalWrite(dhd ,HIGH);
  digitalWrite(dbg ,HIGH);
  digitalWrite(dbd ,LOW);
  digitalWrite(db ,HIGH);
  digitalWrite(dh ,HIGH);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void affiche_3(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd){
  digitalWrite(dc ,HIGH);
  digitalWrite(dhg ,LOW);
  digitalWrite(dhd ,HIGH);
  digitalWrite(dbg ,LOW);
  digitalWrite(dbd ,HIGH);
  digitalWrite(db ,HIGH);
  digitalWrite(dh ,HIGH);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void affiche_4(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd){
  digitalWrite(dc ,HIGH);
  digitalWrite(dhg ,HIGH);
  digitalWrite(dhd ,HIGH);
  digitalWrite(dbg ,LOW);
  digitalWrite(dbd ,HIGH);
  digitalWrite(db ,LOW);
  digitalWrite(dh ,LOW);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void affiche_5(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd){
  digitalWrite(dc ,HIGH);
  digitalWrite(dhg ,HIGH);
  digitalWrite(dhd ,LOW);
  digitalWrite(dbg ,LOW);
  digitalWrite(dbd ,HIGH);
  digitalWrite(db ,HIGH);
  digitalWrite(dh ,HIGH);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void affiche_6(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd){
  digitalWrite(dc ,HIGH);
  digitalWrite(dhg ,HIGH);
  digitalWrite(dhd ,LOW);
  digitalWrite(dbg ,HIGH);
  digitalWrite(dbd ,HIGH);
  digitalWrite(db ,HIGH);
  digitalWrite(dh ,HIGH);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void affiche_7(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd){
  digitalWrite(dc ,LOW);
  digitalWrite(dhg ,LOW);
  digitalWrite(dhd ,HIGH);
  digitalWrite(dbg ,LOW);
  digitalWrite(dbd ,HIGH);
  digitalWrite(db ,LOW);
  digitalWrite(dh ,HIGH);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void affiche_8(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd){
  digitalWrite(dc ,HIGH);
  digitalWrite(dhg ,HIGH);
  digitalWrite(dhd ,HIGH);
  digitalWrite(dbg ,HIGH);
  digitalWrite(dbd ,HIGH);
  digitalWrite(db ,HIGH);
  digitalWrite(dh ,HIGH);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void affiche_9(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd){
  digitalWrite(dc ,HIGH);
  digitalWrite(dhg ,HIGH);
  digitalWrite(dhd ,HIGH);
  digitalWrite(dbg ,LOW);
  digitalWrite(dbd ,HIGH);
  digitalWrite(db ,HIGH);
  digitalWrite(dh ,HIGH);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void afficheInt(int nb ,int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd){
  switch(nb){
    case 1: affiche_1(dhg , dh , dhd ,dc ,dbg , db,dbd);
    break;
    case 2: affiche_2(dhg , dh , dhd ,dc ,dbg , db,dbd);
    break;
    case 3: affiche_3(dhg , dh , dhd ,dc ,dbg , db,dbd);
    break;
    case 4: affiche_4(dhg , dh , dhd ,dc ,dbg , db,dbd);
    break;
    case 5: affiche_5(dhg , dh , dhd ,dc ,dbg , db,dbd);
    break;
    case 6: affiche_6(dhg , dh , dhd ,dc ,dbg , db,dbd);
    break;
    case 7: affiche_7(dhg , dh , dhd ,dc ,dbg , db,dbd);
    break;
    case 8: affiche_8(dhg , dh , dhd ,dc ,dbg , db,dbd);
    break;
    case 9: affiche_9(dhg , dh , dhd ,dc ,dbg , db,dbd);
    break;
    default : affiche_0(dhg , dh , dhd ,dc ,dbg , db,dbd);
    break;
  }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void afficheIntOnDigit(int nb , DIGIT digit){
  switch(digit){
    case DIZAINE: afficheInt(nb,DIZ_DHG , DIZ_DH , DIZ_DHD ,DIZ_DC ,DIZ_DBG , DIZ_DB , DIZ_DBD);  //dizaine
    break;
    case CENTAINE: afficheInt(nb,CENT_DHG , CENT_DH , CENT_DHD ,CENT_DC ,CENT_DBG , CENT_DB , CENT_DBD);  //centaine
    break;

    default : afficheInt(nb,UNIT_DHG , UNIT_DH , UNIT_DHD ,UNIT_DC ,UNIT_DBG , UNIT_DB , UNIT_DBD);  //unité
    break;
  }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void afficheOnHardware(int nb){
  afficheIntOnDigit(nb%10,UNITE);//unit
  afficheIntOnDigit((nb%100)/10,DIZAINE);//dizaine
  afficheIntOnDigit((nb%1000)/100,CENTAINE);//Centaine
}

