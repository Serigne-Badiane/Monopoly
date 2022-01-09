#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 200

#include "bib.h"



///-----------------------------------------------------------PROCEDURE D'ARRIVEE SUR LES PLANETES-----------------------------------------------------------

void arrivplan (planete* p,t_joueur player[NbJoueurMax][TAILLE],int tourjoueur,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_, int *maisonMax, int *hotelMax,int nombreJoueur){
    Color(3,0);
    printf("\n\n%cIA : Nous sommes arriv%cs sur une nouvelle plan%cte... La plan%cte %s !",0x10,0x82,0x8A,0x8A,p->nom);
    p->proprio = 5;
    for (int i =0 ; i<4 ; i++){
        char * result = strstr(player[i]->proprietes, p->nom);
        if (result != NULL){
            p->proprio = player[i]->numeroJoueur;
        }
        result = NULL;
    }

    ///************************************************CAS 1: où la propriété n'appartient à aucun joueur************************************************
    if (p->proprio != player[0]->numeroJoueur && p->proprio != player[1]->numeroJoueur && p->proprio != player[2]->numeroJoueur && p->proprio != player[3]->numeroJoueur){
        printf("\n%cIA : %s",0x10,p->anecdote);

        //affichage des données de la propriété
        printf("\n%cIA : Voici un r%capitulatif capitaine...",0x10,0x82);
        printf("\n\n                                                        ");
        Color(0,p->couleur);
        printf("%c PLAN%cTE %s %c",0x02,0xD4,p->nom,0x02);
        Color(15,0);
        printf("\n                          Prix d'achat : %d",p->prix);
        printf("\n                          Prix loyer sans sonde spatiale  : %d",p->loyer);
        printf("\n                              Prix loyer avec 1 sonde spatiale : %d",p->loyer1);
        printf("\n                              Prix loyer avec 2 sondes spatiales : %d",p->loyer2);
        printf("\n                              Prix loyer avec 3 sondes spatiales : %d",p->loyer3);
        printf("\n                              Prix loyer avec 4 sondes spatiales : %d",p->loyer4);
        printf("\n                              Prix loyer avec 1 station spatiale : %d",p->loyerHotel);

        printf("\n                          Prix d'une sonde spatiale : %d",p->prixMaison);
        printf("\n                          Prix d'une station spatiale : %d",p->prixMaison);
        printf("\n                          Prix hypoth%ccaire : %d",0x82,p->p_hypo);

        Color(3,0);
        printf("\nIA : La plan%cte est libre d'achat, souhaitez-vous l'acheter ?\n ", 0x8A);
        printf("                                  ");
        Color(10,0);
        printf("1.OUI");
        printf("                                  ");
        Color(12,0);
        printf("2.NON\n");
        Color(15,0);
        int answer;
        scanf("%d",&answer);
        while( answer != 1 && answer != 2){ //blindage du choix du joueur
            printf("IA : Saisie incorrecte\n");
            fflush(stdin);
            scanf("%d",&answer);
        }
        Color(3,0);

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~si le joueur veut acheter la propriété ET possède assez d'argent~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if ( answer == 1 && player[tourjoueur]->argent >= p->prix){
            p->proprio = player[tourjoueur]->numeroJoueur; //on ajoute le nom du joueur à la propriété
            strcat(player[tourjoueur]->proprietes,p->nom); //on ajoute la propriété au joueur
            strcat(player[tourjoueur]->proprietes,",");
            player[tourjoueur]->famillec[p->couleurF] += 1;
            verfiwin(player , tourjoueur , nombreJoueur); //on verifie si le joueur a assez de proriétés pour gagner

            player[tourjoueur]->argent -= p->prix; //on retire l'argent de l'achat
            printf("IA : BRAVO %s! Vous avez acquis une nouvelle plan%cte ...\n",player[tourjoueur]->prenomJoueur, 0x8A);
            Color(player[tourjoueur]->couleur, 0);
            printf("%s, Porte Monnaie : %d\n", player[tourjoueur]->prenomJoueur, player[tourjoueur]->argent);


        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~si le joueur veut acheter la propriété MAIS ne possède pas d'argent~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if(player[tourjoueur]->argent< p->prix){
            printf("IA : Vous n'avez pas assez d'argent pour acheter cette plan%cte !",0x8A );
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~si le joueur ne veut pas acheter la propriété~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else {
            printf("IA : Fin de tour ...");
        }

    }



    ///************************************************CAS 2: où la propriété appartient au joueur et que la propriété n'est pas hypothéquée************************************************
    else if(player[p->proprio - 1]->prenomJoueur == player[tourjoueur]->prenomJoueur && p->etatHypo == 0){
        Color(15,0);
        printf("\n                          Prix hypoth%ccaire : %d",0x82,p->p_hypo);
        printf("\n                          Nombre de sondes spatiales : %d",p->maison);
        printf("\n                          Nombre de stations spatiales : %d",p->hotel);
        printf("\n                          Prix d'une sonde spatiale : %d",p->prixMaison);
        printf("\n                          Prix loyer sans sonde spatiale  : %d",p->loyer);
        printf("\n                              Prix loyer avec 1 sonde spatiale : %d",p->loyer1);
        printf("\n                              Prix loyer avec 2 sondes spatiales : %d",p->loyer2);
        printf("\n                              Prix loyer avec 3 sondes spatiales : %d",p->loyer3);
        printf("\n                              Prix loyer avec 4 sondes spatiales : %d",p->loyer4);
        printf("\n                              Prix loyer avec 1 station spatiale : %d",p->loyerHotel);

        printf("                                  ");
        Color(3,0);
        printf("\nIA : Re-bonjour ");
        Color(player[tourjoueur]->couleur,0);
        printf("%s !\n", player[tourjoueur]->prenomJoueur);
        printf("Voici votre Porte Monnaie : %d\n", player[tourjoueur]->argent);
        printf("Voulez-vous acheter une nouvelle sonde spatiale ?\n");
        printf("                                  ");
        Color(10,0);
        printf("1.OUI");
        printf("                                  ");
        Color(12,0);
        printf("2.NON\n");
        Color(15,0);
        int choix;
        scanf("%d", &choix);
        Color(3,0);
        while( choix != 1 && choix != 2){ //blindage
            printf("IA : Saisie incorrecte\n");
            fflush(stdin);
            scanf("%d",&choix);
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si le joueur veut acheter une maison ET possède assez d'argent ET s'il reste des maisons~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if(choix == 1 && player[tourjoueur]->argent >= p->prixMaison && *maisonMax >= 0){
            printf("Vous avez achet%c une sonde spatiale, f%clicitations !\n", 0x82,0x82);
            player[tourjoueur]->argent -= p->prixMaison; //on déduit le prix d'une maison au joueur
            p->maison += 1; //on ajoute une maison à la propriété
            *maisonMax -= 1; //on enlève une maison aux maisons totales (32)

            ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si la propriété possède 4 maisons ET s'il reste des hôtels, on demande au joueur s'il veut acheter un hôtel~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            if (p->maison == 4 && *hotelMax >=0){
                printf("Vous poss%cdez 4 sondes spatiales. Voulez-vous les remplacer par une station spatiale ?\n ", 0x82);
                printf("                                  ");
                Color(10,0);
                printf("1.OUI");
                printf("                                  ");
                Color(12,0);
                printf("2.NON\n");
                Color(15,0);
                int choix2;
                scanf("%d", &choix2);
                while( choix != 1 && choix != 2){ //blindage
                    printf("IA : Saisie incorrecte\n");
                    fflush(stdin);
                    scanf("%d",&choix);
                }

                ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Si le joueur possède assez d'argent et veut acheter un hôtel~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                if(choix2 == 1 && player[tourjoueur]->argent >= p->prixMaison){
                    p->maison = 0; //on enlève les 4 maisons à la propriété
                    p->hotel = 1;   //on ajoute un hôtel à la propriété
                    *hotelMax -=1; //on enlève un hôtel au nombre d'hôtel maximum (12)
                    *maisonMax += 4; //on rajoute les 4 maisons au nombre de maisons maximum (32)
                    Color(3,0);
                    printf("Vous avez achet%c une station spatiale, f%clicitations !", 0x82,0x82);
                    player[tourjoueur]->argent -= p->prixMaison; //on déduit le prix d'une maison au joueur
                    printf("%d", player[tourjoueur]->argent);

                }

                ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sinon si le joueur ne veut pas acheter d'hôtel, on lui demande s'il veut en vendre~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                else if (choix2 == 2 && p->hotel > 0){
                    int choixVente2;
                    int nombreDeHotel;
                    Color(player[tourjoueur]->couleur, 0);
                    printf("%s, voulez-vous vendre une station spatiale ?\n", player[tourjoueur]->prenomJoueur);
                    printf("                                  ");
                    Color(10,0);
                    printf("1.OUI");
                    printf("                                  ");
                    Color(12,0);
                    printf("2.NON\n");
                    Color(15,0);
                    scanf("%d", &choixVente2);
                    Color(3,0);
                    while( choixVente2 != 1 && choixVente2 != 2){ //blindage
                        printf("IA : Saisie incorrecte\n");
                        fflush(stdin);
                        scanf("%d",&choixVente2);
                    }

                    ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~si le joueur veut vendre un hôtel~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if (choixVente2 == 1){
                        printf("Vous poss%cdez %d station(s).\n", 0x82, p->hotel);
                        printf("Combien de stations voulez-vous vendre ?\n");
                        scanf("%d", &nombreDeHotel);
                        while(nombreDeHotel > p->hotel ){ //blindage
                            printf("IA : Saisie incorrecte !\n");
                        }
                        *hotelMax += nombreDeHotel; //on rajoute un hôtel au nombre d'hôtel maximum
                        p->hotel -= nombreDeHotel; //on enlève un hôtel à la propriété
                        for (int m = 0; m<nombreDeHotel; m++){ //on retire le prix d'une maison, n fois (n étant le nombre d'hôtel que le joueur veut vendre)
                            player[tourjoueur]->argent += p->prixMaison;
                        }

                    }
                    printf("IA : Vente r%cussie !\n", 0x82);

                }

                ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si le joueur veut acheter un hôtel mais n'a pas assez d'argents~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                else if(player[tourjoueur]->argent < p->prixMaison){
                    printf("\nIA : Vous n'avez pas assez d'argent pour acheter une station spatiale");
                }

            }
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si le joueur ne veut pas acheter de maisons ET la propriété possède des maisons, on lui demande s'il veut en vendre~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (choix == 2 && p->maison > 0 && p->etatHypo == 0){
                int choixVente;
                int nombreDeMaison;
                printf("Voulez-vous vendre une sonde spatiale ?\n");
                printf("                                  ");
                Color(10,0);
                printf("1.OUI");
                printf("                                  ");
                Color(12,0);
                printf("2.NON\n");
                Color(15,0);
                scanf("%d", &choixVente);
                Color(3,0);
                while( choixVente != 1 && choixVente != 2){ //blindage
                    printf("IA : Saisie incorrecte\n");
                    fflush(stdin);
                    scanf("%d",&choixVente);
                }

                ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ si le joueur veut vendre~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                if (choixVente == 1){
                    printf("Vous poss%cdez %d sonde(s).\n",0x82, p->maison);
                    printf("Combien de maison voulez-vous vendre ?\n");
                    scanf("%d", &nombreDeMaison);
                    while(nombreDeMaison > p->maison ){ //blindage
                        printf("IA : Saisie incorrecte !\n");
                        fflush(stdin);
                        scanf("%d", &nombreDeMaison);
                    }
                    *maisonMax += nombreDeMaison; //on rajoute le nombre de maisons vendues au nombre de maisons maximum
                    p->maison -= nombreDeMaison; //on retire le nombre de maisons vendues à la propriété
                    for (int m = 0; m<nombreDeMaison; m++){ //on retire le prix d'une maison au joueur, n fois (n étant le nombre de maisons vendues)
                        player[tourjoueur]->argent += p->prixMaison;
                    }
                    printf("IA : Vente r%cussie !\n", 0x82);

                }
        }


        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sinon si le joueur ne veut pas acheter de maisons ET ne possède aucune maison ET aucun hôtel ET la propriété n'est pas hypothéquée~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if(choix == 2 && p->maison == 0 && p->hotel == 0 && p->etatHypo == 0){
                    int choixHypo;
                    Color(player[tourjoueur]->couleur,0);
                    printf("Souhaitez-vous hypoth%cquer votre propri%ct%c ?\n", 0x82,0x82,0x82);
                    printf("                                  ");
                    Color(10,0);
                    printf("1.OUI");
                    printf("                                  ");
                    Color(12,0);
                    printf("2.NON\n");
                    Color(15,0);
                    scanf("%d", &choixHypo);
                    Color(3,0);
                    while( choixHypo!= 1 && choixHypo != 2){ //blindage
                        printf("IA : Saisie incorrecte\n");
                        fflush(stdin);
                        scanf("%d",&choixHypo);
                    }

                    ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Si le joueur veut hypothéquer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if (choixHypo == 1){
                        Color(player[tourjoueur]->couleur, 0);
                        printf("Vous recevez %d !\n", p->p_hypo);
                        player[tourjoueur]->argent += p->p_hypo; //le joueur reçoit le prix de l'hypothèque
                        p->loyerFixe = p->loyer; //on stocke le prix du loyer dans un variable
                        p->loyer = 0; //le loyer passer à 0, car la propriété est hypothéquée
                        p->etatHypo = 1; //la propriété est hypothéquée
                    }
                }

    }

     ///************************************************CAS 3: àù la propriété est hypothéquée************************************************
    else if (player[p->proprio - 1]->prenomJoueur == player[tourjoueur]->prenomJoueur && p->etatHypo == 1){
            int choixLeverHypo;
            Color(player[tourjoueur]->couleur,0);
            printf("\n%s, voulez-vous lever l'hypoth%cque ?\n", player[tourjoueur]->prenomJoueur, 0x8A);
            printf("                                  ");
            Color(10,0);
            printf("1.OUI");
            printf("                                  ");
            Color(12,0);
            printf("2.NON\n");
            Color(15,0);
            scanf("%d", &choixLeverHypo);
            Color(3,0);
            while( choixLeverHypo!= 1 && choixLeverHypo != 2){ //blindage
                printf("IA : Saisie incorrecte\n");
                fflush(stdin);
                scanf("%d", &choixLeverHypo);
            }

            ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~si le joueur veut lever l'hypothèque~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            if(choixLeverHypo == 1){
                int prixADeduire= (p->p_hypo)*0.1; //il doit payer 10% de l'hypothèque
                prixADeduire += p->p_hypo;
                printf("Vous payez %d \n", prixADeduire);
                player[tourjoueur]->argent -= prixADeduire; //le joueur est déduit
                Color(player[tourjoueur]->couleur,0);
                printf("Porte-monnaie : %d\n", player[tourjoueur]->argent);
                p->loyer = p->loyerFixe; //le prix du loyer redevient "normal"
                p->etatHypo = 0; //la propriété n'est plus hypothéquée

            }
        }
        else if (player[tourjoueur]->argent < p->prixMaison){
            printf("\nIA : Vous n'avez pas assez d'argent pour acheter une sonde");
        }



    ///************************************************CAS 4: où le joueur ne possède pas la propriété mais est déjà possédée par un joueur************************************************
    else {
        Color(15,0);
        printf("\n                          Nombre de sondes spatiales : %d",p->maison);
        printf("\n                          Nombre de stations spatiales : %d",p->hotel);
        printf("\n                          Prix loyer sans sonde spatiale  : %d",p->loyer);
        printf("\n                              Prix loyer avec 1 sonde spatiale : %d",p->loyer1);
        printf("\n                              Prix loyer avec 2 sondes spatiales : %d",p->loyer2);
        printf("\n                              Prix loyer avec 3 sondes spatiales : %d",p->loyer3);
        printf("\n                              Prix loyer avec 4 sondes spatiales : %d",p->loyer4);
        printf("\n                              Prix loyer avec 1 station spatiale : %d",p->loyerHotel);


        printf("                                  ");
        Color(3,0);
        printf("\nIA : La plan%cte appartient a ", 0x8A);
        Color(player[p->proprio - 1]->couleur,0);
        printf("%s",player[p->proprio - 1]->prenomJoueur);
        Color(3,0);
        printf("... Vous devez lui payer son loyer !");

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si le propriétaire possède toutes les propriétés d'une même couleur, le joueur paye double loyer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
            printf("\nIA: ");
            Color(player[p->proprio - 1]->couleurJoueur,0);
            printf("%s",player[p->proprio - 1]->prenomJoueur);
            printf(" poss%cde cette famille d'astre ! Le loyer est donc double !", 0x8A );
            Color(player[tourjoueur]->couleur,0);
            printf("\n%s",player[tourjoueur]->prenomJoueur);
            Color(3,0);
            printf(" paye a ");
            Color(player[p->proprio - 1]->couleur,0);
            printf("%s",player[p->proprio - 1]->prenomJoueur);
            Color(3,0);
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si le loyer est "simple"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else {
        Color(player[tourjoueur]->couleur,0);
        printf("\n%s",player[tourjoueur]->prenomJoueur);
        Color(3,0);
        printf(" paye a ");
        Color(player[p->proprio - 1]->couleur,0);
        printf("%s",player[p->proprio - 1]->prenomJoueur);
        Color(3,0);
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si la propriété ne possède aucune maison / aucun hôtel ET possède assez d'argent pour payer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if(p->maison == 0 && p->hotel == 0 && player[tourjoueur]->argent >= p->loyer){

            ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si loyer double~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
            player[tourjoueur]->argent -= (p->loyer)*2; //le joueur payer le loyer 2 fois
            player[p->proprio - 1]->argent += (p->loyer)*2; //le propriétaire gagne 2 fois le loyer
            printf(" %d euros...",(p->loyer)*2);
            }

            ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si loyer simple~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            else {
            player[tourjoueur]->argent -= p->loyer; //on déduit le prix du loyer au joueur
            player[p->proprio - 1]->argent += p->loyer; //le propriétaire gagner l'argent du loyer
            printf(" %d euros...",p->loyer);
            }
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Sinon si la propriété ne possède une maison ET possède assez d'argent pour payer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (p->maison == 1 && player[tourjoueur]->argent >= p->loyer1){
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                player[tourjoueur]->argent -= (p->loyer1)*2;
                player[p->proprio - 1]->argent += (p->loyer1)*2;
                printf(" %d euros...",(p->loyer1)*2);
            }
            else{
            player[tourjoueur]->argent -= p->loyer1;
            player[p->proprio - 1]->argent += p->loyer1;
            printf(" %d euros...",p->loyer1);
            }
        }
        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si la propriété ne possède 2 maisons ET possède assez d'argent pour payer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (p->maison == 2 && player[tourjoueur]->argent >= p->loyer2){
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                player[tourjoueur]->argent -= (p->loyer2)*2;
                player[p->proprio - 1]->argent += (p->loyer2)*2;
                printf(" %d euros...",(p->loyer2)*2);
            }
            else{
                player[tourjoueur]->argent -= p->loyer2;
                player[p->proprio - 1]->argent += p->loyer2;
                printf(" %d euros...",p->loyer2);
            }
        }
        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Sinon si la propriété ne possède 3 maisons ET possède assez d'argent pour payer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (p->maison == 3 && player[tourjoueur]->argent >= p->loyer3){
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                player[tourjoueur]->argent -= (p->loyer3)*2;
                player[p->proprio - 1]->argent += (p->loyer3)*2;
                printf(" %d euros...",(p->loyer3)*2);
            }
            else {
                player[tourjoueur]->argent -= p->loyer3;
                player[p->proprio - 1]->argent += p->loyer3;
                printf(" %d euros...",p->loyer3);
            }
        }
        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Sinon si la propriété ne possède 4 maisons ET possède assez d'argent pour payer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if(p->maison == 4 && player[tourjoueur]->argent >= p->loyer4){
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                player[tourjoueur]->argent -= (p->loyer4)*2;
                player[p->proprio - 1]->argent += (p->loyer4)*2;
                printf(" %d euros...",(p->loyer4)*2);
            }
            else{
                player[tourjoueur]->argent -= p->loyer4;
                player[p->proprio - 1]->argent += p->loyer4;
                printf(" %d euros...",p->loyer4);
            }
        }
        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Sinon si la propriété ne possède un hôtel ET possède assez d'argent pour payer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if(p->hotel == 1 && player[tourjoueur]->argent >= p->loyerHotel){
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                player[tourjoueur]->argent -= (p->loyerHotel)*2;
                player[p->proprio - 1]->argent += (p->loyerHotel)*2;
                printf(" %d euros...",(p->loyerHotel)*2);
            }
            else{
                player[tourjoueur]->argent -= p->loyerHotel;
                player[p->proprio - 1] ->argent += p->loyerHotel;
                printf(" %d euros...", p->loyerHotel);
            }
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Sinon si le joueur ne possède pas assez d'argent pour payer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (p->maison == 0 && p->hotel == 0 && player[tourjoueur]->argent <= p->loyer) {
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer;
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
            prixapayer = ((p->loyer)*2) - player[tourjoueur]->argent;
            }
            else {
            prixapayer = p->loyer - player[tourjoueur]->argent;
            }
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                player[tourjoueur]->argent -= p->loyer *2;
                player[p->proprio - 1] ->argent += p->loyer *2;
            }

            else{
            player[tourjoueur]->argent -= p->loyer;
            player[p->proprio - 1] ->argent += p->loyer;
            }
        }
        else if (p->maison == 1 && player[tourjoueur]->argent <= p->loyer1){
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer;
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                prixapayer = ((p->loyer1)*2) - player[tourjoueur]->argent;
            }
            else {
            prixapayer = p->loyer1 - player[tourjoueur]->argent;
            }
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                player[tourjoueur]->argent -= p->loyer1 *2;
                player[p->proprio - 1] ->argent += p->loyer1 *2;
            }
            else{
            player[tourjoueur]->argent -= p->loyer1;
            player[p->proprio - 1] ->argent += p->loyer1;
            }
        }
        else if(p->maison == 2 && player[tourjoueur]->argent <= p->loyer2){
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer;
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                prixapayer = ((p->loyer2)*2) - player[tourjoueur]->argent;
            }
            else {
            prixapayer = p->loyer2 - player[tourjoueur]->argent;
            }
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                player[tourjoueur]->argent -= p->loyer2 *2;
                player[p->proprio - 1] ->argent += p->loyer2 *2;
            }
            else{
            player[tourjoueur]->argent -= p->loyer2;
            player[p->proprio - 1] ->argent += p->loyer2;
            }
        }
        else if (p->maison == 3 && player[tourjoueur]->argent <= p->loyer3){
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer;
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                prixapayer = ((p->loyer3)*2) - player[tourjoueur]->argent;
            }
            else {
            prixapayer = p->loyer3 - player[tourjoueur]->argent;
            }
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                player[tourjoueur]->argent -= p->loyer3 *2;
                player[p->proprio - 1] ->argent += p->loyer3 *2;
            }

            else{
            player[tourjoueur]->argent -= p->loyer3;
            player[p->proprio - 1] ->argent += p->loyer3;
            }
        }
        else if (p->maison == 4 && player[tourjoueur]->argent <= p->loyer4){
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer;
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                prixapayer = ((p->loyer4)*2) - player[tourjoueur]->argent;
            }
            else {
            prixapayer = p->loyer4 - player[tourjoueur]->argent;
            }
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                player[tourjoueur]->argent -= p->loyer4 *2;
                player[p->proprio - 1] ->argent += p->loyer4 *2;
            }

            else{
            player[tourjoueur]->argent -= p->loyer4;
            player[p->proprio - 1] ->argent += p->loyer4;
            }
        }
        else if (p->hotel == 1 && player[tourjoueur]->argent <= p->loyerHotel) {
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer;
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                prixapayer = ((p->loyerHotel)*2) - player[tourjoueur]->argent;
            }
            else {
            prixapayer = p->loyerHotel - player[tourjoueur]->argent;
            }
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);
            if (player[p->proprio - 1]->famillec[p->couleurF] == 2){
                player[tourjoueur]->argent -= p->loyerHotel *2;
                player[p->proprio - 1] ->argent += p->loyerHotel *2;
            }

            else{
            player[tourjoueur]->argent -= p->loyerHotel;
            player[p->proprio - 1] ->argent += p->loyerHotel;
            }
        }

        Color(player[p->proprio-1]->couleur, 0);
        printf("%s, Porte Monnaie : %d\n", player[p->proprio-1]->prenomJoueur, player[p->proprio - 1]->argent);

        Color(player[tourjoueur]->couleur, 0);
        printf("%s, Porte Monnaire : %d\n", player[tourjoueur]->prenomJoueur, player[tourjoueur]->argent);






    }
}


