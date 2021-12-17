#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 300
#include "bib.h"



///AFFICHAGE DE L'ARRIVEE SUR LES PLANETES
void arrivplan (planete p){
    Color(3,0);
    printf("\n\n%cIA : Nous sommes arriv%cs sur une nouvelle plan%cte... La plan%cte %s !",0x10,0x82,0x8A,0x8A,p.nom);
    printf("\n%cIA : %s",0x10,p.anecdote);
    printf("\n%cIA : Voici un r%ccapitulatif capitaine...",0x10,0x82);
    printf("\n\n                                                        ");
    Color(0,p.couleur);
    printf("%c PLAN%cTE %s %c",0x02,0xD4,p.nom,0x02);
    Color(15,0);
    printf("\n                          Propri%ctaire : %s",0x82,p.proprio);
    printf("\n                          Prix d'achat : %d",p.prix);
    printf("\n                          Prix d'une maison: %d",p.prixMaison);
    printf("\n                          Prix loyer actuel : %d",p.loyer);
    printf("\n                          Prix hypoth%cquaire : %d",0x82,p.p_hypo);
    if (p.maison == 4){
        p.hotel = 1;
        printf("\n                          Nombre d'hotel : %d",p.hotel);
    }
    printf("\n                          Nombre de maisons : %d",p.maison);

}

///AFFICHAGE DE L'ARRIVEE SUR LES ETOILES
void arrivgalax(galaxie g){
    Color(3,0);
    printf("\n\n%cIA : Nous sommes arriv%cs sur une nouvelle galaxie : ...%s !",0x10,0x82,g.nom);
    printf("\n%cIA : %s",0x10,g.anecdote);
    printf("\n%cIA : Voici un r%capitulatif capitaine...",0x10,0x82);
    Color(15,0);
    printf("\n\n                                                         ");
    Color(0,g.couleur);
    printf("%c GALAXIE %s %c",0x0f,g.nom,0x0f);
    Color(15,0);
    printf("\n                          Propri%ctaire : %s",0x82,g.proprio);
    printf("\n                          Prix d'achat : %d",g.prix);
    printf("\n                          Prix loyer actuel : %d",g.loyer);
    printf("\n                          Prix hypoth%cquaire : %d",0x82,g.p_hypo);

}

void arrivsat(satellite s)
{
    Color(3,0);
    printf("\n\n%cIA : Nous sommes arriv%cs sur un nouveaux satellite ...  %s !",0x10,0x82,s.nom);
    printf("\n%cIA : %s",0x10,s.anecdote);
    printf("\n%cIA : Voici un r%ccapitulatif capitaine...",0x10,0x82);
    printf("\n\n                                                        ");
    Color(0,s.couleur);
    printf("%c SATELLITE %s %c",0x02,s.nom,0x02);
    Color(15,0);
    printf("\n                          Propri%ctaire : %s",0x82,s.proprio);
    printf("\n                          Prix d'achat : %d",s.prix);
    printf("\n                          Prix d'une maison : %d",s.prixMaison);
    printf("\n                          Prix loyer actuel : %d",s.loyer);
    printf("\n                          Prix hypoth%cquaire : %d",0x82,s.p_hypo);
    if (s.maison == 4){
        s.hotel = 1;
        printf("\n                          Nombre d'hotel : %d",s.hotel);
    }
    printf("\n                          Nombre de maisons : %d",s.maison);
}


///PROCEDURES DES PLANETES
void lune()
{
    satellite lune = {"", "","",0,0,0,0,0,0,0};
    lune.prix = 60;
    char noms[] = "LUNE";
    strcpy(lune.nom, noms);
    char anecdotes[] = "La Lune est l'unique satellite naturel de la planete Terre. Il s'agit du cinquieme plus grand satellite naturel du Systeme Solaire, avec un diametre de 2 500 KM.";
    strcpy(lune.anecdote, anecdotes);

    lune.loyer = 2;
    lune.prixMaison = 50;
    lune.p_hypo = 30 ;
    lune.couleur = 5;
    arrivsat(lune);
}

