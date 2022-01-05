#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 200

#include "bib.h"

void melangerCartes(int tab[12])
{

    int x;
    for (int i = 0; i<=12; i++){
        x = 1 + rand()%12;

        for (int j = 0; j<= 12; j++){
            if(tab[j] == x){
                x = 1 + rand()%12;
                j = 0;
            }
        }
        tab[i] =x;
        printf("%d\n", tab[i]);
    }

}






///--------------------------------------------------------------------CARTES COMMUNAUTE---------------------------------------------------------------

void cc1(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="\nRETOURNEZ VISTER LA VOIE LACTEE !\n";
    Color(3,0);
    printf("%s", c);
    player[tourJoueur]->numeroCase = 4;

}

void cc2(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="\nVOTRE VAISSEAU EST ENDOMMAGE, vous devez le reparer !\nPayer 150.\n";
    Color(5,0);
    printf("%s", c);
    player[tourJoueur]->argent -= 150;

}

void cc3(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="FRAUDE! ALLEZ EN PRISON!\nNe recevez pas d'argent en passant par la case depart.\n";
    Color(5,0);

    printf("%s", c);
    player[tourJoueur]->numeroCase = 22;
    player[tourJoueur]->prison = 1;
}


void cc4(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="VOUS POUVEZ VOUS LIBERER DE LA PRISON SPATIALE A TOUT MOMENT!\n";
    Color(5,0);
    printf("%s", c);
    player[tourJoueur]->carteSortiePrison = 1;

}


void cc5(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur, int nombreDeJoueur)
{
    char c[TAILLE]="DEAL FORCE!\nEchangez une de vos proprietes avec celle du joueur de votre choix\n";
    Color(5,0);
    printf("%s", c);

    echange(nombreDeJoueur,player,tourJoueur);
}


void cc6(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="\nVOUS ETES RAPPELES DE TOUTE URGENCE SUR TERRE !\nAvancez jusqu'à la planete Terre et recevez les 200 euros\n";
    Color(5,0);
    printf("%s", c);

    player[tourJoueur]->argent += 200;
    player[tourJoueur]->numeroCase = 3;

}


void cc7(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur, int nombreDeJoueur)
{
    char c[TAILLE]="BONNE ACTION ! Vous avez fait le ménage sur le vaissseau\nChacun des autres joueurs vous versent 20 euros.\n";
    Color(5,0);
    printf("%s", c);

    for (int i = 0; i<= nombreDeJoueur - 1; i++)
    {
        if(i != tourJoueur)
        {
            player[i]->argent -= 20;
            player[tourJoueur]->argent += 20;
        }
    }
}


void cc8(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="PETIT VOYAGE INTERGALACTIQUE!\nAvancez jusqu'aux nuages de Magelan.\n";
    Color(5,0);
    printf("%s", c);

    player[tourJoueur]->numeroCase = 25;

}


void cc9(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="PANNE, vous connaissez un leger souci technique.!\n. Reculez de 3 cases\n";
    Color(5,0);
    printf("%s", c);

    player[tourJoueur]->numeroCase -=3;

}


void cc10(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur, int nombreDeJoueur)
{
    char c[TAILLE]="VOUS N'AVEZ PAS RESPECTES CERTAINES REGLES A BORD DU VAISSEAU!\nVersez 50 euros a tous les joueurs.\n";
    Color(5,0);
    printf("%s", c);

    for (int i = 0; i<= nombreDeJoueur - 1; i++)
    {
        if(i != tourJoueur)
        {
            player[i]->argent += 50;
            player[tourJoueur]->argent -= 50;
        }
    }

}


