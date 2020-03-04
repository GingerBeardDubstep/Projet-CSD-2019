#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "film.h"
#ifndef TABLEFILM_H
#define TABLEFILM_H



typedef struct tableFilm{
	int clef;
	struct tableFilm* suivant;
	struct tableFilm* precedent;
	film* valeur;
}tableFilm;

tableFilm* createTableFilm();

int tf_getClef(film* f);

int tf_getClefTitre(char* s);

void tf_ajoutFilm(tableFilm* tf, film* f);

film* tf_getFilmByNb(tableFilm* tf,int iteration);

film* tf_getFilmByClef(tableFilm* tf,int clef);

film* tf_getFilmByTitre(tableFilm* tf,char* titre);

void tf_suppressionFilmByTitre(tableFilm* tf, char* titre);

tableFilm* tf_suppressionFilmByClef(tableFilm* tf, int clef);

void libererMemoireTableFilm(tableFilm* tf);

int tf_taille(tableFilm* tf);

void tf_voirToutFilm(tableFilm* tf);


#endif