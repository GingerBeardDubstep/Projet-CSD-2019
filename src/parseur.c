#include "parseur.h"



void parseFichier(char* emplacement, tableFilm* tf){
char ligne[1000]; //Declaration des variables
int id;
char* annee;
char* titre;
char* duree;
char* testDirector;
char* directors;
char* director;
char* description;
char* acteurs;
char* acteur;
char* genre;
char* genres;
int type;
film* f;
FILE* fp;
int dureeFinale;
int i;
int j;
int v;
tableFilm* tfTemp = malloc(sizeof(tableFilm *));

fp = fopen(emplacement,"r");//Fichier ouvert en mode lecture
	if(fp!=NULL){
		while( fgets(ligne,sizeof ligne, fp)){//tant que l'on a pas parcouru le fichier en entier
			if(sscanf(ligne,"%d//.*",&id)==1){

				f=film_create();
				dureeFinale=-1; //Valeur impossible si jamais la duree d'un film n'est pas spécifié
				i=0;
				j=0;
				while( !((ligne[i]>='a' && ligne[i]<='z') || (ligne[i]>='A' && ligne[i]<='Z')) && i<strlen(ligne)){//Tant que l'on atteint pas la premiere lettre du titre
					i++;
				}
				while( ligne[j]!= '(' && j<strlen(ligne)){//Tant que l'on atteint pas ( qui permet de savoir que l'on atteint l'annee
					j++;
				}
				titre=malloc(sizeof(char)*(j-i));
				strncpy(titre,ligne+i,j-i-1);	//-1 Car on ne veut pas l'espace entre le titre et la parenthése
				titre[j-i-1]='\0';
				
				

				annee=malloc(sizeof(char)*5);
				strncpy(annee,ligne+j+1,4); //+1 Car on ne veut pas de la parenthése et 4 car l'année est toujours sous 4 chiffres
				annee[4]='\0';
				


				if(ligne[j+6]=='T'){//si après l'année on a un "T" alors c'est une TV Series 
					type=1;
				}else{
					type=0;
				}



				j=1;
				while(j){
					fgets(ligne,sizeof ligne, fp);
					for(i=0;i<strlen(ligne);i++){// on parcours le fichier jusqu'a obtenir une lettre
						if( (ligne[i]>='a' && ligne[i]<='z') || (ligne[i]>='A' && ligne[i]<='Z')){
							j=0;
						}
					}
				}







				i=0;j=0;
				while(ligne[i]!=' ' || i+2<strlen(ligne)){
					i++;
				}


				description=malloc(sizeof(char)*(i+1));
				strncpy(description,ligne,i);
				description[i]='\0';

				



				fgets(ligne,sizeof ligne,fp);







				testDirector = malloc(sizeof(char)*9);
				strncpy(testDirector,ligne,8);//test si les 8 prochains char sont "Director"
				testDirector[8]='\0';
				if(strcmp(testDirector,"Director")==0){
					i=10;//Pour commencer juste apres les deux points
					j=0;
					while(i<strlen(ligne)){
							ligne[j]=ligne[i];
							i++;	
							j++;
					}
					ligne[j]='\0';
					directors = malloc(sizeof(char)*(strlen(ligne)));
					directors = strtok(ligne, ",");//Le caractere de séparation est ","
					
				   	while( directors != NULL ) {
				   		director = malloc(sizeof(char)*strlen(directors));
				   		for(i=0;i+3<strlen(directors);i++){
				   			director[i]=directors[i+1];
				   		}
				   		director[i]='\0';
				   		film_ajout_director(f,director);
				   		directors = strtok(NULL, ",");
				   		free(director);

					}
				   	
				   	fgets(ligne,sizeof(ligne),fp);
				   	
				}else{
					directors=malloc(sizeof(char)*23);
					strcpy(directors,"director non reference");//sinon il n'est pas référencé
					directors[22]='\0';

					film_ajout_director(f,directors);
				}

				


				


				i=0;

				while(ligne[i]!=':' && i<strlen(ligne)){//On parcours jusqu'à obtenir les : de With :
					i++;
				}
				i++;

				if(i<strlen(ligne)){
					acteurs=malloc(sizeof(char)*(strlen(ligne)-i+1));
					strncpy(acteurs,ligne+i,strlen(ligne)-i);
					acteurs[strlen(ligne)-i]='\0';
					acteurs = strtok(acteurs, ",");//Le caractere de séparation est ","
				   	while( acteurs != NULL ) {//On parcours l'entiéreté des acteurs
				   		i=1;
				   		j=0;
				   		acteur=malloc(sizeof(char)*(strlen(acteurs)));
						while( (i<strlen(acteurs))  && (i+2<strlen(acteurs) || (acteurs[i]>=33 && acteurs[i]<=126))){     
								acteur[j]=acteurs[i];
								j++;
								i++;
						}
				   		acteur[j]='\0';
				   		film_ajout_acteur(f,acteur);
				   		//
				      	acteurs = strtok(NULL, ",");
				      	free(acteur);
				   	}
				   	fgets(ligne,sizeof ligne, fp);
				}

				

				genres = malloc(sizeof(char)*strlen(ligne));
				genres = strtok(ligne, "|");
			   	while( genres != NULL ) {//Pareil que les acteurs mais avec les genres
			   		i=0;
				   	j=0;
				   	v=0;
			    	if(genres[strlen(genres)-2]=='.'){
			    		while((genres[v] < '0' || genres[v] > '9') && v<strlen(genres)){
							v++;
						}
						duree=malloc(sizeof(char)*(strlen(genres)-v-4));
						strncpy(duree,genres+v,strlen(genres)-v-7);
						duree[strlen(genres)-v-3]='\0';
						dureeFinale=atoi(duree);
						
						free(duree);
					}
			    	
			    	genre=malloc(sizeof(char)*(strlen(genres)));
					while((v==0 || i+1!=v) && (i<strlen(genres))){
							if((genres[i]>='a' && genres[i]<='z') || (genres[i]>='A' && genres[i]<='Z') ||(i>0 && i<strlen(genres)-1 && genres[i]==' ' && ((genres[i-1]>='a' && genres[i-1]<='z') || (genres[i-1]>='A' && genres[i-1]<='Z')))){
								genre[j]=genres[i];
								j++;
							}
							i++;
					}
				   	genre[j]='\0';
				   	film_ajout_genre(f,genre);
				   	free(genre);
			      	genres = strtok(NULL, "|");
			      	
				}

				f=film_ajout(f,titre,description,type,dureeFinale,id,atoi(annee));
				tfTemp=tf;
				tf_ajoutFilm(tfTemp,f);
				/*printf("id : %d\n",f->id);
				printf("titre : %s\n",f->titre);
				printf("director : %s\n",f->director[0]);
				printf("description : %s\n",f->description);
				printf("bonjour\n");
				printf("type : %d\n",f->type);
				printf("duree : %d\n",f->duree);
				printf("nbAct : %d\n",f->nbAct);
				printf("Premier Acteur : %s\n",f->acteurs[0]);
				printf("Premier Genre : %s\n",f->genres[0]);
				
				printf("------------------------------------------\n");*/
				free(description);
				free(titre);
				free(annee);
				free(testDirector);
				free(directors);
				free(acteurs);
				free(genres);
				film_free(f);
				
				
				
			}


		}
	}


fclose(fp);
}

