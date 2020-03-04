#include "algoRecom.h"
#include <time.h>
#define NBFilm 20


void note_films_hasard(utilisateur* u, tableFilm* tf){
	int i,j,alea;
	film* iteration = malloc(sizeof(film*));
	srand(time(NULL));
	alea=rand() % (tf_taille(tf)-NBFilm);
	for(i=0;i<NBFilm;i++){
		int note=-1;
		iteration=tf_getFilmByNb(tf,alea+i);
		while(note>10 || note<0){
			printf("film : %s\n",iteration->titre);
			printf("Veuillez attribuer une note à ce film :\n");
			scanf("%d",&note);
			if(note>10 || note<0){
				printf("La note doit être comprise entre 0 et 10\n");
			}
		}
		system("clear");
		utilisateur_ajoutFilm(u->premierFilm,iteration,note);
	}
}


matriceNote* newMatrice(){
	matriceNote* mn = malloc(sizeof(matriceNote*));
	mn->element=NULL;
	mn->valeur=0;
	mn->suiv=NULL;
}

void voirMatriceNote(matriceNote* mn){
	if(mn!=NULL){
		printf("%s\n",mn->element);
		printf("%i\n",mn->valeur);
		voirMatriceNote(mn->suiv);
	}
}

void ajoutMatrice(matriceNote* mn, char* nom, int valeur){
	if(mn->element==NULL || strcmp(mn->element,nom)==0){
		mn->element=strdup(nom);
		mn->valeur=mn->valeur+valeur;
	}else{
		if(mn->suiv!=NULL){
			ajoutMatrice(mn->suiv,nom,valeur);
		}else{
			matriceNote* mn2 = newMatrice();
			mn2->element=strdup(nom);
			mn2->valeur=valeur;
			mn->suiv=mn2;
		}
	}
	
}

int nbPoints(film* f,matriceNote* mn){
	if(f!=NULL){
		int i,j,v;
		matriceNote* temp;
		int res;
		int max=0;
		temp=mn;
			while(temp!=NULL){
				res=0;
				for(i=0;i<f->nbAct;i++){
					if(strcmp(f->acteurs[i],temp->element)==0){
						res=res+temp->valeur;
					}
				}
				for(j=0;j<f->nbGenre;j++){
					if(strcmp(f->genres[j],temp->element)==0){
						res=res+temp->valeur;
					}
				}
				for(v=0;i<f->nbDirector;v++){
					if(strcmp(f->director[v],temp->element)==0){
						res=res+temp->valeur;
					}
				}
				if(res>max){
					max=res/(i+j+v);
				}
				temp=temp->suiv;
			}
			return max;
	}else{
		return -1;
	}
}


void recommendations(utilisateur* u,tableFilm* tf){
	matriceNote* mn = newMatrice();
	film** listRecom = malloc(5*sizeof(film*));
	int* note=malloc(sizeof(int*)*5);
	int i,j,tmp,tt,taille;

	filmNote* fn = createFilmNote();
	fn=u->premierFilm;
	fn=fn->suivant;
	for(i=0;i<nb_film(u);i++){

		if(fn->note!=-1){
			for(j=0;j<fn->film->nbAct;j++){
				ajoutMatrice(mn,fn->film->acteurs[j],fn->note);
			}
			for(j=0;j<fn->film->nbGenre;j++){
				ajoutMatrice(mn,fn->film->genres[j],fn->note);
			}
			for(j=0;j<fn->film->nbDirector;j++){
				ajoutMatrice(mn,fn->film->director[j],fn->note);
			}


		}
		fn=fn->suivant;
	}


	for(i=0;i<5;i++){
		note[i]=0;
	}

	tf=tf->suivant;
	taille=tf_taille(tf);
	for(i=0;i<taille;i++){
			tmp=nbPoints(tf->valeur,mn);
			tt=-1;
			for(j=0;j<5;j++){
				if((j==4 && note[j]<tmp ) || (note[j]<tmp && note[j+1]>=tmp)){
					if( tf!=NULL && film_note_notIn(tf->valeur,u->premierFilm)==0){
						note[j]=tmp;
						listRecom[j]=tf->valeur;
					}
				}
			}

		tf=tf->suivant;
	}
	for(i=0;i<5;i++){
		utilisateur_ajoutReco(u->premierReco,listRecom[i]); 
	}



	printf("Voici la liste des films recommandés\n");
	for(i=0;i<5;i++){
		printf("%s\n",listRecom[i]->titre);
	}
}


void recommandationsInterface(utilisateur* u,tableFilm* tf,char ** tabF){
	matriceNote* mn = newMatrice();
	film** listRecom = malloc(5*sizeof(film*));
	int* note=malloc(sizeof(int*)*5);
	int i,j,tmp,tt,taille;

	filmNote* fn = createFilmNote();
	fn=u->premierFilm;
	fn=fn->suivant;
	for(i=0;i<nb_film(u);i++){

		if(fn->note!=-1){
			for(j=0;j<fn->film->nbAct;j++){
				ajoutMatrice(mn,fn->film->acteurs[j],fn->note);
			}
			for(j=0;j<fn->film->nbGenre;j++){
				ajoutMatrice(mn,fn->film->genres[j],fn->note);
			}
			for(j=0;j<fn->film->nbDirector;j++){
				ajoutMatrice(mn,fn->film->director[j],fn->note);
			}


		}
		fn=fn->suivant;
	}


	for(i=0;i<5;i++){
		note[i]=0;
	}

	tf=tf->suivant;
	taille=tf_taille(tf);
	for(i=0;i<taille;i++){
			tmp=nbPoints(tf->valeur,mn);
			tt=-1;
			for(j=0;j<5;j++){
				if((j==4 && note[j]<tmp ) || (note[j]<tmp && note[j+1]>=tmp)){
					if(tf !=NULL && film_note_notIn(tf->valeur,u->premierFilm)==0){
						note[j]=tmp;
						listRecom[j]=tf->valeur;
					}
				}
			}
		
		tf=tf->suivant;
	}
	for(i=0;i<5;i++){
		tabF[i]=listRecom[i]->titre;
	}
}


int film_note_notIn(film* f, filmNote* fn){
	if(fn->suivant==NULL || f==NULL){
		return 0;
	}else{
		if(strcmp(fn->suivant->film->titre,f->titre)==0){
			return 1;
		}else{
			return film_note_notIn(f,fn->suivant);
		}
	}
	return 0;
}
