#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	struct arbre* gauche;
	struct arbre* droite;
	film* val;
}arbre;

int comparaison(film* source, film* destination);
arbre* ajout(arbre* a, film* val);