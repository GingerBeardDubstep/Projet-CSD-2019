#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef FILM_H
#define FILM_H

typedef struct film{
	int type;
	int annee;
	char* titre;
	char* description;
	char** acteurs;
	char** genres;
	char** director;
	int duree;
	int nbAct;
	int nbGenre;
	int nbDirector;
	int id;
}film;

film* film_create();
film* film_ajout(film* f,char* titreA, char* descriptionA,int typeA,int dureeA,int id,int annee);
void film_copie(film* destination,film* source);
void film_free(film* f);
film* film_ajout_director(film* f, char* director);
film* film_ajout_acteur(film* f, char* acteur);
film* film_ajout_genre(film* f, char* genre);

#endif