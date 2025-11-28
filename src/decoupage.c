#include <stdlib.h>
#include <graph.h>
#include <stdio.h>
#include <string.h>  /* pour strcmp */
#include "melange.h"

void decoupage(int l, int c, char *image)
{
    /* Déclaration des variables au début (C89) */
    int img_L, img_H;
    int l_tuile, h_tuile;
    int joueur[8][8];    /* tableau des tuiles du joueur */
    int i, j;
    int num = 0;
    int src_x, src_y, dst_x, dst_y;
    
    /* -------------------- Dimensions selon l'image -------------------- */
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
    for (i = 0; i < l; i++)
        for (j = 0; j < c; j++)
            joueur[i][j] = num++;

    /* Charger l'image complète dans l'écran 3 */
    ChoisirEcran(3);
    EffacerEcran(CouleurParNom("white"));
    ChargerImage(image, 0, 0, 0, 0, img_L, img_H);

    /* -------------------- Affichage du modèle non mélangé en haut à gauche -------------------- */
    ChoisirEcran(0);
    ChargerImageFond("../img/fondbleu.png");
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            num = joueur[i][j];
            src_x = (num % c) * l_tuile;
            src_y = (num / c) * h_tuile;
            dst_x = 20 + j * (l_tuile + 2);   /* modèle en haut à gauche */
            dst_y = 20 + i * (h_tuile + 2);
            CopierZone(3, 0, src_x, src_y, l_tuile, h_tuile, dst_x, dst_y);
        }
    }

    /* -------------------- Affichage du puzzle joueur au centre -------------------- */
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            num = joueur[i][j];
            src_x = (num % c) * l_tuile;
            src_y = (num / c) * h_tuile;
            dst_x = 600 - (img_L / 2) + j * (l_tuile + 2); /* centré */
            dst_y = 300 - (img_H / 2) + i * (h_tuile + 2);
            CopierZone(3, 0, src_x, src_y, l_tuile, h_tuile, dst_x, dst_y);
        }
    }

    /* -------------------- Bouton Mélanger -------------------- */
    RemplirRectangle(450, 500, 150, 89);
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(480, 525, "Melanger", 2);

    /* message */
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(300, 550, "Puzzle prêt ! Mélange non encore fait.", 2);

    /* -------------------- Attente clic sur Mélanger -------------------- */
    while (!SourisCliquee());
    SourisPosition();

    if (_X >= 450 && _X <= 600 && _Y >= 500 && _Y <= 589) {
        melange(l, c, joueur, l_tuile, h_tuile);
    }
}
