#include "film.h"



film* film_create(){//On créé la structure film
	film* f = (film *)malloc(sizeof(film));
	if( f== NULL){
		printf("Erreur allocation memoire1 film\n");
		return NULL;
	}
	f->nbDirector=0;
	f->nbAct=0;
	f->nbGenre=0;
	f->id=-1;
	f->annee=-1;
	f->director=NULL;
	f->acteurs=NULL;
	f->genres=NULL;
	f->titre=NULL;
	f->description=NULL;
	return f;
}
////// ////

film* film_ajout(film* f,char* titreA, char* descriptionA,int typeA,int dureeA,int id,int annee){//On ajoute les infos dans la structure Film mis en parametre
	if(f!=NULL){
		f->id=id;
		f->type=typeA;
		f->duree=dureeA;
		f->titre=strdup(titreA);
		f->description=strdup(descriptionA);
		f->annee=annee;
		
		if(f->titre==NULL || f->description==NULL){
			printf("Erreur allocation memoire3 film\n");
			free(f);
			return NULL;
		}
		
	}else{
		printf("Erreur film ajout\n");
	}
	return f ;
}

film* film_ajout_acteur(film* f, char* acteur){
	int i;
	char** temporaire;
	if(f!=NULL){
		temporaire=malloc((f->nbAct+1)*sizeof(char*));
		if(temporaire==NULL){
			printf("Echec allocation acteur\n");
			return f;
		}
		for(i=0;i<f->nbAct;i++){
			temporaire[i]=strdup(f->acteurs[i]);
			if(temporaire[i]==NULL){
				printf("Echec allocation acteur\n");
			}
		}
		temporaire[f->nbAct] = strdup(acteur);
		if(temporaire[f->nbAct]==NULL){
			printf("Echec allocation2 acteur\n");
			return f;
		}
		for(i=0;i<f->nbAct;i++){
			free(f->acteurs[i]);
		}
		free(f->acteurs);
		f->acteurs=malloc((sizeof(char*)*(f->nbAct+1)));
		for(i=0;i<f->nbAct+1;i++){
			f->acteurs[i]=strdup(temporaire[i]);
			if(f->acteurs[i]==NULL){
				printf("Echec allocation acteur\n");
			}
		}

		
		for(i=0;i<f->nbAct+1;i++){
			free(temporaire[i]);
		}
		

		f->nbAct++;


	}
	free(temporaire);
	return f;
}

film* film_ajout_genre(film* f, char* genre){
	int i;
	char** temporaire;
	if(f!=NULL){
		temporaire=malloc((f->nbGenre+1)*sizeof(char*));
		if(temporaire==NULL){
			printf("Echec allocation genre\n");
			return f;
		}
		for(i=0;i<f->nbGenre;i++){
			//temporaire[i]=strdup(f->genres[i]);
			temporaire[i]=malloc(strlen(f->genres[i]));
			if(temporaire[i]==NULL){
				printf("Echec allocation genre\n");
			}
			strcpy(temporaire[i],f->genres[i]);
		}
		temporaire[f->nbGenre] = strdup(genre);
		if(temporaire[f->nbGenre]==NULL){
			printf("Echec allocation2 genre\n");
			return f;
		}
		for(i=0;i<f->nbGenre;i++){
			free(f->genres[i]);
		}

		free(f->genres);
		f->genres=malloc((sizeof(char*)*(f->nbGenre+1)));
		for(i=0;i<f->nbGenre+1;i++){
			f->genres[i]=strdup(temporaire[i]);
			if(f->genres[i]==NULL){
				printf("Echec allocation genre\n");
			}
		}

		
		for(i=0;i<f->nbGenre+1;i++){
			free(temporaire[i]);
		}
		
		f->nbGenre=f->nbGenre+1;


	}
	free(temporaire);
	return f;
}



film* film_ajout_director(film* f, char* director){
	int i;
	char** temporaire;
	if(f!=NULL){
		temporaire=malloc((f->nbDirector+1)*sizeof(char*));
		if(temporaire==NULL){
			printf("Echec allocation director\n");
			return f;
		}
		for(i=0;i<f->nbDirector;i++){
			temporaire[i]=strdup(f->director[i]);
			if(temporaire[i]==NULL){
				printf("Echec allocation director\n");
			}
		}
		temporaire[f->nbDirector] = strdup(director);
		if(temporaire[f->nbDirector]==NULL){
			printf("Echec allocation2 director\n");
			return f;
		}

		for(i=0;i<f->nbDirector;i++){
			free(f->director[i]);
		}
		f->director=realloc(f->director,(sizeof(char*)*(f->nbDirector+1)));


		for(i=0;i<f->nbDirector+1;i++){
			f->director[i]=strdup(temporaire[i]);
			if(f->director[i]==NULL){
				printf("Echec allocation director\n");
			}
		}

		
		for(i=0;i<f->nbDirector+1;i++){
			free(temporaire[i]);
		}
		

		f->nbDirector=f->nbDirector+1;



	}
	free(temporaire);
	return f;
}






void film_free(film* f){
	int i,j,k;
	if(f!=NULL){
		free(f->titre);
		free(f->description);

		for(k=0;k<f->nbGenre;k++){
			free(f->genres[k]);
		}
		free(f->genres);

		for(j=0;j<f->nbAct;j++){
			free(f->acteurs[j]);
		}
		free(f->acteurs);

		for(i=0;i<f->nbDirector;i++){
			free(f->director[i]);
		}
		free(f->director);
		
	}else{
		printf("suppresion film null\n");
	}
	free(f);
}


void film_copie(film* destination,film* source){
	int i;
	for(i=0;i<source->nbAct;i++){
		destination=film_ajout_acteur(destination,source->acteurs[i]);
	}
	for(i=0;i<source->nbGenre;i++){
		destination=film_ajout_genre(destination,source->genres[i]);
	}
	for(i=0;i<source->nbDirector;i++){
		destination=film_ajout_director(destination,source->director[i]);
	}
	film_ajout(destination,source->titre,source->description,source->type,source->duree,source->id,source->annee);
}




