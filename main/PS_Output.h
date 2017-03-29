#ifndef PS_OUTPUT_h
#define PS_OUTPUT_h

#include "PS_Def.h"

void afficheTemps(int tps);
void afficheCouleur(COULEUR c);

void outputSetUp(); //config des pin
/*void affiche_0(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd); //prend 7 num de pin  => affiche un 0 sur le hardware
void affiche_1(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd); //prend 7 num de pin  => affiche un 0 sur le hardware
void affiche_2(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd); //prend 7 num de pin  => affiche un 0 sur le hardware
void affiche_3(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd); //prend 7 num de pin  => affiche un 0 sur le hardware
void affiche_4(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd); //prend 7 num de pin  => affiche un 0 sur le hardware
void affiche_5(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd); //prend 7 num de pin  => affiche un 0 sur le hardware
void affiche_6(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd); //prend 7 num de pin  => affiche un 0 sur le hardware
void affiche_7(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd); //prend 7 num de pin  => affiche un 0 sur le hardware
void affiche_8(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd); //prend 7 num de pin  => affiche un 0 sur le hardware
void affiche_9(int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd); //prend 7 num de pin  => affiche un 0 sur le hardware

void afficheInt(int nb ,int dhg , int dh , int dhd , int dc , int dbg , int db , int dbd);  //choisi la fonction d'affichage approprié pour affiché nb
void afficheIntOnDigit(int nb , DIGIT digit);// affiche le nb sur le bon digit*/
void afficheOnHardware(int nb);
	
#endif