///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



///-----------------------------------------------------------PROCEDURE D'ARRIVEE SUR LES GALAXIES-----------------------------------------------------------
void arrivgalax(galaxie* g,t_joueur player[NbJoueurMax][TAILLE],int tourjoueur,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_,int nombreJoueur){
    Color(3,0);
    printf("\n\n%cIA : Nous sommes arriv%cs sur une nouvelle galaxie : ...%s !",0x10,0x82,g->nom);
    g->proprio = 5;
    for (int i =0 ; i<4 ; i++){
        char * result = strstr(player[i]->proprietes, g->nom);
        if (result != NULL){
            g->proprio = player[i]->numeroJoueur;
        }
        result = NULL;
    }

    ///************************************************CAS 1: où la galaxie appartient à un joueur************************************************
    if (g->proprio != player[tourjoueur]->numeroJoueur && g->proprio != 5){
        Color(15,0);
        printf("\n                          Nombre de galaxies poss%cd%ces par %s : %d",0x82,0x82,player[g->proprio - 1]->prenomJoueur, player[g->proprio-1]->nbDeGare);
        printf("\n                          Prix loyer avec 1 galaxie : %d",g->loyer);
        printf("\n                              Prix loyer avec 2 galaxies : %d",g->loyer1);
        printf("\n                              Prix loyer avec 3 galaxies : %d",g->loyer2);
        printf("\n                              Prix loyer avec 4 galaxies : %d",g->loyer3);
        Color(3,0);
        printf("\nIA : La galaxie appartient a ");
        Color(player[g->proprio - 1]->couleur,0);
        printf("%s",player[g->proprio - 1]->prenomJoueur);
        Color(3,0);
        printf("... Vous devez lui payer son loyer !");
        Color(player[tourjoueur]->couleur,0);
        printf("\n%s",player[tourjoueur]->prenomJoueur);
        Color(3,0);
        printf(" paye a ");
        Color(player[g->proprio - 1]->couleur,0);
        printf("%s",player[g->proprio - 1]->prenomJoueur);
        Color(3,0);

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~si le joueur possède 1 seule gare~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if(player[g->proprio - 1]->nbDeGare == 1 && player[tourjoueur]->argent >= g->loyer){
            player[tourjoueur]->argent -= g->loyer;
            player[g->proprio - 1]->argent += g->loyer;
            printf(" %d euros...",g->loyer);
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~sinon si le joueur possède 2 gares~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (player[g->proprio - 1]->nbDeGare == 2 && player[tourjoueur]->argent >= g->loyer1){
            player[tourjoueur]->argent -= g->loyer1;
            player[g->proprio - 1]->argent += g->loyer1;
            printf(" %d euros...",g->loyer1);
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~sinon si le joueur possède 3 gares ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (player[g->proprio - 1]->nbDeGare == 3 && player[tourjoueur]->argent >= g->loyer2){
            player[tourjoueur]->argent -= g->loyer2;
            player[g->proprio - 1]->argent += g->loyer2;
            printf(" %d euros...",g->loyer2);
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~sinon si le joueur possède 4 gares~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (player[g->proprio - 1]->nbDeGare == 4 && player[tourjoueur]->argent >= g->loyer3){
            player[tourjoueur]->argent -= g->loyer3;
            player[g->proprio - 1]->argent += g->loyer3;
            printf(" %d euros...",g->loyer3);
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~sinon si le joueur qui doit payer le loyer ne possède pas assez d'argent dans le cas d'1 gare~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (player[g->proprio - 1]->nbDeGare == 1 && player[tourjoueur]->argent <= g->loyer) {
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer = g->loyer1 - player[tourjoueur]->argent;
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);
            player[tourjoueur]->argent -= g->loyer;
            player[g->proprio - 1] ->argent -= g->loyer;
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~sinon si le joueur qui doit payer le loyer ne possède pas assez d'argent dans le cas de 2 gares~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (player[g->proprio - 1]->nbDeGare == 2 && player[tourjoueur]->argent <= g->loyer1){
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer = g->loyer1 - player[tourjoueur]->argent;
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);
            player[tourjoueur]->argent -= g->loyer1;
            player[g->proprio - 1] ->argent += g->loyer1;
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~sinon si le joueur qui doit payer le loyer ne possède pas assez d'argent dans le cas de 3 gares~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if(player[g->proprio - 1]->nbDeGare == 3 && player[tourjoueur]->argent <= g->loyer2){
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer = g->loyer2 - player[tourjoueur]->argent;
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);
            player[tourjoueur]->argent -= g->loyer2;
            player[g->proprio - 1] ->argent += g->loyer2;
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~sinon si le joueur qui doit payer le loyer ne possède pas assez d'argent dans le cas de 4 gares~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (player[g->proprio - 1]->nbDeGare == 4 && player[tourjoueur]->argent <= g->loyer3){
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer = g->loyer3 - player[tourjoueur]->argent;
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);
            player[tourjoueur]->argent -= g->loyer3;
            player[g->proprio - 1] ->argent += g->loyer3;
        }

        Color(player[g->proprio-1]->couleur, 0);
        printf("%s, Porte Monnaie : %d\n", player[g->proprio-1]->prenomJoueur, player[g->proprio - 1]->argent);

        Color(player[tourjoueur]->couleur, 0);
        printf("%s, Porte Monnaire : %d\n", player[tourjoueur]->prenomJoueur, player[tourjoueur]->argent);

    }

    ///************************************************CAS 2: où la galaxie n'appartient à aucun joueur************************************************
    else if( g->proprio != player[0]->numeroJoueur && g->proprio != player[1]->numeroJoueur && g->proprio != player[2]->numeroJoueur && g->proprio != player[3]->numeroJoueur ){
        printf("\n%cIA : %s",0x10,g->anecdote);
        printf("\n%cIA : Voici un r%capitulatif capitaine...",0x10,0x82);
        Color(15,0);
        printf("\n\n                                                         ");
        Color(0,g->couleur);
        printf("%c GALAXIE %s %c",0x0f,g->nom,0x0f);
        Color(15,0);
        printf("\n                          Prix d'achat : %d",g->prix);
        printf("\n                          Prix loyer avec 1 galaxie  : %d",g->loyer);
        printf("\n                              Prix loyer avec 2 galaxies : %d",g->loyer1);
        printf("\n                              Prix loyer avec 3 galaxies : %d",g->loyer2);
        printf("\n                              Prix loyer avec 4 galaxies : %d",g->loyer3);
        printf("\n                          Prix hypoth%ccaire : %d",0x82,g->p_hypo);
        Color(3,0);
        printf("\nIA : La galaxie est libre d'achat, souhaitez-vous l'acheter ?\n ");
        printf("                      ");
        Color(10,0);
        printf("1.OUI");
        printf("                      ");
        Color(12,0);
        printf("2.NON\n");
        Color(15,0);
        int answer;
        scanf("%d",&answer);
        while( answer != 1 && answer != 2){
            printf("IA : Saisie incorrecte\n");
            fflush(stdin);
            scanf("%d",&answer);
        }
        Color(3,0);

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~si le joueur veut acheter la gare~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if ( answer == 1 && player[tourjoueur]->argent >= g->prix){
            g->proprio = player[tourjoueur]->numeroJoueur;
            strcat(player[tourjoueur]->proprietes,g->nom);
            strcat(player[tourjoueur]->proprietes,",");
            player[tourjoueur]->argent -= g->prix;
            player[tourjoueur]->famillec[g->couleurF] += 1;
            verfiwin(player , tourjoueur , nombreJoueur);
            printf("IA : BRAVO %s! Vous avez acquis une nouvelle galaxie ...",player[tourjoueur]->prenomJoueur);
            player[tourjoueur]->nbDeGare += 1; //pour les gares, nous n'avons de maisons. Donc on compte les nombres de gares possédées;
            Color(player[tourjoueur]->couleur, 0);
            printf("%s, Porte Monnaie : %d\n", player[tourjoueur]->prenomJoueur, player[tourjoueur]->argent);



        }
        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~sinon si le joueur ne peut pas acheter la gare car il n'a pas assez d'argent~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if(player[tourjoueur]->argent < g->prix){
            printf("\nIA : Vous n'avez pas assez d'argent pour acheter cette galaxie !");
        }
        else {
            printf("IA : Fin de tour ...");
        }
    }
    else{
        Color(15,0);
        printf("\n                          Nombre de galaxies poss%cd%ces par %s : %d",0x82,0x82,player[g->proprio - 1]->prenomJoueur, player[g->proprio-1]->nbDeGare);
        printf("\n                          Prix hypoth%caire : %d",0x82,g->p_hypo);
        printf("\n                          Prix loyer avec 1 galaxie : %d",g->loyer);
        printf("\n                              Prix loyer avec 2 galaxies : %d",g->loyer1);
        printf("\n                              Prix loyer avec 3 galaxies : %d",g->loyer2);
        printf("\n                              Prix loyer avec 4 galaxies : %d",g->loyer3);
        Color(3,0);
        printf("\nIA : La galaxie appartient a ");
        Color(player[g->proprio - 1]->couleur,0);
        printf("%s",player[g->proprio - 1]->prenomJoueur);
        Color(3,0);
        printf("\nIA : Re-bonjour ");
        Color(player[tourjoueur]->couleur,0);
        printf("%s !\n", player[tourjoueur]->prenomJoueur);
        if(g->etatHypo == 1){
            int choixLeverHypo;
            Color(player[tourjoueur]->couleur,0);
            printf("\n%s, voulez-vous levez l'hypoth%cque ?\n", player[tourjoueur]->prenomJoueur,0x8A);
            printf("                                  ");
            Color(10,0);
            printf("1.OUI");
            printf("                                  ");
            Color(12,0);
            printf("2.NON\n");
            Color(15,0);
            scanf("%d", &choixLeverHypo);
            Color(3,0);
            while( choixLeverHypo!= 1 && choixLeverHypo != 2){
                printf("IA : Saisie incorrecte\n");
                fflush(stdin);
                scanf("%d", &choixLeverHypo);
            }
            if(choixLeverHypo == 1){
                int prixADeduire= (g->p_hypo)*0.1;
                prixADeduire += g->p_hypo;
                printf("IA : Vous payez %d \n", prixADeduire);
                player[tourjoueur]->argent -= prixADeduire;
                Color(player[tourjoueur]->couleur,0);
                printf("Porte-monnaie : %d\n", player[tourjoueur]->argent);
                g->loyer = g->loyerFixe;
                g->etatHypo = 0;

            }

        }
    }
}

