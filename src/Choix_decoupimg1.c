#include <stdlib.h>
#include <graph.h>
#include <stdio.h>
#include "decoupage.h"

void Choix_decoupimg1()
{
    int _xclic, _yclic;

    ChoisirEcran(2);
    ChargerImageFond("../img/fondbleu.png");

    EcrireTexte(300,50,"Choisis le decoupage pour jouer",2);
    ChargerImage("../img/BPimage2.png" ,10,10,0,0,300,188);

    /* Boutons */
    RemplirRectangle(100,200,50,50); /*3x3*/ 
    RemplirRectangle(200,200,50,50); /*3x3*/ 
    RemplirRectangle(300,200,50,50); /*3x3*/ 
    RemplirRectangle(400,200,50,50); /*3x3*/ 
    RemplirRectangle(500,200,50,50); /*3x3*/ 
    RemplirRectangle(600,200,50,50); /*3x3*/ 

    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(120,225,"3x3",2);
    EcrireTexte(220,225,"4x4",2);
    EcrireTexte(320,225,"5x5",2);
    EcrireTexte(420,225,"6x6",2);
    EcrireTexte(520,225,"7x7",2);
    EcrireTexte(620,225,"8x8",2);

    CopierZone(2,0,0,0,1000,550,0,0);

    /* ATTENTE DU CLIC*/
    while (!SourisCliquee());
    SourisPosition();
    _xclic = _X;
    _yclic = _Y;

    /*TESTS DES BOUTONS */

    if (_xclic >= 100 && _xclic <= 150 &&
        _yclic >= 200 && _yclic <= 250)
    {
        decoupage(3, 3, "../img/BPimage2.png");
        return;
    }

    if (_xclic >= 200 && _xclic <= 250 &&
        _yclic >= 200 && _yclic <= 250)
    {
        decoupage(4, 4, "../img/BPimage2.png");
        return;
    }

    if (_xclic >= 300 && _xclic <= 350 &&
        _yclic >= 200 && _yclic <= 250)
    {
        decoupage(5, 5, "../img/BPimage2.png");
        return;
    }

    if (_xclic >= 400 && _xclic <= 450 &&
        _yclic >= 200 && _yclic <= 250)
    {
        decoupage(6, 6, "../img/BPimage2.png");
        return;
    }

    if (_xclic >= 500 && _xclic <= 550 &&
        _yclic >= 200 && _yclic <= 250)
    {
        decoupage(7, 7, "../img/BPimage2.png");
        return;
    }

    if (_xclic >= 600 && _xclic <= 650 &&
        _yclic >= 200 && _yclic <= 250)
    {
        decoupage(8, 8, "../img/BPimage2.pngg");
        return;
    }
}