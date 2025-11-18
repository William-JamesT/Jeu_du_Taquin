#include<stdlib.h>
#include<graph.h>
#include<stdio.h> 
void Choix_decoupimg3()
{
	int x,y;
    char *f;
    couleur c;
    ChoisirEcran(2);
    /*pas besoin de refaire une fenetre*/
    c = CouleurParNom("blue");
    ChoisirCouleurDessin(c);
    ChargerImageFond("../img/fondbleu.png");
    EcrireTexte(300,50,"Chosis le decoupage avec lequel tu souhaitera jouer.",2);
    ChargerImage("../img/OTimage2.png" ,10,10,0,0,350,233);
     /*bouton des lignes */
    RemplirRectangle(100,300,50,50);
    RemplirRectangle(200,300,50,50);
    RemplirRectangle(300,300,50,50);
    RemplirRectangle(400,300,50,50);
    RemplirRectangle(500,300,50,50);
    RemplirRectangle(600,300,50,50);
    /*bouton des colones*/
    RemplirRectangle(100,400,50,50);
    RemplirRectangle(200,400,50,50);
    RemplirRectangle(300,400,50,50);
    RemplirRectangle(400,400,50,50);
    RemplirRectangle(500,400,50,50);
    RemplirRectangle(600,400,50,50);
    c = CouleurParNom("white");
    ChoisirCouleurDessin(c);
    /*ligne*/
    EcrireTexte(120,325,"3",2);
    EcrireTexte(220,325,"4",2);
    EcrireTexte(320,325,"5",2);
    EcrireTexte(420,325,"6",2);
    EcrireTexte(520,325,"7",2);
    EcrireTexte(620,325,"8",2);
    /*colone*/
    EcrireTexte(120,425,"3",2);
    EcrireTexte(220,425,"4",2);
    EcrireTexte(320,425,"5",2);
    EcrireTexte(420,425,"6",2);
    EcrireTexte(520,425,"7",2);
    EcrireTexte(620,425,"8",2);
    /*je copie le contenue de l'ecran 1 pour qu'il remplace celui de l'ecran 0*/
    CopierZone(2,0,0,0,1000,550,0,0);
    return;
}