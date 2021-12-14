#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 100
#include "bib.h"



///AFFICHAGE DE L'ARRIVEE SUR LES PLANETES
void arrivplan (planete p){
    Color(3,0);
    printf("\n\n%cIA : Nous sommes arriv%cs sur une nouvelle plan%cte... La plan%cte %s !",0x10,0x82,0x8A,0x8A,p.nom);
    printf("\n%cIA : %s",0x10,p.anecdote);
    printf("\n%cIA : Voici un r%ccapitulatif capitaine...",0x10,0x82);
    printf("\n\n                                                        ");
    Color(0,p.couleur);
    printf("%c PLAN%cTE %s %c",0x02,0xD4,p.nom,0x02);
    Color(15,0);
    printf("\n                          Propri%ct%cre : %s",0x82,0x8A,p.proprio);
    printf("\n                          Prix d'achat : %d",p.prix);
    printf("\n                          Prix loyer actuel : %d",p.loyer);
    printf("\n                          Prix hypoth%cquaire : %d",0x82,p.p_hypo);
    if (p.p_hypo == 4){
        p.maison = 0;
        p.hotel = 1;
        printf("\n                          Nombre d'hotel : %d",p.hotel);
    }
    printf("\n                          Nombre de maisons : %d",p.maison);

}

///AFFICHAGE DE L'ARRIVEE SUR LES ETOILES
void arrivetoi (etoile e){
    Color(3,0);
    printf("\n\n%cIA : Nous sommes arriv%cs sur une nouvelle %ctoile...%s !",0x10,0x82,0x82,e.nom);
    printf("\n%cIA : %s",0x10,e.anecdote);
    printf("\n%cIA : Voici un r%capitulatif capitaine...",0x10,0x82);
    Color(15,0);
    printf("\n\n                                                         ");
    Color(0,14);
    printf("%c %cTOILE %s %c",0x0f,0x90,e.nom,0x0f);
    Color(15,0);
    printf("\n                          Propri%ct%cre : %s",0x82,0x8A,e.proprio);
    printf("\n                          Prix d'achat : %d",e.prix);
    printf("\n                          Prix loyer actuel : %d",e.loyer);
    printf("\n                          Prix hypoth%cquaire : %d",0x82,e.p_hypo);

}


///PROCEDURES DES PLANETES
void mars (){
    planete mars = {"", "", "", 0, 0, 0, 0 , 0} ;
    mars.prix = 300;
    char noms [] = "MARS";
    strcpy (mars.nom ,noms);
    char anecdotes [] = "La 1re personne a avoir observe Mars au telescope fut l'astronome Galilee.Ce n'est qu'avec l'envoi de la premiere sonde autour de Mars, en 1965, qu on a su que les planete etait inhabitee." ;
    strcpy (mars.anecdote , anecdotes);
    mars.loyer = 80;
    mars.p_hypo = 150;
    mars.couleur = 5;
    arrivplan(mars);
}
void terre (){
    planete terre = {"", "", "", 0, 0, 0, 0 , 0} ;
    terre.prix = 500;
    char noms [] = "TERRE";
    strcpy (terre.nom ,noms);
    char anecdotes [] = "Nous somme de retour chez nous ! Notre belle planete bleu mere porteuse de la vie humaine...";
    strcpy (terre.anecdote , anecdotes);
    terre.loyer = 160;
    terre.p_hypo = 250;
    terre.couleur = 5;
    arrivplan(terre);
}

void saturne (){
    planete saturne = {"", "", "", 0, 0, 0, 0 , 0} ;
    saturne.prix = 400;
    char noms [] = "SATURNE";
    strcpy (saturne.nom ,noms);
    char anecdotes [] = "Saturne, deuxieme plus grande planete du systeme solaire apres Jupiter, a une masse volumique moyenne bien inferieure a celle de l eau (0,69 g/cm3).\nCette particularite physique etonnante signifie que si l on disposait d'une immense baignoire sur laquelle on pouvait la poser, elle y flotterait.";
    strcpy (saturne.anecdote , anecdotes);
    saturne.loyer = 120;
    saturne.p_hypo = 200;
    saturne.couleur = 13;
    arrivplan(saturne);
}

void jupiter (){
    planete jupiter = {"", "", "", 0, 0, 0, 0 , 0} ;
    jupiter.prix = 800;
    char noms [] = "JUPITER";
    strcpy (jupiter.nom ,noms);
    char anecdotes [] = "Jupiter est la plus grande du systeme solaire. Son diametre est dix fois celui de la Terre et son volume est tel qu'il pourrait contenir 1 321 Terre.\nIl y a des tempetes et des cyclones sur Jupiter qui sont plus grandes que notre planete entiere.";
    strcpy (jupiter.anecdote , anecdotes);
    jupiter.loyer = 240;
    jupiter.p_hypo = 400;
    jupiter.couleur = 13;
    arrivplan(jupiter);
}
void venus (){
    planete venus = {"", "", "", 0, 0, 0, 0 , 0} ;
    venus.prix = 150;
    char noms [] = "VENUS";
    strcpy (venus.nom ,noms);
    char anecdotes [] = "Avec une moyenne de 462 C, Venus possede en surface la temperature la plus elevee du Systeme solaire, alors qu'elle n est que la deuxieme planete la plus proche du Soleil.";
    strcpy (venus.anecdote , anecdotes);
    venus.loyer = 50;
    venus.p_hypo = 80;
    venus.couleur = 13;
    arrivplan(venus);
}

void soleil (){
    etoile soleil = {"", "", "", 0, 0, 0};
    soleil.prix = 200;
    char noms [] = "SOLEIL";
    strcpy (soleil.nom ,noms);
    char anecdotes [] = "Dans environ cinq milliards d'annees, le Soleil gonflera pour devenir une geante rouge, avalant du même coup les planètes Mercure, Venus, la Terre et Mars.";
    strcpy (soleil.anecdote , anecdotes);
    soleil.loyer = 40;
    soleil.p_hypo = 100;
    arrivetoi(soleil);
}
