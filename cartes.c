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

void cc1()
{
    char c[TAILLE]="NON!\nRefusez de payer un joueur qui vous r�clame de l'argent ou qui joue une carte DEAL VOLE ou DEAL FORCE\nVous pouvez conserver cette carte pour l'utiliser plus tard.\n";
    Color(3,0);
    printf("%s", c);

}

void cc2()
{
    char c[TAILLE]="BONUS!\nAchetez la prochaine propriete n'appartenat a personne puis recevez 100 de bonus de la banque\n";
    Color(3,0);
    printf("%s", c);

}

void cc3()
{
    char c[TAILLE]="DROIT DEVANT!\nAvancez jusqu'a la prochaine propriete n'appartenant a personne.\nAchetez-la si vous le souhaitez.\n";
    Color(3,0);
    printf("%s", c);

}


void cc4()
{
    char c[TAILLE]="DEAL VOLE!\nVolez la carte de propriete de votre choix a un autre joueur.\nVous pouvez conserver cette carte pour l'utiiser plus tard.\n";
    Color(3,0);
    printf("%s", c);

}


void cc5()
{
    char c[TAILLE]="DEAL FORCE!\nEchangez une de vos proprietes avec celle du joueur de votre choix\nVous pouvez conserver cette carte pour l'utiliser plus tard.\n";
    Color(3,0);
    printf("%s", c);

}


void cc6()
{
    char c[TAILLE]="CADEAU DE MARIAGE\nAchetez la prochaine propriete n'appartenant a personne puis recevez 20 de chacun des autres joueurs.\n";
    Color(3,0);
    printf("%s", c);

}


void cc7()
{
    char c[TAILLE]="BONNE ACTION\nAchetez la prochaine propriete n'appartenant a personne puis donnez 20 a chacun des autres joueurs.\n";
    Color(3,0);
    printf("%s", c);

}


void cc8()
{
    char c[TAILLE]="PETIT VOYAGE!\nAvancez jusqu'a la prochaine propriete n'appartenant a personne.\n. Achetez-la ou mettez-la aux encheres.\n";
    Color(3,0);
    printf("%s", c);

}


void cc9()
{
    char c[TAILLE]="MAISON GRATUITE!\nConstruisez une maison sur n'importe laquelle des proprietes d'un de vos groupes de proprietes complets.\nVous pouvez conserver cette carte pour l'utiliser plus tard.\n";
    Color(3,0);
    printf("%s", c);

}


void cc10()
{
    char c[TAILLE]="COUP DOUBLE!\nAchetez la prochaine propriete n'appartenant a personne.\nAchetez-la ou payez le loyer demande.\n";
    Color(3,0);
    printf("%s", c);

}


void cc11()
{
    char c[TAILLE]="PETIT TOUR EN LIMOUSINE!\nAchetez la prochaine propriete n'appartenant a personne.\n";
    Color(3,0);
    printf("%s", c);

}


void cc12()
{
    char c[TAILLE]="DEAL VOLE!\nVolez la carte de propriete de votre choix a un autre joueur.\nVous pouvez conserver cette carte pour l'utiiser plus tard.\n";
    Color(3,0);
    printf("%s", c);

}


void cc13()
{
    char c[TAILLE]="PETIT TOUR EN LIMOUSINE!\nAchetez la prochaine propriete n'appartenant a personne.\n";
    Color(3,0);
    printf("%s", c);

}


void cc14()
{
    char c[TAILLE]="PETIT VOYAGE!\nAvancez jusqu'a la prochaine propriete n'appartenant a personne.\n. Achetez-la ou mettez-la aux encheres.\n";
    Color(3,0);
    printf("%s", c);

}


void cc15()
{
    char c[TAILLE]="BONNE ACTION\nAchetez la prochaine propriete n'appartenant a personne puis donnez 20 a chacun des autres joueurs.\n";
    Color(3,0);
    printf("%s", c);

}


void cc16()
{
    char c[TAILLE]="CADEAU DE MARIAGE\nAchetez la prochaine propriete n'appartenant a personne puis recevez 20 de chacun des autres joueurs.\n";
    Color(3,0);
    printf("%s", c);

}



///PIOCHE
/*int piocheCartesCommunautes()
{



}*/

///----------------------------------------------------------------------CARTES CHANCES-------------------------------------------------------------------



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

    choix -= 1; //car le tableau des joueurs commence � 0
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
            fflush(stdin);

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

    choix -= 1; //car le tableau des joueurs commence � 0
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
            fflush(stdin);
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
    //deplacement sur la case d�part et donc salaire (� relier � la case d�part)
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
    //A coder avec d�s + cases
}


void c12(t_joueur player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="ALLEZ EN PRISON!\nNe recevez pas d'argent en passant par la case depart.\n";
    Color(3,0);

    printf("%s", c);
    //coder avec prison
}


void c13(t_joueur player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="Vous touchez le fruit de vos investissements!\nChaque joueur vous donne 20\n";
    Color(3,0);

    printf("%s", c);
    //coder avec prison
}


void c14(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="SOIREE AU CASINO!\nChoisissez un adversaire.\nLancez tous les deux les des.\nCelui qui obtient le plus gros score recoit 200 de la Banque.\n";
    Color(3,0);
    printf("%s", c);


    ///il faut blinder si l'utilisateur choix n'existe pas
    printf("Veuillez saisir le numero de l'utilisateur que vous avez choisi de defier : ");
    int choix = 0;
    scanf("%d", &choix);

    choix -= 1; //car le tableau des joueurs commence � 0
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
            fflush(stdin);
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
            player[tourJoueur]->argent += 200;
        }
        else if(resultat2 > resultat1){
            player[choix]->argent += 200;
        }

    }

}


void c15(t_joueur player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="ALLEZ EN PRISON!\nNe recevez pas d'argent en passant par la case depart.\n";
    Color(3,0);

    printf("%s", c);
    //coder avec prison.
}


void c16(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur)
{
    char c[TAILLE]="AMENDE POUR ESPIONNAGE INDUSTRIEL!\nPayez 200 a la Banque.\n";
    Color(3,0);

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
/*int piocheCartesChances(int *i)
{

    if (*i==17){
        *i=1;
    }
    if (*i==1)
    {
        c1(t_joueur player[NbJoueurMax][TAILLE]);
    }
    if (*i==2)
    {
        c2(t_joueur player[NbJoueurMax][TAILLE], int nombreDeJoueur, int tourJoueur);
    }
    if (*i==3)
    {
        c3(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur);
    }
    if (*i==4)
    {
        c4(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur);
    }
    if (*i==5)
    {
        c5(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur);
    }
    if (*i==6)
    {
        c6(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur);
    }
    if (*i==7)
    {
        c7(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur);
    }
    if (*i==8)
    {
        c8(t_joueur player[NbJoueurMax][TAILLE]);
    }
    if (*i==9)
    {
        c9(t_joueur player[NbJoueurMax][TAILLE]);
    }
    if (*i==10)
    {
        c10(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur);
    }
    if (*i==11)
    {
        c11(t_joueur player[NbJoueurMax][TAILLE]);
    }
    if (*i==12)
    {
        c12(t_joueur player[NbJoueurMax][TAILLE]);
    }
    if (*i==13)
    {
        c13(t_joueur player[NbJoueurMax][TAILLE]);
    }
    if (*i==14)
    {
        c14(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur);
    }
    if (*i==15)
    {
        c15(t_joueur player[NbJoueurMax][TAILLE]);
    }
    if (*i==16)
    {
        c16(t_joueur player[NbJoueurMax][TAILLE], int tourJoueur);
    }

}*/
