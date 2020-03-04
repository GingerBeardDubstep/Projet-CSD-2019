#include "tableUtilisateur.h"

filmNote* createFilmNote(){
	filmNote* fn = malloc(sizeof(filmNote*));
	if(fn==NULL){
		return NULL;
	}
	fn->film=NULL;
	fn->suivant=NULL;
	fn->note=-1;
	return fn;
}


utilisateur* createUtilisateur(char* nom){
	utilisateur* u = malloc(sizeof(utilisateur*));
	u->nomUtilisateur = strdup(nom);
	u->premierFilm=createFilmNote();
	u->premierReco=createFilmReco();
}


void utilisateur_ajoutFilm(filmNote* fn,film* f,int note){
	if(fn->suivant!=NULL){
		utilisateur_ajoutFilm(fn->suivant,f,note);
		return;
	}
	fn->suivant=createFilmNote();
	fn->suivant->film=film_create();
	film_copie(fn->suivant->film,f);
	fn->suivant->note=note;
}

int nb_film(utilisateur* u){
	int tot=0;
	filmNote* fn = malloc(sizeof(filmNote*));
	fn=u->premierFilm;
	while(fn->suivant!=NULL){
		tot++;
		fn=fn->suivant;
	}
	return tot;
}

void voir_notes(filmNote* fn){
	if(fn->suivant !=NULL){
		printf("%i\n",fn->suivant->note);
		voir_notes(fn->suivant);
	}
}

void free_filmNote(filmNote* fn){
	if(fn->suivant==NULL){
		free(fn);
	}
	else{
		if(fn->suivant->film!=NULL){
			film_free(fn->suivant->film);
		}
		free_filmNote(fn->suivant);
		free(fn);
	}
}


void free_utilisateur(utilisateur* u){
	if(u->premierFilm!=NULL){
		free_filmNote(u->premierFilm);
	}
	if(u->premierReco!=NULL){
		free_filmReco(u->premierReco);
	}
	free(u->nomUtilisateur);
	free(u);
}

filmReco* createFilmReco(){
	filmReco* fr = malloc(sizeof(filmReco*));
	if(fr==NULL){
		return NULL;
	}
	fr->film=NULL;
	fr->suivant=NULL;
	return fr;
}


void utilisateur_ajoutReco(filmReco* fr,film* f){
	if(fr->suivant!=NULL){
		utilisateur_ajoutReco(fr->suivant,f);
		return;
	}
	fr->suivant=createFilmReco();
	fr->suivant->film=film_create();
	film_copie(fr->suivant->film,f);
}

void free_filmReco(filmReco* fr){
	if(fr->suivant==NULL){
		free(fr);
	}
	else{
		if(fr->suivant->film!=NULL){
			film_free(fr->suivant->film);
		}
		free_filmReco(fr->suivant);
		free(fr);
	}
}


int nb_reco(utilisateur* u){
	int tot=0;
	filmReco* fr = malloc(sizeof(filmReco*));
	fr=u->premierReco;
	while(fr->suivant!=NULL){
		tot++;
		fr=fr->suivant;
	}
	return tot;
}