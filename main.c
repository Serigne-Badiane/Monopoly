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

void pause()
{
    char pause=kbhit('p');
    pause=getch();
    if(pause=='p')
    {
        menu1();
    }
}

int main()
{
    srand(time(NULL));
    t_joueur player[NbJoueurMax][TAILLE];
    satellite lune_ = {0, "","",0,0,0,0,0,0,0};
    planete terre_={0, "","",0,0,0,0,0,0,0};
    galaxie voieLactee_ = {0, "","",0,0,0,0,0,0};
    satellite phobos_={0, "","",0,0,0,0,0,0,0};
    planete mars_= {0, "","",0,0,0,0,0,0,0};
    satellite ganymede_= {0, "","",0,0,0,0,0,0,0};
    satellite callisto_ = {0, "","",0,0,0,0,0,0,0};
    galaxie andromede_ = {0,"","",0,0,0,0,0,0};
    satellite io_ = {0, "","",0,0,0,0,0,0,0};
    planete jupiter_ = {0, "", "", 0, 0, 0, 0 , 0,0,0};
    satellite titan_ = {0, "","",0,0,0,0,0,0,0};
    planete saturne_ = {0, "", "", 0, 0, 0, 0 , 0, 0} ;
    galaxie tetard_= {0,"","",0,0,0,0,0,0};
    planete pluton_ = {0, "", "", 0, 0, 0, 0 , 0, 0} ;
    planete neptune_ = {0, "", "", 0, 0, 0, 0 , 0, 0} ;
    planete venus_ = {0, "", "", 0, 0, 0, 0 , 0} ;
    planete uranus_ = {0, "", "", 0, 0, 0, 0 , 0} ;
    galaxie nuageDeMagellan_ = {0,"","",0,0,0,0,0,0};
    planete mercure_ = {0, "", "", 0, 0, 0, 0 , 0} ;
    planete soleil_ = {0, "", "", 0, 0, 0};


    int nombreJoueur = 0;
    int tourJoueur = 0;
    int deplacement = 0;
    menu1(&nombreJoueur, &deplacement, &tourJoueur, player);
    deplacement += 1;



    mars(&mars_);
    terre(&terre_);
    voieLactee(&voieLactee_);
    lune(&lune_);
    phobos(&phobos_);
    ganymede(&ganymede_);
    callisto(&callisto_);
    andromede(&andromede_);
    io(&io_);
    jupiter(&jupiter_);
    titan(&titan_);
    saturne(&saturne_);
    tetard(&tetard_);
    pluton(&pluton_);
    neptune(&neptune_);
    venus(&venus_);
    uranus(&uranus_);
    nuageDeMagellan(&nuageDeMagellan_);
    mercure(&mercure_);
    soleil(&soleil_);



player[0]->numeroCase = 1;
player[1]->numeroCase = 1;
player[2]->numeroCase = 1;
player[3]->numeroCase = 1;

int choix = 1;

while(choix != 0)
{

    switch(deplacement)
    {
        case 1:
        {
            printf("BONJOUR");
            player[tourJoueur]->numeroCase = 1;
            break;
        }
        case 2:
        {
            arrivsat(&lune_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 2;
            break;
        }
        case 3:
        {
            arrivplan(&terre_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 3;
            break;
        }
        case 4:
        {
            player[tourJoueur]->argent -= 200;
            printf("\nIA : Vous devez payer 200 euros pour les taxes !\n");
            Color(player[tourJoueur]->couleur, 0);
            printf("%s, votre porte monnaie est de : %d\n", player[tourJoueur]->prenomJoueur, player[tourJoueur]->argent);
            player[tourJoueur]->numeroCase = 4;
            break;
        }
        case 5:
        {
            arrivgalax(&voieLactee_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 5;
            break;
        }
        case 6:
        {
            arrivsat(&phobos_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 6;
            break;
        }
        case 7:
        {
            arrivplan(&mars_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 7;
            break;
        }
        case 8:
        {
            printf("\nIA : Vous allez directement en prison !\n");
            player[tourJoueur]->numeroCase = 8;
            break;
        }
        case 9:
        {
            arrivsat(&ganymede_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 9;
            break;
        }
        case 10:
        {
            arrivsat(&callisto_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 10;
            break;
        }
        case 11:
        {
            arrivgalax(&andromede_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 11;
            break;
        }
        case 12:
        {
            arrivsat(&io_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 12;
            break;
        }
        case 13:
        {
            arrivplan(&jupiter_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 13;
            break;
        }
        case 14:
        {
            printf("\nVous êtes sur le parking, reposez-vous !\n");
            player[tourJoueur]->numeroCase = 14;
            break;
        }
        case 15:
        {
            printf("BONJOUR");
            player[tourJoueur]->numeroCase = 15;
            break;
        }
        case 16:
        {

            echange(nombreJoueur,player,tourJoueur);
            arrivsat(&titan_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 16;
            break;
        }
        case 17:
        {
            echange(nombreJoueur,player,tourJoueur);
            arrivplan(&saturne_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 17;
            break;
        }
        case 18:
        {
            echange(nombreJoueur,player,tourJoueur);
            arrivgalax(&tetard_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 18;
            break;
        }
        case 19:
        {
            echange(nombreJoueur,player,tourJoueur);
            arrivsat(&pluton_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 19;
            break;
        }
        case 20:
        {
            echange(nombreJoueur,player,tourJoueur);
            arrivplan(&neptune_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 29;
            break;
        }
        case 21:
        {
            printf("BONJOUR");
            player[tourJoueur]->numeroCase = 21;
            break;
        }
        case 22:
        {
            printf("BONJOUR");
            player[tourJoueur]->numeroCase = 22;
            break;
        }
        case 23:
        {
            arrivplan(&venus_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 23;
            break;
        }
        case 24:
        {
            arrivplan(&uranus_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 24;
            break;
        }
        case 25:
        {
            arrivgalax(&nuageDeMagellan_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 25;
            break;
        }
        case 26:
        {
            arrivplan(&mercure_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 26;
            break;
        }
        case 27:
        {
            arrivplan(&mercure_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 27;
            break;
        }
        case 28:
        {
            printf("BONJOUR");
            player[tourJoueur]->numeroCase = 28;
            break;
        }
    }

    tourJoueur += 1;
    if (tourJoueur == nombreJoueur  )
    {
        tourJoueur = 0;
    }
    Color(3,0);
    printf(" IA : %s, veuillez appuyer sur 1 pour lancer le de : ", player[tourJoueur]->prenomJoueur);
    scanf("%d", &choix);
    while(choix != 1 && choix != 0){
        printf("\nIA : Je n'ai compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
        scanf("%s");
        scanf("%d",&choix);
    }



    int numeroDe[2];
    int deplacement2 = 0;
    int deplacement3 = 0;
    int deplacement1 = 0;

    if (choix == 1)
    {
        deplacement1 = lancerDe(player, numeroDe, tourJoueur);
        if(numeroDe[1] == numeroDe[0])
        {
            deplacement2 = lancerDe(player, numeroDe, tourJoueur);
            if(numeroDe[1] == numeroDe[0])
            {
                deplacement3 = lancerDe(player, numeroDe, tourJoueur);
                if(numeroDe[1] == numeroDe[0])
                {
                    printf("IA : Vous allez en prison !");

                }
            }

        }
        deplacement = deplacement1 + deplacement2 + deplacement3;
        printf("%s avance de %d cases.\n", player[tourJoueur]->prenomJoueur, deplacement);

        deplacement += player[tourJoueur]->numeroCase;
        if (deplacement >= 28)
        {
            deplacement = deplacement - 28;
            player[tourJoueur]->argent += 200;
        }

    }






}
    return 0;
}
