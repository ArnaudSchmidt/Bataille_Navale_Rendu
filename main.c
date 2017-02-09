#include <stdio.h>
#include <stdlib.h>

//Sujet
/*
1. Ecrire une structure cellule composée de 2 champs ligne et colonne qui sont des entiers.
2. Ecrire une structure bateaux composée d'un ensemble de n cellules.
3. Ecrire une structure flottes composée d'un ensemble de bateaux.
4. Ecrire une fonction de création d'une cellule : elle prend en paramètre la ligne et la collone associées à la cellule.
5. Ecrire une fonction de comparaison de 2 cellules : cette fonction renvera vrai ou faux selon le cas.
6. Ecrire une fonction de création de bateaux : elle renvera une structure bateau correctement remplie.
7. Ecrire une fonction qui vérifie qu'une cellule appartient à un bateau cette fonction renverra vrai ou faux selon le cas.
   Attention cette fonction devra utiliser votre fonction de comparaison de cellule créée auparavant.
8. Ecrire une fonction qui vérifie qu'une cellule appartient à une flotte de bateaux.
   Attention cette fonction devra utiliser votre fonction de verification pour un bateau.
9. Ecrire la bataille navale complète.
10. Bonne chance !
*/



/*                                        <----- CONSTANTES ----->                                          */



//On choisit la taille qu'aura un côté du plateau.
#define TailleGrille 25
//On choisit le nombre de joueurs qui prendront part à la partie.
#define NombreJoueurs 2



/*                                      <----- TYPES STRUCTURES ----->                                      */



//On déclare le type structuré qui correspond à la cellule dans laquelle se trouvera un bateau.
typedef struct Cell {

    int colonne, ligne;
    int etat;

}Cell;

//On déclare le type structuré qui regroupera les différents bateaux d'un joueur et qui tiendra le compte du nombre de bateau encore "actifs".
typedef struct Boats{

    int reste;
    Cell tabboats[TailleGrille/5];

}Boats;

//On déclare le type structuré qui regroupera les flottes des différents joueurs.
typedef struct Fleets{

    Boats tabfleet[NombreJoueurs];

}Fleets;

//On déclare l'équivalent d'un booléen afin de l'utiliser dans divers procédures/fonctions.
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

    //déclarations des variables des coordonnées de cellules ainsi que leurs pointeurs associés
    int celluleciblex, cellulecibley;
    int *pcelluleciblex, *pcellulecibley;
    //déclaration de la variable contenant le joueur actic (0 ou 1)
    int joueuractif;
    //déclarationdu tableau des flottes
    Fleets Flottes;
    //initialisation des pointeurs
    *pcelluleciblex = &celluleciblex;
    *pcellulecibley = &cellulecibley;


    //initialisation des flottes (coordonnées des bateaux & etats des bateaux)

    //mise en place de la partie (chaque joueur crée ses 5 bateaux)

    //boucle de jeu (on définit le joueur actif, il choisit 2 coordonnées, on vérifie si il touche quelque chose,
    //puis on passe à l'autre joueur, si le "reste" d'un des joueurs est à 0, la partie se termine et le joueur actif gagne)

    return 0;

}



/*                                  <----- PROCEDURES ET FONCTIONS ----->                                   */



//Procédure qui attribue à une cellule les coordonnées entrées par l'utilisateur.
void CreationBateau(int *coordx, int *coordy)
//But: Créer une cellule/bateau qui aurait les coordonnées entrées par l'utilisateur.
//Entrée: Deux coordonnées que possède un bateau.
//Sortie: Le bateau ciblé a maintenant des coordonnées définies.
{

   printf("Vous devez créer un nouveau bateau.\n");
   printf("Sur quelle colonne voulez-vous le placer ?\n");
   scanf("%d",&coordx);
   printf("Sur quelle ligne voulez-vous le placer ?\n");
   scanf("%d",&coordy);

}

//Fonction qui compare les coordonnées de 2 bateaux et renvoie vrai ou faux en fonction du résultat.
enum BOOL CompCoor(int cellx1, int celly1, int cellx2, int celly2)
//But: Comparer deux couples de coordonnées et dire si ils sont égaux ou non.
//Entrée: Deux couples de coordonnées.
//Sortie: True ou False en fonction du résultat de la comparaison.
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

//Procédure qui crée un bateau.
void CreaBat(int xbat, int ybat, Fleets *pFlotte, int numjoueur)
//But: Créer un bateau appartenant à la flotte du joueur actif.
//Entrée: Les coordonnées que l'on souhaite lui donner, ainsi que la flotte et le joueur auquel elle appartient.
//Sortie: Un bateau fraichement créé.
{

    (*pFlotte).tabfleet[numjoueur].tabboats[(*pFlotte).tabfleet[numjoueur].reste].colonne = xbat;
    (*pFlotte).tabfleet[numjoueur].tabboats[(*pFlotte).tabfleet[numjoueur].reste].ligne = ybat;
    (*pFlotte).tabfleet[numjoueur].tabboats[(*pFlotte).tabfleet[numjoueur].reste].etat = 1;
    (*pFlotte).tabfleet[numjoueur].reste = (*pFlotte).tabfleet[numjoueur].reste + 1;

}

//Fonction qui vérifie si les coordonnées entrées sont celles d'un bateau ennemi.
int VerifBat(int xbat, int ybat, Fleets *pFlotte, int numjoueur)
//But: Vérifier si les coordonnées choisies sont celles d'un bateau ennemi qui peut être coulé.
//Entree: Deux coordonnées, le joueur ciblé et sa flotte.
//Sortie: Le joueur saura si il a touché un bateau ou non.
{

    int i;
    for(i=0;i<(TailleGrille/5);i++)
    {
        if (CompCoor(xbat, ybat, (*pFlotte).tabfleet[numjoueur].tabboats[i].colonne, (*pFlotte).tabfleet[numjoueur].tabboats[i].ligne))
        {
            if ((*pFlotte).tabfleet[numjoueur].tabboats[i].etat == 1)
            {
                (*pFlotte).tabfleet[numjoueur].tabboats[i].etat = 0;
                printf("Vous avez touché une bateau !");
                (*pFlotte).tabfleet[numjoueur].reste = (*pFlotte).tabfleet[numjoueur].reste - 1;
                break;
            }
        }
        else
        {
            //rien, sauf si on a comparé tous les bateaux
            if (i == (TailleGrille/5)-1)
            {
                printf("Dommage, vous n'avez rien touché.");
            }
        }
    }

}

/*
    Je dois m'être un peu perdu dans l'énoncé, car les points 7 et 8 donneraient des fonctions assez similaires si je garde la logique
    que j'utilise depuis le début... Il faudrait donc probablement revoir une partie du code, malheureusement je vais manquer de temps pour :
    1) trouver à quel niveau j'ai fait une erreur d'interprétation
    2) finir mon code
    J'en suis navré, j'espère que le travail rendu montrera tout de même ce que j'ai appris durant les cours de C.
*/

