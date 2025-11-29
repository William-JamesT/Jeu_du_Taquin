#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

/* 
 * Fonction qui permet de déplacer les tuiles dans le puzzle après mélange
 * 
 * Paramètres :
 *   l        : nombre de lignes
 *   c        : nombre de colonnes
 *   joueur   : tableau 2D représentant l'état actuel du puzzle
 *   l_tuile  : largeur d'une tuile
 *   h_tuile  : hauteur d'une tuile
 */
void deplacement(int l, int c, int joueur[8][8], int l_tuile, int h_tuile);

#endif