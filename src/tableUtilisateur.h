#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "film.h"
#ifndef TABLEUTILISATEUR_H
#define TABLEUTILISATEUR_H



typedef struct filmNote{
	film* film;
	struct filmNote* suivant;
	int note; 
}filmNote;

typedef struct filmReco{
	film* film;
	struct filmReco* suivant;
}filmReco;

typedef struct utilisateur{
	char* nomUtilisateur;
	filmNote* premierFilm;
	filmReco* premierReco;
}utilisateur;


filmNote* createFilmNote();
filmReco* createFilmReco();
utilisateur* createUtilisateur(char* nom);
void voir_notes(filmNote* fn);
void utilisateur_ajoutFilm(filmNote* fn,film* f,int note);
void utilisateur_ajoutReco(filmReco* fr,film* f);
void free_filmNote(filmNote* fn);
void free_utilisateur(utilisateur* u);
void free_filmReco(filmReco* fr);
int nb_film(utilisateur* u);
int nb_reco(utilisateur* u);
#endif