#include<stdlib.h>
#include<graph.h>
#include<stdio.h>
#include"Choix_image.h"
void Bouton1P_or_Q()
{
	int x_rectangle1 =450,y_rectangle1=280,x_rectangle2=450,y_rectangle2=375;
    int largeur_r1=150,largeur_r2=150,Hauteur_r1=89,Hauteur_r2=89;
    int _xclic,_yclic;
    /*on verifie les coordonnées de la souris quand elle clique*/
    while(1){
        while(!SourisCliquee());

        /*je récupere la positions de la souris*/
        SourisPosition();
        _xclic= _X;
        _yclic= _Y;
        /*si elle corespond au bouton Play je prend l'ecran 1 et je met le choix des Images */
        if( _xclic >= x_rectangle1 && _xclic<= x_rectangle1 + largeur_r1 
            && _yclic >= y_rectangle1 && _yclic<= y_rectangle1 + Hauteur_r1){
                Choix_images();
                return;
            }
            
            /*si clic = coordonnées boutons quitte*/
            else if(_xclic >= x_rectangle2 && _xclic<=x_rectangle2 + largeur_r2 
                && _yclic >= y_rectangle2 && _yclic<= y_rectangle2 + Hauteur_r2){
                    FermerGraphique();
                    return;
            }
        while (SourisCliquee());

    }
    
}