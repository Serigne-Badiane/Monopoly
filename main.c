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
    printf("\n");
    ///premiere ligne de case
    for(int i;i<8;i++)
    {
    printf(" __________ ");
    }
    printf("\n");

    for(int i=0;i<3;i++)
    {
        for(int k=0;k<8;k++)
        {
            printf("|          |");
        }
        printf("\n");
        if (i==2)
        {
            for(int j=0;j<8;j++)
                {
                printf("|__________|");
                }
        }
    }
    printf("\n");


    //||||||||||||||||||||||||||||||||||||||||||||||||||||

    /// toutes les lignes de case du milieu appart l'avant dernière
    for (int i=0;i<5;i++)
    {
        for (int i=0;i<3;i++)
        {
            printf("|          |");
            for(int i=0;i<9;i++)
            {
                printf("        ");
            }
            printf("|          |\n");
        }
        printf("|__________|");
        for(int i=0;i<8;i++)
        {
            printf("         ");
        }
        printf("|__________|\n");
    }




    ///avant derniere ligne de case

    for (int i=0;i<3;i++)
    {
        printf("|          |");
        for(int i=0;i<6;i++)
        {
            printf("            ");
        }
        printf("|          |\n");
    }
    printf("|__________|");
    for(int i=0;i<6;i++)
    {
        printf(" __________ ");
    }
    printf("|__________|\n");




    //||||||||||||||||||||||||-


    /*printf("        ");
    for(int i;i<6;i++)
    {
    printf(" ______ ");
    }
    printf("        ");
    printf("\n");*/


    ///derniere ligne de case
 for(int i=0;i<3;i++)
    {
        for(int k=0;k<8;k++)
        {
            printf("|          |");
        }
        printf("\n");
        if (i==2)
        {
            for(int j=0;j<8;j++)
                {
                printf("|__________|");
                }
        }
    }
    printf("\n");



    Color(0,15);
    gotoligcol(2,1);
    printf("          ");
    gotoligcol(3,1);
    printf("          ");
    gotoligcol(4,1);
    printf("          ");
    gotoligcol(2,3);
    printf("DEPART");
    gotoligcol(3,5);
    Color(4,15);
    printf("%c",0x1A);

    Color(0,5);
    gotoligcol(2,13);
    printf("          ");
    gotoligcol(2,16);
    Color(0,5);
    printf("LUNE");

    Color(0,5);
    gotoligcol(2,25);
    printf("          ");
    gotoligcol(2,27);
    Color(0,5);
    printf("TERRE");

    Color(0,8);
    gotoligcol(2,37);
    printf("          ");
    gotoligcol(3,37);
    printf("          ");
    gotoligcol(4,37);
    printf("          ");
    gotoligcol(2,39);
    printf("TAXE%c",0x24);

    Color(0,15);
    gotoligcol(2,49);
    printf("          ");
    gotoligcol(3,49);
    printf("          ");
    gotoligcol(2,52);
    printf("VOIE");
    gotoligcol(3,51);
    printf("LACTEE");

    Color(0,11);
    gotoligcol(2,61);
    printf("          ");
    Color(0,11);
    gotoligcol(2,63);
    printf("PHOBOS");

    Color(0,11);
    gotoligcol(2,73);
    printf("          ");
    gotoligcol(2,76);
    Color(0,11);
    printf("MARS");

    Color(15,0);
    gotoligcol(2,89);
    printf("GO");
    gotoligcol(3,87);
    printf("PRISON");
    gotoligcol(4,85);
    Color(6,0);
    gotoligcol(2,85);
    printf("%c%c%c",0xB2,0xB2,0xB2);
    gotoligcol(3,85);
    printf("%c%",0xB2);
    gotoligcol(4,85);
    printf("%c%",0xB2);
    gotoligcol(2,93);
    printf("%c",0xB2);
    gotoligcol(2,94);
    printf("%c",0xB2);
    gotoligcol(5,85);
    printf("%c%c%c%c%c%c%c%c%c",0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2,0xB2);
    gotoligcol(4,94);
    printf("%c",0xB2);
    gotoligcol(3,94);
    printf("%c",0xB2);
    gotoligcol(5,94);
    printf("%c",0xB2);

    ///2ème ligne
    Color(0,6);
    gotoligcol(6,1);
    printf("          ");
    gotoligcol(7,1);
    printf("          ");
    gotoligcol(8,1);
    printf("          ");
    gotoligcol(7,3);
    printf("CHANCE");
    Color(0,13);
    gotoligcol(6,85);
    printf("          ");
    gotoligcol(6,86);
    Color(0,13);
    printf("GANYMEDE");
    ///3ème ligne
    Color(0,9);
    gotoligcol(10,1);
    printf("          ");
    gotoligcol(10,3);
    Color(0,9);
    printf("SOLEIL");
    Color(0,13);
    gotoligcol(10,85);
    printf("          ");
    gotoligcol(10,86);
    Color(0,13);
    printf("CALLISTO");
    ///4ème ligne
    Color(0,9);
    gotoligcol(14,1);
    printf("          ");
    Color(0,9);
    gotoligcol(14,3);
    printf("MERCURE");
    Color(0,15);

    gotoligcol(14,85);
    printf("ANDROMEDE ");
    gotoligcol(15,85);
    printf("          ");


    ///5ème ligne
    Color(0,15);
    gotoligcol(18,1);
    printf("          ");
    gotoligcol(18,2);
    printf("NUAGE DE");
    gotoligcol(19,1);
    printf("          ");
    gotoligcol(19,3);
    printf("MAGELAN");
    Color(0,6);
    gotoligcol(18,85);
    printf("          ");
    gotoligcol(18,89);
    Color(0,6);
    printf("IO");
    ///6ème ligne
    Color(0,2);
    gotoligcol(22,1);
    printf("          ");
    Color(0,2);
    gotoligcol(22,3);
    printf("URANUS");
    Color(0,6);
    gotoligcol(22,85);
    printf("          ");
    Color(0,6);
    gotoligcol(22,87);
    printf("JUPITER");
    ///7ème ligne
    Color(0,2);
    gotoligcol(26,1);
    printf("          ");
    Color(0,2);
    gotoligcol(26,3);
    printf("VENUS");
    Color(0,1);
    gotoligcol(26,85);
    printf("          ");
    gotoligcol(27,85);
    printf("          ");
    gotoligcol(28,85);
    printf("          ");
    Color(0,1);
    gotoligcol(27,85);
    printf("COMMUNAUTE");
    ///8ème ligne
    Color(0,9);
    gotoligcol(30,3);
    printf("PRISON");
    gotoligcol(31,5);
    Color(6,0);
    printf("%c%c",0xB2,0xB2);

    Color(0,1);
    gotoligcol(30,13);
    printf("          ");
    gotoligcol(31,13);
    printf("          ");
    gotoligcol(32,13);
    printf("          ");
    gotoligcol(31,13);
    Color(0,1);
    printf("COMMUNAUTE");

    Color(0,14);
    gotoligcol(30,25);
    printf("          ");
    Color(0,14);
    gotoligcol(30,27);
    printf("NEPTUNE");

    Color(0,14);
    gotoligcol(30,37);
    printf("          ");
    Color(0,14);
    gotoligcol(30,39);
    printf("PLUTON");

    Color(0,15);
    gotoligcol(30,49);
    printf("          ");
    gotoligcol(30,52);
    printf("VOIE");
    gotoligcol(31,49);
    printf("          ");
    gotoligcol(31,51);
    printf("TETARD");

    Color(0,4);
    gotoligcol(30,61);
    printf("          ");
    Color(0,4);
    gotoligcol(30,63);
    printf("SATURNE");

    Color(0,4);
    gotoligcol(30,73);
    printf("          ");
    Color(0,4);
    gotoligcol(30,75);
    printf("TITAN");

    Color(0,12);
    gotoligcol(30,85);
    printf("          ");
    gotoligcol(31,85);
    printf("          ");
    gotoligcol(32,85);
    printf("          ");
    Color(0,12);
    gotoligcol(31,87);
    printf("PARKING");



    Color(15,0);
    gotoligcol(35,0);
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
int numeroDe[2];
int deplacement2 = 0;
int deplacement3 = 0;
int deplacement1 = 0;