///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


///-----------------------------------------------------------PROCEDURE D'ARRIVEE SUR LES SATELITTES-----------------------------------------------------------
void arrivsat(satellite* s,t_joueur player[NbJoueurMax][TAILLE],int tourjoueur,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_, int *maisonMax, int *hotelMax,int nombreJoueur)
{
    Color(3,0);
    s->proprio = 5;
    printf("\n\n%cIA : Nous sommes arriv%cs sur un nouveau satellite ...  %s !",0x10,0x82,s->nom);
    for (int i =0 ; i<4 ; i++){
        char * result = strstr(player[i]->proprietes, s->nom);
        if (result != NULL){
            s->proprio = player[i]->numeroJoueur;
        }
        result = NULL;
    }

     ///************************************************CAS 1: où la propriété appartient au joueur ************************************************
    if(player[s->proprio - 1]->prenomJoueur == player[tourjoueur]->prenomJoueur && s->etatHypo == 0){

        //affichage des données de la propriété
        Color(15,0);
        printf("\n                          Prix hypoth%ccaire : %d",0x82,s->p_hypo);
        printf("\n                          Nombre de sondes spatiales : %d",s->maison);
        printf("\n                          Nombre de stations spatiales : %d",s->hotel);
        printf("\n                          Prix d'une sonde spatiale : %d",s->prixMaison);
        printf("\n                          Prix loyer sans sonde spatiale  : %d",s->loyer);
        printf("\n                              Prix loyer avec 1 sonde spatiale : %d",s->loyer1);
        printf("\n                              Prix loyer avec 2 sondes spatiales : %d",s->loyer2);
        printf("\n                              Prix loyer avec 3 sondes spatiales : %d",s->loyer3);
        printf("\n                              Prix loyer avec 4 sondes spatiales : %d",s->loyer4);
        printf("\n                              Prix loyer avec 1 station spatiale : %d",s->loyerHotel);

        printf("                                  ");
        Color(3,0);
        printf("\nIA : Re-bonjour ");
        Color(player[tourjoueur]->couleur,0);
        printf("%s ! \n", player[tourjoueur]->prenomJoueur);
        printf("Voici votre Porte Monnaie : %d\n", player[tourjoueur]->argent);
        printf("Voulez-vous acheter une nouvelle sonde spatiale ?\n");
        printf("                                  ");
        Color(10,0);
        printf("1.OUI");
        printf("                                  ");
        Color(12,0);
        printf("2.NON\n");
        Color(15,0);
        int choix;
        scanf("%d", &choix);
        Color(3,0);
        while( choix != 1 && choix != 2){ //blindage
            printf("IA : Saisie incorrecte\n");
            fflush(stdin);
            scanf("%d",&choix);
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si le joueur veut acheter une maison ET possède assez d'argent ET s'il reste des maisons~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if(choix == 1 && player[tourjoueur]->argent >= s->prixMaison && *maisonMax >= 0){
            printf("Vous avez achet%c une sonde spatiale, f%clicitations !", 0x82, 0x82);
            player[tourjoueur]->argent -= s->prixMaison;
            s->maison += 1;
            *maisonMax -= 1;


            ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si la propriété possède 4 maisons ET s'il reste des hôtels, on demande au joueur s'il veut acheter un hôtel~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            if (s->maison == 4 && *hotelMax >= 0){
                printf("Vous possedez 4 maisons. Voulez-vous les remplacer par une station spatiale ?\n ");
                printf("                                  ");
                Color(10,0);
                printf("1.OUI");
                printf("                                  ");
                Color(12,0);
                printf("2.NON\n");
                Color(15,0);
                int choix2;
                scanf("%d", &choix2);
                while( choix != 1 && choix != 2){ //blindage
                    printf("IA : Saisie incorrecte\n");
                    getchar();
                    scanf("%d",&choix);
                }

                ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Si le joueur possède assez d'argent et veut acheter un hôtel~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                if(choix2 == 1 && player[tourjoueur]->argent >= s->prixMaison){
                    s->maison = 0;
                    s->hotel = 1;
                    *hotelMax -= 1;
                    *maisonMax += 4;
                    Color(3,0);
                    printf("Vous avez achet%c une station spatiale, f%clicitations !", 0x82, 0x82);
                    player[tourjoueur]->argent -= s->prixMaison;


                }

                ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sinon si le joueur ne veut pas acheter d'hôtel, on lui demande s'il veut en vendre~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                else if (choix2 == 2 && s->hotel > 0){
                    int choixVente2;
                    int nombreDeHotel;
                    printf("Voulez-vous vendre une station spatiale ?\n");
                    printf("                                  ");
                    Color(10,0);
                    printf("1.OUI");
                    printf("                                  ");
                    Color(12,0);
                    printf("2.NON\n");
                    Color(15,0);
                    scanf("%d", &choixVente2);
                    Color(3,0);
                    while( choixVente2 != 1 && choixVente2 != 2){ //blindage
                        printf("IA : Saisie incorrect\n");
                        fflush(stdin);
                        scanf("%d",&choixVente2);
                    }

                     ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~si le joueur veut vendre un hôtel~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if (choixVente2 == 1){
                        printf("Vous poss%cdez %d stations.\n",0x82, s->hotel);
                        printf("Combien de stations voulez-vous vendre ?\n");
                        scanf("%d", &nombreDeHotel);
                        while(nombreDeHotel > s->hotel ){ //blindage
                            printf("IA : Saisie incorrect !\n");
                        }
                        *hotelMax += nombreDeHotel; //on rajoute un hôtel au nombre d'hôtel maximum
                        s->hotel -= nombreDeHotel; //on enlève un hôtel à la propriété
                        for (int m = 0; m<nombreDeHotel; m++){ //on retire le prix d'une maison, n fois (n étant le nombre d'hôtel que le joueur veut vendre)
                            player[tourjoueur]->argent += s->prixMaison;
                        }

                    }
                    printf("IA : Vente r%cussie !\n", 0x82);
                }

                 ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Sinon si le joueur veut acheter un hôtel mais n'a pas assez d'argent~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                else if(player[tourjoueur]->argent < s->prixMaison){
                    printf("\nIA : Vous n'avez pas assez d'argent pour acheter une station spataile !");
                }

            }
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Sinon si le joueur ne veut pas acheter de maisons ET la propriété possède des maisons, on lui demande s'il veut en vendre~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (choix == 2 && s->maison > 0){
                int choixVente;
                int nombreDeMaison;
                printf("Voulez-vous vendre une sonde spatiale ?\n");
                printf("                                  ");
                Color(10,0);
                printf("1.OUI");
                printf("                                  ");
                Color(12,0);
                printf("2.NON\n");
                Color(15,0);
                scanf("%d", &choixVente);
                Color(3,0);
                while( choixVente != 1 && choixVente != 2){ //blindage
                    printf("IA : Saisie incorrect\n");
                    fflush(stdin);
                    scanf("%d",&choixVente);
                }
                ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ si le joueur veut vendre~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                if (choixVente == 1){
                    printf("Vous poss%cdez %d sondes.\n",0x82, s->maison);
                    printf("Combien de maisons voulez-vous vendre ?\n");
                    scanf("%d", &nombreDeMaison);
                    while(nombreDeMaison > s->maison ){
                        printf("IA : Saisie incorrecte !\n");
                        fflush(stdin);
                        scanf("%d", &nombreDeMaison);
                    }
                    *maisonMax += nombreDeMaison; //on rajoute le nombre de maisons vendues au nombre de maisons maximum
                    s->maison -= nombreDeMaison; //on retire le nombre de maisons vendues à la propriété
                    for (int m = 0; m<nombreDeMaison; m++){ //on retire le prix d'une maison au joueur, n fois (n étant le nombre de maisons vendues)
                        player[tourjoueur]->argent += s->prixMaison;
                    }
                    printf("IA : Vente r%cussie !\n", 0x82);

                }

        }
    }

    ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Si la propriété est hypothéquée~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    else if (player[s->proprio - 1]->prenomJoueur == player[tourjoueur]->prenomJoueur && s->etatHypo == 1){
            int choixLeverHypo;
            Color(player[tourjoueur]->couleur,0);
            printf("\n%s, voulez-vous lever l'hypoth%cque ?\n", player[tourjoueur]->prenomJoueur, 0x8A);
            printf("                                  ");
            Color(10,0);
            printf("1.OUI");
            printf("                                  ");
            Color(12,0);
            printf("2.NON\n");
            Color(15,0);
            scanf("%d", &choixLeverHypo);
            Color(3,0);
            while( choixLeverHypo!= 1 && choixLeverHypo != 2){ //blindage
                printf("IA : Saisie incorrecte\n");
                fflush(stdin);
                scanf("%d", &choixLeverHypo);
            }

            ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~si le joueur veut lever l'hypothèque~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            if(choixLeverHypo == 1){
                int prixADeduire= (s->p_hypo)*0.1;
                prixADeduire += s->p_hypo;
                printf("IA : Vous payez %d \n", prixADeduire);
                player[tourjoueur]->argent -= prixADeduire;
                Color(player[tourjoueur]->couleur,0);
                printf("Porte-monnaie : %d\n", player[tourjoueur]->argent);
                s->loyer = s->loyerFixe;
                s->etatHypo = 0;

            }
        }
    else if (player[tourjoueur]->argent < s->prixMaison){
            printf("\nIA : Vous n'avez pas assez d'argent pour acheter une sonde !");
        }


    ///************************************************CAS 2: où le joueur ne possède pas la propriété mais est déjà possédé par un joueur************************************************
    else if (s->proprio == player[0]->numeroJoueur || s->proprio == player[1]->numeroJoueur || s->proprio == player[2]->numeroJoueur || s->proprio == player[3]->numeroJoueur){
        Color(15,0);
        printf("\n                          Nombre de sondes spatiales : %d",s->maison);
        printf("\n                          Prix loyer sans sonde spatiale  : %d",s->loyer);
        printf("\n                              Prix loyer avec 1 sonde spatiale : %d",s->loyer1);
        printf("\n                              Prix loyer avec 2 sondes spatiales : %d",s->loyer2);
        printf("\n                              Prix loyer avec 3 sondes spatiales : %d",s->loyer3);
        printf("\n                              Prix loyer avec 4 sondes spatiales : %d",s->loyer4);
        printf("\n                              Prix loyer avec 1 station spatiale : %d",s->loyerHotel);

        printf("                                  ");
        Color(3,0);
        printf("\nIA : Le satellite appartient a ");
        Color(player[s->proprio - 1]->couleur,0);
        printf("%s",player[s->proprio - 1]->prenomJoueur);
        Color(3,0);
        printf("... Vous devez lui payer son loyer !");

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si le propriétaire possède toutes les propriétés d'une même couleur, le joueur paye double loyer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
            printf("\nIA: ");
            Color(player[s->proprio - 1]->couleurJoueur,0);
            printf("%s",player[s->proprio - 1]->prenomJoueur);
            printf(" poss%cde cette famille d'astres ! Le loyer est donc double !", 0x8A);
            Color(player[tourjoueur]->couleur,0);
            printf("\n%s",player[tourjoueur]->prenomJoueur);
            Color(3,0);
            printf(" paye a ");
            Color(player[s->proprio - 1]->couleur,0);
            printf("%s",player[s->proprio - 1]->prenomJoueur);
            Color(3,0);
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si le loyer est "simple"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else {
        Color(player[tourjoueur]->couleur,0);
        printf("\n%s",player[tourjoueur]->prenomJoueur);
        Color(3,0);
        printf(" paye a ");
        Color(player[s->proprio - 1]->couleur,0);
        printf("%s",player[s->proprio - 1]->prenomJoueur);
        }
        Color(3,0);

         ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si la propriété ne possède aucune maison / aucun hôtel ET possède assez d'argent pour payer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if(s->maison == 0 && s->hotel == 0 && player[tourjoueur]->argent >= s->loyer){

            ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si loyer double~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                player[tourjoueur]->argent -= s->loyer *2;//le joueur payer le loyer 2 fois
                player[s->proprio - 1]->argent += s->loyer *2;//le propriétaire gagne 2 fois le loyer
                printf(" %d euros...",s->loyer *2);
            }
            ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Si loyer simple~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            else{
                player[tourjoueur]->argent -= s->loyer; //on déduit le prix du loyer au joueur
                player[s->proprio - 1]->argent += s->loyer;//le propriétaire gagner l'argent du loyer
                printf(" %d euros...",s->loyer);
            }
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Sinon si la propriété ne possède une maison ET possède assez d'argent pour payer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (s->maison == 1 && player[tourjoueur]->argent >= s->loyer1){
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                player[tourjoueur]->argent -= s->loyer1 *2;
                player[s->proprio - 1]->argent += s->loyer1 *2;
                printf(" %d euros...",s->loyer1 *2);
            }
            else{
                player[tourjoueur]->argent -= s->loyer1;
                player[s->proprio - 1]->argent += s->loyer1;
                printf(" %d euros...",s->loyer1);
            }
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Sinon si la propriété ne possède 2 maisons ET possède assez d'argent pour payer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (s->maison == 2 && player[tourjoueur]->argent >= s->loyer2){
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                player[tourjoueur]->argent -= s->loyer2 *2;
                player[s->proprio - 1]->argent += s->loyer2 *2;
                printf(" %d euros...",s->loyer2 *2);
            }
            else{
                player[tourjoueur]->argent -= s->loyer2;
                player[s->proprio - 1]->argent += s->loyer2;
                printf(" %d euros...",s->loyer2);
            }
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Sinon si la propriété ne possède 3 maisons ET possède assez d'argent pour payer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (s->maison == 3 && player[tourjoueur]->argent >= s->loyer3){
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                player[tourjoueur]->argent -= s->loyer3 *2;
                player[s->proprio - 1]->argent += s->loyer3 *2;
                printf(" %d euros...",s->loyer3 *2);
            }
            else{
                player[tourjoueur]->argent -= s->loyer3;
                player[s->proprio - 1]->argent += s->loyer3;
                printf(" %d euros...",s->loyer3);
            }
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Sinon si la propriété ne possède 4 maisons ET possède assez d'argent pour payer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if(s->maison == 4 && player[tourjoueur]->argent >= s->loyer4){
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                player[tourjoueur]->argent -= s->loyer4 *2;
                player[s->proprio - 1]->argent += s->loyer4 *2;
                printf(" %d euros...",s->loyer4 *2);
            }
            else{
                player[tourjoueur]->argent -= s->loyer4;
                player[s->proprio- 1]->argent += s->loyer4;
                printf(" %d euros...", s->loyer4);
            }

        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Sinon si la propriété ne possède un hôtel ET possède assez d'argent pour payer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if(s->hotel == 1 && player[tourjoueur]->argent >= s->loyerHotel){
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                player[tourjoueur]->argent -= s->loyerHotel *2;
                player[s->proprio - 1]->argent += s->loyerHotel  *2;
                printf(" %d euros...",s->loyerHotel *2);
            }
            else{
                player[tourjoueur]->argent -= s->loyerHotel;
                player[s->proprio- 1]->argent += s->loyerHotel;
                printf(" %d euros...", s->loyerHotel);
            }

        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Sinon si le joueur ne possède pas assez d'argent pour payer~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (s->maison == 0 && s->hotel == 0 && player[tourjoueur]->argent <= s->loyer) {
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer;
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                prixapayer = (s->loyer*2) - player[tourjoueur]->argent;

            }
            else{
                prixapayer = s->loyer - player[tourjoueur]->argent;
            }
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                player[tourjoueur]->argent -= s->loyer*2;
                player[s->proprio - 1] ->argent += s->loyer*2;
            }
            else{
                player[tourjoueur]->argent -= s->loyer;
                player[s->proprio - 1] ->argent += s->loyer;
            }
        }
        else if (s->maison == 1 && player[tourjoueur]->argent <= s->loyer1){
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer;
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                prixapayer = (s->loyer1*2) - player[tourjoueur]->argent;

            }
            else{
                prixapayer = s->loyer1 - player[tourjoueur]->argent;
            }
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                player[tourjoueur]->argent -= s->loyer1*2;
                player[s->proprio - 1] ->argent += s->loyer1*2;
            }
            else{
                player[tourjoueur]->argent -= s->loyer1;
                player[s->proprio - 1] ->argent += s->loyer1;
            }
        }
        else if(s->maison == 2 && player[tourjoueur]->argent <= s->loyer2){
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer;
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                prixapayer = (s->loyer2*2) - player[tourjoueur]->argent;

            }
            else{
                prixapayer = s->loyer2 - player[tourjoueur]->argent;
            }
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);player[tourjoueur]->argent -= s->loyer2;
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                player[tourjoueur]->argent -= s->loyer2*2;
                player[s->proprio - 1] ->argent += s->loyer2*2;
            }
            else{
                player[tourjoueur]->argent -= s->loyer2;
                player[s->proprio - 1] ->argent += s->loyer2;
            }
        }
        else if (s->maison == 3 && player[tourjoueur]->argent <= s->loyer3){
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer;
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                prixapayer = (s->loyer3*2) - player[tourjoueur]->argent;

            }
            else{
                prixapayer = s->loyer3 - player[tourjoueur]->argent;
            }
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                player[tourjoueur]->argent -= s->loyer3*2;
                player[s->proprio - 1] ->argent += s->loyer3*2;
            }
            else{
                player[tourjoueur]->argent -= s->loyer3;
                player[s->proprio - 1] ->argent += s->loyer3;
            }
        }
        else if (s->maison == 4 && player[tourjoueur]->argent <= s->loyer4){
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer;
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                prixapayer = (s->loyer4*2) - player[tourjoueur]->argent;

            }
            else{
                prixapayer = s->loyer4 - player[tourjoueur]->argent;
            }
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                player[tourjoueur]->argent -= s->loyer4*2;
                player[s->proprio - 1] ->argent += s->loyer4*2;
            }
            else{
                player[tourjoueur]->argent -= s->loyer4;
                player[s->proprio - 1] ->argent += s->loyer4;
            }
        }
        else if (s->hotel == 1 && player[tourjoueur]->argent <= s->loyerHotel) {
            Color(player[tourjoueur]->couleur, 0);
            printf("\nIA : %s, vous n'avez pas assez d'argent pour payer le loyer !\n", player[tourjoueur]->prenomJoueur);
            int prixapayer;
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                prixapayer = (s->loyerHotel*2) - player[tourjoueur]->argent;

            }
            else{
                prixapayer = s->loyerHotel - player[tourjoueur]->argent;
            }
            hypotheque(player,tourjoueur,prixapayer,&terre_,&mars_,&jupiter_,& saturne_, &pluton_,& neptune_, &venus_, &uranus_, &mercure_, &soleil_, &lune_, &phobos_, &ganymede_, &callisto_, &io_, &titan_,& voieLactee_,& andromede_, &tetard_,&nuageDeMagellan_);
            if (player[s->proprio - 1]->famillec[s->couleurF] == 2){
                player[tourjoueur]->argent -= s->loyerHotel*2;
                player[s->proprio - 1] ->argent += s->loyerHotel*2;
            }
            else{
                player[tourjoueur]->argent -= s->loyerHotel;
                player[s->proprio - 1] ->argent += s->loyerHotel;
            }
        }

        Color(player[s->proprio-1]->couleur, 0);
        printf("%s, Porte Monnaie : %d\n", player[s->proprio-1]->prenomJoueur, player[s->proprio - 1]->argent);

        Color(player[tourjoueur]->couleur, 0);
        printf("%s, Porte Monnaire : %d\n", player[tourjoueur]->prenomJoueur, player[tourjoueur]->argent);

    }

   ///************************************************CAS 3: où la propriété n'appartient à aucun joueur************************************************
    else{
        Color(3,0);
        printf("\n%cIA : %s",0x10,s->anecdote);

        //affichage des données de la propriété
        printf("\n%cIA : Voici un r%ccapitulatif capitaine...",0x10,0x82);
        printf("\n\n                                                        ");
        Color(0,s->couleur);
        printf("%c SATELLITE %s %c",0x02,s->nom,0x02);
        Color(15,0);

        printf("\n                          Prix d'achat : %d",s->prix);
        printf("\n                          Prix loyer sans sonde spatiale  : %d",s->loyer);
        printf("\n                              Prix loyer avec 1 sonde spatiale : %d",s->loyer1);
        printf("\n                              Prix loyer avec 2 sondes spatiales : %d",s->loyer2);
        printf("\n                              Prix loyer avec 3 sondes spatiales : %d",s->loyer3);
        printf("\n                              Prix loyer avec 4 sondes spatiales : %d",s->loyer4);
        printf("\n                              Prix loyer avec 1 station spatiale : %d",s->loyerHotel);

        printf("\n                          Prix d'une sonde spatiale : %d",s->prixMaison);
        printf("\n                          Prix d'une station spatiale : %d",s->prixMaison);
        printf("\n                          Prix hypoth%ccaire : %d",0x82,s->p_hypo);
        Color(3,0);
        printf("\nIA : Le satellite est libre d'achat, souhaitez-vous l'acheter ?\n ");
        printf("                      ");
        Color(10,0);
        printf("1.OUI");
        printf("                      ");
        Color(12,0);
        printf("2.NON\n");
        Color(15,0);
        int answer;
        scanf("%d",&answer);
        while( answer != 1 && answer != 2){ //blindage
            printf("IA : Saisie incorrecte\n");
            fflush(stdin);
            scanf("%d",&answer);
        }
        Color(3,0);

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~si le joueur veut acheter la propriété ET possède assez d'argent~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if ( answer == 1 && player[tourjoueur]->argent >= s->prix){
            s->proprio = player[tourjoueur]->numeroJoueur; //on ajoute le nom du joueur à la propriété
            strcat(player[tourjoueur]->proprietes,s->nom);  //on ajoute la propriété au joueur
            strcat(player[tourjoueur]->proprietes,",");
            player[tourjoueur]->argent -= s->prix; //on retire l'argent de l'achat
            player[tourjoueur]->famillec[s->couleurF] += 1;
            verfiwin(player , tourjoueur , nombreJoueur);  //on verifie si le joueur a assez de proriétés pour gagner
            printf("IA : BRAVO %s! Vous avez aquis un nouveau satellite ...",player[tourjoueur]->prenomJoueur);
            Color(player[tourjoueur]->couleur, 0);
            printf("%s, Porte Monnaie : %d\n", player[tourjoueur]->prenomJoueur, player[tourjoueur]->argent);

        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~si le joueur veut acheter la propriété MAIS ne possède pas d'argent~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if(player[tourjoueur]->argent < s->prix){
            printf("\nIA : Vous n'avez pas assez d'argent pour acheter ce satellite ! ");
        }

        ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~si le joueur ne veut pas acheter la propriété~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else {
            printf("IA : Fin de tour ...");
        }
    }
}


