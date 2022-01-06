#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED




///JOUEURS

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

}t_joueur;

//Sous programmes joueurs
t_joueur saisie(t_joueur player[NbJoueurMax][TAILLE], int nombreDeJoueur);
int choixDuPremier(int nbJoueur);
int lancerDe(t_joueur player[NbJoueurMax][TAILLE], int de[2], int joueur);


///MENU
void menu (t_joueur player[NbJoueurMax] [TAILLE]);

///PLANETES ET ETOILES

//Structures planetes et etoiles
//Structures planetes et etoiles
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
}planete;

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
}satellite;

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

}galaxie;

//Procedures planetes et etoiles
void arrivplan (planete *p,t_joueur player[NbJoueurMax][TAILLE],int tourjoueur,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_, int *maisonMax, int *hotelMax);
void arrivgalax (galaxie* g,t_joueur player[NbJoueurMax][TAILLE],int tourjoueur,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_);
void arrivsat (satellite* s,t_joueur player[NbJoueurMax][TAILLE],int tourjoueur,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_, int *maisonMax, int *hotelMax);
void hypotheque (t_joueur player [NbJoueurMax] [TAILLE],int tourjoueur,int prixapayer,planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_);
int cherchplan (planete terre_,planete mars_,planete jupiter_,planete saturne_,planete pluton_,planete neptune_,planete venus_,planete uranus_,planete mercure_,planete soleil_,satellite lune_,satellite phobos_,satellite ganymede_,satellite callisto_,satellite io_,satellite titan_,galaxie voieLactee_,galaxie andromede_,galaxie tetard_,galaxie nuageDeMagellan_,char input [TAILLE]);
//Affichage plateau
void plateau();

#endif // BIB_H_INCLUDED
