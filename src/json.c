#include "json.h"


void openWriteJson (char* buffer){
        FILE *fp;
        fp=fopen("film.json", "w+b" );
	fprintf(fp,"%s",buffer);
        fclose(fp);
}

void oneFilmJson (film* f){
	char buffer[2048];
	unsigned int buflen= 2048;
	jwOpen( buffer, buflen, JW_OBJECT, JW_PRETTY );

	//ajout de la valeur type film/serie à la clé type
	if (f->type==0){
		jwObj_string((char *)"Type",(char *)"Film");
	}else if(f->type==1){
		jwObj_string((char *)"Type",(char *)"TV Series");
	}
	//ajout le titre
	jwObj_string((char *)"Titre", f->titre);

	//ajout l'annee si elle existe
	jwObj_int((char *)"Annee", f->annee);

	//ajout l'annee si elle existe
	if (f->description != NULL){
	jwObj_string((char *)"Description", f->description);
	}

	//ajout des acteurs s'ils existent
	if (f->acteurs!=NULL){
		jwObj_array((char *)"Acteurs");
		for (int i=0;i<f->nbAct;i++){
			jwArr_string(f->acteurs[i]);
		}
		jwEnd();
	}
	//ajout de la duree si elle existe
	if (&f-> duree!=NULL){
		jwObj_int((char *)"Duree", f->duree );
	}
	//ajout des directors s'il existe
	if (f-> nbDirector ==1){
		jwObj_string((char *)"Director",f->director[0]);
	}else if (f->nbDirector >1){
		jwObj_array((char *)"Directors");
		for (int i=0; i<f->nbDirector;i++){
			jwArr_string(f->director[i]);
		}
		jwEnd();
	}
	//ajout des genres
	if (f->nbGenre == 1){
		jwObj_string((char *)"Genre",f->genres[0]);
	}else if (f->nbGenre > 1){
		jwObj_array((char *)"Genres");
		for (int i=0; i<f ->nbGenre;i++){
			jwArr_string(f->genres[i]);
		}
		jwEnd();
	}
	jwClose();
	//printf (strcat(buffer,"\n"));
	FILE *fp;
        fp=fopen("film.json", "w+b" );
	fprintf(fp,"%s",buffer);
        fclose(fp);

}

void filmTableJson (tableFilm* tf){
	char buffer[2048*tf_taille(tf)];
	unsigned int buflen= 2048*tf_taille(tf);

	jwOpen( buffer, buflen, JW_OBJECT, JW_PRETTY );
  tableFilm* tempTF = tf;

  while (tempTF->suivant!=NULL){

	   jwObj_object((char *)"Recommandation ");
		   //ajout de la valeur type film/serie à la clé type
		 if (tempTF->suivant->valeur->type==0){
		     jwObj_string((char *)"Type",(char *)"Film");
		 }else if(tempTF->suivant->valeur->type==1){
		 jwObj_string((char *)"Type",(char *)"TV Series");
		 }
		   //ajout le titre
		 jwObj_string((char *)"Titre", tempTF->suivant->valeur->titre);

		 //ajout l'annee si elle existe
		 jwObj_int((char *)"Annee", tempTF->suivant->valeur->annee);

		 //ajout l'annee si elle existe
		 if (tempTF->suivant->valeur->description != NULL){
		     jwObj_string((char *)"Description", tempTF->suivant->valeur->description);
		 }

		 //ajout des acteurs s'ils existent
		 if (tempTF->suivant->valeur->acteurs!=NULL){
		     jwObj_array((char *)"Acteurs");
			   for (int i=0;i<tempTF->suivant->valeur->nbAct;i++){
				       jwArr_string(tempTF->suivant->valeur->acteurs[i]);
			   }
			   jwEnd();
		 }
		 //ajout de la duree si elle existe
		 if (&tempTF->suivant->valeur->duree!=NULL){
			   jwObj_int((char *)"Duree", tempTF->suivant->valeur->duree );
		 }
		 //ajout des directors s'il existe
		 if (tempTF->suivant->valeur->nbDirector ==1){
		     jwObj_string((char *)"Director",tempTF->suivant->valeur->director[0]);
		 }else if (tempTF->suivant->valeur->nbDirector >1){
			   jwObj_array((char *)"Directors");
		     for (int i=0; i<tempTF->suivant->valeur->nbDirector;i++){
				       jwArr_string(tempTF->suivant->valeur->director[i]);
			   }
			   jwEnd();
		 }
		 //ajout des genres
		 if (tempTF->suivant->valeur->nbGenre == 1){
		     jwObj_string((char *)"Genre",tempTF->suivant->valeur->genres[0]);
		 }else if (tempTF->suivant->valeur->nbGenre > 1){
		     jwObj_array((char *)"Genres");
			   for (int i=0; i<tempTF->suivant->valeur->nbGenre;i++){
				       jwArr_string(tempTF->suivant->valeur->genres[i]);
			   }
			   jwEnd();
		 }
	   jwEnd();

  tempTF=tempTF->suivant;
  }
	jwClose();
	//printf (strcat(buffer,"\n"));
	FILE *fp;
	fp=fopen("film.json", "w+b" );
	fprintf(fp,"%s",buffer);
	fclose(fp);

}

