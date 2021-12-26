#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 200

#include "bib.h"

///MANQUE CARTES COMMUNAUTE

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

///CARTES CHANCES
void c1(t_joueur player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="VOUS ETES LIBERES DE PRISON!\n";
    Color(3,0);
    printf("%s", c);
    //faire en sorte que le joueur garde la carte et coder avec prison
}


void c2(t_joueur player[NbJoueurMax][TAILLE], int nombreDeJoueur, int tourJoueur)
{
    char c[TAILLE]="JOYEUX ANNIVERSAIRE!\nChaque joueur vous verse 50 \n";
    Color(3,0);

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
    char c[TAILLE]="CAMPAGNE PUBLICITAIRE PAYANTE!\nLa banque vous verse 100\n";
    Color(3,0);

    printf("%s", c);
    player[tourJoueur]->argent += 100;
}

void c4(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    Color(3,0);
    char c[TAILLE]="SOIREE AU CASINO!\nChoisissez un adversaire.\nLancez tous les deux les des.\nCelui qui obtient le plus gros score recoit 200 de la Banque.\n";
    printf("%s\n", c);

    ///il faut blinder si l'utilisateur choix n'existe pas
    printf("Veuillez saisir le numero de l'utilisateur que vous avez choisi de defier : ");
    int choix = 0;
    scanf("%d", &choix);

    choix -= 1; //car le tableau des joueurs commence à 0
    int de1[2];
    int de2[2];
    int resultat1 = 0;
    int resultat2 = 0;

    while (resultat1 == resultat2){
        Color(3,0);
        printf(" IA : Veuillez appuyer sur 1 pour lancer le de : ");
        int choix2;
        scanf("%d", &choix2);
        while(choix2 != 1){
            printf("\nIA : Je n'ai pas compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
            scanf("%s");
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
            scanf("%s");
            scanf("%d", &choix3);
        }
        resultat2 = lancerDe(player, de2, choix);
        Color(player[choix]->couleur, 0);
        printf("%s, vous avez un score de %d\n", player[choix]->prenomJoueur, resultat2);

        if (resultat1 > resultat2){
            player[tourJoueur]->argent += 200;
        }
        else if(resultat2 > resultat1){
            player[choix]->argent += 200;
        }

    }




}

void c5(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="SOIREE AU CASINO!\nChoisissez un adversaire.\nLancez tous les deux les des.\nCelui qui obtient le plus gros score recoit 200 de la Banque.\n";
    Color(3,0);
    printf("%s", c);


    ///il faut blinder si l'utilisateur choix n'existe pas
    printf("Veuillez saisir le numero de l'utilisateur que vous avez choisi de defier : ");
    int choix = 0;
    scanf("%d", &choix);

    choix -= 1; //car le tableau des joueurs commence à 0
    int de1[2];
    int de2[2];
    int resultat1 = 0;
    int resultat2 = 0;

    while (resultat1 == resultat2){
        Color(3,0);
        printf(" IA : Veuillez appuyer sur 1 pour lancer le de : ");
        int choix2;
        scanf("%d", &choix2);
        while(choix2 != 1){
            printf("\nIA : Je n'ai pas compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
            scanf("%s");
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
            scanf("%s");
            scanf("%d", &choix3);
        }
        resultat2 = lancerDe(player, de2, choix);
        Color(player[choix]->couleur, 0);
        printf("%s, vous avez un score de %d\n", player[choix]->prenomJoueur, resultat2);

        if (resultat1 > resultat2){
            player[tourJoueur]->argent += 200;
        }
        else if(resultat2 > resultat1){
            player[choix]->argent += 200;
        }

    }

}

void c6(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="PRIX DU BUSINESSMAN DE L'ANNEE!\nLa banque vous verse 400.\n";
    Color(3,0);

    printf("%s", c);
    player[tourJoueur]->argent += 400;
}

void c7(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="VOUS LANCEZ VOTRE SITE INTERNET!\nVos ventes decollent!\nLa banque vous verse 300.\n";
    Color(3,0);

    printf("%s", c);
    player[tourJoueur]->argent += 300;
}

void c8(t_joueur player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="FRAUDE! ALLEZ EN PRISON!\nNe recevez pas d'argent en passant par la case depart.\n";
    Color(3,0);

    printf("%s", c);
    //coder avec prison
}

void c9(t_joueur player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="AVANCE SUR VOS PROFITS!\nAvancez jusqu'a la case Depart pour toucher votre salaire!\n";
    Color(3,0);

    printf("%s", c);
    //deplacement sur la case départ et donc salaire (à relier à la case départ)
}

void c10(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="AMENDE POUR ESPIONNAGE INDUSTRIEL!\nPayez 200 a la Banque.\n";
    Color(3,0);

    printf("%s", c);
    player[tourJoueur]->argent -= 200;
}

void c11(t_joueur player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="ROULEZ BOLIDES!\nAvancez de cinq cases dans votre voiture de course!\n";
    Color(3,0);

    printf("%s", c);
    //A coder avec dés + cases
}

void c12(t_joueur player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="ALLEZ EN PRISON!\nNe recevez pas d'argent en passant par la case depart.\n";
    Color(3,0);

    printf("%s", c);
    //coder avec prison
}
