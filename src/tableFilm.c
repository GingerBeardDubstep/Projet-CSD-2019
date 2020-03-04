#include <stdio.h>
#include <math.h>
#include "tableFilm.h"
#include "film.h"



tableFilm* createTableFilm(){//Renvoie la tête de la fonction 
	tableFilm* tf = malloc(sizeof(tableFilm));
	if(tf==NULL){
		printf("Erreur allocation mémoire tableFilm\n");
		return NULL;
	}
	tf->suivant=NULL;
	tf->precedent=NULL;
	tf->valeur=NULL;
	tf->clef=-1;
	return tf;
}


int tf_getClef(film* f){
	int tot = 7;
	char* s=strdup(f->titre);
	for(int i=0;i<strlen(s);i++){
		//tot=tot+(s[i]-64)*(powl(31,strlen(s)-i));
		tot=abs(tot*31+s[i]);
	}
	return tot ;
}

int tf_getClefTitre(char* s){
	int tot = 7;
	for(int i=0;i<strlen(s);i++){
		//tot=tot+(s[i]-64)*(powl(31,strlen(s)-i));
		tot=abs(tot*31+s[i]);
	}
	return tot ;
}

void tf_ajoutFilm(tableFilm* tf, film* f){
	int val1 = tf_getClef(f);
	while(tf->suivant!=NULL){
	//if(tf->suivant!=NULL){
		if(tf->suivant->clef>val1){
			tableFilm* newTF = createTableFilm();
			newTF->suivant=tf->suivant;
			newTF->precedent=tf;
			newTF->clef=val1;
			newTF->valeur=film_create();
			film_copie(newTF->valeur,f);
			tf->suivant=newTF;
			newTF->suivant->precedent=newTF;
			tf=tf->suivant;
			return;
		}else{
			tf=tf->suivant;
		}

	}
	if(tf->suivant==NULL){
		tf->suivant=createTableFilm();
		tf->suivant->clef=val1;
		tf->suivant->valeur=film_create();
		film_copie(tf->suivant->valeur,f);
		tf->precedent=tf;
	}
	
	
}


film* tf_getFilmByNb(tableFilm* tf,int iteration){
	int j;
	tableFilm* itera = malloc(sizeof(tableFilm*));
	itera=tf;
	if(iteration>tf_taille(tf)){
		printf("erreur indice trop grand\n");
		return NULL;
	}
	for(j=0;j<=iteration;j++){
			itera=itera->suivant;
	}
	return itera->valeur;
}

film* tf_getFilmByClef(tableFilm* tf,int clef){
	if(tf->suivant==NULL){
		return NULL;
	}
	if(tf->suivant->clef==clef){
		return tf->suivant->valeur;
	}else{
		return tf_getFilmByClef(tf->suivant,clef);
	}
}


film* tf_getFilmByTitre(tableFilm* tf,char* titre){
	long clef = tf_getClefTitre(titre);
	if(tf->suivant==NULL){
		return NULL;
	}
	if(tf->suivant->clef==clef){
		return tf->suivant->valeur;
	}else{
		return tf_getFilmByClef(tf->suivant,clef);
	}
}

tableFilm* tf_suppressionFilmByClef(tableFilm* tf,int clef){
	tableFilm* temp;
	if(tf->suivant==NULL){
		printf("Impossible de supprimer\n");
		return NULL;
	}
	if(tf->suivant->clef==clef){
		if(tf->suivant->suivant!=NULL){
			temp = malloc(sizeof(tableFilm*));
			temp=tf->suivant->suivant;
			film_free(tf->suivant->valeur);
			free(tf->suivant);
			tf->suivant=temp;
			tf->suivant->precedent=tf;
			free(temp);
		}else{
			film_free(tf->suivant->valeur);
			free(tf->suivant);
			tf->suivant=NULL;
		}
		return tf;
	}else{
		return tf_suppressionFilmByClef(tf->suivant,clef);
	}
}


void tf_suppressionFilmByTitre(tableFilm* tf, char* titre){
	int clef=tf_getClefTitre(titre);
	tableFilm* temp;
	if(tf->suivant==NULL){
		printf("Impossible de supprimer\n");
	}
	if(tf->suivant->clef==clef){
		if(tf->suivant->suivant!=NULL){
			temp = malloc(sizeof(tableFilm*));
			temp=tf->suivant->suivant;
			film_free(tf->suivant->valeur);
			free(tf->suivant);
			tf->suivant=temp;
			tf->suivant->precedent=tf;
			free(temp);
		}else{
			film_free(tf->suivant->valeur);
			free(tf->suivant);
			tf->suivant=NULL;
		}
		
		
	}else{
		tf_suppressionFilmByClef(tf->suivant,clef);
	}
}


void libererMemoireTableFilm(tableFilm* tf){
	if(tf->suivant==NULL){
		free(tf);
	}
	else{
		if(tf->suivant->valeur!=NULL){
			film_free(tf->suivant->valeur);
		}
		libererMemoireTableFilm(tf->suivant);
		free(tf);
	}
	
}


int tf_taille(tableFilm* tf){
	if(tf==NULL){
		return -1;
	}
	else{
		return 1+tf_taille(tf->suivant);
	}
}

void tf_voirToutFilm(tableFilm* tf){
	if(tf->suivant==NULL){
	}
	else{
		int i;
		printf("-------------------------------------\n");
		printf("%s\n",tf->suivant->valeur->titre);
		printf("%s\n",tf->suivant->valeur->description);
		printf("Acteurs :\n");
		for(i=0;i<tf->suivant->valeur->nbAct;i++){
			printf("|->%s\n",tf->suivant->valeur->acteurs[i]);
		}
		printf("Genres :\n");
		for(i=0;i<tf->suivant->valeur->nbGenre;i++){
			printf("|->%s\n",tf->suivant->valeur->genres[i]);
		}
		tf_voirToutFilm(tf->suivant);
	}
}
