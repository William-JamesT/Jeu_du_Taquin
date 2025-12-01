#include <stdlib.h>
#include <graph.h>
#include <stdio.h>


void Ecran_Gagne()
{
    int _xclic, _yclic;

    // === Création de l’écran victoire ===
    ChoisirEcran(1);
    ChargerImageFond("../img/fond_victoire.png"); // mets l’image que tu veux

    couleur c = CouleurParNom("white");
    ChoisirCouleurDessin(c);

    EcrireTexte(250, 80, "Bravo, vous avez gagné !", 2);

    // === Boutons ===
    // Bouton REJOUER
    int x_rejouer = 250, y_rejouer = 200;
    int w_rejouer = 300, h_rejouer = 100;
    RemplirRectangle(x_rejouer, y_rejouer, w_rejouer, h_rejouer);
    ChargerImage("../img/bouton_rejouer.png", x_rejouer, y_rejouer, 0, 0, w_rejouer, h_rejouer);

    // Bouton ACCUEIL
    int x_accueil = 250, y_accueil = 350;
    int w_accueil = 300, h_accueil = 100;
    RemplirRectangle(x_accueil, y_accueil, w_accueil, h_accueil);
    ChargerImage("../img/bouton_accueil.png", x_accueil, y_accueil, 0, 0, w_accueil, h_accueil);

    // Copier sur l’écran principal
    CopierZone(1, 0, 0, 0, 1000, 600, 0, 0);

    // === Boucle clic ===
    while (1) {

        while (!SourisCliquee());

        SourisPosition();
        _xclic = _X;
        _yclic = _Y;

        // --- Clique sur REJOUER ---
        if (_xclic >= x_rejouer && _xclic <= x_rejouer + w_rejouer &&
            _yclic >= y_rejouer && _yclic <= y_rejouer + h_rejouer)
        {
            lancerPartie();
            return;
        }

        // --- Clique sur ACCUEIL ---
        if (_xclic >= x_accueil && _xclic <= x_accueil + w_accueil &&
            _yclic >= y_accueil && _yclic <= y_accueil + h_accueil)
        {
            afficherAccueil();
            return;
        }

        while (SourisCliquee());
    }
}