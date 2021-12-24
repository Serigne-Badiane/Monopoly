#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 200

#include "bib.h"

///MANQUE CARTES COMMUNAUTE

void melangerCartes()
{
    //procédure pour mélanger une fois les cartes en début de partie

}

///CARTES CHANCES
void c1(t_joueur* player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="VOUS ETES LIBERES DE PRISON!\n";
    //faire en sorte que le joueur garde la carte et coder avec prison
}


void c2(* player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="JOYEUX ANNIVERSAIRE!\nChaque joueur vous verse 50 \n";
}


void c3(t_joueur* player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="CAMPAGNE PUBLICITAIRE PAYANTE!\nLa banque vous verse 100\n";
    player->argent=100;
}

void c4(t_joueur* player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="SOIREE AU CASINO!\nChoisissez un adversaire.\nLancez tous les deux les des.\nCelui qui obtient le plus gros score recoit 200 de la Banque.\n";
    //je ne sais pas trop comment le coder
}

void c5(t_joueur* player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="SOIREE AU CASINO!\nChoisissez un adversaire.\nLancez tous les deux les des.\nCelui qui obtient le plus gros score recoit 200 de la Banque.\n";
    //idem
}

void c6(t_joueur* player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="PRIX DU BUSINESSMAN DE L'ANNEE!\nLa banque vous verse 400.\n";
    player->argent=player->argent+400;
}

void c7(t_joueur* player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="VOUS LANCEZ VOTRE SITE INTERNET!\nVos ventes decollent!\nLa banque vous verse 300.\n";
    player->argent=player->argent+300;
}

void c8(t_joueur* player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="FRAUDE! ALLEZ EN PRISON!\nNe recevez pas d'argent en passant par la case depart.\n";
    //coder avec prison
}

void c9(t_joueur* player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="AVANCE SYR VOS PROFITS!\nAvancez jusqu'a la case Depart pour toucher votre salaire!\n";
    //deplacement sur la case départ et donc salaire (à relier à la case départ)
}

void c10(t_joueur* player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="AMENDE POUR ESPIONNAGE INDUSTRIEL!\nPayez 200 a la Banque.\n";
    player->argent=player->argent-200;
}

void c11(t_joueur* player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="ROULEZ BOLIDES!\nAvancez de cinq cases dans votre voiture de course!\n";
    //A coder avec dés + cases
}

void c12(t_joueur* player[NbJoueurMax][TAILLE])
{
    char c[TAILLE]="ALLEZ EN PRISON!\nNe recevez pas d'argent en passant par la case depart.\n";
    //coder avec prison
}
