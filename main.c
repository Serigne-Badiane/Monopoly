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




    switch(deplacement)
    {
        case 1:
        {
            case1();
            break;
        }

        case 2:
        {
            case2(lune_,player,tourJoueur);
            break;
        }
        case 3:
        {
            case3(terre_,player,tourJoueur);
            break;
        }
        case 4:
        {
            case4();
            break;
        }
        case 5:
        {
            case5(voieLactee_,player,tourJoueur);
            break;
        }
        case 6:
        {
            case6(phobos_,player,tourJoueur);
            break;
        }
        case 7:
        {
            case7(mars_,player,tourJoueur);
            break;
        }
        case 8:
        {
            case8();
            break;
        }
        case 9:
        {
            case9(ganymede_,player,tourJoueur);
            break;
        }
        case 10:
        {
            case10(callisto_,player,tourJoueur);
            break;
        }
        case 11:
        {
            case11(andromede_,player,tourJoueur);
            break;
        }
        case 12:
        {
            case12(io_,player,tourJoueur);
            break;
        }
        case 13:
        {
            case13(jupiter_,player,tourJoueur);
            break;
        }
        case 14:
        {
            case14();
            break;
        }
        case 15:
        {
            case15();
            break;
        }
        case 16:
        {
            case16(titan_,player,tourJoueur);
            break;
        }
        case 17:
        {
            case17(saturne_,player,tourJoueur);
            break;
        }
        case 18:
        {
            case18(tetard_,player,tourJoueur);
            break;
        }
        case 19:
        {
            case19(pluton_,player,tourJoueur);
            break;
        }
        case 20:
        {
            case20(neptune_,player,tourJoueur);
            break;
        }
        case 21:
        {
            case21();
            break;
        }
        case 22:
        {
            case22();
            break;
        }
        case 23:
        {
            case23(venus_,player,tourJoueur);
            break;
        }
        case 24:
        {
            case24(uranus_,player,tourJoueur);
            break;
        }
        case 25:
        {
            case25(nuageDeMagellan_,player,tourJoueur);
            break;
        }
        case 26:
        {
            case26(mercure_,player,tourJoueur);
            break;
        }
        case 27:
        {
            case27(soleil_,player,tourJoueur);
            break;
        }
        case 28:
        {
            case28();
            break;
        }
    }






    return 0;
}
