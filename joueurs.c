#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 300
#include "bib.h"



///Sous-programme permettant de r�cup�rer le nom et num�ro des joueurs
t_joueur saisie(t_joueur player[NbJoueurMax][TAILLE], int nombreDeJoueur)
{

    char astronaute[NbJoueurMax][TAILLE]; //tableau des noms de familles
    strcpy(astronaute[0], "PESQUET");
    strcpy(astronaute[1], "ARMSTRONG");
    strcpy(astronaute[2], "GARGARINE");
    strcpy(astronaute[3], "ALDRIN");
    strcpy(astronaute[4], "COLLINS");
    strcpy(astronaute[5], "GLENN");




    for (int i = 0; i<nombreDeJoueur; i++)
    {
        if (i == 0)
        {
            Color(4,0);
            player[i]->couleurJoueur = 4;
            printf("\n\nBienvenu cher joueur !\n\nVotre but aujourd'hui est de devenir le joueur le plus riche\n\nBonne chance !\n\n");
            printf("Indiquez votre pr%cnom\n",0x82);

            scanf("%s", &player[i]->prenomJoueur);
            fflush(stdin);
            strcat(&player[i]->prenomJoueur, " "); //on ajoute un espace apr�s le pr�nom
            strcat(&player[i]->prenomJoueur, astronaute[i]); //on ajoute un nom d'astronaute au pr�nom de l'utilisateur

            player[i]->numeroJoueur = i+1;
            fflush(stdin);

            player[i]->argent = 1500;
            fflush(stdin);

            player[i]->couleur = 4;
        }
        else if (i==1)
        {
            Color(6,0);
            player[i]->couleurJoueur = 6;
            printf("\n\nBienvenu cher joueur !\n\nVotre but aujourd'hui est de devenir le joueur le plus riche\n\nBonne chance !\n\n");
            printf("Indiquez votre pr%cnom\n",0x82);

            scanf("%s", &player[i]->prenomJoueur);
            fflush(stdin);
            strcat(&player[i]->prenomJoueur, " "); //on ajoute un espace apr�s le pr�nom
            strcat(&player[i]->prenomJoueur, astronaute[i]); //on ajoute un nom d'astronaute au pr�nom de l'utilisateur

            player[i]->numeroJoueur = i+1;
            fflush(stdin);

            player[i]->argent = 1500;
            fflush(stdin);

            player[i]->couleur = 6;
        }
        else if (i==2)
        {
            Color(9,0);
            player[i]->couleurJoueur = 9;
            printf("\n\nBienvenu cher joueur !\n\nVotre but aujourd'hui est de devenir le joueur le plus riche\n\nBonne chance !\n\n");
            printf("Indiquez votre pr%cnom\n",0x82);

            scanf("%s", &player[i]->prenomJoueur);
            fflush(stdin);
            strcat(&player[i]->prenomJoueur, " "); //on ajoute un espace apr�s le pr�nom
            strcat(&player[i]->prenomJoueur, astronaute[i]); //on ajoute un nom d'astronaute au pr�nom de l'utilisateur

            player[i]->numeroJoueur = i+1;
            fflush(stdin);

            player[i]->argent = 1500;
            fflush(stdin);

            player[i]->couleur = 9;

        }

        else if (i==3)
        {
            Color(11,0);
            player[i]->couleurJoueur = 11;
            printf("\n\nBienvenu cher joueur !\n\nVotre but aujourd'hui est de devenir le joueur le plus riche\n\nBonne chance !\n\n");
            printf("Indiquez votre pr%cnom\n",0x82);

            scanf("%s", &player[i]->prenomJoueur);
            fflush(stdin);
            strcat(&player[i]->prenomJoueur, " "); //on ajoute un espace apr�s le pr�nom
            strcat(&player[i]->prenomJoueur, astronaute[i]); //on ajoute un nom d'astronaute au pr�nom de l'utilisateur

            player[i]->numeroJoueur = i+1;
            fflush(stdin);

            player[i]->argent = 1500;
            fflush(stdin);

            player[i]->couleur = 11;

        }



    }
    Color(3,0);
    printf("\nIA : Les joueurs de cette partie sont les suivants : \n"); //affichage des joueurs de la partie
    for(int j = 0; j<nombreDeJoueur; j++)
    {
        Color(player[j]->couleur, 0);
        printf("Joueur numero %d : %s  \n Porte Monnaie : %d\n", player[j]->numeroJoueur, player[j]->prenomJoueur, player[j]->argent);

    }

}

int choixDuPremier(int nbJoueur)
{
        int nombre = 0 + rand()%nbJoueur; //on choisit une personne parmi tous les utilisateurs pour commencer.
        return nombre;
}

int lancerDe(t_joueur player[NbJoueurMax][TAILLE], int de[2], int joueur)
{
    for (int i = 0; i<=1; i++)
    {
        de[i] = 1 + rand()%6; //r�cuperer une valeur entre 0 et 6
        Color(player[joueur]->couleur, 0);
        printf("%s a lance un %d\n", &player[joueur]->prenomJoueur, de[i]);
    }

    int nombreDeplacement = 0;
    nombreDeplacement = de[0] + de[1]; //somme des 2 d�s pour calcule le nombre de deplacements.




}
