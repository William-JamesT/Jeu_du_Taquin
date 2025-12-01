#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>

void melange(int l, int c, int joueur[8][8], int l_tuile, int h_tuile)
{
    int i, j, k;
    int tmp;
    int imgB_i, imgB_j;
    int dst_x, dst_y;
    int modele[8][8];
    int num;
    int numTile;
    int centre_x;
    int centre_y;
    /* c'est bon j'ai reussi 3x3 2fois d'affilé*/
    /*ooooooooooooooooooooooooooooo*/

    /* Initialiser le tableau modèle non mélangé */
    num = 0;
    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
        {
            modele[i][j] = num++;
        }
    }

    /* Initialiser le générateur aléatoire */
    srand((unsigned int)time(NULL));

    /* Mélange aléatoire des tuiles dans joueur */

/* Trouver la position initiale de la tuile blanche (-1) */
for (i = 0; i < l; i++)
{
    for (j = 0; j < c; j++)
    {
        if (joueur[i][j] == -1)
        {
            imgB_i = i;   /* réutilisation de imgB_i pour stocker bl_i */
            imgB_j = j;   /* réutilisation de imgB_j pour stocker bl_j */
        }
    }
}

/* Effectuer des mouvements aléatoires en jouant des coup */
for (k = 0; k < l * c * 20; k++)
{
    tmp = rand() % 4; /* tmp = direction (0=haut,1=bas,2=gauche,3=droite) */

    /* HAUT */
    if (tmp == 0 && imgB_i < l - 1)
    {
        joueur[imgB_i][imgB_j] = joueur[imgB_i + 1][imgB_j];
        joueur[imgB_i + 1][imgB_j] = -1;
        imgB_i++;
    }
    /* BAS */
    else if (tmp == 1 && imgB_i > 0)
    {
        joueur[imgB_i][imgB_j] = joueur[imgB_i - 1][imgB_j];
        joueur[imgB_i - 1][imgB_j] = -1;
        imgB_i--;
    }
    /* GAUCHE */
    else if (tmp == 2 && imgB_j < c - 1)
    {
        joueur[imgB_i][imgB_j] = joueur[imgB_i][imgB_j + 1];
        joueur[imgB_i][imgB_j + 1] = -1;
        imgB_j++;
    }
    /* DROITE */
    else if (tmp == 3 && imgB_j > 0)
    {
        joueur[imgB_i][imgB_j] = joueur[imgB_i][imgB_j - 1];
        joueur[imgB_i][imgB_j - 1] = -1;
        imgB_j--;
    }
}


    /* Réaffichage sur l'écran 0 */
    ChoisirEcran(0);
    ChargerImageFond("../img/fondbleu.png");

    /* Affichage du modèle non mélangé en haut à gauche */
    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
        {
            numTile = modele[i][j];
            dst_x = 20 + j*(l_tuile+2);
            dst_y = 20 + i*(h_tuile+2);
            CopierZone(3, 0, (numTile%c)*l_tuile, (numTile/c)*h_tuile,
                       l_tuile, h_tuile, dst_x, dst_y);
        }
    }

    /* Affichage du puzzle joueur mélangé au centre mais pas trop parceque sinon
    pour la grande image OT le modele et le jouable il ce chevauche */
    centre_x = 600 - (c*(l_tuile+2))/2;
    centre_y = 300 - (l*(h_tuile+2))/2;
    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
        {
            numTile = joueur[i][j];
            dst_x = centre_x + j*(l_tuile+2);
            dst_y = centre_y + i*(h_tuile+2);

            /*si ça correspond a la tuile[0][0] qui a comme valeur -1 on copie la tuiles
            blanche qu'on avait dessiné */

            if(numTile == -1){
                CopierZone(3,0,500,0,l_tuile,h_tuile,dst_x,dst_y);
                
            /*sinon pour le reste on prend celle de l'image*/

            }else{
                CopierZone(3, 0, (numTile%c)*l_tuile, (numTile/c)*h_tuile,
                l_tuile, h_tuile, dst_x, dst_y);
            }
        }
    }

    

    /* Message */
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(450, 100, "A toi de jouer !", 2);
}
