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

int pause(int sauvegarde)
{
    char pause=kbhit('p');
    pause=getch();
    if(pause=='p')
    {
        sauvegarde=menu1();
    }
}



int main()
{

    int sauvegarde=0;
    srand(time(NULL));
    t_joueur player[NbJoueurMax][TAILLE];
    satellite lune_ = {0, "","",0,0,0,0,0,0,0,0};
    planete terre_={0, "","",0,0,0,0,0,0,0,0};
    galaxie voieLactee_ = {0, "","",0,0,0,0,0,0,0};
    satellite phobos_={0, "","",0,0,0,0,0,0,0,0};
    planete mars_= {0, "","",0,0,0,0,0,0,0,0};
    satellite ganymede_= {0, "","",0,0,0,0,0,0,0,0};
    satellite callisto_ = {0, "","",0,0,0,0,0,0,0,0};
    galaxie andromede_ = {0,"","",0,0,0,0,0,0,0};
    satellite io_ = {0, "","",0,0,0,0,0,0,0,0};
    planete jupiter_ = {0, "", "", 0, 0, 0, 0 , 0,0,0,0};
    satellite titan_ = {0, "","",0,0,0,0,0,0,0,0};
    planete saturne_ = {0, "", "", 0, 0, 0, 0 , 0, 0,0} ;
    galaxie tetard_= {0,"","",0,0,0,0,0,0,0};
    planete pluton_ = {0, "", "", 0, 0, 0, 0 , 0, 0,0} ;
    planete neptune_ = {0, "", "", 0, 0, 0, 0 , 0, 0,0} ;
    planete venus_ = {0, "", "", 0, 0, 0, 0 , 0,0} ;
    planete uranus_ = {0, "", "", 0, 0, 0, 0 , 0,0} ;
    galaxie nuageDeMagellan_ = {0,"","",0,0,0,0,0,0,0};
    planete mercure_ = {0, "", "", 0, 0, 0, 0 , 0,0} ;
    planete soleil_ = {0, "", "", 0, 0, 0,0};


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
int choix2 = 0;
int choix3 = 0;
int choix4 = 0;
int carte = 1;
int numeroDe[2];
int deplacement2 = 0;
int deplacement3 = 0;
int deplacement1 = 0;

int maisonMax = 32;
int hotelMax = 12;
while(choix != 0)
{
    system("cls");
    Color(15,0);
    plateau();
    affichageDesJoueurs(player);




    switch(deplacement)
    {
        case 1:
        {
            gotoligcol(4,5);
            Color(player[tourJoueur]->couleur, 10);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            Color(4,0);
            printf("\nCASE DEPART ! Recevez ");
            Color(2,0);
            printf("200%c",0x24);
            Color(4,0);
            printf(" !C'est cadeau !\n");
            verfiwin(player , tourJoueur , nombreJoueur);
            player[tourJoueur]->numeroCase = 1;
            break;
        }
        case 2:
        {

            gotoligcol(4,17);
            Color(player[tourJoueur]->couleur, 15);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivsat(&lune_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 2;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 3:
        {

            gotoligcol(4,29);
            Color(player[tourJoueur]->couleur, 15);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&terre_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 3;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 4:
        {


            gotoligcol(4,41);
            Color(player[tourJoueur]->couleur, 7);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            player[tourJoueur]->argent -= 200;
            Color(3,0);
            printf("\nIA : Vous devez payer 200 euros pour les taxes !\n");
            Color(player[tourJoueur]->couleur, 0);
            printf("%s, votre porte monnaie est de : %d\n", player[tourJoueur]->prenomJoueur, player[tourJoueur]->argent);
            player[tourJoueur]->numeroCase = 4;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 5:
        {

            gotoligcol(4,52);
            Color(player[tourJoueur]->couleur, 7);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivgalax(&voieLactee_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, nombreJoueur);
            player[tourJoueur]->numeroCase = 5;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 6:
        {

            gotoligcol(4,64);
            Color(player[tourJoueur]->couleur, 15);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivsat(&phobos_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 6;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 7:
        {

            gotoligcol(3,77);
            Color(player[tourJoueur]->couleur, 15);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&mars_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 7;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 8:
        {

            gotoligcol(32,3);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            printf("\nIA : Vous allez directement en prison !\n");
            player[tourJoueur]->prison = 1;
            player[tourJoueur]->numeroCase = 22;
            verfiwin(player , tourJoueur , nombreJoueur);

            break;
        }
        case 9:
        {

            gotoligcol(8,89);
            Color(player[tourJoueur]->couleur, 15);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivsat(&ganymede_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 9;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 10:
        {

            gotoligcol(12,89);
            Color(player[tourJoueur]->couleur, 15);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivsat(&callisto_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 10;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 11:
        {

            gotoligcol(16,89);
            Color(player[tourJoueur]->couleur, 7);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivgalax(&andromede_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, nombreJoueur);
            player[tourJoueur]->numeroCase = 11;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 12:
        {

            gotoligcol(20,89);
            Color(player[tourJoueur]->couleur, 15);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivsat(&io_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 12;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 13:
        {

            gotoligcol(24,89);
            Color(player[tourJoueur]->couleur, 15);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&jupiter_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 13;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 14:
        {

            gotoligcol(28,89);
            Color(player[tourJoueur]->couleur, 1);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            Color(15,0);
            printf("\nAppuyer sur 1 pour piocher une carte de communaute !\n");
            scanf("%d", &choix2);
            while(choix2 != 1){
                Color(3,0);
                printf("\nIA : Je n'ai compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
                scanf("%s");
                scanf("%d",&choix2);
            }

            if (choix2 == 1){
                piocheCartesCommu(carte, player, nombreJoueur, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_);
            }
            player[tourJoueur]->numeroCase = 14;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 15:
        {

            gotoligcol(32,89);
            Color(player[tourJoueur]->couleur, 12);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            Color(15,0);
            printf("\nVous etes sur le parking, reposez-vous !\n");
            player[tourJoueur]->numeroCase = 15;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 16:
        {

            gotoligcol(32,77);
            Color(player[tourJoueur]->couleur, 15);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivsat(&titan_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 16;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 17:
        {

            gotoligcol(32,65);
            Color(player[tourJoueur]->couleur, 15);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&saturne_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 17;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 18:
        {

            gotoligcol(32,53);
            Color(player[tourJoueur]->couleur, 7);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivgalax(&tetard_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, nombreJoueur);
            player[tourJoueur]->numeroCase = 18;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 19:
        {

            gotoligcol(32,40);
            Color(player[tourJoueur]->couleur, 15);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivsat(&pluton_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 19;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 20:
        {

            gotoligcol(32,29);
            Color(player[tourJoueur]->couleur, 15);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&neptune_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 20;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 21:
        {

            player[tourJoueur]->numeroCase = 21;
            gotoligcol(32,17);
            Color(player[tourJoueur]->couleur, 1);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            Color(15,0);
            printf("\nAppuyer sur 1 pour piocher une carte de communaute !\n");
            scanf("%d", &choix3);
            while(choix3 != 1){
                Color(3,0);
                printf("\nIA : Je n'ai compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
                scanf("%s");
                scanf("%d",&choix3);
            }

            if (choix3 == 1){
                piocheCartesCommu(carte, player, nombreJoueur, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_);
            }
            player[tourJoueur]->numeroCase = 21;
            verfiwin(player , tourJoueur , nombreJoueur);

            break;
        }
        case 22:
        {

            gotoligcol(32,5);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            if(player[tourJoueur]->prison == 1){
                gotoligcol(35,1);
                prison(player, tourJoueur, nombreJoueur);
                player[tourJoueur]->numeroCase = 22;
            }
            else{
                gotoligcol(35,1);
                Color(3,0);
                printf("\nVous visitez la prison spatiale !\n");
                player[tourJoueur]->numeroCase = 22;
            }
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 23:
        {


            gotoligcol(28,5);
            Color(player[tourJoueur]->couleur, 15);

            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&venus_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 23;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 24:
        {

            gotoligcol(24,5);
            Color(player[tourJoueur]->couleur, 15);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&uranus_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 24;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 25:
        {

            gotoligcol(20,5);
            Color(player[tourJoueur]->couleur, 7);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivgalax(&nuageDeMagellan_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, nombreJoueur);
            player[tourJoueur]->numeroCase = 25;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 26:
        {

            gotoligcol(15,5);
            Color(player[tourJoueur]->couleur, 15);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&mercure_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 26;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 27:
        {

            gotoligcol(12,5);
            Color(player[tourJoueur]->couleur, 15);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            arrivplan(&soleil_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);
            player[tourJoueur]->numeroCase = 27;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 28:
        {

            player[tourJoueur]->numeroCase = 28;
            gotoligcol(9,5);
            Color(player[tourJoueur]->couleur, 6);
            printf("%c", player[tourJoueur]->pion);
            gotoligcol(35,1);
            printf("\nAppuyer sur 1 pour piocher une carte chance !\n");
            scanf("%d", &choix4);
            while(choix4 != 1){
                printf("\nIA : Je n'ai compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
                scanf("%s");
                scanf("%d",&choix2);
            }

            if (choix4 == 1){
                piocheCartesChances(carte, player, nombreJoueur, tourJoueur);
            }
            player[tourJoueur]->numeroCase = 28;
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
    }

    tourJoueur += 1;
    if (tourJoueur == nombreJoueur )
    {
        tourJoueur = 0;
    }

    while(player[tourJoueur]->prison == 1){

        prison(player, tourJoueur, nombreJoueur);
        player[tourJoueur]->numeroCase = 22;
        if (player[tourJoueur]->prison == 1){
            tourJoueur += 1;
        }
    }
    if (tourJoueur == nombreJoueur )
    {
        tourJoueur = 0;
    }
    Color(3,0);
    printf(" IA : %s, veuillez appuyer sur 1 pour lancer le de, ou 2 pour un echange : ", player[tourJoueur]->prenomJoueur);
    sauvegarde=pause(sauvegarde);
    if(sauvegarde==1)
    {
        FILE * fp=NULL;
        fp=fopen("Partie.txt","w");
        if (fp==NULL)
        {
        printf("erreur d'ouverture");
        exit (0);
        }
        for(int l = 0; l<NbJoueurMax; l++)
        {
            fprintf(fp,"%s\n",player[l]->prenomJoueur);
            fprintf(fp,"%d\n",player[l]->argent);
            fprintf(fp,"%d\n",player[l]->couleur);
            fprintf(fp,"%d\n",player[l]->numeroCase);
            fprintf(fp,"%d\n",player[l]->numeroJoueur);
            fprintf(fp,"%d\n",player[l]->prison);
            fprintf(fp,"%s\n",player[l]->proprietes);
            fprintf(fp,"%d\n",player[l]->nbDeGare);
            fprintf(fp,"%d\n",player[l]->couleurJoueur);
        }
        fclose(fp);
    }
    scanf("%d", &choix);


    while(choix != 1 && choix != 0 && choix != 2){
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

                    player[tourJoueur]->prison = 1;
                    player[tourJoueur]->numeroCase = 22;
                    prison(player,tourJoueur, nombreJoueur);
                }
            }

        }

        deplacement = deplacement1 + deplacement2 + deplacement3;
        deplacement1 = 0;
        deplacement2 = 0;
        deplacement3 = 0;
        printf("%s avance de %d cases.\n", player[tourJoueur]->prenomJoueur, deplacement);




        deplacement += player[tourJoueur]->numeroCase;

        if (deplacement >= 28)
        {
            deplacement = deplacement - 28;
            player[tourJoueur]->argent += 200;
        }

    }
    if (choix == 2) {
        echange(nombreJoueur,player,tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_);
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
    carte += 1;
    if (carte >=16){
        carte = 1;
    }
    system("PAUSE");

}
return 0;

}
