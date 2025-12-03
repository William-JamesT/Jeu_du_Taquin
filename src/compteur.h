#ifndef COMPTEUR_H
#define COMPTEUR_H

/* Initialise le compteur de coups à 0 */
void init_compteur();

/* Incrémente le compteur de coups */
void incrementer_compteur();

/* Retourne la valeur actuelle du compteur */
int get_compteur();

/* Réinitialise le compteur à 0 */
void reset_compteur();

/* Affiche le compteur à l'écran aux coordonnées (x, y) */
void afficher_compteur(int x, int y);

#endif

