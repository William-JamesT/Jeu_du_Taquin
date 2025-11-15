#include<stdlib.h>
#include<graph.h>
#include<stdio.h> 
#include"Bouton.h"
int main()
{
	int x,y;
    char *f;
    couleur c;
    InitialiserGraphique();
    CreerFenetre(50,50,1000,550);
    c = CouleurParNom("red");
    ChoisirCouleurDessin(c);
    
    ChargerImageFond("../img/fondbleu.png");
    EcrireTexte(430,50,"Bienvenue sur le jeu du Taquin !",2);
    /*Je remplis des triangle a l'endroit de mes boutons pour detecter si je clique dessus*/
    RemplirRectangle(450,280,150,89);
    ChargerImage("../img/bouton_jouer.png" ,450 ,280,0,0,150,89);
    RemplirRectangle(450,375,150,89);
    ChargerImage("../img/bouton_quitter.png" ,450 ,375,0,0,150,89);
    Bouton1P_or_Q();
	while(Touche()!= XK_space);
	FermerGraphique();
	return EXIT_SUCCESS;
}