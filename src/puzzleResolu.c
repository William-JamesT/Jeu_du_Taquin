#include <stdio.h>

int puzzle_resolu(int l, int c, int joueur[8][8])
{
    int i, j;
    int valeur_attendue;

    /* Vérifier que la première case (0,0) contient -1 (tuile blanche) */
    if (joueur[0][0] != -1)
    {
        return 0;   /* pas résolu - la tuile blanche n'est pas en haut à gauche */
    }

    /* Vérifier que toutes les autres cases correspondent au modèle */
    /* Le modèle a les valeurs 0, 1, 2, 3, ... donc le joueur doit avoir les mêmes valeurs */
    /* sauf que (0,0) doit être -1 au lieu de 0 */
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            /* On saute la case (0,0) car elle doit être -1 */
            if (i == 0 && j == 0)
            {
                continue;
            }
            
            /* La valeur attendue pour (i,j) est i*c + j (comme dans le modèle) */
            valeur_attendue = i * c + j;
            
            if (joueur[i][j] != valeur_attendue)
            {
                return 0;   /* pas résolu - une tuile n'est pas à la bonne place */
            }
        }
    }

    /* Le puzzle est résolu ! */
    return 1;
}