void cc11(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE] = "SORTIE SPATIALE, vous devez sortir du vaisseau pour realiser des experiences !\nPayer 50 euros au joueur de votre choix pour qu'il vous accompagne.";
    Color(5,0);
    printf("%s", c);

    int choix;
    printf("Veuillez saisir le numero du joueur : ");
    scanf("%d", &choix);
    choix -= 1;
    while(choix >= 4){
        Color(3,0);
        printf("\nCe joueur n'existe pas !");
        fflush(stdin);
        scanf("%d", &choix);
    }
    while(choix == tourJoueur){
        Color(3,0);
        printf("\nVous ne pouvez pas sortir seul, ca serait trop dangereux !");
        fflush(stdin);
        scanf("%d", &choix);
    }

    Color(player[choix]->couleur, 0);
    printf("\n%s, ", player[choix]->prenomJoueur);
    Color(3,0);
    printf("vous l'accompagnez pour cette sortie spatiale et recevez 50 euros.\n");
    player[choix]->argent += 50;
    player[tourJoueur]->argent -= 50;

    Color(player[choix]->couleur, 0);
    printf("Votre porte-monnaie : %d\n", player[choix]->argent);
}


void cc12(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="REPARATION DU MODULE REUSSI!\nRecevez 50 euros.\n";
    Color(5,0);
    printf("%s", c);
    player[tourJoueur]->argent += 50;

}


void cc13(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="COUP DE BOOST DANS LES REACTEURS !\nAvancer de 5 cases.\n";
    Color(5,0);
    printf("%s", c);

    player[tourJoueur]->numeroCase += 5;

}


void cc14(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="VOUS AVEZ ETE NOMMME COMMANDANT DE BORD!\nRecevez 100 euros \n";
    Color(5,0);
    printf("%s", c);

    player[tourJoueur]->argent += 100;

}


void cc15(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur, int nombreDeJoueur)
{
    char c[TAILLE]="DEAL FORCE!\nEchangez une de vos proprietes avec celle du joueur de votre choix\n";
    Color(5,0);
    printf("%s", c);

    echange(nombreDeJoueur,player,tourJoueur);

}


void cc16(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur, int nombreDeJoueur)
{
    char c[TAILLE]="JOYEUX ANNIVERSAIRE !\nTous les joueurs vous versent 100 euros \n";
    Color(5,0);
    printf("%s", c);
    for (int i = 0; i<= nombreDeJoueur - 1; i++)
    {
        if(i != tourJoueur)
        {
            player[i]->argent -= 100;
            player[tourJoueur]->argent += 100;
        }
    }

}



///PIOCHE
int piocheCartesCommu(int carte, t_joueur player[NbJoueurMax][TAILLE], int nombreDeJoueur, int tourJoueur)
{

    switch (carte)
    {
        case 1:
        case 17:
        {
            cc1(player, tourJoueur);
            break;
        }
        case 2:
        {
            cc2(player, tourJoueur);
            break;
        }
        case 3:
        {
            cc3( player,   tourJoueur);
            break;
        }
        case 4:
        {
            cc4( player,   tourJoueur);
            break;
        }
        case 5:
        {
            cc5( player,tourJoueur, nombreDeJoueur);
            break;
        }
        case 6:
        {
            cc6( player ,   tourJoueur);
            break;
        }
        case 7:
        {
            cc7( player ,   tourJoueur, nombreDeJoueur);
            break;
        }
        case 8:
        {
            cc8( player, tourJoueur);
            break;
        }
        case 9:
        {
            cc9(  player, tourJoueur );
            break;
        }
        case 10:
        {
            cc10(  player ,   tourJoueur, nombreDeJoueur);
            break;
        }
        case 11:
        {
            cc11(  player, tourJoueur );
            break;
        }
        case 12:
        {
            c12(  player, tourJoueur );
            break;
        }
        case 13:
        {
            cc13(player, tourJoueur);
            break;
        }
        case 14:
        {
            cc14(  player ,   tourJoueur);
            break;
        }
        case 15:
        {
            cc15(  player, tourJoueur, nombreDeJoueur);
            break;
        }
        case 16:
        {
            cc16(  player ,   tourJoueur, nombreDeJoueur);
            break;
        }


    }
}

///----------------------------------------------------------------------CARTES CHANCES-------------------------------------------------------------------



void c1( t_joueur player[NbJoueurMax][TAILLE], int numeroTour)
{
    char c[TAILLE]="VOUS POUVEZ VOUS LIBERER DE LA PRISON SPATIALE A TOUT MOMENT!\n";
    Color(5,0);
    printf("%s", c);
    player[numeroTour]->carteSortiePrison = 1;
}


