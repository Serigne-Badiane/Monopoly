#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 200

#include "bib.h"

///Dans les cases il faudra définir le curseur dans la console pour que ça place automatiquement l'icone du joueur au bon endroit en fonction de la case


//DEPART
void case1(){
        //200 à chaque passage
    printf("BONJOUR");


}

void case2(satellite lune_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){

    arrivsat(&lune_, player, numeroJoueur);

}


void case3(planete terre_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){

   arrivplan(&terre_, player, numeroJoueur);
}


//IMPOT
void case4(){
    //Retirer 200 aux joueurs qui passent par ici
    printf("BONJOUR");

}


void case5(galaxie voieLactee_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
   arrivgalax(&voieLactee_, player, numeroJoueur);

}


void case6(satellite phobos_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
    arrivsat(&phobos_, player, numeroJoueur);
}


void case7(planete mars_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
     arrivplan(&mars_, player, numeroJoueur);
}

//Prison
void case8(){
    //Emmène directement le joueur en prison
    printf("BONJOUR");

}


void case9(satellite ganymede_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
    arrivsat(&ganymede_, player, numeroJoueur);
}


void case10(satellite callisto_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
    arrivsat(&callisto_, player, numeroJoueur);
}


void case11(galaxie andromede_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
    arrivgalax(&andromede_, player, numeroJoueur);
}


void case12(satellite io_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
    arrivsat(&io_, player, numeroJoueur);
}


void case13(planete jupiter_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
    arrivplan(&jupiter_, player, numeroJoueur);
}


void case14(){
    //carte chance
    printf("BONJOUR");

}


void case15(){
    //parking
    printf("BONJOUR");

}


void case16(satellite titan_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
   arrivsat(&titan_, player, numeroJoueur);
}

void case17(planete saturne_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
    arrivplan(&saturne_, player, numeroJoueur);

}


void case18(galaxie tetard_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
    arrivgalax(&tetard_, player, numeroJoueur);
}


void case19(satellite pluton_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
   arrivsat(&pluton_, player, numeroJoueur);
}


void case20(planete neptune_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
    arrivplan(&neptune_, player, numeroJoueur);
}

void case21(){
    //carte communaute
    printf("BONJOUR");

}

void case22(){
    //prison
    printf("BONJOUR");

}

void case23(planete venus_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
    arrivplan(&venus_, player, numeroJoueur);
}


void case24(planete uranus_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
    arrivplan(&uranus_, player, numeroJoueur);
}


void case25(galaxie nuageDeMagellan_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
    arrivgalax(&nuageDeMagellan_, player, numeroJoueur);

}


void case26(planete mercure_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
    arrivplan(&mercure_, player, numeroJoueur);

}


void case27(planete soleil_, t_joueur player[NbJoueurMax][TAILLE], int numeroJoueur){
    arrivplan(&soleil_, player, numeroJoueur);
}


void case28(){
    //chance ou commu
    printf("BONJOUR");

}
