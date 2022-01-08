#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 200

#include "bib.h"

void hypotheque (t_joueur player [NbJoueurMax] [TAILLE],int tourjoueur,int prixapayer,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_){
    Color(13,0);
    printf("\n                                      HYPOTHEQUE");
    printf("\nVoici vos proprietes ");
    Color(player[tourjoueur]->couleurJoueur,0);
    printf("%s",player[tourjoueur]->prenomJoueur);
    Color(13,0);
    printf(" : ");
    Color(player[tourjoueur]->couleurJoueur,0);
    printf("%s",player[tourjoueur]->proprietes);
    Color(13,0);
    printf("\nVous avez une dette de %d",prixapayer);
    printf("\nIndiquez en majuscule la propriete que vous souhaitez hypothequer : ");
    Color(15,0);
    char input [TAILLE];
    fflush(stdin);
    gets(input);
    char * result = strstr(player[tourjoueur]->proprietes,input);
    while (result == NULL){
        Color(13,0);
        printf("\nPropriete non reconnu, veuillez ressaisir : ");
        fflush(stdin);
        Color(15,0);
        gets(input);
        result = NULL;
        result = strstr(player[tourjoueur]->proprietes,input);
    }
    int prixhp = cherchplan(terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_,input);
    player[tourjoueur]->famillec[cherchplanp(terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_,input)] -= 1;
    strcat(input,",");
    strcpy(player[tourjoueur]->proprietes,str_replace(player[tourjoueur]->proprietes,input,""));
    player[tourjoueur]->argent += prixhp;
    Color(13,0);
    printf("\nLe prix hypothequaire de la planete %s est de %d",input,prixhp);
    prixapayer += prixhp;
    if (prixapayer < 0){
        printf("\nL'hypotheque de cette prorpiete ne suffit pas a rembourser votre dette !");
        printf("\nVoulez vous poursuivre avec une autre hypotheque ?");
        printf("\n                                  ");
        Color(10,0);
        printf("1.OUI");
        printf("                                  ");
        Color(12,0);
        printf("2.NON\n");
        int inpu;
        Color(3,0);
        scanf("%d",&inpu);
        while( inpu != 1 && inpu != 2){
            printf("IA : Saisie incorrect, veuilelz ressaisir : ");
            fflush(stdin);
            scanf("%d",&inpu);
        }
        if ( inpu == 1){
            hypotheque(player,tourjoueur,prixapayer,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_);
        }
    }
    printf("\nVotre dette a ete rembourse avec succes !");
    printf("\nInformation J%d : ",player[tourjoueur]->numeroJoueur);
        Color(player[tourjoueur]->couleurJoueur,0);
        printf("%s",player[tourjoueur]->prenomJoueur);
        printf("\nPorte Monnaie : %d",player[tourjoueur]->argent);
        printf("\nProprietes : ");
        printf("%s",player[tourjoueur]->proprietes);
    Color(13,0);
    printf("\nFin de l'hypotheque ...\n");


}