void c2(t_joueur player[NbJoueurMax][TAILLE], int nombreDeJoueur, int tourJoueur)
{
    char c[TAILLE]="JOYEUX ANNIVERSAIRE!\nChaque joueur vous verse 50 \n";
    Color(5,0);

    printf("%s", c);

    for (int i = 0; i<= nombreDeJoueur - 1; i++)
    {
        if(i != tourJoueur)
        {
            player[i]->argent -= 50;
            player[tourJoueur]->argent += 50;
        }
    }
}


void c3(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="CAMPAGNE PUBLICITAIRE PAYANTE!\nLa banque vous verse 100 euros\n";
    Color(5,0);

    printf("%s", c);
    player[tourJoueur]->argent += 100;
}


void c4(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    int choix = 0;
    int de1[2];
    int de2[2];
    int resultat1 = 0;
    int resultat2 = 0;
    Color(5,0);
    char c[TAILLE]="SOIREE DETENTE SUR LE VAISSEAU!\nChoisissez un adversaire.\nLancez tous les deux les des.\nCelui qui obtient le plus gros score recoit 200 de la Banque.\n";
    printf("%s\n", c);


    printf("Veuillez saisir le numero de l'utilisateur que vous avez choisi de defier : ");
    scanf("%d", &choix);

    choix = choix - 1; //car le tableau des joueurs commence à 0



    while(choix >= 4){
        Color(3,0);
        printf("\nIA : Ce joueur n'existe pas !\n");
        fflush(stdin);
        scanf("%d",&choix );
    }
    while(choix == tourJoueur)
    {
        Color(3,0);
        printf("\nIA : Vous ne pouvez vous defier vous-meme !\n");
        fflush(stdin);
        scanf("%d",&choix);
    }


    while (resultat1 == resultat2){
        Color(3,0);
        printf(" IA : Veuillez appuyer sur 1 pour lancer le de : ");
        int choix2;
        scanf("%d", &choix2);
        while(choix2 != 1){
            printf("\nIA : Je n'ai pas compris ... je sens que ca va etre complique ... veuillez ressaisir\n");

            scanf("%d",&choix2);
        }
        resultat1 = lancerDe(player, de1, tourJoueur);
        Color(player[tourJoueur]->couleur, 0);
        printf("\n%s, vous avez un score de : %d\n", player[tourJoueur]->prenomJoueur, resultat1);

        int choix3;
        Color(3,0);
        printf(" IA : Veuillez appuyer sur 1 pour lancer le de : ");
        scanf("%d", &choix3);
        while(choix3 != 1){
            printf("\nIA : Je n'ai pas compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
            fflush(stdin);
            scanf("%d", &choix3);
        }
        resultat2 = lancerDe(player, de2, choix);
        Color(player[choix]->couleur, 0);
        printf("%s, vous avez un score de %d\n", player[choix]->prenomJoueur, resultat2);

        if (resultat1 > resultat2){
            Color(player[tourJoueur]->couleur, 0);
            printf("%s, ", player[tourJoueur]->prenomJoueur);
            Color(3,0);
            printf("vous gagnez 200 euros !\n");
            player[tourJoueur]->argent += 200;
        }
        else if(resultat2 > resultat1){
            Color(player[choix]->couleur, 0);
            printf("%s, ", player[choix]->prenomJoueur);
            Color(3,0);
            printf("vous gagnez 200 euros !\n");
            player[choix]->argent += 200;
        }

    }




}



void c5(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    int choix = 0;
    int de1[2];
    int de2[2];
    int resultat1 = 0;
    int resultat2 = 0;
    Color(5,0);
    char c[TAILLE]="SOIREE DETENTE SUR LE VAISSEAU !\nChoisissez un adversaire.\nLancez tous les deux les des.\nCelui qui obtient le plus gros score recoit 200 de la Banque.\n";
    printf("%s\n", c);


    printf("Veuillez saisir le numero de l'utilisateur que vous avez choisi de defier : ");
    scanf("%d", &choix);

    choix = choix - 1; //car le tableau des joueurs commence à 0



    while(choix >= 4){
        Color(3,0);
        printf("\nIA : Ce joueur n'existe pas !\n");
        fflush(stdin);
        scanf("%d",&choix );
    }
    while(choix == tourJoueur)
    {
        Color(3,0);
        printf("\nIA : Vous ne pouvez vous defier vous-meme !\n");
        fflush(stdin);
        scanf("%d",&choix);
    }


    while (resultat1 == resultat2){
        Color(3,0);
        printf(" IA : Veuillez appuyer sur 1 pour lancer le de : ");
        int choix2;
        scanf("%d", &choix2);
        while(choix2 != 1){
            printf("\nIA : Je n'ai pas compris ... je sens que ca va etre complique ... veuillez ressaisir\n");

            scanf("%d",&choix2);
        }
        resultat1 = lancerDe(player, de1, tourJoueur);
        Color(player[tourJoueur]->couleur, 0);
        printf("\n%s, vous avez un score de : %d\n", player[tourJoueur]->prenomJoueur, resultat1);

        int choix3;
        Color(3,0);
        printf(" IA : Veuillez appuyer sur 1 pour lancer le de : ");
        scanf("%d", &choix3);
        while(choix3 != 1){
            printf("\nIA : Je n'ai pas compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
            fflush(stdin);
            scanf("%d", &choix3);
        }
        resultat2 = lancerDe(player, de2, choix);
        Color(player[choix]->couleur, 0);
        printf("%s, vous avez un score de %d\n", player[choix]->prenomJoueur, resultat2);

        if (resultat1 > resultat2){
            Color(player[tourJoueur]->couleur, 0);
            printf("%s, ", player[tourJoueur]->prenomJoueur);
            Color(3,0);
            printf("vous gagnez 200 euros !\n");
            player[tourJoueur]->argent += 200;
        }
        else if(resultat2 > resultat1){
            Color(player[choix]->couleur, 0);
            printf("%s, ", player[choix]->prenomJoueur);
            Color(3,0);
            printf("vous gagnez 200 euros !\n");
            player[choix]->argent += 200;
        }

    }
}


void c6(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="PRIX DU BUSINESSMAN DE L'ANNEE!\nLa banque vous verse 400.\n";
    Color(5,0);

    printf("%s", c);
    player[tourJoueur]->argent += 400;
}


void c7(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="VOUS LANCEZ VOTRE SITE INTERNET!\nVos ventes decollent!\nLa banque vous verse 300.\n";
    Color(5,0);

    printf("%s", c);
    player[tourJoueur]->argent += 300;
}


void c8(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="FRAUDE! ALLEZ EN PRISON!\nNe recevez pas d'argent en passant par la case depart.\n";
    Color(5,0);

    printf("%s", c);
    player[tourJoueur]->numeroCase = 22;
    player[tourJoueur]->prison = 1;
}


void c9(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="AVANCE SUR VOS PROFITS!\nAvancez jusqu'a la case Depart pour toucher votre salaire!\n";
    Color(5,0);

    printf("%s", c);
    player[tourJoueur]->numeroCase = 1;
    player[tourJoueur]->argent +=200;
}


void c10(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="AMENDE POUR ESPIONNAGE INDUSTRIEL!\nPayez 200 a la Banque.\n";
    Color(5,0);

    printf("%s", c);
    player[tourJoueur]->argent -= 200;
}


void c11(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="ROULEZ BOLIDES!\nAvancez de cinq cases dans votre vaisseau supersonique !\n";
    Color(5,0);

    printf("%s", c);
    player[tourJoueur]->numeroCase += 5;
}


void c12(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="ALLEZ EN PRISON!\nNe recevez pas d'argent en passant par la case depart.\n";
    Color(3,0);

    printf("%s", c);
    player[tourJoueur]->numeroCase = 22;
    player[tourJoueur]->prison = 1;
}


void c13(t_joueur player[NbJoueurMax][TAILLE], int nombreDeJoueur, int tourJoueur)
{
    char c[TAILLE]="Vous touchez le fruit de vos investissements!\nChaque joueur vous donne 20\n";
    Color(5,0);

    printf("%s", c);
    for (int i = 0; i<= nombreDeJoueur - 1; i++)
    {
        if(i != tourJoueur)
        {
            player[i]->argent -= 20;
            player[tourJoueur]->argent += 20;
        }
    }
}


void c14(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    int choix = 0;
    int de1[2];
    int de2[2];
    int resultat1 = 0;
    int resultat2 = 0;
    Color(5,0);
    char c[TAILLE]="SOIREE DETENTE SUR LE VAISSEAU!\nChoisissez un adversaire.\nLancez tous les deux les des.\nCelui qui obtient le plus gros score recoit 200 de la Banque.\n";
    printf("%s\n", c);


    printf("Veuillez saisir le numero de l'utilisateur que vous avez choisi de defier : ");
    scanf("%d", &choix);

    choix = choix - 1; //car le tableau des joueurs commence à 0



    while(choix >= 4){
        Color(3,0);
        printf("\nIA : Ce joueur n'existe pas !\n");
        fflush(stdin);
        scanf("%d",&choix );
    }
    while(choix == tourJoueur)
    {
        Color(3,0);
        printf("\nIA : Vous ne pouvez vous defier vous-meme !\n");
        fflush(stdin);
        scanf("%d",&choix);
    }


    while (resultat1 == resultat2){
        Color(3,0);
        printf(" IA : Veuillez appuyer sur 1 pour lancer le de : ");
        int choix2;
        scanf("%d", &choix2);
        while(choix2 != 1){
            printf("\nIA : Je n'ai pas compris ... je sens que ca va etre complique ... veuillez ressaisir\n");

            scanf("%d",&choix2);
        }
        resultat1 = lancerDe(player, de1, tourJoueur);
        Color(player[tourJoueur]->couleur, 0);
        printf("\n%s, vous avez un score de : %d\n", player[tourJoueur]->prenomJoueur, resultat1);

        int choix3;
        Color(3,0);
        printf(" IA : Veuillez appuyer sur 1 pour lancer le de : ");
        scanf("%d", &choix3);
        while(choix3 != 1){
            printf("\nIA : Je n'ai pas compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
            fflush(stdin);
            scanf("%d", &choix3);
        }
        resultat2 = lancerDe(player, de2, choix);
        Color(player[choix]->couleur, 0);
        printf("%s, vous avez un score de %d\n", player[choix]->prenomJoueur, resultat2);

        if (resultat1 > resultat2){
            Color(player[tourJoueur]->couleur, 0);
            printf("%s, ", player[tourJoueur]->prenomJoueur);
            Color(3,0);
            printf("vous gagnez 200 euros !\n");
            player[tourJoueur]->argent += 200;
        }
        else if(resultat2 > resultat1){
            Color(player[choix]->couleur, 0);
            printf("%s, ", player[choix]->prenomJoueur);
            Color(3,0);
            printf("vous gagnez 200 euros !\n");
            player[choix]->argent += 200;
        }

    }

}


void c15(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="ALLEZ EN PRISON!\nNe recevez pas d'argent en passant par la case depart.\n";
    Color(5,0);

    printf("%s", c);
    player[tourJoueur]->numeroCase = 22;
    player[tourJoueur]->prison = 1;
}


void c16(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="AMENDE POUR ESPIONNAGE INDUSTRIEL!\nPayez 200 a la Banque.\n";
    Color(5,0);

    printf("%s", c);
    player[tourJoueur]->argent -= 200;
}

void prison(t_joueur player[NbJoueurMax][TAILLE], int numeroTour, int nbDeJoueur)
{

    int choix;
    int choix2;
    int choix3;
    int choix4;
    int de[2];

    Color(3,0);

    ///carte sortie de prison
    if(player[numeroTour]->carteSortiePrison == 1){
        Color(player[numeroTour]->couleur, 0);
        printf("\n%s, ", player[numeroTour]->prenomJoueur);
        Color(3,0);
        printf("vous etes en prison !\n");
        printf("%s");
        printf("Vous possedez une carte permettant de sortir de prison.\nVoulez-vous l'utiliser ou la conserver pour plus tard ?\n");
        printf("                                  ");
        Color(10,0);
        printf("1.UTILISER");
        printf("                                  ");
        Color(12,0);
        printf("2.NE PAS UTILISER\n");
        scanf("%d", &choix);
        while( choix != 1 && choix != 2){
            printf("IA : Saisie incorrect\n");
            getchar();
            scanf("%d",&choix);
        }
        if(choix == 1){
            player[numeroTour]->prison = 0;
            Color(player[numeroTour]->couleur, 0);
            printf("%s, ", player[numeroTour]->prenomJoueur);
            Color(3,0);
            printf("vous etes sortis de prison, felicitations !\n");


        }

    }
    else if (player[numeroTour]->carteSortiePrison != 1 && player[0]->carteSortiePrison == 1 || player[1]->carteSortiePrison == 1 || player[2]->carteSortiePrison == 1 || player[3]->carteSortiePrison == 1){
        for (int i = 0; i<nbDeJoueur; i++){

            if(player[i]->carteSortiePrison == 1 ){
                Color(player[i]->couleur, 0);
                printf("\n%s, ", player[i]->prenomJoueur);
                Color(5,0);
                printf("voulez-vous vendre votre carte 'sortir de prison' a ");
                Color(player[numeroTour]->couleur, 0);
                printf("%s ?\n", player[numeroTour]->prenomJoueur);
                printf("                                  ");
                Color(10,0);
                printf("1.OUI");
                printf("                                  ");
                Color(12,0);
                printf("2.NON\n");
                int answer;
                scanf("%d", &answer);
                while( answer != 1 && answer != 2){
                    printf("IA : Saisie incorrect\n");
                    getchar();
                    scanf("%d",&answer);
                }
                if(answer == 1){
                    Color(5,0);
                    printf("Pour quel prix voulez-vous la vendre ?\n");
                    int prixCarte;
                    scanf("%d", &prixCarte);
                    Color(player[numeroTour]->couleur, 0);
                    printf("%s, ", player[numeroTour]->prenomJoueur);
                    Color(5,0);
                    printf("Acceptez-vous ce prix ?\n");
                    printf("                                  ");
                    Color(10,0);
                    printf("1.OUI");
                    printf("                                  ");
                    Color(12,0);
                    printf("2.NON\n");
                    int answer2;
                    fflush(stdin);
                    scanf("%d", &answer2);
                    while( answer2 != 1 && answer2 != 2){
                        printf("IA : Saisie incorrect\n");
                        getchar();
                        scanf("%d",&answer2);
                    }
                    if (answer2 == 1){
                        Color(5,0);
                        player[numeroTour]->argent -= prixCarte;
                        player[i]->carteSortiePrison = 0;
                        player[i]->argent += prixCarte;
                        printf("Vous pouvez sortir de la prison, ");
                        Color(player[numeroTour]->couleur, 0);
                        printf("%s !\n", player[numeroTour]->prenomJoueur);
                        player[numeroTour]->prison = 0;


                    }

                }
            }
        }
    }

    ///si le joueur ne paye pas 50 et n'a pas de carte
if(player[numeroTour]->prison == 1){
    if(player[numeroTour]->numeroTourPrison == 3){
            Color(player[numeroTour]->couleur, 0);
            printf("\n%s, ", player[numeroTour]->prenomJoueur);
            Color(3,0);
            printf("Vous sortez de prison en payant l'amande de 50 euros !\n");
            player[numeroTour]->argent -= 50;

            player[numeroTour]->prison = 0;
            player[numeroTour]->numeroTourPrison = 0;
    }
    else if(player[numeroTour]->numeroTourPrison == 1 || player[numeroTour]->numeroTourPrison == 2){
        Color(player[numeroTour]->couleur, 0);
        printf("\n%s, ", player[numeroTour]->prenomJoueur);
        Color(3,0);
        printf("vous etes en prison !\n");
        printf("Voulez-vous payer une amende de 50 euros pour sortir de la prison spatiale ?\n");
        printf("                                  ");
        Color(10,0);
        printf("1.OUI");
        printf("                                  ");
        Color(12,0);
        printf("2.NON\n");
        scanf("%d", &choix4);
        while( choix4 != 1 && choix4 != 2){
            printf("IA : Saisie incorrect\n");
            getchar();
            scanf("%d",&choix4);
        }
        if(choix4 == 1){
            player[numeroTour]->prison = 0;
            Color(player[numeroTour]->couleur, 0);
            printf("%s, ", player[numeroTour]->prenomJoueur);
            Color(3,0);
            printf("vous etes sortis de prison, felicitations !\n");
            player[numeroTour]->argent -= 50;

        }
        else{
            printf("Appuyer sur 1 pour lancer les des. Si vous faites un double, vous avez l'autorisation de quitter la prison spatiale !\n");
            scanf("%d",&choix2);
            while(choix2 != 1){
                printf("IA : Saisie incorrect\n");
                getchar();
                scanf("%d",&choix2);
            }

            lancerDe(player,de,numeroTour);

            if (de[0] == de[1]){
                player[numeroTour]->prison = 0;
                Color(player[numeroTour]->couleur, 0);
                printf("%s, ", player[numeroTour]->prenomJoueur);
                Color(3,0);
                printf("vous etes sortis de prison, felicitations !\n");

            }
            else{
                Color(3,0);
                printf("Dommage, peut-etre au prochain tour !\n");
                player[numeroTour]->numeroTourPrison += 1;

            }





        }
    }

    else{

        Color(3,0);
        Color(player[numeroTour]->couleur, 0);
        printf("\n%s, ", player[numeroTour]->prenomJoueur);
        Color(3,0);
        printf("vous etes en prison !\n");
        printf("Appuyer sur 1 pour lancer les des. Si vous faites un double, vous avez l'autorisation de quitter la prison spatiale !\n");
        scanf("%d",&choix2);
        while(choix2 != 1){
            printf("IA : Saisie incorrect\n");
            getchar();
            scanf("%d",&choix2);
        }

        lancerDe(player,de,numeroTour);

        if (de[0] == de[1]){
            player[numeroTour]->prison = 0;
            Color(player[numeroTour]->couleur, 0);
            printf("%s, ", player[numeroTour]->prenomJoueur);
            Color(3,0);
            printf("vous etes sortis de prison, felicitations !\n");

        }
        else{
            Color(3,0);
            printf("Dommage, peut-etre au prochain tour !\n");
            player[numeroTour]->numeroTourPrison += 1;

        }

    }
}

}




///PIOCHE
int piocheCartesChances(int carte, t_joueur player[NbJoueurMax][TAILLE], int nombreDeJoueur, int tourJoueur)
{

    switch (carte)
    {
        case 1:
        case 17:
        {
            c1(player, tourJoueur);
            break;
        }
        case 2:
        {
            c2(  player,   nombreDeJoueur,   tourJoueur);
            break;
        }
        case 3:
        {
            c3( player,   tourJoueur);
            break;
        }
        case 4:
        {
            c4( player,   tourJoueur);
            break;
        }
        case 5:
        {
            c5( player,   tourJoueur);
            break;
        }
        case 6:
        {
            c6( player ,   tourJoueur);
            break;
        }
        case 7:
        {
            c7( player ,   tourJoueur);
            break;
        }
        case 8:
        {
            c8( player, tourJoueur);
            break;
        }
        case 9:
        {
            c9(  player, tourJoueur );
            break;
        }
        case 10:
        {
            c10(  player ,   tourJoueur);
            break;
        }
        case 11:
        {
            c11(  player, tourJoueur );
            break;
        }
        case 12:
        {
            c12(  player, tourJoueur );
            break;
        }
        case 13:
        {
            c13(player, nombreDeJoueur, tourJoueur);
            break;
        }
        case 14:
        {
            c14(  player ,   tourJoueur);
            break;
        }
        case 15:
        {
            c15(  player, tourJoueur);
            break;
        }
        case 16:
        {
            c16(  player ,   tourJoueur);
            break;
        }


    }
}
