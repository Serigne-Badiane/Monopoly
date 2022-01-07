#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 200

#include "bib.h"




void verfiwin (t_joueur player [NbJoueurMax][TAILLE],int tourjoueur,int nombreJoueur){
    int compteur;
    for ( int i = 0 ; i < nombreJoueur ; i ++){
        if (player[i]->argent <= 0){
            compteur ++;

        }
    }
    if (compteur == nombreJoueur - 1 ){

        system("cls");
        Color(3,0);
        printf("                           IA : FELICITATION NOUS AVONS NOTRE ASTRONAUTE ULTIME !\nIA : ");
        Color(player[tourjoueur]->couleurJoueur,0);
        printf("%s",player[tourjoueur]->prenomJoueur);
        Color(3,0);
        printf(" EST LE DERNIER ! IL REMPORTE DONC LA PARTIE !");
        printf("\n                                  RECAPITULATIF DE LA PARTIE : ");
        for (int i = 0; i<nombreJoueur ; i++){
            Color(player[i]->couleurJoueur,0);
            printf("\nInformation J%d : ",player[i]->numeroJoueur);
            printf("%s",player[i]->prenomJoueur);
            printf("\nPorte Monnaie : %d",player[i]->argent);
            printf("\nProprietes : ");
            printf("%s",player[i]->proprietes);

        }
        exit (0);


    }
    else {
        compteur = 0;
    }
}



void faillite(t_joueur player [NbJoueurMax][TAILLE],int tourjoueur,int nombreJoueur)
{
    if (player[tourjoueur]->argent<=0  )
    {
        player[tourjoueur]->etatIG=0;
    }
}
