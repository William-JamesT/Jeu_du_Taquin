# Nom de l'exécutable
EXEC = taquin

# Compilateur
CC = gcc
CFLAGS = -Wall -Wextra -g -ansi -pedantic

# Librairies externes
LDFLAGS = -lgraph

# Fichiers sources et objets
SRC = main.c Bouton.c Choix_image.c
OBJ = $(SRC:.c=.o)

# Règle par défaut
all: $(EXEC)

# Edition de liens
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

# Compilation des .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJ)

# Nettoyage complet
fclean: clean
	rm -f $(EXEC)

# Recompilation complète
re: fclean all
