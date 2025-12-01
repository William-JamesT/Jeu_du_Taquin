#include <stdlib.h>
#include <graph.h>
#include <stdio.h>
#include "decoupage.h"
#include"Choix_image.h"
#include"bouton_Choix_image.h"


void Choix_decoupimg3(char *image)
{
    int _xclic, _yclic;
    int lignes = 0;
    int colonnes = 0;

    ChoisirEcran(2);
    ChargerImageFond("../img/fondbleu.png");

    EcrireTexte(250, 50, "Choisissez les lignes et les colonnes :", 2);

    /* ---------- BOUTONS LIGNES ---------- */
    EcrireTexte(100, 150, "Lignes :", 2);
    ChoisirCouleurDessin(CouleurParNom("grey"));

    RemplirRectangle(200,130,50,50);  /* 3 */
    RemplirRectangle(260,130,50,50);  /* 4 */
    RemplirRectangle(320,130,50,50);  /* 5 */
    RemplirRectangle(380,130,50,50);  /* 6 */
    RemplirRectangle(440,130,50,50);  /* 7 */
    RemplirRectangle(500,130,50,50);  /* 8 */

    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(215,160,"3",2);
    EcrireTexte(275,160,"4",2);
    EcrireTexte(335,160,"5",2);
    EcrireTexte(395,160,"6",2);
    EcrireTexte(455,160,"7",2);
    EcrireTexte(515,160,"8",2);

    /* ---------- BOUTONS COLONNES ---------- */
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(60, 270, "Colonnes :", 2);

    RemplirRectangle(200,250,50,50);
    RemplirRectangle(260,250,50,50);
    RemplirRectangle(320,250,50,50);
    RemplirRectangle(380,250,50,50);
    RemplirRectangle(440,250,50,50);
    RemplirRectangle(500,250,50,50);
    RemplirRectangle(750,375,100,100); /*bouton retourn sur choix image*/
    ChargerImage("../img/Bretour.png" ,750,375,0,0,100,100); 


    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(215,280,"3",2);
    EcrireTexte(275,280,"4",2);
    EcrireTexte(335,280,"5",2);
    EcrireTexte(395,280,"6",2);
    EcrireTexte(455,280,"7",2);
    EcrireTexte(515,280,"8",2);

    /* ---------- BOUTON VALIDER ---------- */
    ChoisirCouleurDessin(CouleurParNom("black"));
    RemplirRectangle(350, 380, 150, 70);
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(360, 425, "VALIDER", 2);

    CopierZone(2,0,0,0,1000,550,0,0);

    /* ---------- BOUCLE D’INTERACTION ---------- */
    while (1)
    {
        while (!SourisCliquee());
        SourisPosition();
        _xclic = _X; _yclic = _Y;
        while (SourisCliquee());

        /* Sélection lignes */
        if (_yclic > 130 && _yclic < 180)
        {
            if (_xclic > 200 && _xclic < 250) lignes = 3;
            else if (_xclic > 260 && _xclic < 310) lignes = 4;
            else if (_xclic > 320 && _xclic < 370) lignes = 5;
            else if (_xclic > 380 && _xclic < 430) lignes = 6;
            else if (_xclic > 440 && _xclic < 490) lignes = 7;
            else if (_xclic > 500 && _xclic < 550) lignes = 8;

            printf("Lignes choisies = %d\n", lignes);
        }

        /* Sélection colonnes */
        if (_yclic > 250 && _yclic < 300)
        {
            if (_xclic > 200 && _xclic < 250) colonnes = 3;
            else if (_xclic > 260 && _xclic < 310) colonnes = 4;
            else if (_xclic > 320 && _xclic < 370) colonnes = 5;
            else if (_xclic > 380 && _xclic < 430) colonnes = 6;
            else if (_xclic > 440 && _xclic < 490) colonnes = 7;
            else if (_xclic> 500 && _xclic < 550) colonnes = 8;

            printf("Colonnes choisies = %d\n", colonnes);
        }
        /*pour le bouton retour*/
        if (_xclic >= 750 && _xclic <= 850 &&
        _yclic >= 375 && _yclic <= 475)
    {
        Choix_images();
        bouton_choix_image();
        return;
    }

        /* Bouton valider */
        if (_xclic >= 350 && _xclic <= 500 && _yclic >= 380 && _yclic <= 450)
        {
            if (lignes != 0 && colonnes != 0)
            {
                /* LANCEMENT DU JEU */
                decoupage(lignes, colonnes, image);
                return;
            }
        }
    }
}