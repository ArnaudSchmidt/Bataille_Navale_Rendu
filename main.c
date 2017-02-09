#include <stdio.h>
#include <stdlib.h>

//Sujet
/*
1. Ecrire une structure cellule compos�e de 2 champs ligne et colonne qui sont des entiers.
2. Ecrire une structure bateaux compos�e d'un ensemble de n cellules.
3. Ecrire une structure flottes compos�e d'un ensemble de bateaux.
4. Ecrire une fonction de cr�ation d'une cellule : elle prend en param�tre la ligne et la collone associ�es � la cellule.
5. Ecrire une fonction de comparaison de 2 cellules : cette fonction renvera vrai ou faux selon le cas.
6. Ecrire une fonction de cr�ation de bateaux : elle renvera une structure bateau correctement remplie.
7. Ecrire une fonction qui v�rifie qu'une cellule appartient � un bateau cette fonction renverra vrai ou faux selon le cas.
   Attention cette fonction devra utiliser votre fonction de comparaison de cellule cr��e auparavant.
8. Ecrire une fonction qui v�rifie qu'une cellule appartient � une flotte de bateaux.
   Attention cette fonction devra utiliser votre fonction de verification pour un bateau.
9. Ecrire la bataille navale compl�te.
10. Bonne chance !
*/



/*                                        <----- CONSTANTES ----->                                          */



//On choisit la taille qu'aura un c�t� du plateau.
#define TailleGrille 25
//On choisit le nombre de joueurs qui prendront part � la partie.
#define NombreJoueurs 2



/*                                      <----- TYPES STRUCTURES ----->                                      */



//On d�clare le type structur� qui correspond � la cellule dans laquelle se trouvera un bateau.
typedef struct Cell {

    int colonne, ligne;
    int etat;

}Cell;

//On d�clare le type structur� qui regroupera les diff�rents bateaux d'un joueur et qui tiendra le compte du nombre de bateau encore "actifs".
typedef struct Boats{

    int reste;
    Cell tabboats[TailleGrille/5];

}Boats;

//On d�clare le type structur� qui regroupera les flottes des diff�rents joueurs.
typedef struct Fleets{

    Boats tabfleet[NombreJoueurs];

}Fleets;

//On d�clare l'�quivalent d'un bool�en afin de l'utiliser dans divers proc�dures/fonctions.
enum BOOL{

    True,False

};



/*                                        <----- PROTOTYPES ----->                                          */



void CreationBateau(int *coordx, int *coordy);
enum BOOL CompCoor(int cellx1, int celly1, int cellx2, int celly2);
void CreaBat(int xbat, int ybat, Fleets *pFlotte, int numjoueur);
int VerifBat(int xbat, int ybat, Fleets *pFlotte, int numjoueur);



/*                                      <----- CODE PRINCIPAL ----->                                        */



int main()
{

    //d�clarations des variables des coordonn�es de cellules ainsi que leurs pointeurs associ�s
    int celluleciblex, cellulecibley;
    int *pcelluleciblex, *pcellulecibley;
    //d�claration de la variable contenant le joueur actic (0 ou 1)
    int joueuractif;
    //d�clarationdu tableau des flottes
    Fleets Flottes;
    //initialisation des pointeurs
    *pcelluleciblex = &celluleciblex;
    *pcellulecibley = &cellulecibley;


    //initialisation des flottes (coordonn�es des bateaux & etats des bateaux)

    //mise en place de la partie (chaque joueur cr�e ses 5 bateaux)

    //boucle de jeu (on d�finit le joueur actif, il choisit 2 coordonn�es, on v�rifie si il touche quelque chose,
    //puis on passe � l'autre joueur, si le "reste" d'un des joueurs est � 0, la partie se termine et le joueur actif gagne)

    return 0;

}



/*                                  <----- PROCEDURES ET FONCTIONS ----->                                   */



