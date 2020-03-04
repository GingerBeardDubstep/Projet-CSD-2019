#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableUtilisateur.h"
#include "tableFilm.h"
#ifndef ALGORECOM_H
#define ALGORECOM_H

typedef struct matriceNote{
	char* element;
	int valeur;
	struct matriceNote* suiv;
}matriceNote;

matriceNote* newMatrice();
void recommendations(utilisateur* u,tableFilm* tf);
char** recommendationsInterface(utilisateur* u,tableFilm* tf);
void note_films_hasard(utilisateur* u, tableFilm* tf);
void ajoutMatrice(matriceNote* mn, char* nom, int valeur);
int nbPoints(film* f,matriceNote* mn);
void voirMatriceNote(matriceNote* mn);
int film_note_notIn(film* f, filmNote* fn);

#endif