#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "PS_Coeur.h"
#include "PS_Output.h"


//=================================================================================================================================

void chrono (int temps, TypeVague vague){
    clock_t debut,retard,debutCpt,finCpt;
    retard = 0;
    int tempsAttente;


    debut = clock();
    debutCpt = debut;
    while(temps>0){
        afficheTemps(temps);
        temps--;


        tempsAttente = 1000-retard-(((double)(clock() - debut)/CLOCKS_PER_SEC)*1000);  //1sec - le temps passer a exec du code - le retard
        retard = clock();

        if(tempsAttente > 0){
            _sleep(tempsAttente);
            retard = (clock()-retard)-CLOCKS_PER_SEC;   //on enleve la seconde passer et il reste le temps pris en plus(ou en moins)
        }
        debut = clock();
    }

    finCpt = debut;  //recup valeur clock de la derniere fin de boucle
    afficheTemps(0);    //affiche un 0 pour la forme
    printf("Temps d'execution %f sec",(double)(finCpt - debutCpt)/CLOCKS_PER_SEC);    //verif qu'on a bien mis temps seconde

}

//=================================================================================================================================
