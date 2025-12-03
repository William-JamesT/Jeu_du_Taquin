#include <graph.h>
#include <stdio.h>
#include "compteur.h"

/* Variable statique pour stocker le nombre de coups */
static int nombre_coups = 0;

/* Initialise le compteur de coups à 0 */
void init_compteur()
{
    nombre_coups = 0;
}

/* Incrémente le compteur de coups */
void incrementer_compteur()
{
    nombre_coups++;
}

/* Retourne la valeur actuelle du compteur */
int get_compteur()
{
    return nombre_coups;
}

/* Réinitialise le compteur à 0 */
void reset_compteur()
{
    nombre_coups = 0;
}

/* Affiche le compteur à l'écran aux coordonnées (x, y) */
void afficher_compteur(int x, int y)
{
    char texte[50];
    
    /* Formater le texte avec le nombre de coups */
    sprintf(texte, "Coups: %d", nombre_coups);
    
    /* Afficher le texte en blanc */
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(x, y, texte, 2);
}