while(choix != 0)
{
    system("cls");
    Color(15,0);
    plateau();




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

            gotoligcol(4,17);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivsat(&lune_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 2;
            break;
        }
        case 3:
        {

            gotoligcol(4,27);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&terre_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 3;
            break;
        }
        case 4:
        {


            gotoligcol(4,37);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            player[tourJoueur]->argent -= 200;
            printf("\nIA : Vous devez payer 200 euros pour les taxes !\n");
            Color(player[tourJoueur]->couleur, 0);
            printf("%s, votre porte monnaie est de : %d\n", player[tourJoueur]->prenomJoueur, player[tourJoueur]->argent);
            player[tourJoueur]->numeroCase = 4;
            break;
        }
        case 5:
        {

            gotoligcol(4,49);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivgalax(&voieLactee_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 5;
            break;
        }
        case 6:
        {

            gotoligcol(4,61);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivsat(&phobos_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 6;
            break;
        }
        case 7:
        {

            gotoligcol(4,76);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&mars_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 7;
            break;
        }
        case 8:
        {

            gotoligcol(4,87);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            printf("\nIA : Vous allez directement en prison !\n");
            player[tourJoueur]->numeroCase = 8;
            break;
        }
        case 9:
        {

            gotoligcol(8,87);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivsat(&ganymede_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 9;
            break;
        }
        case 10:
        {

            gotoligcol(12,87);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivsat(&callisto_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 10;
            break;
        }
        case 11:
        {

            gotoligcol(16,87);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivgalax(&andromede_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 11;
            break;
        }
        case 12:
        {

            gotoligcol(20,87);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivsat(&io_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 12;
            break;
        }
        case 13:
        {

            gotoligcol(24,87);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&jupiter_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 13;
            break;
        }
        case 14:
        {

            gotoligcol(30,87);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            printf("BONJOUR");

            player[tourJoueur]->numeroCase = 14;
            break;
        }
        case 15:
        {

            gotoligcol(34,87);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            printf("\nVous etes sur le parking, reposez-vous !\n");
            player[tourJoueur]->numeroCase = 15;
            break;
        }
        case 16:
        {

            gotoligcol(33,63);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivsat(&titan_, player, tourJoueur);
            echange(nombreJoueur,player,tourJoueur);
            player[tourJoueur]->numeroCase = 16;
            break;
        }
        case 17:
        {

            gotoligcol(33,75);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&saturne_, player, tourJoueur);
            echange(nombreJoueur,player,tourJoueur);
            player[tourJoueur]->numeroCase = 17;
            break;
        }
        case 18:
        {

            gotoligcol(33,39);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            echange(nombreJoueur,player,tourJoueur);
            arrivgalax(&tetard_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 18;
            break;
        }
        case 19:
        {

            gotoligcol(33,51);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivsat(&pluton_, player, tourJoueur);
            echange(nombreJoueur,player,tourJoueur);
            player[tourJoueur]->numeroCase = 19;
            break;
        }
        case 20:
        {

            gotoligcol(33,29);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&neptune_, player, tourJoueur);
            echange(nombreJoueur,player,tourJoueur);
            player[tourJoueur]->numeroCase = 29;
            break;
        }
        case 21:
        {

            gotoligcol(33,17);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            printf("BONJOUR");
            player[tourJoueur]->numeroCase = 21;
            break;
        }
        case 22:
        {

            gotoligcol(33,3);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            printf("\nBONJOUR");
            player[tourJoueur]->numeroCase = 22;
            break;
        }
        case 23:
        {


            gotoligcol(29,3);
            Color(player[tourJoueur]->couleur, 0);

            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&venus_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 23;
            break;
        }
        case 24:
        {

            gotoligcol(25,3);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&uranus_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 24;
            break;
        }
        case 25:
        {

            gotoligcol(21,3);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivgalax(&nuageDeMagellan_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 25;
            break;
        }
        case 26:
        {

            gotoligcol(17,3);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&mercure_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 26;
            break;
        }
        case 27:
        {

            gotoligcol(13,3);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&soleil_, player, tourJoueur);
            player[tourJoueur]->numeroCase = 27;
            break;
        }
        case 28:
        {

            gotoligcol(9,3);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
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
    pause();

    while(choix != 1 && choix != 0){
        printf("\nIA : Je n'ai compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
        scanf("%d",&choix);

    }


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
        system("PAUSE");



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