///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


///-----------------------------------------------------------PROCEDURES DES PLANETES ET DES SATELITTES-----------------------------------------------------------
void lune(satellite* lune)
{
    lune->proprio = 5;
    lune->prix = 60;
    char noms[] = "LUNE";
    strcpy(lune->nom, noms);
    char anecdotes[] = "La Lune est l'unique satellite naturel de la planete Terre. Il s'agit du cinquieme plus grand satellite naturel du Systeme Solaire, avec un diametre de 2 500 KM.";
    strcpy(lune->anecdote, anecdotes);

    lune->loyer = 2;
    lune->loyer1 = 10;
    lune->loyer2 = 30;
    lune->loyer3 = 90;
    lune->loyer4 = 160;
    lune->loyerHotel = 250;
    printf("%d", lune->loyerHotel);

    lune->prixMaison = 50;
    lune->p_hypo = 30 ;
    lune->couleur = 5;
    lune->couleurF = 0;

}

void terre (planete* terre){
    terre->proprio = 5;
    terre->prix = 60;
    char noms [] = "TERRE";
    strcpy (terre->nom ,noms);
    char anecdotes [] = "Nous somme de retour chez nous ! Notre belle planete bleu, mere porteuse de la vie humaine...";
    strcpy (terre->anecdote , anecdotes);

    terre->loyer = 4;
    terre->loyer1 = 20;
    terre->loyer2 = 60;
    terre->loyer3 = 180;
    terre->loyer4 = 320;
    terre->loyerHotel = 450;
    terre->prixMaison = 50;
    terre->p_hypo = 30;
    terre->couleur = 5;
    terre->couleurF = 0;

}

