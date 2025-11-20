#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "Bouton.h"
#include "Choix_decoupimg1.h"
#include "Choix_decoupimg2.h"
#include "Choix_decoupimg3.h"
#include "Choix_image.h"
#include "bouton_Choix_image.h"

void tab1(int l, int c, int coordonee[8][8], int joueur[8][8]) {
    int l_image = 260;
    int h_image = 181;
    int l_tuile = l_image / c;
    int h_tuile = h_image / l;
    int marge = 5;
    couleur a, b, w;

    int i, j;
    int x_aff;
    int y_aff;
    int x_src;
    int y_src;

    int x_btn = 575;
    int y_btn = 180;
    int w_btn = 150;
    int h_btn = 60;

    ChoisirEcran(4);

    w = CouleurParNom("white");
    ChoisirCouleurDessin(w);
    EcrireTexte(50, 20, "ce que tu dois reproduire", 2);

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            x_aff = j * (l_tuile + marge) + 50;
            y_aff = i * (h_tuile + marge) + 50;

            x_src = j * l_tuile;
            y_src = i * h_tuile;

            if (i == 0 && j == 0) {
                coordonee[i][j] = ChargerImage("../img/vide.jpg",
                                               x_aff, y_aff,
                                               x_src, y_src,
                                               l_tuile, h_tuile);
            } else {
                coordonee[i][j] = ChargerImage("../img/BPimage.png",
                                               x_aff, y_aff,
                                               x_src, y_src,
                                               l_tuile, h_tuile);
            }
        }
    }

    CopierZone(4, 0, 0, 0, 900, 700, 0, 0);

    ChoisirEcran(4);

    w = CouleurParNom("white");
    ChoisirCouleurDessin(w);
    EcrireTexte(480, 280, "ton jeu", 2);

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            x_aff = j * (l_tuile + marge) + 500;
            y_aff = i * (h_tuile + marge) + 300;

            x_src = j * l_tuile;
            y_src = i * h_tuile;

            if (i == 0 && j == 0) {
                joueur[i][j] = ChargerImage("../img/vide.jpg",
                                            x_aff, y_aff,
                                            x_src, y_src,
                                            l_tuile, h_tuile);
            } else {
                joueur[i][j] = ChargerImage("../img/BPimage.png",
                                            x_aff, y_aff,
                                            x_src, y_src,
                                            l_tuile, h_tuile);
            }
        }
    }

    CopierZone(4, 0, 0, 0, 900, 700, 0, 0);

    ChoisirEcran(1);
    CopierZone(0, 4, 0, 0, 900, 700, 0, 0);

    w = CouleurParNom("white");
    ChoisirCouleurDessin(w);
    DessinerRectangle(575, 180, 150, 60);

    CopierZone(4, 0, 0, 0, 900, 700, 0, 0);

    ChoisirEcran(4);



    ChoisirCouleurDessin(CouleurParNom("white"));
    DessinerRectangle(x_btn, y_btn, w_btn, h_btn);

    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(x_btn + 25, y_btn + 35, "MELANGE", 2);


    CopierZone(4, 0, 0, 0, 900, 700, 0, 0);
}
