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


int choix = 1;
player[0]->numeroCase = 1;
player[1]->numeroCase = 1;
player[2]->numeroCase = 1;
player[3]->numeroCase = 1;
while(choix != 0)
{

    switch(deplacement)
    {
        case 1:
        {
            case1();
            player[tourJoueur]->numeroCase = 1;
            break;
        }
        case 2:
        {
            case2(lune_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 2;
            break;
        }
        case 3:
        {
            case3(terre_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 3;

            break;
        }
        case 4:
        {
            case4();
            player[tourJoueur]->numeroCase = 4;
            break;
        }
        case 5:
        {
            case5(voieLactee_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 5;
            break;
        }
        case 6:
        {
            case6(phobos_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 6;
            break;
        }
        case 7:
        {
            case7(mars_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 7;
            break;
        }
        case 8:
        {
            case8();
            player[tourJoueur]->numeroCase = 8;
            break;
        }
        case 9:
        {
            case9(ganymede_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 9;
            break;
        }
        case 10:
        {
            case10(callisto_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 10;
            break;
        }
        case 11:
        {
            case11(andromede_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 11;
            break;
        }
        case 12:
        {
            case12(io_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 12;
            break;
        }
        case 13:
        {
            case13(jupiter_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 13;
            break;
        }
        case 14:
        {
            case14();
            player[tourJoueur]->numeroCase = 14;
            break;
        }
        case 15:
        {
            case15();
            player[tourJoueur]->numeroCase = 15;
            break;
        }
        case 16:
        {
            case16(titan_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 16;
            break;
        }
        case 17:
        {
            case17(saturne_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 17;
            break;
        }
        case 18:
        {
            case18(tetard_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 18;
            break;
        }
        case 19:
        {
            case19(pluton_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 19;
            break;
        }
        case 20:
        {
            case20(neptune_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 20;
            break;
        }
        case 21:
        {
            case21();
            player[tourJoueur]->numeroCase = 21;
            break;
        }
        case 22:
        {
            case22();
            player[tourJoueur]->numeroCase = 22;
            break;
        }
        case 23:
        {
            case23(venus_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 23;
            break;
        }
        case 24:
        {
            case24(uranus_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 24;
            break;
        }
        case 25:
        {
            case25(nuageDeMagellan_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 25;
            break;
        }
        case 26:
        {
            case26(mercure_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 26;
            break;
        }
        case 27:
        {
            case27(soleil_,player,tourJoueur);
            player[tourJoueur]->numeroCase = 27;
            break;
        }
        case 28:
        {
            case28();
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
