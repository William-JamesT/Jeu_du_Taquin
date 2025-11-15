#include<stdlib.h>
#include<graph.h>
#include<stdio.h> 
int Choix_images()
{
	int x,y;
    char *f;
    couleur c;
    c = CouleurParNom("red");
    ChoisirCouleurDessin(c);
    
    ChargerImageFond("../fondbleu.png");
    EcrireTexte(150,50,"Bienvenue sur le jeu du Taquin !",2);
    EcrireTexte(150,100,"Choisir une image",2);
    ChargerImage("../BPimage.png",430,200,0,0,200,125);
    ChargerImage("../Etooimage.png" ,100,200,0,0,200,125);
    ChargerImage("../OTimage.png" ,750 ,200,0,0,200,133);
    ChargerImage("../bouton_quitter.png" ,450 ,375,0,0,150,89);
	while(Touche()!= XK_space);
	FermerGraphique();
}