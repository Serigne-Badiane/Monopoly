#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED



///JOUEURS

//Structure joueur
typedef struct joueur
{
    int numeroJoueur;
    char prenomJoueur[50];
    int numeroCase;
    int argent;

}t_joueur;


//Sous programmes joueurs
t_joueur saisie(t_joueur player[NbJoueurMax][TAILLE], int nombreDeJoueur);
int choixDuPremier(int nbJoueur);
int lancerDe(t_joueur player[NbJoueurMax][TAILLE], int de[2], int joueur);


///MENU
void menu ();

///PLANETES ET ETOILES

//Structures planetes et etoiles
//Structures planetes et etoiles
typedef struct {
    char proprio [TAILLE];
    char nom [TAILLE];
    char anecdote [TAILLE];
    int couleur;
    int prix;
    int loyer;
    int p_hypo;
    int prixMaison;
    int maison;
    int hotel;
}planete;

typedef struct
{
    char proprio [TAILLE];
    char nom [TAILLE];
    char anecdote[TAILLE];
    int couleur;
    int prix;
    int loyer;
    int p_hypo;
    int prixMaison;
    int maison;
    int hotel;
}satellite;

typedef struct {
    char proprio [TAILLE];
    char nom [TAILLE];
    char anecdote [TAILLE];
    int couleur;
    int prix;
    int loyer;
    int p_hypo;
    int maison;
    int hotel;

}galaxie;

//Procedures planetes et etoiles
void arrivplan (planete p);
void arrivgalax(galaxie g);
void mars ();
void terre ();
void saturne ();
void jupiter ();
void venus ();
void soleil ();


#endif // BIB_H_INCLUDED
