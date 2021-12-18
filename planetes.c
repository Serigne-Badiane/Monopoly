#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 200
#include "bib.h"



///AFFICHAGE DE L'ARRIVEE SUR LES PLANETES
void arrivplan (planete* p,t_joueur player[NbJoueurMax][TAILLE],int tourjoueur){
    Color(3,0);
    printf("\n\n%cIA : Nous sommes arriv%cs sur une nouvelle plan%cte... La plan%cte %s !",0x10,0x82,0x8A,0x8A,p->nom);
    if (p->proprio == player[0]->numeroJoueur || p->proprio == player[1]->numeroJoueur || p->proprio == player[2]->numeroJoueur || p->proprio == player[3]->numeroJoueur){
        Color(3,0);
        printf("\nIA : La planete appartient a ",player[p->proprio - 1]->prenomJoueur);
        Color(player[p->proprio - 1]->couleurJoueur,0);
        printf("%s",player[p->proprio - 1]->prenomJoueur);
        Color(3,0);
        printf("... Vous devez lui payer son loyer !");
        player[tourjoueur]->argent -= p->loyer;
        player[p->proprio - 1]->argent += p->loyer;
        Color(player[tourjoueur]->couleurJoueur,0);
        printf("\n%s",player[tourjoueur]->prenomJoueur);
        Color(3,0);
        printf(" paye a ");
        Color(player[p->proprio - 1]->couleurJoueur,0);
        printf("%s",player[p->proprio - 1]->prenomJoueur);
        Color(3,0);
        printf(" %d euros...",p->loyer);

    }
    else{
        Color(3,0);
        printf("\n%cIA : %s",0x10,p->anecdote);
        printf("\n%cIA : Voici un r%ccapitulatif capitaine...",0x10,0x82);
        printf("\n\n                                                        ");
        Color(0,p->couleur);
        printf("%c PLAN%cTE %s %c",0x02,0xD4,p->nom,0x02);
        Color(15,0);
        printf("\n                          Prix d'achat : %d",p->prix);
        printf("\n                          Prix loyer actuel : %d",p->loyer);
        printf("\n                          Prix hypoth%cquaire : %d",0x82,p->p_hypo);
        if (p->p_hypo == 4){
            p->maison = 0;
            p->hotel = 1;
            printf("\n                          Nombre d'hotel : %d",p->hotel);
        }
        printf("\n                          Nombre de maisons : %d",p->maison);
        Color(3,0);
        printf("\nIA : La planete est libre d'achat, souhaitez-vous l'acheter ?\n ");
        printf("                      ");
        Color(10,0);
        printf("1.OUI");
        printf("                      ");
        Color(12,0);
        printf("2.NON\n");
        Color(15,0);
        int answer;
        scanf("%d",&answer);
        while( answer != 1 && answer != 2){
            printf("IA : Saisie incorrect\n");
            getchar();
            scanf("%d",&answer);
        }
        Color(3,0);
        if ( answer == 1){
            p->proprio = player[tourjoueur]->numeroJoueur;
            strcat(player[tourjoueur]->proprietes,p->nom);
            strcat(player[tourjoueur]->proprietes,",");
            printf("IA : BRAVO %s! Vous avez aquis une nouvelle planete ...",player[tourjoueur]->prenomJoueur);
            printf("%s",player[tourjoueur]->proprietes);
        }
        else {
            printf("IA : Fin de tour ...");
        }
    }
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
void mars (planete* p){
    p->prix = 300;
    p->proprio = 5;
    char noms [] = "MARS";
    strcpy (p->nom ,noms);
    char anecdotes [] = "La 1re personne a avoir observe Mars au telescope fut l'astronome Galilee.Ce n'est qu'avec l'envoi de la premiere sonde autour de Mars, en 1965, qu on a su que les planete etait inhabitee." ;
    strcpy (p->anecdote , anecdotes);
    p->loyer = 80;
    p->p_hypo = 150;
    p->couleur = 5;

}
void terre (planete* terre){
    terre->prix = 500;
    char noms [] = "TERRE";
    strcpy (terre->nom ,noms);
    char anecdotes [] = "Nous somme de retour chez nous ! Notre belle planete bleu mere porteuse de la vie humaine...";
    strcpy (terre->anecdote , anecdotes);
    terre->loyer = 160;
    terre->p_hypo = 250;
    terre->couleur = 5;

}

void saturne (planete* saturne){

    saturne->prix = 400;
    char noms [] = "SATURNE";
    strcpy (saturne->nom ,noms);
    char anecdotes [] = "Saturne, deuxieme plus grande planete du systeme solaire apres Jupiter, a une masse volumique moyenne bien inferieure a celle de l eau (0,69 g/cm3).\nCette particularite physique etonnante signifie que si l on disposait d'une immense baignoire sur laquelle on pouvait la poser, elle y flotterait.";
    strcpy (saturne->anecdote , anecdotes);
    saturne->loyer = 120;
    saturne->p_hypo = 200;
    saturne->couleur = 13;

}

void jupiter (planete* jupiter){

    jupiter->prix = 800;
    char noms [] = "JUPITER";
    strcpy (jupiter->nom ,noms);
    char anecdotes [] = "Jupiter est la plus grande du systeme solaire. Son diametre est dix fois celui de la Terre et son volume est tel qu'il pourrait contenir 1 321 Terre.\nIl y a des tempetes et des cyclones sur Jupiter qui sont plus grandes que notre planete entiere.";
    strcpy (jupiter->anecdote , anecdotes);
    jupiter->loyer = 240;
    jupiter->p_hypo = 400;
    jupiter->couleur = 13;

}
void venus (planete* venus){

    venus->prix = 150;
    char noms [] = "VENUS";
    strcpy (venus->nom ,noms);
    char anecdotes [] = "Avec une moyenne de 462 C, Venus possede en surface la temperature la plus elevee du Systeme solaire, alors qu'elle n est que la deuxieme planete la plus proche du Soleil.";
    strcpy (venus->anecdote , anecdotes);
    venus->loyer = 50;
    venus->p_hypo = 80;
    venus->couleur = 13;

}


