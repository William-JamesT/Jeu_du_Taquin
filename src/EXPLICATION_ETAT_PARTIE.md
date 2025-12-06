État d'une partie en cours

Lorsque l'utilisateur va lancer le programme, il verra un écran d'accueil avec un bouton jouer et un bouton quitter sur lesquels il devra appuyer selon s'il veut jouer ou non.

Boutons de l'écran d'accueil

Le programme va donc lors de cette étape vérifier si le clic de la souris est bien compris dans la zone de l'un des deux rectangles qui nous sert de bouton jouer et quitter. Leurs valeurs sont représentées grâce à des variables de types int pour leurs coordonnées (x, y) mais également pour l'espace qu'ils occupent, donc leurs largeur et hauteur.

Variables utilisées :
- x_rectangle1, y_rectangle1 : coordonnées du bouton jouer (type int)
- x_rectangle2, y_rectangle2 : coordonnées du bouton quitter (type int)
- largeur_r1, Hauteur_r1 : largeur et hauteur du bouton jouer (type int)
- largeur_r2, Hauteur_r2 : largeur et hauteur du bouton quitter (type int)
- _xclic, _yclic : coordonnées du clic de la souris récupérées via SourisPosition() (type int)

Le choix des images

Lors de cette partie plusieurs valeurs vont être mobilisées notamment le même système que pour les boutons de l'écran d'accueil mais cette fois-ci ce seront les coordonnées des images qui remplaceront la largeur et la hauteur toujours de types int. Après avoir choisi l'image, 4 autres variables vont entrer en jeu, les 3 premières étant de types int et la dernière de type char :

Variables utilisées :
- x_rectangle1, y_rectangle1 : coordonnées de la première image (type int)
- x_rectangle2, y_rectangle2 : coordonnées de la deuxième image (type int)
- x_rectangle3, y_rectangle3 : coordonnées de la troisième image (type int)
- largeur_r1, Hauteur_r1 : largeur et hauteur de la première image (type int)
- largeur_r2, Hauteur_r2 : largeur et hauteur de la deuxième image (type int)
- largeur_r3, Hauteur_r3 : largeur et hauteur de la troisième image (type int)
- _xclic, _yclic : coordonnées du clic de la souris (type int)
- lignes : stocke le nombre de lignes choisi par l'utilisateur, débute à 0 (type int)
- colonnes : stocke le nombre de colonnes choisi par l'utilisateur, débute à 0 (type int)
- image : pointe vers l'image que l'on a choisie précédemment (type char*)

Les valeurs lignes et colonnes qui débutent à 0 vont stocker les valeurs en fonction de où l'utilisateur cliquera. Leurs valeurs respectives seront ensuite transmises à la fonction découpage pour qu'elle sache quel type de découpage effectuer.

La variable image de type char pointe vers l'image que l'on a choisie précédemment.

Les prémices du jeu

Pour la modélisation du puzzle nous avons utilisées des tableaux multidimensionnels de types int. Le premier nous sert de modèle et le deuxième nous permet de jouer. Pour remplir le tableau nous avons utilisées des boucles imbriquées avec les variables i et j de types int qui travaillent avec les variables l_tuile, h_tuile, num, numTile toutes de types int pour dans un premier temps découper l'image puis stocker les tuiles découpées dans les deux tableaux et dans un second afficher les deux tableaux à des endroits différents l'un de l'autre.

Variables utilisées :
- modele[8][8] : tableau représentant l'état résolu du puzzle, contient les valeurs 0, 1, 2, 3... dans l'ordre (type int)
- joueur[8][8] : tableau représentant l'état actuel du puzzle joué, contient les valeurs mélangées avec -1 pour la tuile blanche (type int)
- i, j : variables de boucle pour parcourir les tableaux (type int)
- l_tuile : largeur d'une tuile en pixels, calculée par img_L / c (type int)
- h_tuile : hauteur d'une tuile en pixels, calculée par img_H / l (type int)
- num : compteur pour numéroter les tuiles de 0 à (l*c - 1) (type int)
- numTile : valeur stockée dans une case du tableau, représente l'identifiant de la tuile (type int)
- l : nombre de lignes du puzzle, transmis depuis le choix de l'utilisateur (type int)
- c : nombre de colonnes du puzzle, transmis depuis le choix de l'utilisateur (type int)
- img_L, img_H : dimensions de l'image originale en pixels (type int)
- src_x, src_y : coordonnées source pour copier une zone de l'image (type int)
- dst_x, dst_y : coordonnées destination pour afficher une tuile (type int)

Pendant le jeu

Variables supplémentaires utilisées pendant le jeu :
- nombre_coups : compteur de mouvements effectués, initialisé à 0 (type static int)
- centre_x, centre_y : coordonnées pour centrer le puzzle à l'écran (type int)
- bl_i, bl_j : position de la tuile blanche dans le tableau joueur, trouvée en cherchant la valeur -1 (type int)
- x, y : coordonnées temporaires pour les calculs d'affichage et de détection de clic (type int)
- mouvement_effectue : indicateur booléen pour savoir si un mouvement a été fait (type int)
- touche : code de la touche clavier pressée (type int)