void voieLactee(galaxie* voieLactee)
{

    voieLactee->proprio = 5;
    voieLactee->prix = 200;
    char noms [] = "VOIE LACTEE";
    strcpy(voieLactee->nom, noms);
    char anecdotes[] = "Voici notre galaxie : l a Voie Lactee. Elle comprend entre 200 et 400 milliards d'etoiles et au minimum 100 milliards de planetes, dont la Terre ! ";
    strcpy(voieLactee->anecdote, anecdotes);

    voieLactee->loyer = 25;
    voieLactee->loyer1 = 50;
    voieLactee->loyer2 = 100;
    voieLactee->loyer3 = 200;
    voieLactee->p_hypo = 100;
    voieLactee->couleur = 8;
    voieLactee->couleurF = 1;


}

void phobos(satellite* phobos)
{
    phobos->proprio = 5;
    phobos->prix = 100;
    char noms[] = "PHOBOS";
    strcpy(phobos->nom, noms);
    char anecdotes[] = "Phobos est le plus grand des deux satellites naturels de Mars. Son nom fait reference a la mythologie grecque, Phobos etant l'enfant du dieu Ares et de la deesse Aphrodite.";
    strcpy(phobos->anecdote, anecdotes);

    phobos->loyer = 6;
    phobos->loyer1 = 30;
    phobos->loyer2 = 90;
    phobos->loyer3 = 270;
    phobos->loyer4 = 400;
    phobos->loyerHotel = 550;
    phobos->prixMaison = 50;
    phobos->p_hypo = 50;
    phobos->couleur = 3;
    phobos->couleurF = 2;

}


