#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 200
#include "bib.h"

///-----------------------------------------------------------Initialisation couleur-----------------------------------------------------------
void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}



///-----------------------------------------------------------Placement du curseur-----------------------------------------------------------
void gotoligcol( int lig, int col )
{

COORD mycoord;

mycoord.X = col;

mycoord.Y = lig;

SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

}


///-----------------------------------------------------------Fonction pause-----------------------------------------------------------
int pause(int sauvegarde, int* nombreDeJoueur, int* nombreDeDeplacement, int* tourJoueur, t_joueur player[NbJoueurMax][TAILLE], int* chargement)
{
    char pause=kbhit('p');
    pause=getch();
    if(pause=='p')
    {
        system("cls");
        sauvegarde=menu1(&nombreDeJoueur, &nombreDeDeplacement, &tourJoueur, player, &chargement);
    }
}



int main()
{

    int sauvegarde=0;
    int chargement=0;
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

    menu1(&nombreJoueur, &deplacement, &tourJoueur, player, &chargement);
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

player[0]->etatIG = 1;
player[1]->etatIG = 1;
player[2]->etatIG = 1;
player[3]->etatIG = 1;

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

FILE * fp=NULL;

if(chargement==1)
    {
        int chJ=0;
        printf("\nIA : Bonjour ! Pouvez vous me communiquez combien de joueurs etiez vous dans la Partie que vous voulez reprendre");
        scanf("%d",&chJ);
        while(chJ !=2 && chJ !=3 && chJ !=4)
        {
            printf("\nIA : Saisissez le bon nombre de joueur");
        }
        fp=fopen("Partie.txt","r");
        if (fp==NULL)
        {
        printf("erreur d'ouverture");
        exit (0);
        }
        for(int h = 0; h<chJ; h++)
        {
            //fgets(player[h]->prenomJoueur,50,fp);
            fscanf(fp,"%d",&player[h]->argent);
            //fscanf(fp,"%d",player[h]->couleur);
            fscanf(fp,"%d",&player[h]->numeroCase);
            //fscanf(fp,"%d",player[h]->numeroJoueur);
            fscanf(fp,"%d",&player[h]->prison);
            //fgets(player[h]->proprietes,TAILLE,fp);
            fscanf(fp,"%d",&player[h]->nbDeGare);
            fscanf(fp,"%d",&player[h]->couleurJoueur);
        }
        fscanf(fp,"%d",&lune_.proprio);
        fscanf(fp,"%d",&lune_.maison);
        fscanf(fp,"%d",&lune_.hotel);
        fscanf(fp,"%d",&terre_.proprio);
        fscanf(fp,"%d",&terre_.maison);
        fscanf(fp,"%d",&terre_.hotel);
        fscanf(fp,"%d",&voieLactee_.proprio);
        fscanf(fp,"%d",&voieLactee_.maison);
        fscanf(fp,"%d",&voieLactee_.hotel);
        fscanf(fp,"%d",&phobos_.proprio);
        fscanf(fp,"%d",&phobos_.maison);
        fscanf(fp,"%d",&phobos_.hotel);
        fscanf(fp,"%d",&mars_.proprio);
        fscanf(fp,"%d",&mars_.maison);
        fscanf(fp,"%d",&mars_.hotel);
        fscanf(fp,"%d",&ganymede_.proprio);
        fscanf(fp,"%d",&ganymede_.maison);
        fscanf(fp,"%d",&ganymede_.hotel);
        fscanf(fp,"%d",&callisto_.proprio);
        fscanf(fp,"%d",&callisto_.maison);
        fscanf(fp,"%d",&callisto_.hotel);
        fscanf(fp,"%d",&andromede_.proprio);
        fscanf(fp,"%d",&andromede_.maison);
        fscanf(fp,"%d",&andromede_.hotel);
        fscanf(fp,"%d",&io_.proprio);
        fscanf(fp,"%d",&io_.maison);
        fscanf(fp,"%d",&io_.hotel);
        fscanf(fp,"%d",&jupiter_.proprio);
        fscanf(fp,"%d",&jupiter_.maison);
        fscanf(fp,"%d",&jupiter_.hotel);
        fscanf(fp,"%d",&titan_.proprio);
        fscanf(fp,"%d",&titan_.maison);
        fscanf(fp,"%d",&titan_.hotel);
        fscanf(fp,"%d",&saturne_.proprio);
        fscanf(fp,"%d",&saturne_.maison);
        fscanf(fp,"%d",&saturne_.hotel);
        fscanf(fp,"%d",&pluton_.proprio);
        fscanf(fp,"%d",&pluton_.maison);
        fscanf(fp,"%d",&pluton_.hotel);
        fscanf(fp,"%d",&neptune_.proprio);
        fscanf(fp,"%d",&neptune_.maison);
        fscanf(fp,"%d",&neptune_.hotel);
        fscanf(fp,"%d",&venus_.proprio);
        fscanf(fp,"%d",&venus_.maison);
        fscanf(fp,"%d",&venus_.hotel);
        fscanf(fp,"%d",&uranus_.proprio);
        fscanf(fp,"%d",&uranus_.maison);
        fscanf(fp,"%d",&uranus_.hotel);
        fscanf(fp,"%d",&nuageDeMagellan_.proprio);
        fscanf(fp,"%d",&nuageDeMagellan_.maison);
        fscanf(fp,"%d",&nuageDeMagellan_.hotel);
        fscanf(fp,"%d",&mercure_.proprio);
        fscanf(fp,"%d",&mercure_.maison);
        fscanf(fp,"%d",&mercure_.hotel);
        fscanf(fp,"%d",&soleil_.proprio);
        fscanf(fp,"%d",&soleil_.maison);
        fscanf(fp,"%d",&soleil_.hotel);
        fclose(fp);
        for(int i=0; i<chJ;i++)
        {
            char astronaute[NbJoueurMax][TAILLE]; //tableau des noms de familles
            strcpy(astronaute[0], "PESQUET");
            strcpy(astronaute[1], "ARMSTRONG");
            strcpy(astronaute[2], "GARGARINE");
            strcpy(astronaute[3], "ALDRIN");

            if (i == 0)
            {
                Color(4,0);
                player[i]->couleurJoueur = 4;
                printf("\n\nRebonjour cher joueur !\n\nJe suis content de vous revoir !\n\nBonne chance !\n\n");
                printf("Pouvez vous me redonner votre pr%cnom ?\n",0x82);

                scanf("%s", &player[i]->prenomJoueur);
                fflush(stdin);
                strcat(player[i]->prenomJoueur, " "); //on ajoute un espace apr�s le pr�nom
                strcat(player[i]->prenomJoueur, astronaute[i]); //on ajoute un nom d'astronaute au pr�nom de l'utilisateur

                player[i]->numeroJoueur = i+1;
                fflush(stdin);

                player[i]->couleur = 4;
                player[i]->pion = 0x03;
            }
            else if (i==1)
            {
                Color(6,0);
                player[i]->couleurJoueur = 6;
                printf("\n\nRebonjour cher joueur !\n\nJe suis content de vous revoir !\n\nBonne chance !\n\n");
                printf("Pouvez vous me redonner votre pr%cnom ?\n",0x82);

                scanf("%s", player[i]->prenomJoueur);
                fflush(stdin);
                strcat(player[i]->prenomJoueur, " "); //on ajoute un espace apr�s le pr�nom
                strcat(player[i]->prenomJoueur, astronaute[i]); //on ajoute un nom d'astronaute au pr�nom de l'utilisateur

                player[i]->numeroJoueur = i+1;
                fflush(stdin);

                player[i]->couleur = 6;
                player[i]->pion = 0x04;
            }
            else if (i==2)
            {
                Color(9,0);
                player[i]->couleurJoueur = 9;
                printf("\n\nRebonjour cher joueur !\n\nJe suis content de vous revoir !\n\nBonne chance !\n\n");
                printf("Pouvez vous me redonner votre pr%cnom ?\n",0x82);

                scanf("%s", &player[i]->prenomJoueur);
                fflush(stdin);
                strcat(player[i]->prenomJoueur, " "); //on ajoute un espace apr�s le pr�nom
                strcat(player[i]->prenomJoueur, astronaute[i]); //on ajoute un nom d'astronaute au pr�nom de l'utilisateur

                player[i]->numeroJoueur = i+1;
                fflush(stdin);

                player[i]->couleur = 9;
                player[i]->pion = 0x05;

            }

            else if (i==3)
            {
                Color(11,0);
                player[i]->couleurJoueur = 11;
                printf("\n\nRebonjour cher joueur !\n\nJe suis content de vous revoir !\n\nBonne chance !\n\n");
                printf("Pouvez vous me redonner votre pr%cnom ?\n",0x82);

                scanf("%s", &player[i]->prenomJoueur);
                fflush(stdin);
                strcat(player[i]->prenomJoueur, " "); //on ajoute un espace apr�s le pr�nom
                strcat(player[i]->prenomJoueur, astronaute[i]); //on ajoute un nom d'astronaute au pr�nom de l'utilisateur

                player[i]->numeroJoueur = i+1;
                fflush(stdin);

                player[i]->couleur = 11;
                player[i]->pion = 0x06;

            }
        }

        for(int i=0; i<chJ;i++)
        {
            if(player[i]->numeroJoueur==lune_.proprio)
            {
                strcat(player[i]->proprietes,lune_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==terre_.proprio)
            {
                strcat(player[i]->proprietes,terre_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==voieLactee_.proprio)
            {
                strcat(player[i]->proprietes,voieLactee_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==phobos_.proprio)
            {
                strcat(player[i]->proprietes,phobos_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==mars_.proprio)
            {
                strcat(player[i]->proprietes,mars_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==ganymede_.proprio)
            {
                strcat(player[i]->proprietes,ganymede_.nom);
                strcat(player[i]->proprietes,",");
            }

            if(player[i]->numeroJoueur==callisto_.proprio)
            {
                strcat(player[i]->proprietes,callisto_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==andromede_.proprio)
            {
                strcat(player[i]->proprietes,andromede_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==io_.proprio)
            {
                strcat(player[i]->proprietes,io_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==jupiter_.proprio)
            {
                strcat(player[i]->proprietes,jupiter_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==titan_.proprio)
            {
                strcat(player[i]->proprietes,titan_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==saturne_.proprio)
            {
                strcat(player[i]->proprietes,saturne_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==tetard_.proprio)
            {
                strcat(player[i]->proprietes,tetard_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==pluton_.proprio)
            {
                strcat(player[i]->proprietes,pluton_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==neptune_.proprio)
            {
                strcat(player[i]->proprietes,neptune_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==venus_.proprio)
            {
                strcat(player[i]->proprietes,venus_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==uranus_.proprio)
            {
                strcat(player[i]->proprietes,uranus_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==nuageDeMagellan_.proprio)
            {
                strcat(player[i]->proprietes,nuageDeMagellan_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==mercure_.proprio)
            {
                strcat(player[i]->proprietes,mercure_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==soleil_.proprio)
            {
                strcat(player[i]->proprietes,soleil_.nom);
                strcat(player[i]->proprietes,",");
            }
        }
    }
    chargement=0;

while(choix != 0)
{
    system("cls");
    Color(15,0);
    plateau();
    affichageDesJoueurs(player);

    /*if(player[tourJoueur]->etatIG==0)
    {
        tourJoueur+=1;
    }*/
    if (player[tourJoueur]->etatIG == 0){

    }
    else{

    ///-----------------------------------------------------------PLATEAU-----------------------------------------------------------
    switch(deplacement)
    {
        case 1:
        {
            player[tourJoueur]->numeroCase = 1; //on assigne le joueur au numéro de la case du plateau
            pion(player,nombreJoueur); //on place le pion du joueur à cette case
            gotoligcol(35,1);
            Color(4,0);
            printf("\nCASE DEPART ! Recevez ");
            Color(2,0);
            printf("200%c",0x24);
            Color(4,0);
            printf(" !C'est cadeau !\n");
            verfiwin(player , tourJoueur , nombreJoueur);

            break;
        }
        case 2:
        {
            player[tourJoueur]->numeroCase = 2;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivsat(&lune_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 3:
        {

            player[tourJoueur]->numeroCase = 3;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivplan(&terre_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 4:
        {


            player[tourJoueur]->numeroCase = 4;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            player[tourJoueur]->argent -= 200;
            Color(3,0);
            printf("\nIA : Vous devez payer 200 euros pour les taxes !\n");
            Color(player[tourJoueur]->couleur, 0);
            printf("%s, votre porte monnaie est de : %d\n", player[tourJoueur]->prenomJoueur, player[tourJoueur]->argent);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 5:
        {


            player[tourJoueur]->numeroCase = 5;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivgalax(&voieLactee_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 6:
        {

            player[tourJoueur]->numeroCase = 6;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivsat(&phobos_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 7:
        {

            player[tourJoueur]->numeroCase = 7;
            pion(player,nombreJoueur);

            gotoligcol(35,1);
            arrivplan(&mars_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 8:
        {

            gotoligcol(4,89);
            Color(player[tourJoueur]->couleur, 0);
            printf("%c", player[tourJoueur]->pion);
            player[tourJoueur]->numeroCase = 22;
            gotoligcol(35,1);
            printf("\nIA : Vous allez directement en prison !\n");



            player[tourJoueur]->prison = 1;

            verfiwin(player , tourJoueur , nombreJoueur);

            break;
        }
        case 9:
        {


            player[tourJoueur]->numeroCase = 9;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivsat(&ganymede_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 10:
        {

            player[tourJoueur]->numeroCase = 10;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivsat(&callisto_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 11:
        {

            player[tourJoueur]->numeroCase = 11;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivgalax(&andromede_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 12:
        {

            player[tourJoueur]->numeroCase = 12;
            pion(player,nombreJoueur);

            gotoligcol(35,1);
            arrivsat(&io_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 13:
        {

            player[tourJoueur]->numeroCase = 13;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivplan(&jupiter_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 14:
        {


            player[tourJoueur]->numeroCase = 14;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            Color(15,0);
            printf("\nAppuyez sur 1 pour piocher une carte de communaute !\n");
            scanf("%d", &choix2);
            while(choix2 != 1){ //blindage
                Color(3,0);
                printf("\nIA : Je n'ai pas compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
                fflush(stdin);
                scanf("%d",&choix2);
            }

            if (choix2 == 1){
                piocheCartesCommu(carte, player, nombreJoueur, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_,&maisonMax,&hotelMax);
            }

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 15:
        {


            player[tourJoueur]->numeroCase = 15;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            Color(15,0);
            printf("\nVous etes sur le parking, reposez-vous !\n");

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 16:
        {

            player[tourJoueur]->numeroCase = 16;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivsat(&titan_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 17:
        {

            player[tourJoueur]->numeroCase = 17;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivplan(&saturne_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 18:
        {

            player[tourJoueur]->numeroCase = 18;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivgalax(&tetard_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 19:
        {

            player[tourJoueur]->numeroCase = 19;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivsat(&pluton_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 20:
        {

            player[tourJoueur]->numeroCase = 20;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivplan(&neptune_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 21:
        {

            player[tourJoueur]->numeroCase = 21;
            pion(player,nombreJoueur);

            gotoligcol(35,1);
            Color(15,0);
            printf("\nAppuyez sur 1 pour piocher une carte de communaute !\n");
            scanf("%d", &choix3);
            while(choix3 != 1){
                Color(3,0);
                printf("\nIA : Je n'ai pas compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
                scanf("%s");
                scanf("%d",&choix3);
            }

            if (choix3 == 1){
                piocheCartesCommu(carte, player, nombreJoueur, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_,&maisonMax,&hotelMax);
            }
            verfiwin(player , tourJoueur , nombreJoueur);

            break;
        }
        case 22:
        {
            player[tourJoueur]->numeroCase = 22;
            pion(player,nombreJoueur);
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



            player[tourJoueur]->numeroCase = 23;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivplan(&venus_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 24:
        {
            player[tourJoueur]->numeroCase = 24;
             pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivplan(&uranus_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 25:
        {

            player[tourJoueur]->numeroCase = 25;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivgalax(&nuageDeMagellan_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 26:
        {

            player[tourJoueur]->numeroCase = 26;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivplan(&mercure_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 27:
        {

            player[tourJoueur]->numeroCase = 27;
            pion(player,nombreJoueur);
            gotoligcol(35,1);
            arrivplan(&soleil_, player, tourJoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_, &maisonMax, &hotelMax, nombreJoueur);

            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
        case 28:
        {

            player[tourJoueur]->numeroCase = 28;
            pion(player,nombreJoueur);

            gotoligcol(35,1);
            printf("\nAppuyez sur 1 pour piocher une carte chance !\n");
            scanf("%d", &choix4);
            while(choix4 != 1){
                printf("\nIA : Je n'ai pas compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
                scanf("%s");
                scanf("%d",&choix2);
            }

            if (choix4 == 1){
                piocheCartesChances(carte, player, nombreJoueur, tourJoueur);
            }
            verfiwin(player , tourJoueur , nombreJoueur);
            break;
        }
    }
    }

    ///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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
    printf("\nIA : %s, veuillez appuyer sur 1 pour lancer le de, ou 2 pour un echange : ", player[tourJoueur]->prenomJoueur);
    sauvegarde=pause(sauvegarde,&nombreJoueur, &deplacement, &tourJoueur, player, &chargement);
    if(sauvegarde==1)
    {
        fp=fopen("Partie.txt","w");
        if (fp==NULL)
        {
        printf("erreur d'ouverture");
        exit (0);
        }
        for(int l=0; l<NbJoueurMax; l++)
        {
            //fprintf(fp,"%s\n",player[l]->prenomJoueur);
            fprintf(fp,"%d\n",player[l]->argent);
            //fprintf(fp,"%d\n",player[l]->couleur);
            fprintf(fp,"%d\n",player[l]->numeroCase);
            //fprintf(fp,"%d\n",player[l]->numeroJoueur);
            fprintf(fp,"%d\n",player[l]->prison);
            //fprintf(fp,"%s\n",player[l]->proprietes);
            fprintf(fp,"%d\n",player[l]->nbDeGare);
            fprintf(fp,"%d\n",player[l]->couleurJoueur);
        }
        fprintf(fp,"%d\n",lune_.proprio);
        fprintf(fp,"%d\n",lune_.maison);
        fprintf(fp,"%d\n",lune_.hotel);
        fprintf(fp,"%d\n",terre_.proprio);
        fprintf(fp,"%d\n",terre_.maison);
        fprintf(fp,"%d\n",terre_.hotel);
        fprintf(fp,"%d\n",voieLactee_.proprio);
        fprintf(fp,"%d\n",voieLactee_.maison);
        fprintf(fp,"%d\n",voieLactee_.hotel);
        fprintf(fp,"%d\n",phobos_.proprio);
        fprintf(fp,"%d\n",phobos_.maison);
        fprintf(fp,"%d\n",phobos_.hotel);
        fprintf(fp,"%d\n",mars_.proprio);
        fprintf(fp,"%d\n",mars_.maison);
        fprintf(fp,"%d\n",mars_.hotel);
        fprintf(fp,"%d\n",ganymede_.proprio);
        fprintf(fp,"%d\n",ganymede_.maison);
        fprintf(fp,"%d\n",ganymede_.hotel);
        fprintf(fp,"%d\n",callisto_.proprio);
        fprintf(fp,"%d\n",callisto_.maison);
        fprintf(fp,"%d\n",callisto_.hotel);
        fprintf(fp,"%d\n",andromede_.proprio);
        fprintf(fp,"%d\n",andromede_.maison);
        fprintf(fp,"%d\n",andromede_.hotel);
        fprintf(fp,"%d\n",io_.proprio);
        fprintf(fp,"%d\n",io_.maison);
        fprintf(fp,"%d\n",io_.hotel);
        fprintf(fp,"%d\n",jupiter_.proprio);
        fprintf(fp,"%d\n",jupiter_.maison);
        fprintf(fp,"%d\n",jupiter_.hotel);
        fprintf(fp,"%d\n",titan_.proprio);
        fprintf(fp,"%d\n",titan_.maison);
        fprintf(fp,"%d\n",titan_.hotel);
        fprintf(fp,"%d\n",saturne_.proprio);
        fprintf(fp,"%d\n",saturne_.maison);
        fprintf(fp,"%d\n",saturne_.hotel);
        fprintf(fp,"%d\n",pluton_.proprio);
        fprintf(fp,"%d\n",pluton_.maison);
        fprintf(fp,"%d\n",pluton_.hotel);
        fprintf(fp,"%d\n",neptune_.proprio);
        fprintf(fp,"%d\n",neptune_.maison);
        fprintf(fp,"%d\n",neptune_.hotel);
        fprintf(fp,"%d\n",venus_.proprio);
        fprintf(fp,"%d\n",venus_.maison);
        fprintf(fp,"%d\n",venus_.hotel);
        fprintf(fp,"%d\n",uranus_.proprio);
        fprintf(fp,"%d\n",uranus_.maison);
        fprintf(fp,"%d\n",uranus_.hotel);
        fprintf(fp,"%d\n",nuageDeMagellan_.proprio);
        fprintf(fp,"%d\n",nuageDeMagellan_.maison);
        fprintf(fp,"%d\n",nuageDeMagellan_.hotel);
        fprintf(fp,"%d\n",mercure_.proprio);
        fprintf(fp,"%d\n",mercure_.maison);
        fprintf(fp,"%d\n",mercure_.hotel);
        fprintf(fp,"%d\n",soleil_.proprio);
        fprintf(fp,"%d\n",soleil_.maison);
        fprintf(fp,"%d\n",soleil_.hotel);
        fclose(fp);
    }
    sauvegarde=0;
    //printf("\n\n%d\n\n",chargement);
    if(chargement==1)
    {
        int chJ=0;
        printf("\nIA : Bonjour ! Pouvez vous me communiquer combien de joueurs etiez vous dans la Partie que vous voulez reprendre");
        scanf("%d",&chJ);
        while(chJ !=2 && chJ !=3 && chJ !=4)
        {
            printf("\nIA : Saisissez le bon nombre de joueur");
        }
        fp=fopen("Partie.txt","r");
        if (fp==NULL)
        {
        printf("erreur d'ouverture");
        exit (0);
        }
        for(int h = 0; h<chJ; h++)
        {
            //fgets(player[h]->prenomJoueur,50,fp);
            fscanf(fp,"%d",&player[h]->argent);
            //fscanf(fp,"%d",player[h]->couleur);
            fscanf(fp,"%d",&player[h]->numeroCase);
            //fscanf(fp,"%d",player[h]->numeroJoueur);
            fscanf(fp,"%d",&player[h]->prison);
            //fgets(player[h]->proprietes,TAILLE,fp);
            fscanf(fp,"%d",&player[h]->nbDeGare);
            fscanf(fp,"%d",&player[h]->couleurJoueur);
        }
        fscanf(fp,"%d",&lune_.proprio);
        fscanf(fp,"%d",&lune_.maison);
        fscanf(fp,"%d",&lune_.hotel);
        fscanf(fp,"%d",&terre_.proprio);
        fscanf(fp,"%d",&terre_.maison);
        fscanf(fp,"%d",&terre_.hotel);
        fscanf(fp,"%d",&voieLactee_.proprio);
        fscanf(fp,"%d",&voieLactee_.maison);
        fscanf(fp,"%d",&voieLactee_.hotel);
        fscanf(fp,"%d",&phobos_.proprio);
        fscanf(fp,"%d",&phobos_.maison);
        fscanf(fp,"%d",&phobos_.hotel);
        fscanf(fp,"%d",&mars_.proprio);
        fscanf(fp,"%d",&mars_.maison);
        fscanf(fp,"%d",&mars_.hotel);
        fscanf(fp,"%d",&ganymede_.proprio);
        fscanf(fp,"%d",&ganymede_.maison);
        fscanf(fp,"%d",&ganymede_.hotel);
        fscanf(fp,"%d",&callisto_.proprio);
        fscanf(fp,"%d",&callisto_.maison);
        fscanf(fp,"%d",&callisto_.hotel);
        fscanf(fp,"%d",&andromede_.proprio);
        fscanf(fp,"%d",&andromede_.maison);
        fscanf(fp,"%d",&andromede_.hotel);
        fscanf(fp,"%d",&io_.proprio);
        fscanf(fp,"%d",&io_.maison);
        fscanf(fp,"%d",&io_.hotel);
        fscanf(fp,"%d",&jupiter_.proprio);
        fscanf(fp,"%d",&jupiter_.maison);
        fscanf(fp,"%d",&jupiter_.hotel);
        fscanf(fp,"%d",&titan_.proprio);
        fscanf(fp,"%d",&titan_.maison);
        fscanf(fp,"%d",&titan_.hotel);
        fscanf(fp,"%d",&saturne_.proprio);
        fscanf(fp,"%d",&saturne_.maison);
        fscanf(fp,"%d",&saturne_.hotel);
        fscanf(fp,"%d",&pluton_.proprio);
        fscanf(fp,"%d",&pluton_.maison);
        fscanf(fp,"%d",&pluton_.hotel);
        fscanf(fp,"%d",&neptune_.proprio);
        fscanf(fp,"%d",&neptune_.maison);
        fscanf(fp,"%d",&neptune_.hotel);
        fscanf(fp,"%d",&venus_.proprio);
        fscanf(fp,"%d",&venus_.maison);
        fscanf(fp,"%d",&venus_.hotel);
        fscanf(fp,"%d",&uranus_.proprio);
        fscanf(fp,"%d",&uranus_.maison);
        fscanf(fp,"%d",&uranus_.hotel);
        fscanf(fp,"%d",&nuageDeMagellan_.proprio);
        fscanf(fp,"%d",&nuageDeMagellan_.maison);
        fscanf(fp,"%d",&nuageDeMagellan_.hotel);
        fscanf(fp,"%d",&mercure_.proprio);
        fscanf(fp,"%d",&mercure_.maison);
        fscanf(fp,"%d",&mercure_.hotel);
        fscanf(fp,"%d",&soleil_.proprio);
        fscanf(fp,"%d",&soleil_.maison);
        fscanf(fp,"%d",&soleil_.hotel);
        fclose(fp);

        for(int i=0; i<chJ;i++)
        {
            char astronaute[NbJoueurMax][TAILLE]; //tableau des noms de familles
            strcpy(astronaute[0], "PESQUET");
            strcpy(astronaute[1], "ARMSTRONG");
            strcpy(astronaute[2], "GARGARINE");
            strcpy(astronaute[3], "ALDRIN");

            if (i == 0)
            {
                Color(4,0);
                player[i]->couleurJoueur = 4;
                printf("\n\nRebonjour cher joueur !\n\nJe suis content de vous revoir !\n\nBonne chance !\n\n");
                printf("Pouvez vous me redonner votre pr%cnom ?\n",0x82);

                scanf("%s", &player[i]->prenomJoueur);
                fflush(stdin);
                strcat(player[i]->prenomJoueur, " "); //on ajoute un espace apr�s le pr�nom
                strcat(player[i]->prenomJoueur, astronaute[i]); //on ajoute un nom d'astronaute au pr�nom de l'utilisateur

                player[i]->numeroJoueur = i+1;
                fflush(stdin);

                player[i]->couleur = 4;
                player[i]->pion = 0x03;
            }
            else if (i==1)
            {
                Color(6,0);
                player[i]->couleurJoueur = 6;
                printf("\n\nRebonjour cher joueur !\n\nJe suis content de vous revoir !\n\nBonne chance !\n\n");
                printf("Pouvez vous me redonner votre pr%cnom ?\n",0x82);

                scanf("%s", player[i]->prenomJoueur);
                fflush(stdin);
                strcat(player[i]->prenomJoueur, " "); //on ajoute un espace apr�s le pr�nom
                strcat(player[i]->prenomJoueur, astronaute[i]); //on ajoute un nom d'astronaute au pr�nom de l'utilisateur

                player[i]->numeroJoueur = i+1;
                fflush(stdin);

                player[i]->couleur = 6;
                player[i]->pion = 0x04;
            }
            else if (i==2)
            {
                Color(9,0);
                player[i]->couleurJoueur = 9;
                printf("\n\nRebonjour cher joueur !\n\nJe suis content de vous revoir !\n\nBonne chance !\n\n");
                printf("Pouvez vous me redonner votre pr%cnom ?\n",0x82);

                scanf("%s", &player[i]->prenomJoueur);
                fflush(stdin);
                strcat(player[i]->prenomJoueur, " "); //on ajoute un espace apr�s le pr�nom
                strcat(player[i]->prenomJoueur, astronaute[i]); //on ajoute un nom d'astronaute au pr�nom de l'utilisateur

                player[i]->numeroJoueur = i+1;
                fflush(stdin);

                player[i]->couleur = 9;
                player[i]->pion = 0x05;

            }

            else if (i==3)
            {
                Color(11,0);
                player[i]->couleurJoueur = 11;
                printf("\n\nRebonjour cher joueur !\n\nJe suis content de vous revoir !\n\nBonne chance !\n\n");
                printf("Pouvez vous me redonner votre pr%cnom ?\n",0x82);

                scanf("%s", &player[i]->prenomJoueur);
                fflush(stdin);
                strcat(player[i]->prenomJoueur, " "); //on ajoute un espace apr�s le pr�nom
                strcat(player[i]->prenomJoueur, astronaute[i]); //on ajoute un nom d'astronaute au pr�nom de l'utilisateur

                player[i]->numeroJoueur = i+1;
                fflush(stdin);

                player[i]->couleur = 11;
                player[i]->pion = 0x06;

            }
        }

        for(int i=0; i<chJ;i++)
        {
            if(player[i]->numeroJoueur==lune_.proprio)
            {
                strcat(player[i]->proprietes,lune_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==terre_.proprio)
            {
                strcat(player[i]->proprietes,terre_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==voieLactee_.proprio)
            {
                strcat(player[i]->proprietes,voieLactee_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==phobos_.proprio)
            {
                strcat(player[i]->proprietes,phobos_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==mars_.proprio)
            {
                strcat(player[i]->proprietes,mars_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==ganymede_.proprio)
            {
                strcat(player[i]->proprietes,ganymede_.nom);
                strcat(player[i]->proprietes,",");
            }

            if(player[i]->numeroJoueur==callisto_.proprio)
            {
                strcat(player[i]->proprietes,callisto_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==andromede_.proprio)
            {
                strcat(player[i]->proprietes,andromede_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==io_.proprio)
            {
                strcat(player[i]->proprietes,io_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==jupiter_.proprio)
            {
                strcat(player[i]->proprietes,jupiter_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==titan_.proprio)
            {
                strcat(player[i]->proprietes,titan_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==saturne_.proprio)
            {
                strcat(player[i]->proprietes,saturne_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==tetard_.proprio)
            {
                strcat(player[i]->proprietes,tetard_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==pluton_.proprio)
            {
                strcat(player[i]->proprietes,pluton_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==neptune_.proprio)
            {
                strcat(player[i]->proprietes,neptune_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==venus_.proprio)
            {
                strcat(player[i]->proprietes,venus_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==uranus_.proprio)
            {
                strcat(player[i]->proprietes,uranus_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==nuageDeMagellan_.proprio)
            {
                strcat(player[i]->proprietes,nuageDeMagellan_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==mercure_.proprio)
            {
                strcat(player[i]->proprietes,mercure_.nom);
                strcat(player[i]->proprietes,",");
            }
            if(player[i]->numeroJoueur==soleil_.proprio)
            {
                strcat(player[i]->proprietes,soleil_.nom);
                strcat(player[i]->proprietes,",");
            }
        }
        printf("\nVeuillez appuyer sur 1 pour lancer les des : ");
    }
    chargement=0;
    scanf("%d", &choix);


    while(choix != 1 && choix != 0 && choix != 2){
        printf("\nIA : Je n'ai pas compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
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


