#include <stdlib.h>
#include <graph.h>
#include <stdio.h>

void Melanger()
{
    int x_btn = 575;
    int y_btn = 180;
    int w_btn = 150;
    int h_btn = 60;

    while(!SourisCliquee());

        /*je récupere la positions de la souris*/
        SourisPosition();
        _xclic= _X;
        _yclic= _Y;
        /*si elle corespond au bouton Play je prend l'ecran 1 et je met le choix des Images */
        if( _xclic >= x_btn && _xclic<= x_btn1 + largeur_r1 
            && _yclic >= y_rectangle1 && _yclic<= y_rectangle1 + Hauteur_r1){
               
                

                return;
            }

}
