#include<stdlib.h>
#include<graph.h>
#include<stdio.h>
#include"Choix_image.h"
#include"Choix_decoupimg1.h"
#include"Choix_decoupimg2.h"
#include"Choix_decoupimg3.h"
void bouton_choix_image()
{
	int x_rectangle1 =20,y_rectangle1=150,x_rectangle2=370,y_rectangle2=200,x_rectangle3=620,y_rectangle3=100,x_rectangle4=450,y_rectangle4=375;
    int largeur_r1=300,largeur_r2=200,Hauteur_r1=188,Hauteur_r2=125,largeur_r3=350,Hauteur_r3=233,largeur_r4=150,Hauteur_r4=89;
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
                /*CopierZone(0,0,1000,550,0,0,500,500);j'ai pas encore compris comment l'utiliser*/
                /*ChoisirEcran(1);*/
                /*si il a choisi l'image avec samuel etoo*/
                Choix_decoupimg1("../img/BPimage2.png");
                return;
            }
            
            /*si clic = coordonnées boutons quitte*/
            else if(_xclic >= x_rectangle2 && _xclic<=x_rectangle2 + largeur_r2 
                && _yclic >= y_rectangle2 && _yclic<= y_rectangle2 + Hauteur_r2){
                    /*si il a choisi l'image avec Black Panther*/
                    Choix_decoupimg2("../img/Etooimage.png");
                    return;
            }
            /*redirige vers choix de decoup img3*/
            else if(_xclic >= x_rectangle3 && _xclic<=x_rectangle3 + largeur_r3 
                && _yclic >= y_rectangle3 && _yclic<= y_rectangle3 + Hauteur_r3){
                    /*si il a choisi l'image avec olive&Tom*/
                    Choix_decoupimg3("../img/OTimage2.png");
                    return;
            }
            /*si elle corespond au bouton quitter je ferme le graphique */
            else if( _xclic >= x_rectangle4 && _xclic<= x_rectangle4 + largeur_r4 
                && _yclic >= y_rectangle4 && _yclic<= y_rectangle4 + Hauteur_r4){
                    /*CopierZone(0,0,1000,550,0,0,500,500);j'ai pas encore compris comment l'utiliser*/
                    /*ChoisirEcran(1);*/
                    printf("Bouton Quitté");
                    exit(EXIT_SUCCESS);
                    return;
            }
        while (SourisCliquee());

    }

}