void mars (planete* mars){

    mars->proprio = 5;
    mars->prix = 120;
    char noms [] = "MARS";
    strcpy (mars->nom ,noms);
    char anecdotes [] = "La 1re personne a avoir observe Mars au telescope fut l'astronome Galilee.Ce n'est qu'avec l'envoi de la premiere sonde autour de Mars, en 1965, qu on a su que les planete etait inhabitee." ;
    strcpy (mars->anecdote , anecdotes);
    mars->loyer = 8;
    mars->loyer1 = 40;
    mars->loyer2 = 100;
    mars->loyer3 = 300;
    mars->loyer4 = 450;
    mars->loyerHotel = 600;
    mars->p_hypo = 50;
    mars->couleur = 3;
    mars->prixMaison = 50;
    mars->couleurF = 2;

}

void ganymede(satellite* ganymede)
{
    ganymede->proprio = 5;
    ganymede->prix = 140;
    char noms[] = "GANYMEDE";
    strcpy(ganymede->nom, noms);
    char anecdotes[] = "Ganymede est le plus grand satellite naturel de Jupiter, mais egalement de notre Systeme Solaire ! Ganymede est nomme d'apres le guerrier troyen de la mythologie grecque, qui fut enleve par Zeus.";
    strcpy(ganymede->anecdote, anecdotes);

    ganymede->loyer = 10;
    ganymede->loyer1 = 50;
    ganymede->loyer2 = 150;
    ganymede->loyer3 = 450;
    ganymede->loyer4 = 625;
    ganymede->loyerHotel = 750;
    ganymede->prixMaison = 100;
    ganymede->p_hypo = 70;
    ganymede->couleur = 13;
    ganymede->couleurF = 3;

}

