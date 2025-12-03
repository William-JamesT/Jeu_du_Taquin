#include <stdlib.h>
#include <graph.h>
#include <stdio.h>
#include <string.h>  /* pour strcmp */
#include "melange.h"
#include "deplacement.h"

void decoupage(int l, int c, char *image)
{
    
    int img_L, img_H;
    int l_tuile, h_tuile;
    int joueur[8][8];    /* tableau des tuiles du joueur */
    int modele[8][8];
    int i, j;
    int num = 0;
    int numTile;
    int src_x, src_y, dst_x, dst_y;
    
    /* Dimensions selon l'image  grace la fonction strcmp va regarder ce quelle fait c'est grace a ça que le decoupage il s'adapte*/
    if (strcmp(image, "../img/BPimage2.png") == 0) {
        img_L = 300;
        img_H = 188;
    } else if (strcmp(image, "../img/Etooimage.png") == 0) {
        img_L = 200;
        img_H = 125;
    } else if (strcmp(image, "../img/OTimage2.png") == 0) {
        img_L = 350;
        img_H = 233;
    } 

    /* Taille des tuiles */
    l_tuile = img_L / c;
    h_tuile = img_H / l;

    /* Remplir le tableau du joueur dans l'ordre */
    for (i = 0; i < l; i++){
        for (j = 0; j < c; j++){
            joueur[i][j] = num;
            modele[i][j] = num;
            num++;
        }
    }
    /*on créer notre tuiles blanche*/
    joueur[0][0] = -1;

    /* Charger l'image complète dans l'écran 3 */

    ChoisirEcran(3);
    EffacerEcran(CouleurParNom("white"));
    ChargerImage(image, 0, 0, 0, 0, img_L, img_H);

    /* Créeation la tuile blanche dans l’écran 3 */
    ChoisirCouleurDessin(CouleurParNom("white"));
    RemplirRectangle(500, 0, l_tuile, h_tuile);


    /* Affichage du modèle non mélangé en haut à gauche  */
    ChoisirEcran(0);
    ChargerImageFond("../img/fondbleu.png");
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            numTile = modele[i][j];
            src_x = (numTile % c) * l_tuile;
            src_y = (numTile / c) * h_tuile;
            dst_x = 20 + j * (l_tuile + 2);   /* modèle en haut à gauche */
            dst_y = 20 + i * (h_tuile + 2);
            CopierZone(3, 0, src_x, src_y, l_tuile, h_tuile, dst_x, dst_y);
        }
    }

    /*  Affichage du puzzle joueur au centre */
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            numTile = joueur[i][j];
            dst_x = 600 - (img_L / 2) + j * (l_tuile + 2); /* centré */
            dst_y = 300 - (img_H / 2) + i * (h_tuile + 2);


            /*si onn est sur la valeur -1 donc la première case*/
            if (numTile == -1){
                /*on copie la zone de la tuile blanche*/
                CopierZone(3, 0, 500, 0, l_tuile, h_tuile, dst_x, dst_y);
            }else{
                /*on prend les tuiles de l'image selectionné pour le reste du puzzle*/
                src_x = (numTile % c) * l_tuile;
                src_y = (numTile / c) * h_tuile;
                CopierZone(3, 0, src_x, src_y, l_tuile, h_tuile, dst_x, dst_y);
            }
        }    
    }

    /*Bouton Mélanger*/
    ChoisirCouleurDessin(CouleurParNom("black"));
    RemplirRectangle(450, 450, 150, 89);
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(460, 515, "Melanger", 2);

    

    /*Attente clic sur Mélanger*/
    while (1) {
        while (!SourisCliquee());
        SourisPosition();
        
        /* Vérifier si le clic est sur le bouton Mélanger */
        if (_X >= 450 && _X <= 600 && _Y >= 450 && _Y <= 589) {
            /* Attendre que le clic soit relâché */
            while (SourisCliquee());
            /* Mélanger le puzzle */
            melange(l, c, joueur, l_tuile, h_tuile);
            /* Lancer le jeu */
            deplacement(l, c, joueur, l_tuile, h_tuile);
            return;
        }
        /* Si le clic n'est pas sur le bouton, attendre qu'il soit relâché et continuer la boucle */
        while (SourisCliquee());
    }
}