void recommandationJson (utilisateur* u){
  filmReco* fr = u->premierReco;
	char buffer[2048*nb_reco(u)];
	unsigned int buflen= 2048*nb_reco(u);

	jwOpen( buffer, buflen, JW_OBJECT, JW_PRETTY );
  filmReco* tempTF = fr;
  while (tempTF->suivant!=NULL){
	   jwObj_object((char *)"Recommandation");
		   //ajout de la valeur type film/serie à la clé type
		 if (tempTF->suivant->film->type==0){
		     jwObj_string((char *)"Type",(char *)"Film");
		 }else if(tempTF->suivant->film->type==1){
		 jwObj_string((char *)"Type",(char *)"TV Series");
		 }
		   //ajout le titre
		 jwObj_string((char *)"Titre", tempTF->suivant->film->titre);

		 //ajout l'annee si elle existe
		 jwObj_int((char *)"Annee", tempTF->suivant->film->annee);

		 //ajout l'annee si elle existe
		 if (tempTF->suivant->film->description != NULL){
		     jwObj_string((char *)"Description", tempTF->suivant->film->description);
		 }

		 //ajout des acteurs s'ils existent
		 if (tempTF->suivant->film->acteurs!=NULL){
		     jwObj_array((char *)"Acteurs");
			   for (int i=0;i<tempTF->suivant->film->nbAct;i++){
				       jwArr_string(tempTF->suivant->film->acteurs[i]);
			   }
			   jwEnd();
		 }
		 //ajout de la duree si elle existe
		 if (&tempTF->suivant->film->duree!=NULL){
			   jwObj_int((char *)"Duree", tempTF->suivant->film->duree );
		 }
		 //ajout des directors s'il existe
		 if (tempTF->suivant->film->nbDirector ==1){
		     jwObj_string((char *)"Director",tempTF->suivant->film->director[0]);
		 }else if (tempTF->suivant->film->nbDirector >1){
			   jwObj_array((char *)"Directors");
		     for (int i=0; i<tempTF->suivant->film->nbDirector;i++){
				       jwArr_string(tempTF->suivant->film->director[i]);
			   }
			   jwEnd();
		 }
		 //ajout des genres
		 if (tempTF->suivant->film->nbGenre == 1){
		     jwObj_string((char *)"Genre",tempTF->suivant->film->genres[0]);
		 }else if (tempTF->suivant->film->nbGenre > 1){
		     jwObj_array((char *)"Genres");
			   for (int i=0; i<tempTF->suivant->film->nbGenre;i++){
				       jwArr_string(tempTF->suivant->film->genres[i]);
			   }
			   jwEnd();
		 }
	   jwEnd();
  tempTF=tempTF->suivant;
  }
	jwClose();
	//printf (strcat(buffer,"\n"));
	FILE *fp;
	fp=fopen("film.json", "w+b" );
	fprintf(fp,"%s",buffer);
	fclose(fp);

}