void callisto(satellite* callisto)
{
    callisto->proprio = 5;
    callisto->prix = 160;
    char noms[] = "CALLISTO";
    strcpy(callisto->nom, noms);
    char anecdotes[] = "Callisto a ete decouverte par Galilee, en 1610. Elle fait partie des nombreuses satellites de Jupiter. De plus, Callisto etait l'une des nombreuses conquetes de Zeus.";
    strcpy(callisto->anecdote, anecdotes);

    callisto->loyer = 12;
    callisto->loyer1 = 60;
    callisto->loyer2 = 180;
    callisto->loyer3 = 500;
    callisto->loyer4 = 700;
    callisto->loyerHotel = 900;
    callisto->prixMaison = 100;
    callisto->p_hypo = 80;
    callisto->couleur = 13;
    callisto->couleurF = 3;
}

void andromede(galaxie* andromede)
{
    andromede->proprio = 5;
    andromede->prix = 200;
    char noms [] = "ANDROMEDE";
    strcpy(andromede->nom, noms);
    char anecdotes[] = "Andromede est la galaxie la plus proche de la notre ! Elle est situee a 2,55 millions d'annees-lumiere de notre Soleil. Elle est donc la galaxie la plus proche de la notre. Elle possede un diametre de 220 000 annees-lumieres et contiendrait environ mille milliards d'etoiles !";
    strcpy(andromede->anecdote, anecdotes);

    andromede->loyer = 25;
    andromede->loyer1 = 50;
    andromede->loyer2 = 100;
    andromede->loyer3 = 200;
    andromede->p_hypo = 100;
    andromede->couleur = 8;
    andromede->couleurF = 1;

}

void io(satellite* io)
{
    io->proprio = 5;
    io->prix = 180;
    char noms[] = "IO";
    strcpy(io->nom, noms);
    char anecdotes[] = "IO, satellite de Jupiter, a ete decouvert par Galilee, en 1610. Avec environ 400 volcans actifs, il est l'astre le plus, geologiquement, actif du Systeme Solaire. ";
    strcpy(io->anecdote, anecdotes);

    io->loyer = 14;
    io->loyer1 = 70;
    io->loyer2 = 200;
    io->loyer3 = 550;
    io->loyer4 = 750;
    io->loyerHotel = 950;
    io->prixMaison = 100;
    io->p_hypo = 90;
    io->couleur = 6;
    io->couleurF = 4;

}

void jupiter (planete* jupiter){
    jupiter->proprio = 5;
    jupiter->prix = 200;
    char noms [] = "JUPITER";
    strcpy (jupiter->nom ,noms);
    char anecdotes [] = "Jupiter est la plus grande de notre systeme solaire. Son diametre est dix fois celui de la Terre et son volume est tel qu'il pourrait contenir 1 321 Terre.\nIl y a des tempetes et des cyclones sur Jupiter qui sont plus grandes que notre planete entiere.";
    strcpy (jupiter->anecdote , anecdotes);

    jupiter->loyer = 16;
    jupiter->loyer1 = 80;
    jupiter->loyer2 = 220;
    jupiter->loyer3 = 600;
    jupiter->loyer4 = 800;
    jupiter->loyerHotel = 1000;
    jupiter->p_hypo = 100;
    jupiter->couleur = 6;
    jupiter->prixMaison = 100;
    jupiter->couleurF = 4;

}

void titan(satellite* titan)
{
    titan->proprio = 5;
    titan->prix = 220;
    char noms[] = "TITAN";
    strcpy(titan->nom, noms);
    char anecdotes[] = "Titan est le plus grand satellite naturel de Saturne, decouvert en 1665. Il est le deuxieme satellite le plus gros du Systeme Solaire, derriere Ganymede.";
    strcpy(titan->anecdote, anecdotes);

    titan->loyer = 18;
    titan->loyer1 = 90;
    titan->loyer2 = 250;
    titan->loyer3 = 700;
    titan->loyer4 = 875;
    titan->loyerHotel = 1050;
    titan->prixMaison = 150;
    titan->p_hypo = 110;
    titan->couleur = 4;
    titan->couleurF = 5;

}


void saturne (planete* saturne){
    saturne->proprio = 5;
    saturne->prix = 240;
    char noms [] = "SATURNE";
    strcpy (saturne->nom ,noms);
    char anecdotes [] = "Saturne, deuxieme plus grande planete du systeme solaire apres Jupiter, a une masse volumique moyenne bien inferieure a celle de l eau (0,69 g/cm3).\nCette particularite physique etonnante signifie que si l on disposait d'une immense baignoire sur laquelle on pouvait la poser, elle y flotterait.";
    strcpy (saturne->anecdote , anecdotes);

    saturne->loyer = 20;
    saturne->loyer1 = 100;
    saturne->loyer2 = 300;
    saturne->loyer3 = 750;
    saturne->loyer4 = 925;
    saturne->loyerHotel = 1100;
    saturne->p_hypo = 120;
    saturne->couleur = 4;
    saturne->prixMaison = 150;
    saturne->couleurF = 5;

}

void tetard(galaxie* tetard)
{
    tetard->proprio = 5;
    tetard->prix = 200;
    char noms [] = "TETARD";
    strcpy(tetard->nom, noms);
    char anecdotes[] = "La Galaxie du Tetard est situee a environ 400 millions d'annees-lumieres de la Voie Lactee. On peut la distinguer par sa queue de maree, longue de plus de 280 000 annees-lumiere.";
    strcpy(tetard->anecdote, anecdotes);

    tetard->loyer = 25;
    tetard->loyer1 = 50;
    tetard->loyer2 = 100;
    tetard->loyer3 = 200;
    tetard->p_hypo = 100;
    tetard->couleur = 8;
    tetard->couleurF = 1;

}

void pluton(planete* pluton)
{
    pluton->proprio = 5;
    pluton->prix = 260;
    char noms [] = "PLUTON";
    strcpy (pluton->nom ,noms);
    char anecdotes [] = "Pluton a ete decouverte en 1930 et a ete considere comme la 9e planete du Systeme Solaire. Mais a la fin du XXe, d'autres objets similaires ont ete decouvert, d'ou la creation de la categorie de planetes naines. Pluton est donc une planete naine.";
    strcpy (pluton->anecdote , anecdotes);
    pluton->loyer = 22;
    pluton->loyer1 = 110;
    pluton->loyer2 = 330;
    pluton->loyer3 = 800;
    pluton->loyer4 = 975;
    pluton->loyerHotel = 1150;
    pluton->p_hypo = 130;
    pluton->couleur = 14;
    pluton->prixMaison = 150;
    pluton->couleurF = 6;

}

void neptune(planete* neptune)
{
    neptune->proprio = 5;
    neptune->prix = 280;
    char noms [] = "NEPTUNE";
    strcpy (neptune->nom ,noms);
    char anecdotes [] = "Neptune est la derniere planete de notre Systeme Solaire. Son nom vient du dieu romain des oceans, Neptune. Elle met 165 ans a realise un tour complet au tour du Soleil !";
    strcpy (neptune->anecdote , anecdotes);
    neptune->loyer = 24;
    neptune->loyer1 = 120;
    neptune->loyer2 = 360;
    neptune->loyer3 = 850;
    neptune->loyer4 = 1025;
    neptune->loyerHotel = 1200;
    neptune->p_hypo = 140;
    neptune->couleur = 14;
    neptune->prixMaison = 150;
    neptune->couleurF = 6;

}


void venus (planete* venus){
    venus->proprio = 5;
    venus->prix = 300;
    char noms [] = "VENUS";
    strcpy (venus->nom ,noms);
    char anecdotes [] = "Avec une moyenne de 462 C, Venus possede en surface la temperature la plus elevee du Systeme solaire, alors qu'elle n est que la deuxieme planete la plus proche du Soleil.";
    strcpy (venus->anecdote , anecdotes);
    venus->loyer = 26;
    venus->loyer1 = 130;
    venus->loyer2 = 390;
    venus->loyer3 = 900;
    venus->loyer4 = 1100;
    venus->loyerHotel = 1275;
    venus->p_hypo = 150;
    venus->couleur = 2;
    venus->prixMaison = 200;
    venus->couleurF = 7;

}

void uranus(planete* uranus){
    uranus->proprio = 5;
    uranus->prix = 320;
    char noms [] = "URANUS";
    strcpy (uranus->nom ,noms);
    char anecdotes [] = "Uranus est la premiere planete decouverte a l'aide d'un telescope. Elle tient son nom du dieu du ciel, Ouranos, l'une des divinites primordiales de la mythologie grecque.";
    strcpy (uranus->anecdote , anecdotes);
    uranus->loyer = 28;
    uranus->loyer1 = 150;
    uranus->loyer2 = 450;
    uranus->loyer3 = 1000;
    uranus->loyer4 = 1200;
    uranus->loyerHotel = 1400;
    uranus->p_hypo = 160;
    uranus->couleur = 2;
    uranus->prixMaison = 200;
    uranus->couleurF = 7;

}

void nuageDeMagellan(galaxie* nuageDeMagellan)
{
    nuageDeMagellan->proprio = 5;
    nuageDeMagellan->prix = 200;
    char noms [] = "NUAGE DE MAGELLAN";
    strcpy(nuageDeMagellan->nom, noms);
    char anecdotes[] = "Les nuages de magellan forment un groupe de deux galaxie. D'une part le Grand Nuage de Magellan, situe a environ 157 000 annees-lumieres de notre Soleil. Et d'autre part, le Petit Nuage de Magellan, situe a environ 197 000 annees-lumiers";
    strcpy(nuageDeMagellan->anecdote, anecdotes);

    nuageDeMagellan->loyer = 25;
    nuageDeMagellan->loyer1 = 50;
    nuageDeMagellan->loyer2 = 100;
    nuageDeMagellan->loyer3 = 200;
    nuageDeMagellan->p_hypo = 100;
    nuageDeMagellan->couleur = 8;
    nuageDeMagellan->couleurF = 1;


}

void mercure(planete* mercure)
{
    mercure->proprio = 5;
    mercure->prix = 350;
    char noms [] = "MERCURE";
    strcpy (mercure->nom ,noms);
    char anecdotes [] = "Mercure est la plane   te la plus proche du systeme solaire, il y fait une temperature moyenne de 167 degres pouvant montant jusqu'a 427 degres ! Elle est 3 fois plus petite que notre Terre mais egalement 20 moins massive.";
    strcpy (mercure->anecdote , anecdotes);
    mercure->loyer = 35;
    mercure->loyer1 = 175;
    mercure->loyer2 = 500;
    mercure->loyer3 = 1100;
    mercure->loyer4 = 1300;
    mercure->loyerHotel = 1500;
    mercure->p_hypo = 175;
    mercure->couleur = 1;
    mercure->prixMaison = 200;
    mercure->couleurF = 8;

}