void echange2 (int nombreJoueur,int j, t_joueur player [NbJoueurMax] [TAILLE], int tourjoueur,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_){
        Color(5,0);
        int compteur;
        int compteur2;
        for (int i = 0; i < 9 ; i++){
            if  ( player[tourjoueur]->famillec[i] > 0) {
                compteur++;
            }
        }
        for (int h = 0; h < 9 ; h++){
            if  ( player[j]->famillec[h] > 0) {
                compteur2++;
            }
        }
        if ( compteur == 0 || compteur2 == 0){
            Color(3,0);
            printf("IA : Ce joueur n'a pas de proprietes !\n");
            echange(nombreJoueur,player,tourjoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_);
        }
        else {
        printf("\n                                                  L'ECHANGE COMMENCE ENTRE LE J%d ET LE J%d !",player[tourjoueur]->numeroJoueur,player[j]->numeroJoueur);
        printf("\nInformation J%d : ",player[tourjoueur]->numeroJoueur);
        Color(player[tourjoueur]->couleurJoueur,0);
        printf("%s",player[tourjoueur]->prenomJoueur);
        printf("\nPorte Monnaie : %d",player[tourjoueur]->argent);
        printf("\nProprietes : ");
        printf("%s",player[tourjoueur]->proprietes);
        Color(5,0);
        printf("\nInformation J%d : ",player[j]->numeroJoueur);
        Color(player[j]->couleurJoueur,0);
        printf("%s",player[j]->prenomJoueur);
        printf("\nPorte Monnaie : %d",player[j]->argent);
        printf("\nProprietes : ");
        printf("%s",player[j]->proprietes);
        Color(5,0);
        printf("\nA present choissiez quel propriete doit echange ");
        Color(player[tourjoueur]->couleurJoueur,0);
        printf("%s",player[tourjoueur]->prenomJoueur);
        Color(5,0);
        printf(".(Ecrire en majuscule le nom de la propriete) : ");
        char input1 [TAILLE] = {NULL};
        fflush(stdin);
        gets(input1);
        char * result = strstr(player[tourjoueur]->proprietes,input1);
        while ( result == NULL ) {
            printf("Vous ne possedez pas cette propriete !(ou vous l'avez peut etre mal ecrite).\nVeuillez ressaisir : ");
            gets(input1);
            result = NULL;
            result = strstr(player[tourjoueur]->proprietes,input1);
        }

        int argent1;
        printf("\nEt combien d'euros avec ca ? : ");
        scanf("%d",&argent1);
        while(argent1 < 0 || argent1 > player[tourjoueur]->argent){
            fflush(stdin);
            printf("\nFonds insuffisants, veuillez ressaisir : ");
            scanf("%d",&argent1);
        }
        char input2 [TAILLE];
        int argent2;
        printf("A present choissiez quel propriete doit echange ");
        Color(player[j]->couleurJoueur,0);
        printf("%s",player[j]->prenomJoueur);
        Color(5,0);
        printf(".(Ecrire en majuscule le nom de la propriete) : ");
        getchar();
        gets(input2);
        char * result2 = strstr(player[j]->proprietes,input2);
        while ( result2 == NULL ) {
            printf("Vous ne possedez pas cette propriete !(ou vous l'avez peut etre mal ecrite).\nVeuillez ressaisir : ");
            gets(input2);
            result2 = NULL;
            result2 = strstr(player[j]->proprietes,input2);
        }

        printf("\nEt combien d'euros avec ca ? : ");
        scanf("%d",&argent2);
        while(argent2 < 0 || argent2 > player[tourjoueur]->argent){
            fflush(stdin);
            printf("\nFonds insuffisants, veuillezz ressaisir : ");
            scanf("%d",&argent2);
        }
        player[j]->argent += argent1;
        player[j]->argent -= argent2;
        player[tourjoueur]->argent += argent2;
        player[tourjoueur]->argent -= argent1;
        player[tourjoueur]->famillec[cherchplanp(terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_,input1)] -= 1;
        player[tourjoueur]->famillec[cherchplanp(terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_,input2)] += 1;
        player[j]->famillec[cherchplanp(terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_,input1)] += 1;
        player[j]->famillec[cherchplanp(terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_,input2)] -= 1;
        strcat(input1,",");
        strcat(input2,",");
        strcat(player[j]->proprietes,input1);
        strcpy(player[tourjoueur]->proprietes,str_replace(player[tourjoueur]->proprietes,input1,""));
        strcpy(player[j]->proprietes,str_replace(player[j]->proprietes,input2,""));
        strcat(player[tourjoueur]->proprietes,input2);
        printf("\nEchange effectue ! Felicitation !");
        printf("\nRecapitulatif : ");
        printf("\nInformation J%d : ",player[tourjoueur]->numeroJoueur);
        Color(player[tourjoueur]->couleurJoueur,0);
        printf("%s",player[tourjoueur]->prenomJoueur);
        printf("\nPorte Monnaie : %d",player[tourjoueur]->argent);
        printf("\nProprietes : ");
        printf("%s",player[tourjoueur]->proprietes);
        Color(5,0);
        printf("\nInformation J%d : ",player[j]->numeroJoueur);
        Color(player[j]->couleurJoueur,0);
        printf("%s",player[j]->prenomJoueur);
        printf("\nPorte Monnaie : %d",player[j]->argent);
        printf("\nProprietes : ");
        printf("%s\n",player[j]->proprietes);
        }

}


