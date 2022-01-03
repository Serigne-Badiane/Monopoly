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

void gotoligcol( int lig, int col )
{

COORD mycoord;

mycoord.X = col;

mycoord.Y = lig;

SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

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

void plateau()
{
    ///premiere ligne de case
    for(int i;i<8;i++)
    {
    printf(" ______ ");
    }
    printf("\n");

    for(int i=0;i<2;i++)
    {
    for(int k=0;k<8;k++)
    {
        printf("|      |");
    }
    printf("\n");
    if (i==1)
    {
        for(int j=0;j<8;j++)
            {
            printf("|______|");
            }
    }
    }
    printf("\n");


    //||||||||||||||||||||||||||||||||||||||||||||||||||||

    /// toutes les lignes de case du milieu appart l'avant dernière
    for (int i=0;i<5;i++)
    {
    for (int i=0;i<2;i++)
    {
    printf("|      |");
    for(int i=0;i<6;i++)
    {
        printf("        ");
    }
    printf("|      |\n");
    }
    printf("|______|");
    for(int i=0;i<6;i++)
    {
        printf("        ");
    }
    printf("|______|\n");
    }




    ///avant derniere ligne de case

    for (int i=0;i<2;i++)
    {
    printf("|      |");
    for(int i=0;i<6;i++)
    {
        printf("        ");
    }
    printf("|      |\n");
    }
    printf("|______|");
    for(int i=0;i<6;i++)
    {
        printf(" ______ ");
    }
    printf("|______|\n");




    //||||||||||||||||||||||||-


    /*printf("        ");
    for(int i;i<6;i++)
    {
    printf(" ______ ");
    }
    printf("        ");
    printf("\n");*/


    ///derniere ligne de case
    for(int i=0;i<2;i++)
    {
    for(int k=0;k<8;k++)
    {
        printf("|      |");
    }
    printf("\n");
    if (i==1)
    {
        for(int j=0;j<8;j++)
            {
            printf("|______|");
            }
    }
    }
    printf("\n");



    gotoligcol(2,1);
    printf("DEPART");
    gotoligcol(3,3);
    Color(4,0);
    printf("%c",0x1A);

    Color(6,0);
    gotoligcol(3,9);
    printf("LUNE");
    Color(15,0);
    printf("%c",0xB8);

    Color(6,0);
    gotoligcol(3,17);
    printf("TERRE");

    Color(15,0);
    gotoligcol(3,25);
    printf("TAXE%c",0x24);

    Color(0,15);
    gotoligcol(2,33);
    printf("VOIE  ");
    gotoligcol(3,33);
    printf("LACTEE");

    Color(11,0);
    gotoligcol(3,41);
    printf("PHOBOS");

    gotoligcol(3,50);
    printf("MARS");

    Color(15,0);
    gotoligcol(2,59);
    printf("GO");
    gotoligcol(3,57);
    printf("PRISON");
    gotoligcol(4,59);
    Color(6,0);
    printf("%c%c",0xB2,0xB2);

    ///2ème ligne
    gotoligcol(6,1);
    printf("CHANCE");
    Color(13,0);
    gotoligcol(6,57);
    printf("GARYME");
    ///3ème ligne
    Color(14,0);
    gotoligcol(8,3);
    printf("%c",0x0F);
    Color(9,0);
    gotoligcol(9,1);
    printf("SOLEIL");
    Color(13,0);
    gotoligcol(9,57);
    printf("CALLIS");
    ///4ème ligne
    Color(9,0);
    gotoligcol(12,1);
    printf("MERCUR");
    Color(0,15);
    gotoligcol(11,57);
    printf("ANDRO ");
    gotoligcol(12,57);
    printf(" MEDE ");
    ///5ème ligne
    Color(0,15);
    gotoligcol(14,1);
    printf("NUAGE ");
    gotoligcol(15,1);
    printf("MAGELA");
    Color(6,0);
    gotoligcol(15,59);
    printf("IO");
    ///6ème ligne
    Color(2,0);
    gotoligcol(18,1);
    printf("URANUS");
    Color(6,0);
    gotoligcol(17,58);
    printf("JUPI");
    gotoligcol(18,58);
    printf("TER");
    ///7ème ligne
    Color(2,0);
    gotoligcol(21,1);
    printf("VENUS");
    Color(1,0);
    gotoligcol(20,57);
    printf("COMMU");
    gotoligcol(21,57);
    printf("NNOTE");
    ///8ème ligne
    Color(9,0);
    gotoligcol(24,1);
    printf("PRISON");
    gotoligcol(25,3);
    Color(6,0);
    printf("%c%c",0xB2,0xB2);

    Color(1,0);
    gotoligcol(23,9);
    printf("COMMU");
    gotoligcol(24,9);
    printf("NNOTE");

    Color(14,0);
    gotoligcol(23,18);
    printf("NEP");
    gotoligcol(24,18);
    printf("TUNE");

    gotoligcol(24,25);
    printf("PLUTON");

    Color(0,15);
    gotoligcol(23,33);
    printf("VOIE  ");
    gotoligcol(24,33);
    printf("TETARD");

    Color(4,0);
    gotoligcol(23,42);
    printf("SAT");
    gotoligcol(24,42);
    printf("URNE");

    gotoligcol(24,49);
    printf("TITAN");

    Color(12,0);
    gotoligcol(23,58);
    printf("PAR");
    gotoligcol(24,58);
    printf("KING");



    Color(15,0);
    gotoligcol(30,0);
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

            arrivsat(&titan_, player, tourJoueur);
            echange(nombreJoueur,player,tourJoueur);
            player[tourJoueur]->numeroCase = 16;
            break;
        }
        case 17:
        {
            arrivplan(&saturne_, player, tourJoueur);
            echange(nombreJoueur,player,tourJoueur);
            player[tourJoueur]->numeroCase = 17;
            break;
        }
        case 18:
        {
            arrivgalax(&tetard_, player, tourJoueur);
            echange(nombreJoueur,player,tourJoueur);
            player[tourJoueur]->numeroCase = 18;
            break;
        }
        case 19:
        {
            arrivsat(&pluton_, player, tourJoueur);
            echange(nombreJoueur,player,tourJoueur);
            player[tourJoueur]->numeroCase = 19;
            break;
        }
        case 20:
        {
            arrivplan(&neptune_, player, tourJoueur);
            echange(nombreJoueur,player,tourJoueur);
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
    pause();
    scanf("%d", &choix);
    while(choix != 1 && choix != 0){
        printf("\nIA : Je n'ai compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
        fflush(stdin);
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