void terre (){
    planete terre={"", "","",0,0,0,0,0,0,0};;
    terre.prix = 60;
    char noms [] = "TERRE";
    strcpy (terre.nom ,noms);
    char anecdotes [] = "Nous somme de retour chez nous ! Notre belle planete bleu, mere porteuse de la vie humaine...";
    strcpy (terre.anecdote , anecdotes);

    terre.loyer = 4;
    terre.prixMaison = 50;
    terre.p_hypo = 30;
    terre.couleur = 5;
    arrivplan(terre);
}

void voieLactee()
{

    galaxie voieLactee = {"", "","",0,0,0,0,0,0};;
    voieLactee.prix = 200;
    char noms [] = "VOIE LACTEE";
    strcpy(voieLactee.nom, noms);
    char anecdotes[] = "Voici notre galaxie : l a Voie Lactee. Elle comprend entre 200 et 400 milliards d'etoiles et au minimum 100 milliards de planetes, dont la Terre ! ";
    strcpy(voieLactee.anecdote, anecdotes);

    voieLactee.loyer = 25;
    voieLactee.p_hypo = 100;
    voieLactee.couleur = 8;
    arrivgalax(voieLactee);

}

void phobos()
{
    satellite phobos={"", "","",0,0,0,0,0,0,0};
    phobos.prix = 100;
    char noms[] = "PHOBOS";
    strcpy(phobos.nom, noms);
    char anecdotes[] = "Phobos est le plus grand des deux satellites naturels de Mars. Son nom fait reference a la mythologie grecque, Phobos etant l'enfant du dieu Ares et de la deesse Aphrodite.";
    strcpy(phobos.anecdote, anecdotes);

    phobos.loyer = 6;
    phobos.prixMaison = 50;
    phobos.p_hypo = 50;
    phobos.couleur = 3;
    arrivsat(phobos);
}


void mars (){

    planete mars= {"", "","",0,0,0,0,0,0,0};
    mars.prix = 120;
    char noms [] = "MARS";
    strcpy (mars.nom ,noms);
    char anecdotes [] = "La 1re personne a avoir observe Mars au telescope fut l'astronome Galilee.Ce n'est qu'avec l'envoi de la premiere sonde autour de Mars, en 1965, qu on a su que les planete etait inhabitee." ;
    strcpy (mars.anecdote , anecdotes);
    mars.loyer = 8;
    mars.p_hypo = 50;
    mars.couleur = 3;
    mars.prixMaison = 50;
    arrivplan(mars);
}

void ganymede()
{
    satellite ganymede= {"", "","",0,0,0,0,0,0,0};
    ganymede.prix = 140;
    char noms[] = "GANYMEDE";
    strcpy(ganymede.nom, noms);
    char anecdotes[] = "Ganymede est le plus grand satellite naturel de Jupiter, mais egalement de notre Systeme Solaire ! Ganymede est nomme d'apres le guerrier troyen de la mythologie grecque, qui fut enleve par Zeus.";
    strcpy(ganymede.anecdote, anecdotes);

    ganymede.loyer = 10;
    ganymede.prixMaison = 100;
    ganymede.p_hypo = 70;
    ganymede.couleur = 13;
    arrivsat(ganymede);
}

void callisto()
{
    satellite callisto = {"", "","",0,0,0,0,0,0,0};
    callisto.prix = 160;
    char noms[] = "CALLISTO";
    strcpy(callisto.nom, noms);
    char anecdotes[] = "Callisto a ete decouverte par Galilee, en 1610. Elle fait partie des nombreuses satellites de Jupiter. De plus, Callisto etait l'une des nombreuses conquetes de Zeus.";
    strcpy(callisto.anecdote, anecdotes);

    callisto.loyer = 12;
    callisto.prixMaison = 100;
    callisto.p_hypo = 80;
    callisto.couleur = 13;
    arrivsat(callisto);
}

void andromede()
{
    galaxie andromede = {"","","",0,0,0,0,0,0};
    andromede.prix = 200;
    char noms [] = "ANDROMEDE";
    strcpy(andromede.nom, noms);
    char anecdotes[] = "Andromede est la galaxie la plus proche de la notre ! Elle est situee a 2,55 millions d'annees-lumiere de notre Soleil. Elle est donc la galaxie la plus proche de la notre. Elle possede un diametre de 220 000 annees-lumieres et contiendrait environ mille milliards d'etoiles !";
    strcpy(andromede.anecdote, anecdotes);

    andromede.loyer = 25;
    andromede.p_hypo = 100;
    andromede.couleur = 8;
    arrivgalax(andromede);

}

