int puzzle_resolu(int l, int c, int joueur[8][8])
{
    int i, j;
    int valeur_attendue = 0;

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            /* La dernière case doit être -1 (tuile blanche) */
            if (i == l - 1 && j == c - 1)
            {
                if (joueur[i][j] != -1)
                    return 0;   /* pas résolu*/
            }
            else
            {
                if (joueur[i][j] != valeur_attendue)
                    return 0;   /* pas résolu*/
            }
            valeur_attendue++;
        }
    }

    return 1;   /* le puzzle est entièrement correct*/
}
