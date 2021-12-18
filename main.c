#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 200
#include "bib.h"


void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}









int main()
{
    srand(time(NULL));
    t_joueur player[NbJoueurMax][TAILLE];
    planete marss = {"", "", "", 0, 0, 0, 0 , 0} ;
    planete terre = {"", "", "", 0, 0, 0, 0 , 0} ;
    menu(player);
    mars(&marss);
    arrivplan(&marss,player,0);
    arrivplan(&marss,player,1);

    return 0;
}
