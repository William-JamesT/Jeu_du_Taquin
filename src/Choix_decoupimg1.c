#include <stdlib.h>
#include <graph.h>
#include <stdio.h>

void Choix_decoupimg1(int *l, int *c)
{
    int x, y;
    couleur col;

    ChoisirEcran(2);

    /* Affichage de ton interface (inchangée) */
    col = CouleurParNom("red");
    ChoisirCouleurDessin(col);
    ChargerImageFond("../img/fondbleu.png");

    EcrireTexte(400,50,"Chosis le decoupage avec lequel tu souhaitera jouer.",2);
    ChargerImage("../img/BPimage2.png" ,10,10,0,0,300,188);

    col = CouleurParNom("black");
    ChoisirCouleurDessin(col);

    /* Boutons lignes */
    RemplirRectangle(100,300,50,50);
    RemplirRectangle(200,300,50,50);
    RemplirRectangle(300,300,50,50);
    RemplirRectangle(400,300,50,50);
    RemplirRectangle(500,300,50,50);
    RemplirRectangle(600,300,50,50);

    /* Boutons colonnes */
    RemplirRectangle(100,400,50,50);
    RemplirRectangle(200,400,50,50);
    RemplirRectangle(300,400,50,50);
    RemplirRectangle(400,400,50,50);
    RemplirRectangle(500,400,50,50);
    RemplirRectangle(600,400,50,50);

    col = CouleurParNom("white");
    ChoisirCouleurDessin(col);

    /* lignes */
    EcrireTexte(120,325,"3",2);
    EcrireTexte(220,325,"4",2);
    EcrireTexte(320,325,"5",2);
    EcrireTexte(420,325,"6",2);
    EcrireTexte(520,325,"7",2);
    EcrireTexte(620,325,"8",2);

    /* colonnes */
    EcrireTexte(120,425,"3",2);
    EcrireTexte(220,425,"4",2);
    EcrireTexte(320,425,"5",2);
    EcrireTexte(420,425,"6",2);
    EcrireTexte(520,425,"7",2);
    EcrireTexte(620,425,"8",2);

    /* Copier l'écran 2 vers l'écran principal */
    CopierZone(2,0,0,0,1000,550,0,0);

    /* -------------------------- */
    /* CHOIX DES LIGNES (premier clic) */
    /* -------------------------- */
    while (!SourisCliquee()) {}
    x = _X;
    y = _Y;

    if (y >= 300 && y <= 350) {
        if      (x >= 100 && x <= 150) *l = 3;
        else if (x >= 200 && x <= 250) *l = 4;
        else if (x >= 300 && x <= 350) *l = 5;
        else if (x >= 400 && x <= 450) *l = 6;
        else if (x >= 500 && x <= 550) *l = 7;
        else if (x >= 600 && x <= 650) *l = 8;
    }

    /* -------------------------- */
    /* CHOIX DES COLONNES (2e clic) */
    /* -------------------------- */
    while (!SourisCliquee()) {}
    x = _X;
    y = _Y;

    if (y >= 400 && y <= 450) {
        if      (x >= 100 && x <= 150) *c = 3;
        else if (x >= 200 && x <= 250) *c = 4;
        else if (x >= 300 && x <= 350) *c = 5;
        else if (x >= 400 && x <= 450) *c = 6;
        else if (x >= 500 && x <= 550) *c = 7;
        else if (x >= 600 && x <= 650) *c = 8;
    }
    return;
}
