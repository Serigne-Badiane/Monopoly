#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 200

#include "bib.h"

//Affichage plateau
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




///--------------------------------------------------------------PROCEDURES CASES--------------------------------------------------------------


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
    //ajouter un pointeur compteur i qui augmente de 1 a chaque fois que quelqu'un passe par la case
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
    //ajouter un pointeur compteur j qui augmente de 1 a chaque fois que quelqu'un passe par la case
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
    //chance ou commu ?
    printf("BONJOUR");

}