void io()
{
    satellite io = {"", "","",0,0,0,0,0,0,0};
    io.prix = 180;
    char noms[] = "IO";
    strcpy(io.nom, noms);
    char anecdotes[] = "IO, satellite de Jupiter, a ete decouvert par Galilee, en 1610. Avec environ 400 volcans actifs, il est l'astre le plus, geologiquement, actif du Systeme Solaire. ";
    strcpy(io.anecdote, anecdotes);

    io.loyer = 14;
    io.prixMaison = 100;
    io.p_hypo = 90;
    io.couleur = 6;
    arrivsat(io);
}

void jupiter (){
    planete jupiter = {"", "", "", 0, 0, 0, 0 , 0,0,0} ;
    jupiter.prix = 200;
    char noms [] = "JUPITER";
    strcpy (jupiter.nom ,noms);
    char anecdotes [] = "Jupiter est la plus grande de notre systeme solaire. Son diametre est dix fois celui de la Terre et son volume est tel qu'il pourrait contenir 1 321 Terre.\nIl y a des tempetes et des cyclones sur Jupiter qui sont plus grandes que notre planete entiere.";
    strcpy (jupiter.anecdote , anecdotes);

    jupiter.loyer = 16;
    jupiter.p_hypo = 100;
    jupiter.couleur = 6;
    jupiter.prixMaison = 100;
    arrivplan(jupiter);
}

void titan()
{
    satellite titan = {"", "","",0,0,0,0,0,0,0};
    titan.prix = 220;
    char noms[] = "TITAN";
    strcpy(titan.nom, noms);
    char anecdotes[] = "Titan est le plus grand satellite naturel de Saturne, decouvert en 1665. Il est le deuxieme satellite le plus gros du Systeme Solaire, derriere Ganymede.";
    strcpy(titan.anecdote, anecdotes);

    titan.loyer = 18;
    titan.prixMaison = 150;
    titan.p_hypo = 110;
    titan.couleur = 4;
    arrivsat(titan);
}


void saturne (){
    planete saturne = {"", "", "", 0, 0, 0, 0 , 0, 0} ;
    saturne.prix = 240;
    char noms [] = "SATURNE";
    strcpy (saturne.nom ,noms);
    char anecdotes [] = "Saturne, deuxieme plus grande planete du systeme solaire apres Jupiter, a une masse volumique moyenne bien inferieure a celle de l eau (0,69 g/cm3).\nCette particularite physique etonnante signifie que si l on disposait d'une immense baignoire sur laquelle on pouvait la poser, elle y flotterait.";
    strcpy (saturne.anecdote , anecdotes);
    saturne.loyer = 20;
    saturne.p_hypo = 120;
    saturne.couleur = 4;
    saturne.prixMaison = 150;
    arrivplan(saturne);
}

void tetard()
{
    galaxie tetard = {"","","",0,0,0,0,0,0};
    tetard.prix = 200;
    char noms [] = "TETARD";
    strcpy(tetard.nom, noms);
    char anecdotes[] = "La Galaxie du Tetard est situee a environ 400 millions d'annees-lumieres de la Voie Lactee. On peut la distinguer par sa queue de maree, longue de plus de 280 000 annees-lumiere. ";
    strcpy(tetard.anecdote, anecdotes);

    tetard.loyer = 25;
    tetard.p_hypo = 100;
    tetard.couleur = 8;
    arrivgalax(tetard);
}

void pluton()
{
    planete pluton = {"", "", "", 0, 0, 0, 0 , 0, 0} ;
    pluton.prix = 260;
    char noms [] = "PLUTON";
    strcpy (pluton.nom ,noms);
    char anecdotes [] = "Pluton a ete decouverte en 1930 et a ete considere comme la 9e planete du Systeme Solaire. Mais a la fin du XXe, d'autres objets similaires ont ete decouvert, d'ou la creation de la categorie de planetes naines. Pluton est donc une planete naine.";
    strcpy (pluton.anecdote , anecdotes);
    pluton.loyer = 22;
    pluton.p_hypo = 130;
    pluton.couleur = 14;
    pluton.prixMaison = 150;
    arrivplan(pluton);
}