void soleil (planete* soleil){
    soleil->proprio = 5;
    soleil->prix = 400;
    char noms [] = "SOLEIL";
    strcpy (soleil->nom ,noms);
    char anecdotes [] = "Dans environ cinq milliards d'annees, le Soleil gonflera pour devenir une geante rouge, avalant du meme coup les planetes Mercure, Venus, la Terre et Mars.";
    strcpy (soleil->anecdote , anecdotes);
    soleil->loyer = 50;
    soleil->loyer1 = 200;
    soleil->loyer2 = 600;
    soleil->loyer3 = 1400;
    soleil->loyer4 = 1700;
    soleil->loyerHotel = 2000;
    soleil->p_hypo = 200;
    soleil->couleur = 1;
    soleil->prixMaison = 200;
    soleil->couleurF = 8;

}

///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

char *str_replace (const char *txt, const char *Avant, const char *Apres)
{
  const char *pos;
  char *TxtRetour;
  size_t PosTxtRetour;

  size_t Long;
  size_t TailleAllouee;
  pos = strstr (txt, Avant);
  if (pos == NULL)
  {
    return NULL;
  }

  Long = (size_t)pos - (size_t)txt;
  TailleAllouee = Long + strlen (Apres) + 1;
  TxtRetour = malloc (TailleAllouee);
  PosTxtRetour = 0;

  strncpy (TxtRetour + PosTxtRetour, txt, Long);
  PosTxtRetour += Long;
  txt = pos + strlen (Avant);

  Long = strlen (Apres);
  strncpy (TxtRetour + PosTxtRetour, Apres, Long);
  PosTxtRetour += Long;

  pos = strstr (txt, Avant);
  while (pos != NULL)
  {
    Long = (size_t)pos - (size_t)txt;
    TailleAllouee += Long + strlen (Apres);
    TxtRetour = (char *)realloc (TxtRetour, TailleAllouee);
    strncpy (TxtRetour + PosTxtRetour, txt, Long);
    PosTxtRetour += Long;
    txt = pos + strlen (Avant);
    Long = strlen (Apres);
    strncpy (TxtRetour + PosTxtRetour, Apres, Long);
    PosTxtRetour += Long;
    pos = strstr (txt, Avant);
  }
  Long = strlen (txt) + 1;
  TailleAllouee += Long;
  TxtRetour = realloc (TxtRetour, TailleAllouee);
  strncpy (TxtRetour + PosTxtRetour, txt, Long);
  return TxtRetour;
}









int cherchplan (planete* terre_,planete* mars_,planete* jupiter_,planete* saturne_,planete* pluton_,planete *neptune_,planete* venus_,planete *uranus_,planete *mercure_,planete *soleil_,satellite* lune_,satellite* phobos_,satellite *ganymede_,satellite *callisto_,satellite *io_,satellite *titan_,galaxie* voieLactee_,galaxie *andromede_,galaxie *tetard_,galaxie *nuageDeMagellan_,char input [TAILLE]){
    char *result = strstr(terre_->nom,input);
    if (result != NULL){
        return terre_->p_hypo;
    }
    result = strstr(mars_->nom,input);
    if (result != NULL){
        return mars_->p_hypo;
    }
    result = strstr(jupiter_->nom,input);
    if (result != NULL){
        return jupiter_->p_hypo;
    }
    result = strstr(saturne_->nom,input);
    if (result != NULL){
        return saturne_->p_hypo;
    }
    result = strstr(pluton_->nom,input);
    if (result != NULL){
        return pluton_->p_hypo;
    }
    result = strstr(neptune_->nom,input);
    if (result != NULL){
        return saturne_->p_hypo;
    }
    result = strstr(venus_->nom,input);
    if (result != NULL){
        return venus_->p_hypo;
    }
    result = strstr(uranus_->nom,input);
    if (result != NULL){
        return uranus_->p_hypo;
    }
    result = strstr(mercure_->nom,input);
    if (result != NULL){
        return mercure_->p_hypo;
    }
    result = strstr(soleil_->nom,input);
    if (result != NULL){
        return soleil_->p_hypo;
    }
    result = strstr(lune_->nom,input);
    if (result != NULL){
        return lune_->p_hypo;
    }
    result = strstr(phobos_->nom,input);
    if (result != NULL){
        return phobos_->p_hypo;
    }
    result = strstr(ganymede_->nom,input);
    if (result != NULL){
        return ganymede_->p_hypo;
    }
    result = strstr(callisto_->nom,input);
    if (result != NULL){
        return callisto_->p_hypo;
    }
    result = strstr(io_->nom,input);
    if (result != NULL){
        return io_->p_hypo;
    }
    result = strstr(titan_->nom,input);
    if (result != NULL){
        return titan_->p_hypo;
    }
    result = strstr(voieLactee_->nom,input);
    if (result != NULL){
        return voieLactee_->p_hypo;
    }
    result = strstr(andromede_->nom,input);
    if (result != NULL){
        return andromede_->p_hypo;
    }
    result = strstr(tetard_->nom,input);
    if (result != NULL){
        return tetard_->p_hypo;
    }
    result = strstr(nuageDeMagellan_->nom,input);
    if (result != NULL){
        return nuageDeMagellan_->p_hypo;
    }
}




int cherchplanp (planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_,char input [TAILLE]){
    char *result = strstr(terre_.nom,input);
    if (result != NULL){
        return terre_.couleurF;
    }
    result = strstr(mars_.nom,input);
    if (result != NULL){
        return mars_.couleurF;
    }
    result = strstr(jupiter_.nom,input);
    if (result != NULL){
        return jupiter_.couleurF;
    }
    result = strstr(saturne_.nom,input);
    if (result != NULL){
        return saturne_.couleurF;
    }
    result = strstr(pluton_.nom,input);
    if (result != NULL){
        return pluton_.couleurF;
    }
    result = strstr(neptune_.nom,input);
    if (result != NULL){
        return saturne_.couleurF;
    }
    result = strstr(venus_.nom,input);
    if (result != NULL){
        return venus_.couleurF;
    }
    result = strstr(uranus_.nom,input);
    if (result != NULL){
        return uranus_.couleurF;
    }
    result = strstr(mercure_.nom,input);
    if (result != NULL){
        return mercure_.couleurF;
    }
    result = strstr(soleil_.nom,input);
    if (result != NULL){
        return soleil_.couleurF;
    }
    result = strstr(lune_.nom,input);
    if (result != NULL){
        return lune_.couleurF;
    }
    result = strstr(phobos_.nom,input);
    if (result != NULL){
        return phobos_.couleurF;
    }
    result = strstr(ganymede_.nom,input);
    if (result != NULL){
        return ganymede_.couleurF;
    }
    result = strstr(callisto_.nom,input);
    if (result != NULL){
        return callisto_.couleurF;
    }
    result = strstr(io_.nom,input);
    if (result != NULL){
        return io_.couleurF;
    }
    result = strstr(titan_.nom,input);
    if (result != NULL){
        return titan_.couleurF;
    }
    result = strstr(voieLactee_.nom,input);
    if (result != NULL){
        return voieLactee_.couleurF;
    }
    result = strstr(andromede_.nom,input);
    if (result != NULL){
        return andromede_.couleurF;
    }
    result = strstr(tetard_.nom,input);
    if (result != NULL){
        return tetard_.couleurF;
    }
    result = strstr(nuageDeMagellan_.nom,input);
    if (result != NULL){
        return nuageDeMagellan_.couleurF;
    }
}

planete cherchplanpp (planete *terre_,planete* mars_,planete *jupiter_,planete* saturne_,planete* pluton_,planete* neptune_,planete *venus_,planete* uranus_,planete *mercure_,planete *soleil_,char input [TAILLE]){
    char *result = strstr(terre_->nom,input);
    if (result != NULL){
        terre_->etatHypo +=1;
    }
    result = strstr(mars_->nom,input);
    if (result != NULL){
        mars_->etatHypo +=1;
    }
    result = strstr(jupiter_->nom,input);
    if (result != NULL){
        jupiter_->etatHypo +=1;
    }
    result = strstr(saturne_->nom,input);
    if (result != NULL){
        saturne_->etatHypo +=1;
    }
    result = strstr(pluton_->nom,input);
    if (result != NULL){
        pluton_->etatHypo +=1;
    }
    result = strstr(neptune_->nom,input);
    if (result != NULL){
        neptune_->etatHypo +=1;
    }
    result = strstr(venus_->nom,input);
    if (result != NULL){
        venus_->etatHypo +=1;
    }
    result = strstr(uranus_->nom,input);
    if (result != NULL){
        uranus_->etatHypo +=1;
    }
    result = strstr(mercure_->nom,input);
    if (result != NULL){
        mercure_;
    }
    result = strstr(soleil_->nom,input);
    if (result != NULL){
        soleil_->etatHypo +=1;
    }

}
satellite cherplanps (satellite *lune_,satellite* phobos_,satellite* ganymede_,satellite *callisto_,satellite* io_,satellite* titan_,char input [TAILLE]){
    char * result = strstr(lune_->nom,input);
    if (result != NULL){
        lune_->etatHypo +=1;
    }
    result = strstr(phobos_->nom,input);
    if (result != NULL){
        phobos_->etatHypo +=1;
    }
    result = strstr(ganymede_->nom,input);
    if (result != NULL){
        ganymede_->etatHypo +=1;
    }
    result = strstr(callisto_->nom,input);
    if (result != NULL){
        callisto_->etatHypo +=1;
    }
    result = strstr(io_->nom,input);
    if (result != NULL){
        io_->etatHypo +=1;
    }
    result = strstr(titan_->nom,input);
    if (result != NULL){
        titan_->etatHypo +=1;
    }
}

galaxie cherplanpg ( galaxie* voieLactee_,galaxie *andromede_,galaxie* tetard_,galaxie* nuageDeMagellan_,char input [TAILLE]){
    char * result = strstr(voieLactee_->nom,input);
    if (result != NULL){
        voieLactee_->etatHypo +=1;
    }
    result = strstr(andromede_->nom,input);
    if (result != NULL){
        andromede_->etatHypo +=1;
    }
    result = strstr(tetard_->nom,input);
    if (result != NULL){
        tetard_->etatHypo +=1;
    }
    result = strstr(nuageDeMagellan_->nom,input);
    if (result != NULL){
        nuageDeMagellan_->etatHypo +=1;
    }
}