//Proc�dure qui attribue � une cellule les coordonn�es entr�es par l'utilisateur.
void CreationBateau(int *coordx, int *coordy)
//But: Cr�er une cellule/bateau qui aurait les coordonn�es entr�es par l'utilisateur.
//Entr�e: Deux coordonn�es que poss�de un bateau.
//Sortie: Le bateau cibl� a maintenant des coordonn�es d�finies.
{

   printf("Vous devez cr�er un nouveau bateau.\n");
   printf("Sur quelle colonne voulez-vous le placer ?\n");
   scanf("%d",&coordx);
   printf("Sur quelle ligne voulez-vous le placer ?\n");
   scanf("%d",&coordy);

}

//Fonction qui compare les coordonn�es de 2 bateaux et renvoie vrai ou faux en fonction du r�sultat.
enum BOOL CompCoor(int cellx1, int celly1, int cellx2, int celly2)
//But: Comparer deux couples de coordonn�es et dire si ils sont �gaux ou non.
//Entr�e: Deux couples de coordonn�es.
//Sortie: True ou False en fonction du r�sultat de la comparaison.
{

    if (cellx1 == cellx2 && celly1 == celly2)
    {
        return True;
    }
    else
    {
        return False;
    }

};

//Proc�dure qui cr�e un bateau.
void CreaBat(int xbat, int ybat, Fleets *pFlotte, int numjoueur)
//But: Cr�er un bateau appartenant � la flotte du joueur actif.
//Entr�e: Les coordonn�es que l'on souhaite lui donner, ainsi que la flotte et le joueur auquel elle appartient.
//Sortie: Un bateau fraichement cr��.
{

    (*pFlotte).tabfleet[numjoueur].tabboats[(*pFlotte).tabfleet[numjoueur].reste].colonne = xbat;
    (*pFlotte).tabfleet[numjoueur].tabboats[(*pFlotte).tabfleet[numjoueur].reste].ligne = ybat;
    (*pFlotte).tabfleet[numjoueur].tabboats[(*pFlotte).tabfleet[numjoueur].reste].etat = 1;
    (*pFlotte).tabfleet[numjoueur].reste = (*pFlotte).tabfleet[numjoueur].reste + 1;

}

//Fonction qui v�rifie si les coordonn�es entr�es sont celles d'un bateau ennemi.
int VerifBat(int xbat, int ybat, Fleets *pFlotte, int numjoueur)
//But: V�rifier si les coordonn�es choisies sont celles d'un bateau ennemi qui peut �tre coul�.
//Entree: Deux coordonn�es, le joueur cibl� et sa flotte.
//Sortie: Le joueur saura si il a touch� un bateau ou non.
{

    int i;
    for(i=0;i<(TailleGrille/5);i++)
    {
        if (CompCoor(xbat, ybat, (*pFlotte).tabfleet[numjoueur].tabboats[i].colonne, (*pFlotte).tabfleet[numjoueur].tabboats[i].ligne))
        {
            if ((*pFlotte).tabfleet[numjoueur].tabboats[i].etat == 1)
            {
                (*pFlotte).tabfleet[numjoueur].tabboats[i].etat = 0;
                printf("Vous avez touch� une bateau !");
                (*pFlotte).tabfleet[numjoueur].reste = (*pFlotte).tabfleet[numjoueur].reste - 1;
                break;
            }
        }
        else
        {
            //rien, sauf si on a compar� tous les bateaux
            if (i == (TailleGrille/5)-1)
            {
                printf("Dommage, vous n'avez rien touch�.");
            }
        }
    }

}

/*
    Je dois m'�tre un peu perdu dans l'�nonc�, car les points 7 et 8 donneraient des fonctions assez similaires si je garde la logique
    que j'utilise depuis le d�but... Il faudrait donc probablement revoir une partie du code, malheureusement je vais manquer de temps pour :
    1) trouver � quel niveau j'ai fait une erreur d'interpr�tation
    2) finir mon code
    J'en suis navr�, j'esp�re que le travail rendu montrera tout de m�me ce que j'ai appris durant les cours de C.
*/

