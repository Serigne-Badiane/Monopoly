#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Jr 20
#define NbJoueurMax 5
#define TAILLE 200
#define TAILLE2 21
#include "bib.h"


///PROCEDURE MENU
void menu1 (int* nombreDeJoueur, int* nombreDeDeplacement, int* tourJoueur, t_joueur player[NbJoueurMax][TAILLE]){
    FILE * fp=NULL;
    int menu=0;
    int J=0;
    printf("        \n\n    MONOPOLY\n1.-Nouvelle Partie\n\n2.-Sauvegarder Partie en cours\n\n3.-Charger Partie\n\n4.-Regle\n\n5.-Cr%cdit\n\n",0x82);
    scanf("%d",&menu);

    while (menu!=1&&menu!=2&&menu!=3&&menu!=4&&menu!=5)
    {
        Color(3,0);
        printf("\nIA : Je n'ai compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
        fflush(stdin);
        scanf("%d",&menu);
    }

    if (menu==5)
    {
        printf("-Serigne BADIANE\n-Antany JOHNOLY JUSTIN\n-Lena LECORNEC\n-James LEMAITRE");
        return 0;
    }
    if(menu==1)
    {
        Color(3,0);
        printf("IA : Bonjour humains, ca fait longtemps que je vous attendais, vous en avez mis du temps a me trouver ! je dois vous communiquer une information grave, l'Univers est en danger et vous etes les seuls etres vivants pouvant selon moi remettre les choses dans l'ordre ici, il y a enormement de choses encore que vous ne savez pas a propos du cosmos, suivez moi nous partons avec ma fusee\n\n");
        Color(15,0);
        printf("Veuillez saisir le nombre de participants : \n");
        scanf("%d",&J);
        while(J>=5 || J<2)
        {
             Color(3,0);
             printf("IA : il ne peut y avoir que 2 a 4 joueurs ... vous croyez que notre fus%ce peut acceuillir plus de monde ?",0x82);
             fflush(stdin);
             scanf("%d", &J);
        }

        Color(3,0);
        printf("IA : Pour qu'on puisse mieux se comprendre je m'allumerai d'une couleur differente a chaque fois que je voudrais parler a l'un d'entre vous en particulier, chaque joueur a sa couleur et vous garderez celle que vous avez eu toute la partie\n");


        saisie(player, J);
        *nombreDeJoueur = J;


    }
        if (menu==2)
    {
        fp=fopen("Partie.txt","w");
        if (fp==NULL)
        {
        printf("erreur d'ouverture");
        exit (0);
        }
        for(int l = 0; l<4; l++)
        {
            fprintf(fp,"%s\n",player[l]->prenomJoueur);
            fprintf(fp,"%d\n",player[l]->argent);
            fprintf(fp,"%d\n",player[l]->couleur);
            fprintf(fp,"%d\n",player[l]->numeroCase);
            fprintf(fp,"%d\n",player[l]->numeroJoueur);
            fprintf(fp,"%d\n",player[l]->prison);
            fprintf(fp,"%s\n",player[l]->proprietes);
            fprintf(fp,"%d\n",player[l]->nbDeGare);
            fprintf(fp,"%d\n",player[l]->couleurJoueur);
        }
        fclose(fp);
        return(0);


    }

    if (menu==3)
    {

        fp=fopen("Partie.txt","r");
        if (fp==NULL)
        {
        printf("erreur d'ouverture");
        exit (0);
        }
        for(int h = 0; h<4; h++)
        {
            fscanf(fp,"%s\n",&player[h]->prenomJoueur);
            fscanf(fp,"%d\n",&player[h]->argent);
            fscanf(fp,"%d\n",&player[h]->couleur);
            fscanf(fp,"%d\n",&player[h]->numeroCase);
            fscanf(fp,"%d\n",&player[h]->numeroJoueur);
            fscanf(fp,"%d\n",&player[h]->prison);
            fscanf(fp,"%s\n",&player[h]->proprietes);
            fscanf(fp,"%d\n",&player[h]->nbDeGare);
            fscanf(fp,"%d\n",&player[h]->couleurJoueur);
        }
        fclose(fp);
        return(0);
    }
    if (menu==4)
    {
        printf("\n\nLa Banque\n\n Outre son argent, la Banque detient les cartes des terrains, les maisons et les hotels avant leur achat et utilisation par les joueurs.\nLa Banque paie les salaires (200 Euros pour le passage de la case depart) et les bonus.\nElle vend les maisons et les hotels pour les joueurs et prete de l'argent lorsque requis sur les hypotheques.\nLa Banque percoit toutes les taxes, amendes, prets et interets. La Banque ne fait jamais faillite (elle dispose de fonds illimites).\n\nLe jeu\n\nAu debut, et une fois que chaque joueur.euse ait saisi son nom, Le programme choisira aleatoirement qui commence.  Son jeton est affiche sur le coin marque ''GO'', il ''lance'' les 2 des, et sera deplace du nombre indique. Apres qu'il/elle ait termine son jeu, le tour de jeu passe a sa gauche (sens horaire). Les jetons restent sur la case et proceder a partir de ce point au tour suivant\nDeux ou plus de deux joueur.euses peuvent etre sur la meme cases au meme moment. En fonction de la case que son jeton atteint, le joueur peut avoir le droit d'acheter des biens immobiliers ou d'autres proprietes ou etre oblige de payer un loyer, payer des impots, tirer une carte chance ou communaute etc.\n\nDoubles\n\nSi un.e joueur.euse lance des doubles, il deplace son jeton comme d'habitude, la somme des deux des, et est assujetti a tous les privileges ou penalites relatifs a l'espace sur lequel il atterrit.\nIl a alors le droit de relancer les des une deuxieme fois. Il relance et deplace son jeton\nSi un.e joueur.euse lance des doubles trois fois de suite, il deplace immediatement son jeton dans l'espace ''En prison''.\n\nDepart\n\nChaque fois qu'un jeton atterrit ou passe par-dessus la case depart, que ce soit en jetant les des ou en tirant une carte, le banquier paie au joueur un salaire de 200 Euros.\nLes 200 Euros ne sont payes qu'une seule fois a chaque fois autour de la planche.\nCependant, si un.e joueur.euse qui passe le depart sur le jet d'un de atterrit 2 cases au-dela sur le Coffre de la communaute, ou 7 cases au-dela sur la Chance, et tire la carte ''Avance au Depart'', il ramasse 200 Euros pour passer le depart la premiere fois et 200 Euros pour l'atteindre la deuxieme fois par des instructions sur la carte.\n\nAcheter une propriete\n\nChaque fois qu'un.e joueur.euse atterrit sur une propriete non possedee, il.elle peut acheter cette propriete a la Banque a son prix imprime.\nLe joueur recoit la carte de titre de propriete et la place face visible devant lui.\n\nPaiement du loyer\n\nLorsqu'un.e joueur.euse atterrit sur une propriete appartenant a un autre joueur, le proprietaire percoit le loyer du joueur conformement a la liste imprimee sur la carte de titre de propriete qui lui est applicable.\nSi la propriete est hypothequee, aucun loyer ne peut etre percu. Lorsqu'une propriete est hypothequee, sa carte de titre de propriete est placee face cachee devant le proprietaire.\nC'est un avantage de detenir toutes les cartes de titre de propriete dans un groupe de couleur parce que le proprietaire peut alors facturer un double loyer pour les proprietes non ameliorees dans ce groupe de couleur. Cette regle s'applique aux proprietes non hypothequees, meme si une autre propriete de ce groupe de couleur est hypothequee.\nIl est encore plus avantageux d'avoir des maisons et des hotels sur les proprietes parce que les loyers sont beaucoup plus eleves que pour les proprietes non ameliorees.\nLe loyer est retire automatiquement de la cagnotte de la personne qui doit payer : si le solde est insuffisant on lui demande s'il.elle veut hypothequer ou vendre des biens : si ce n'est pas possible c'est la faillite et c'est perdu !\n\nChance et communaute\n\nQuand un.e joueur.euse atterrit sur l'un de ces cases, il/elle prend la carte du haut de la pioche indiquee, suit les instructions et retourne la carte face cachee au bas de la pioche. La carte ''Sortir de prison'' est conservee jusqu'a ce qu'elle soit utilisee, puis retournee au fond du paquet.\n\nImpot sur le revenu\n\nLorsqu'un.e joueur.euse atterrit sur ''Impot sur le revenu'', il doit payer l'impot de 200 Euros a la Banque.\n\nPrison\n\nUn.e joueur.euse atterrit en prison quand :\n1.	Son jeton atterrit dans l'espace marque ''ALLER EN PRISON''\n2.	Il tire une carte marquee ''ALLER EN PRISON''\n3.	Il lance trois fois de suite des doubles.\nLorsqu'un.e joueur.euse est envoye en prison, il ne peut pas recevoir 200Euros de salaire pour ce coup car, peu importe ou se trouve son jeton sur le plateau, il doit le deplacer directement en prison.\nSon tour se termine lorsqu'il est envoye en prison. Si un.e joueur.euse n'est pas ''envoye en prison'' mais qu'il atterrit dans le cours normal du jeu sur cet case, il est juste ''En visite'', n'encourt aucune penalite, et avance de la maniere habituelle sur son prochain jet.\nUn.e joueur.euse sort de prison lorsqu'il :\n1.	Lance des doubles sur l'un de ses trois tours suivants, s'il reussit a le faire, il avance immediatement le nombre d'espaces indiques par son double, meme s'il a lance des doubles, il ne prend pas un autre tour\n2.	Utilise la carte ''Sortir de prison gratuitement'' s'il en a une\n3.	Achete la carte ''Sortir de prison gratuitement'' d'un autre joueur et la jouer\n4.	Payer une amende de 50 Euros avant de lancer les des lors de l'un ou l'autre de ses deux tours suivants.\n5.	Si le joueur ne lance pas le double a son troisieme tour, il doit payer l'amende de 50 Euros. Il/elle sort alors de prison et avance immediatement le nombre de cases indiquees par son jet.\nMeme s'il.elle est en prison, un.e joueur.euse peut encore acheter, vendre ou hypothequer une propriete, acheter ou vendre des maisons et des hotels, faire des echanges et percevoir des loyers.\n\nStationnement gratuit\n\nUn.e joueur.euse qui atterrit sur cet espace ne recoit pas d'argent, de biens ou de recompenses de quelque nature que ce soit. Ce n'est qu'un lieu de repos ''libre''.\n\nMaisons\n\nUne maison peut etre achete sur n'importe quel case propriete possedee.\nS'il achete une maison, il peut la mettre sur la propriete ou il.elle est.\nLe prix que le joueur doit payer a la Banque pour chaque maison est indique sur sa carte de titre de propriete pour la propriete sur laquelle il erige la maison.\nLe proprietaire peut toujours percevoir un double loyer s'il.elle possede tout un groupe de proprietes.\n\nHotels\n\nQuand un.e joueur.euse a quatre maisons sur une propriete, il.elle peut acheter un hotel a la Banque et l'eriger sur cette propriete. Il/elle rend les quatre maisons de cette propriete a la Banque et paie le prix de l'hotel tel qu'indique sur la carte de titre de propriete.\nUn seul hotel peut etre erige sur une meme propriete.\n\nPenurie de batiments\n\nLorsque la Banque n'a pas de maisons a vendre, les joueurs souhaitant construire doivent attendre qu'un autre joueur vende ses maisons a la Banque avant de construire.\n\nVendre/negocier un bien immobilier\n\nLes maisons et les hotels peuvent etre revendus a la Banque a tout moment pour la moitie du prix paye.\nLes hotels peuvent etre vendus en une seule fois. Ou bien ils peuvent etre vendus une maison a la fois (un hotel equivaut a cinq maisons), de maniere egale, a l'inverse de la maniere dont ils ont ete eriges.\n\nHypotheques\n\nLes proprietes non ameliorees peuvent etre hypothequees par l'entremise de la Banque en tout temps.\nAvant qu'une propriete amelioree puisse etre hypothequee, tous les batiments sur toutes les proprietes de son groupe de couleur doivent etre revendus a la Banque a moitie prix. La valeur de l'hypotheque est imprimee sur chaque carte de titre de propriete.\nAucun loyer ne peut etre percu sur les proprietes hypothequees ou les services publics, mais le loyer peut etre percu sur les proprietes non hypothequees du meme groupe de couleur. Afin de lever l'hypotheque, le proprietaire doit payer a la Banque le montant de l'hypotheque majore d'un interet de 10 %.\nToutefois, le proprietaire peut vendre ou echanger cette propriete hypothequee a un autre joueur a n'importe quel prix convenu. Le nouveau proprietaire peut lever l'hypotheque immediatement, s'il le desire, en remboursant l'hypotheque plus 10 % d'interets a la Banque. S'il ne resilie pas l'hypotheque immediatement, il doit payer a la banque un interet de 10% lorsqu'il achete/recoit la propriete hypothequee, et s'il leve l'hypotheque plus tard, il doit payer a la Banque un interet additionnel de 10% ainsi que le montant de l'hypotheque.\n\nFaillite\n\nUn.e joueur.euse est en faillite lorsqu'il doit plus qu'il ne peut payer a un autre joueur ou a la Banque. Si sa dette est envers un autre joueur, il doit remettre a ce joueur tout ce qu'il a de valeur et se retirer du jeu.\nDans le cadre de ce reglement, s'il est proprietaire de maisons ou d'hotels, il doit les restituer a la Banque en echange d'argent a hauteur de la moitie du montant paye et cet argent est remis au creancier.\nS'il a hypotheque un bien, il remet egalement son bien a ce creancier, mais le nouveau proprietaire doit payer immediatement a la Banque le montant des interets sur le pret, soit 10 % de la valeur du bien.\nUne fois que le nouveau proprietaire l'a fait, il peut, a son gre, payer le capital ou detenir la propriete jusqu'a une date ulterieure a laquelle il peut resilier l'hypotheque. S'il detient des biens de cette facon jusqu'a un tour ulterieur, il/elle doit payer les interets a nouveau lorsqu'il/elle leve l'hypotheque.\nSi un.e joueur.euse doit a la Banque, au lieu d'un autre joueur, plus que ce qu'il peut payer (en raison de taxes ou de penalites), meme en vendant ses batiments, en hypothequant sa propriete ou en vendant ou en echangeant avec d'autres joueurs, il doit remettre tous ses biens a la Banque.\n\nDivers\n\nLa Banque ne peut preter de l'argent a un.e joueur.euse qu'en hypothequant un bien immobilier. Aucun.e joueur.euse ne peut emprunter a ou preter de l'argent a un autre joueur.");
        return 0;
    }

    int choix;
    int numeroTour;
    int numeroDe[2];
    int deplacementCase;
    numeroTour = choixDuPremier(J); //on choisit le premier utilisateur � jouer
    *tourJoueur = numeroTour;
    Color(3,0);
    printf("\nIA : Le premier joueur a debute la partie est : ");
    Color(player[numeroTour]->couleur, 0);
    printf("%s\n", player[numeroTour]->prenomJoueur);
    Color(3,0);
    printf(" IA : Veuillez appuyer sur 1 pour lancer le de : ");
    scanf("%d", &choix);
    while(choix != 1){
        printf("\nIA : Je n'ai compris ... je sens que ca va etre complique ... veuillez ressaisir\n");
        fflush(stdin);
        scanf("%d",&choix);
    }



    int deplacementCase1 = 0;
    int deplacementCase2 = 0;
    int deplacementCase3 = 0;

    if (choix == 1)
    {
        deplacementCase1 = lancerDe(player, numeroDe, numeroTour);
        if(numeroDe[1] == numeroDe[0])
        {
            deplacementCase2 = lancerDe(player, numeroDe, numeroTour);
            if(numeroDe[1] == numeroDe[0])
            {
                deplacementCase3 = lancerDe(player, numeroDe, numeroTour);
                if(numeroDe[1] == numeroDe[0])
                {
                    printf("IA : Vous allez en prison !");

                }
            }

        }
        deplacementCase = deplacementCase1 + deplacementCase2 + deplacementCase3;
        printf("%s avance de %d cases.\n", player[numeroTour]->prenomJoueur, deplacementCase);
        *nombreDeDeplacement = deplacementCase;
         system("PAUSE");


    }


}
