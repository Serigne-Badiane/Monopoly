#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 200

#include "bib.h"



///-----------------------------------------------------------FONCTION VERIFICATION DE LA VICTOIRE-----------------------------------------------------------
void verfiwin (t_joueur player [NbJoueurMax][TAILLE],int tourjoueur,int nombreJoueur){
    int compteur;
    int numgan;
    for ( int i = 0 ; i < nombreJoueur ; i ++){
        if (player[i]->etatIG == 0){
            compteur ++;

        }
        if (player[i]->etatIG == 1){
            numgan = player[i]->numeroJoueur;
        }
    }
    if (compteur == nombreJoueur - 1 ){

        system("cls");
        Color(3,0);
        printf("                           IA : FELICITATIONS NOUS AVONS NOTRE ASTRONAUTE ULTIME !\nIA : ");
        Color(player[numgan]->couleurJoueur,0);
        printf("%s",player[numgan]->prenomJoueur);
        Color(3,0);
        printf(" EST LE DERNIER ! IL REMPORTE DONC LA PARTIE !");
        printf("\n                                  RECAPITULATIF DE LA PARTIE : ");
        for (int i = 0; i<nombreJoueur ; i++){ //Affichage de toutes les stats des joueurs
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