void neptune()
{
    planete neptune = {"", "", "", 0, 0, 0, 0 , 0, 0} ;
    neptune.prix = 280;
    char noms [] = "NEPTUNE";
    strcpy (neptune.nom ,noms);
    char anecdotes [] = "Neptune est la derniere planete de notre Systeme Solaire. Son nom vient du dieu romain des oceans, Neptune. Elle met 165 ans a realise un tour complet au tour du Soleil !";
    strcpy (neptune.anecdote , anecdotes);
    neptune.loyer = 24;
    neptune.p_hypo = 140;
    neptune.couleur = 14;
    neptune.prixMaison = 150;
    arrivplan(neptune);
}


void venus (){
    planete venus = {"", "", "", 0, 0, 0, 0 , 0} ;
    venus.prix = 300;
    char noms [] = "VENUS";
    strcpy (venus.nom ,noms);
    char anecdotes [] = "Avec une moyenne de 462 C, Venus possede en surface la temperature la plus elevee du Systeme solaire, alors qu'elle n est que la deuxieme planete la plus proche du Soleil.";
    strcpy (venus.anecdote , anecdotes);
    venus.loyer = 26;
    venus.p_hypo = 150;
    venus.couleur = 2;
    venus.prixMaison = 200;
    arrivplan(venus);
}

void uranus(){
    planete uranus = {"", "", "", 0, 0, 0, 0 , 0} ;
    uranus.prix = 320;
    char noms [] = "URANUS";
    strcpy (uranus.nom ,noms);
    char anecdotes [] = "Uranus est la premiere planete decouverte a l'aide d'un telescope. Elle tient son nom du dieu du ciel, Ouranos, l'une des divinites primordiales de la mythologie grecque.";
    strcpy (uranus.anecdote , anecdotes);
    uranus.loyer = 28;
    uranus.p_hypo = 160;
    uranus.couleur = 2;
    uranus.prixMaison = 200;
    arrivplan(uranus);
}

void nuageDeMagellan()
{
    galaxie nuageDeMagellan = {"","","",0,0,0,0,0,0};
    nuageDeMagellan.prix = 200;
    char noms [] = "NUAGE DE MAGELLAN";
    strcpy(nuageDeMagellan.nom, noms);
    char anecdotes[] = "Les nuages de magellan forment un groupe de deux galaxie. D'une part le Grand Nuage de Magellan, situe a environ 157 000 annees-lumieres de notre Soleil. Et d'autre part, le Petit Nuage de Magellan, situe a environ 197 000 annees-lumiers";
    strcpy(nuageDeMagellan.anecdote, anecdotes);

    nuageDeMagellan.loyer = 25;
    nuageDeMagellan.p_hypo = 100;
    nuageDeMagellan.couleur = 8;
    arrivgalax(nuageDeMagellan);

}

void mercure()
{
    planete mercure = {"", "", "", 0, 0, 0, 0 , 0} ;
    mercure.prix = 350;
    char noms [] = "MERCURE";
    strcpy (mercure.nom ,noms);
    char anecdotes [] = "Mercure est la planète la plus proche du système solaire, il y fait une temperature moyenne de 167 degres pouvant montant jusqu'a 427 degres ! Elle est 3 fois plus petite que notre Terre mais egalement 20 moins massive.";
    strcpy (mercure.anecdote , anecdotes);
    mercure.loyer = 35;
    mercure.p_hypo = 175;
    mercure.couleur = 1;
    mercure.prixMaison = 200;
    arrivplan(mercure);
}



void soleil (){
    planete soleil = {"", "", "", 0, 0, 0};
    soleil.prix = 400;
    char noms [] = "SOLEIL";
    strcpy (soleil.nom ,noms);
    char anecdotes [] = "Dans environ cinq milliards d'annees, le Soleil gonflera pour devenir une geante rouge, avalant du meme coup les planetes Mercure, Venus, la Terre et Mars.";
    strcpy (soleil.anecdote , anecdotes);
    soleil.loyer = 50;
    soleil.p_hypo = 200;
    soleil.couleur = 1;
    soleil.prixMaison = 200;
    arrivplan(soleil);
}
