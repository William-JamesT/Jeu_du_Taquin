#include <graph.h>
#include <stdio.h>
#include "bouton_Choix_image.h"  

void ecran_fin()
{
    int x, y;

    int btn_rejouer_x = 350, btn_rejouer_y = 250;
    int btn_rejouer_w = 300, btn_rejouer_h = 80;

    int btn_quitter_x = 350, btn_quitter_y = 360;
    int btn_quitter_w = 300, btn_quitter_h = 80;

    /* --- Affichage de l’écran de fin --- */
    ChoisirEcran(0);
    ChargerImageFond("../img/fondbleu.png");

    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(300, 150, "Bravo, tu as résolu le puzzle !", 2);

    /* Bouton Rejouer */
    ChoisirCouleurDessin(CouleurParNom("green"));
    RemplirRectangle(btn_rejouer_x, btn_rejouer_y, btn_rejouer_w, btn_rejouer_h);
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(btn_rejouer_x + 90, btn_rejouer_y + 50, "Rejouer", 2);

    /* Bouton Quitter */
    ChoisirCouleurDessin(CouleurParNom("red"));
    RemplirRectangle(btn_quitter_x, btn_quitter_y, btn_quitter_w, btn_quitter_h);
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(btn_quitter_x + 90, btn_quitter_y + 50, "Quitter", 2);

    /* --- Gestion du clic --- */
    while (1)
    {
        if (SourisCliquee())
        {
            SourisPosition();
            x = _X;
            y = _Y;

            /* Clic sur REJOUER */
            if (x >= btn_rejouer_x && x <= btn_rejouer_x + btn_rejouer_w &&
                y >= btn_rejouer_y && y <= btn_rejouer_y + btn_rejouer_h)
            {
                bouton_choix_image();     /* retour à la première page*/
                return;
            }

            /* Clic sur QUITTER */
            if (x >= btn_quitter_x && x <= btn_quitter_x + btn_quitter_w &&
                y >= btn_quitter_y && y <= btn_quitter_y + btn_quitter_h)
            {
                FermerGraphique();
                exit(0);
            }
        }
    }
}