void echange (int* nombreDeJoueur,t_joueur player[NbJoueurMax][TAILLE],int tourjoueur,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_){
    Color(3,0);
    printf("IA : Souhaitez vous faire un echange ?\n");
    printf("                                  ");
    Color(10,0);
    printf("1.OUI");
    printf("                                  ");
    Color(12,0);
    printf("2.NON\n");
    int inpu;
    scanf("%d",&inpu);
    while( inpu != 1 && inpu != 2){
        printf("IA : Saisie incorrect, veuilelz ressaisir : ");
        fflush(stdin);
        scanf("%d",&inpu);
    }
    if (inpu == 1){
        if (nombreDeJoueur == 2){
            Color(3,0);
            printf("\nIA : Avec qui souhaitez-vous echanger ?");
            Color(player[0]->couleurJoueur,0);
            printf("\n1.%s  ",player[0]->prenomJoueur);
            Color(player[1]->couleurJoueur,0);
            printf(" 2.%s",player[1]->prenomJoueur);
            int j;
            Color(3,0);
            scanf("%d",&j);
            while (j != 1 && j!= 2){
                fflush(stdin);
                printf("Saisie incorrect.");
                scanf("%d",&j);
            }
            while ((j - 1) == tourjoueur){
                fflush(stdin);
                printf("IA : Vous ne pouvez pas echanger avec vous meme !\nIA : Veuillez ressaisir : ");
                scanf("%d",&j);
            }
            j--;
            echange2(nombreDeJoueur,j,player,tourjoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_);

        }

        if (nombreDeJoueur == 3){
            Color(3,0);
            printf("\nIA : Avec qui souhaitez-vous echanger ?");
            Color(player[0]->couleurJoueur,0);
            printf("\n1.%s  ",player[0]->prenomJoueur);
            Color(player[1]->couleurJoueur,0);
            printf("2.%s  ",player[1]->prenomJoueur);
            Color(player[2]->couleurJoueur,0);
            printf("3.%s",player[2]->prenomJoueur);
            int j;
            Color(3,0);
            scanf("%d",&j);
            while (j != 1 && j!= 2 && j != 3){
                fflush(stdin);
                printf("Saisie incorrect.");
                scanf("%d",&j);
            }
            while ((j - 1)  == tourjoueur){
                fflush(stdin);
                printf("IA : Vous ne pouvez pas echanger avec vous meme !\nIA : Veuillez ressaisir : ");
                scanf("%d",&j);
            }
            j--;
            echange2(nombreDeJoueur,j,player,tourjoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_);

        }
        else if (nombreDeJoueur == 4){

            Color(3,0);
            printf("\nIA : Avec qui souhaitez-vous echanger ?");
            Color(player[0]->couleurJoueur,0);
            printf("\n1.%s  ",player[0]->prenomJoueur);
            Color(player[1]->couleurJoueur,0);
            printf("2.%s  ",player[1]->prenomJoueur);
            Color(player[2]->couleurJoueur,0);
            printf("3.%s  ",player[2]->prenomJoueur);
            Color(player[3]->couleurJoueur,0);
            printf("4.%s",player[3]->prenomJoueur);
            int k;
            Color(3,0);
            scanf("%d",&k);
            while (k != 1 && k!= 2 && k != 3 && k!= 4){
                fflush(stdin);
                printf("IA : Saisie incorrect.");
                scanf("%d",&k);
            }
            while ((k- 1)  == tourjoueur){
                fflush(stdin);
                printf("IA : Vous ne pouvez pas echanger avec vous meme !\nIA : Veuillez ressaisir : ");
                scanf("%d",&k);
            }
            k--;
            echange2(nombreDeJoueur,k,player,tourjoueur,terre_,mars_,jupiter_, saturne_, pluton_, neptune_, venus_, uranus_, mercure_, soleil_, lune_, phobos_, ganymede_, callisto_, io_, titan_, voieLactee_, andromede_, tetard_,nuageDeMagellan_);
        }
    }
}
