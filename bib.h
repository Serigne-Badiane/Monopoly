#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED




///-----------------------------------------------------------JOUEURS-----------------------------------------------------------

//Structure joueur
typedef struct joueur
{
    int numeroJoueur;
    int couleurJoueur;
    char prenomJoueur[50];
    char proprietes [TAILLE];
    int numeroCase;
    int prison;
    int couleur;
    int argent;
    int nbDeGare;
    int pion;
    int numeroTourPrison;
    int carteSortiePrison;
    int famillec [TAILLE];
    int etatIG;

}t_joueur;

//Sous programmes joueurs
void saisie(t_joueur player[NbJoueurMax][TAILLE], int nombreDeJoueur);
int choixDuPremier(int nbJoueur);
int lancerDe(t_joueur player[NbJoueurMax][TAILLE], int de[2], int joueur);

///-----------------------------------------------------------FIN JOUEURS-----------------------------------------------------------


///-----------------------------------------------------------MENU-----------------------------------------------------------

void menu (t_joueur player[NbJoueurMax] [TAILLE]);

///-----------------------------------------------------------FIN MENU-----------------------------------------------------------


///-----------------------------------------------------------PLANETES, GALAXIE ET SATELLITES-----------------------------------------------------------

//Structures planetes

typedef struct {
    int proprio;
    char nom [TAILLE];
    char anecdote [300];
    int couleur;
    int prix;
    int loyer;
    int loyer1;
    int loyer2;
    int loyer3;
    int loyer4;
    int loyerHotel;
    int p_hypo;
    int prixMaison;
    int maison;
    int hotel;
    int couleurF;
    int etatHypo;
    int loyerFixe;
}planete;

//structure satellites
typedef struct
{
    int proprio;
    char nom [TAILLE];
    char anecdote[300];
    int couleur;
    int prix;
    int loyer;
    int loyer1;
    int loyer2;
    int loyer3;
    int loyer4;
    int loyerHotel;
    int p_hypo;
    int prixMaison;
    int maison;
    int hotel;
    int couleurF;
    int loyerFixe;
    int etatHypo;
}satellite;

//structure galaxie
typedef struct {
    int proprio ;
    char nom [TAILLE];
    char anecdote [300];
    int couleur;
    int prix;
    int loyer;
    int loyer1;
    int loyer2;
    int loyer3;
    int p_hypo;
    int maison;
    int hotel;
    int couleurF;
    int etatHypo;
    int loyerFixe;

}galaxie;


//Procedures planetes, galaxie et satellites
void arrivplan (planete *p,t_joueur player[NbJoueurMax][TAILLE],int tourjoueur,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_, int *maisonMax, int *hotelMax,int nombreJoueur);
void arrivgalax (galaxie* g,t_joueur player[NbJoueurMax][TAILLE],int tourjoueur,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_,int nombreJoueur);
void arrivsat (satellite* s,t_joueur player[NbJoueurMax][TAILLE],int tourjoueur,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_, int *maisonMax, int *hotelMax,int nombreJoueur);
void hypotheque (t_joueur player [NbJoueurMax] [TAILLE],int tourjoueur,int prixapayer,planete* terre_,planete* mars_,planete* jupiter_,planete* saturne_,planete* pluton_,planete *neptune_,planete* venus_,planete *uranus_,planete *mercure_,planete *soleil_,satellite* lune_,satellite* phobos_,satellite *ganymede_,satellite *callisto_,satellite *io_,satellite *titan_,galaxie* voieLactee_,galaxie *andromede_,galaxie *tetard_,galaxie *nuageDeMagellan_);
int cherchplan (planete* terre_,planete* mars_,planete* jupiter_,planete* saturne_,planete* pluton_,planete *neptune_,planete* venus_,planete *uranus_,planete *mercure_,planete *soleil_,satellite* lune_,satellite* phobos_,satellite *ganymede_,satellite *callisto_,satellite *io_,satellite *titan_,galaxie* voieLactee_,galaxie *andromede_,galaxie *tetard_,galaxie *nuageDeMagellan_,char input [TAILLE]);
int cherchplanp (planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_,char input [TAILLE]);
void verfiwin (t_joueur player [NbJoueurMax][TAILLE],int tourjoueur,int nombreJoueur);
void affichageDesJoueurs(t_joueur player[NbJoueurMax][TAILLE]);
void lune(satellite* lune);
void terre(planete* terre);
void voieLactee(galaxie* voieLactee);
void phobos(satellite* phobos);
void mars (planete* mars);
void ganymede(satellite* ganymede);
void callisto(satellite* callisto);
void andromede(galaxie* andromede);
void io(satellite* io);
void jupiter (planete* jupiter);
void titan(satellite* titan);
void saturne (planete* saturne);
void tetard(galaxie* tetard);
void pluton(planete* pluton);
void neptune(planete* neptune);
void venus (planete* venus);
void uranus(planete* uranus);
void nuageDeMagellan(galaxie* nuageDeMagellan);
void mercure(planete* mercure);
void soleil (planete* soleil);
void echange (int nombreDeJoueur,t_joueur player[NbJoueurMax][TAILLE],int tourjoueur,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_);

///-----------------------------------------------------------FIN PLANETES, GALAXIE ET SATELLITES-----------------------------------------------------------



///-----------------------------------------------------------PLATEAU-----------------------------------------------------------

//Affichage plateau
void plateau();
void pion (t_joueur player [NbJoueurMax][TAILLE],int nombreDeJoueur);
void Color(int couleurDuTexte,int couleurDeFond);
void gotoligcol( int lig, int col );

///-----------------------------------------------------------FIN PLATEAU-----------------------------------------------------------


///-----------------------------------------------------------DEAL-----------------------------------------------------------

void echange (int nombreDeJoueur,t_joueur player[NbJoueurMax][TAILLE],int tourjoueur,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_);

///-----------------------------------------------------------FIN DEAL-----------------------------------------------------------



///-----------------------------------------------------------CARTES-----------------------------------------------------------

void piocheCartesCommu(int carte, t_joueur player[NbJoueurMax][TAILLE], int nombreDeJoueur, int tourJoueur,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_,int *maisonMax, int *hotelMax);

///-----------------------------------------------------------FIN CARTES-----------------------------------------------------------



#endif // BIB_H_INCLUDED
