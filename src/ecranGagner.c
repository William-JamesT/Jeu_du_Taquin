#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "bouton_Choix_image.h"
#include "Choix_image.h"

void ecran_fin()
{
    int x, y;

    /* Coordonnées et dimensions du bouton Rejouer */
    int btn_rejouer_x = 350;
    int btn_rejouer_y = 250;
    int btn_rejouer_w = 300;
    int btn_rejouer_h = 80;

    /* Coordonnées et dimensions du bouton Quitter */
    int btn_quitter_x = 350;
    int btn_quitter_y = 360;
    int btn_quitter_w = 300;
    int btn_quitter_h = 80;

    /* --- Affichage de l'écran de fin --- */
    ChoisirEcran(0);
    ChargerImageFond("../img/fondbleu.png");

    /* Message de félicitations */
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(300, 150, "Bravo, tu as résolu le puzzle !", 2);

    /* --- Bouton Rejouer --- */
    ChoisirCouleurDessin(CouleurParNom("green"));
    RemplirRectangle(btn_rejouer_x, btn_rejouer_y, btn_rejouer_w, btn_rejouer_h);
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(btn_rejouer_x + 90, btn_rejouer_y + 50, "Rejouer", 2);

    /* --- Bouton Quitter --- */
    ChoisirCouleurDessin(CouleurParNom("red"));
    RemplirRectangle(btn_quitter_x, btn_quitter_y, btn_quitter_w, btn_quitter_h);
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(btn_quitter_x + 90, btn_quitter_y + 50, "Quitter", 2);

    /* --- Gestion des clics --- */
    while (1)
    {
        if (SourisCliquee())
        {
            SourisPosition();
            x = _X;
            y = _Y;

            /* Clic sur le bouton Rejouer */
            if (x >= btn_rejouer_x && x <= btn_rejouer_x + btn_rejouer_w &&
                y >= btn_rejouer_y && y <= btn_rejouer_y + btn_rejouer_h)
            {
                /* Réafficher l'écran de choix d'image puis attendre le choix */
                Choix_images();
                bouton_choix_image();  /* Retour à la première page */
                return;
            }

            /* Clic sur le bouton Quitter */
            if (x >= btn_quitter_x && x <= btn_quitter_x + btn_quitter_w &&
                y >= btn_quitter_y && y <= btn_quitter_y + btn_quitter_h)
            {
                FermerGraphique();
                exit(0);
            }
        }
    }
}
