#include<stdlib.h>
#include<graph.h>
#include<stdio.h> 
void Choix_images()
{
    couleur c;
    ChoisirEcran(1);
    /*pas besoin de refaire une fenetre*/
    c = CouleurParNom("red");
    ChoisirCouleurDessin(c);
    ChargerImageFond("../img/fondbleu.png");
    EcrireTexte(150,50,"Bienvenue sur le jeu du Taquin !",2);
    EcrireTexte(150,100,"Choisir une image",2);
    RemplirRectangle(20,150,300,188);
    ChargerImage("../img/BPimage2.png",20,150,0,0,300,188);
    RemplirRectangle(370,200,200,125);
    ChargerImage("../img/Etooimage.png" ,370,200,0,0,200,125);
    RemplirRectangle(620,100,350,133);
    ChargerImage("../img/OTimage2.png" ,620 ,100,0,0,350,233);
    RemplirRectangle(450,375,150,89);
    ChargerImage("../img/bouton_quitter.png" ,450 ,375,0,0,150,89);
    /*je copie le contenue de l'ecran 1 pour qu'il remplace celui de l'ecran 0*/
    CopierZone(1,0,0,0,1000,550,0,0);
    return;
}