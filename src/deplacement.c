#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "deplacement.h"
#include "ecranGagner.h"
#include "puzzleResolu.h"
#include "compteur.h"


/* Déplacement du puzzle après mélange */
void deplacement(int l, int c, int joueur[8][8], int l_tuile, int h_tuile)
{
    int centre_x;
    int centre_y;
    int bl_i, bl_j;
    int i, j;
    int m, n;
    int touche;
    int x, y;
    int numTile;
    int trouve;
    int ref;
    int mouvement_effectue;

    /* Initialiser le compteur de coups */
    init_compteur();

    /* Centrage du puzzle */
    centre_x = 600 - (c * (l_tuile + 2)) / 2;
    centre_y = 300 - (l * (h_tuile + 2)) / 2;

    /* Boucle infinie de jeu */
    while (1)
    {
        /* --- Trouver la tuile blanche --- */
        trouve = 0;
        for (i = 0; i < l && !trouve; i++)
        {
            for (j = 0; j < c && !trouve; j++)
            {
                if (joueur[i][j] == -1)
                {
                    bl_i = i;
                    bl_j = j;
                    trouve = 1;
                }
            }
        }

        /* Déplacements au clavier */
        mouvement_effectue = 0;
        if (ToucheEnAttente())
        {
            touche = Touche();

            if (touche == XK_Up && bl_i < l - 1)
            {
                joueur[bl_i][bl_j] = joueur[bl_i + 1][bl_j];
                joueur[bl_i + 1][bl_j] = -1;
                mouvement_effectue = 1;
            }
            else if (touche == XK_Down && bl_i > 0)
            {
                joueur[bl_i][bl_j] = joueur[bl_i - 1][bl_j];
                joueur[bl_i - 1][bl_j] = -1;
                mouvement_effectue = 1;
            }
            else if (touche == XK_Left && bl_j < c - 1)
            {
                joueur[bl_i][bl_j] = joueur[bl_i][bl_j + 1];
                joueur[bl_i][bl_j + 1] = -1;
                mouvement_effectue = 1;
            }
            else if (touche == XK_Right && bl_j > 0)
            {
                joueur[bl_i][bl_j] = joueur[bl_i][bl_j - 1];
                joueur[bl_i][bl_j - 1] = -1;
                mouvement_effectue = 1;
            }
            
            /* Incrémenter le compteur si un mouvement a été effectué */
            if (mouvement_effectue)
            {
                incrementer_compteur();
            }
        }

        /*Déplacements à la souris fallait faire le test quand 
        c'est egale a 1 sinon quand on compare normalement d'es quon bouge la souris
        la val de SourisCliquee elle revient a 0 et l'evenement se declencehe pas*/
        if (SourisCliquee() == 1)
        {
            SourisPosition();
            x = _X;
            y = _Y;

            /* Clic dans la grille ? */
            if (x >= centre_x && x <= centre_x + c * (l_tuile + 2) &&
                y >= centre_y && y <= centre_y + l * (h_tuile + 2))
            {
                i = (y - centre_y) / (h_tuile + 2);
                j = (x - centre_x) / (l_tuile + 2);

                /* Vérifier si (i,j) est adjacent à la blanche */
                if ((i == bl_i && (j == bl_j - 1 || j == bl_j + 1)) ||
                    (j == bl_j && (i == bl_i - 1 || i == bl_i + 1)))
                {
                    joueur[bl_i][bl_j] = joueur[i][j];
                    joueur[i][j] = -1;
                    /* Incrémenter le compteur pour un mouvement à la souris */
                    incrementer_compteur();
                }
            }
        }

        /*Vérifier si le puzzle est résolu AVANT le réaffichage*/
        int resolu = puzzle_resolu(l, c, joueur);
        if (resolu)
        {
            printf("DEBUG: Puzzle résolu détecté, affichage de l'écran de fin\n");
            /* Afficher l'écran de fin */
            ecran_fin();
            return;   /*quitter la fonction de déplacement*/
        }

        /*Réaffichage complet */
        ChoisirEcran(0);
        ChargerImageFond("../img/fondbleu.png");

        /* Réaffichage du modèle en haut a gauche sinon ça fait quand tu clique
        ou t'appuies sur les flèche ta plus le modèle du puzzle */
        for (m = 0; m < l; m++)
        {
            for (n = 0; n < c; n++)
            {
                ref = m * c + n;
                CopierZone(3, 0,(ref % c) * l_tuile,(ref / c) * h_tuile,l_tuile, h_tuile,
                           20 + n * (l_tuile + 2),
                           20 + m * (h_tuile + 2));
            }
        }

        /* Réaffichage du puzzle joué */
        for (m = 0; m < l; m++)
        {
            for (n = 0; n < c; n++)
            {
                numTile = joueur[m][n];
                x = centre_x + n * (l_tuile + 2);
                y = centre_y + m * (h_tuile + 2);

                if (numTile == -1)
                {
                    /* tuile blanche */
                    CopierZone(3, 0, 500, 0, l_tuile, h_tuile, x, y);
                }
                else
                {
                    CopierZone(3, 0,(numTile % c) * l_tuile,(numTile / c) * h_tuile,
                    l_tuile, h_tuile,x, y);
                }
            }
            
        }
        EcrireTexte(450, 100, "A toi de jouer !", 2);
        
        /* Afficher le compteur de coups */
        afficher_compteur(450, 130);
    }
}
