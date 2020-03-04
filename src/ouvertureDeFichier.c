#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableFilm.h"


void remplirListeFilm(char* emplacement, tableFilm* tf){
char ligne[1000]; //Declaration des variables
int id;
char annee[4];
char* titre;
char* duree;
char* testDirector;
char* director;
char* description;
char* acteurs;
char* acteur;
char* genre;
char* genres;
char * teeeest;
film* f;
int type;//1 si TV Series , 0 si film

FILE* fp ;
fp = fopen(emplacement,"r");//Fichier ouvert en mode lecture
	if(fp!=NULL){
		while( fgets(ligne,sizeof ligne, fp)){//tant que l'on a pas parcouru le fichier en entier
			if(sscanf(ligne,"%d//.*",&id)==1){//si la ligne commence par un chiffre puis un "." on récupere le chiffre que l'on rentre dans id
				char c = 'a';
				int j=0;
				int i;

				titre = malloc(1000*sizeof(char)); 
				duree= malloc(50*sizeof(char));
				testDirector = malloc(8*sizeof(char));
				director = malloc(1000*sizeof(char));
				description = malloc(1000*sizeof(char));
				acteurs = malloc(1000*sizeof(char));
				genres = malloc(1000*sizeof(char));
				teeeest = malloc(1000*sizeof(char));
				f=film_create();


				while( c!='.' && j<strlen(ligne)){//Tant que l'on atteint pas "."
					c=ligne[j];//On parcours la ligne
					j++;
				}
				j+=2;
				i=j;
				while( c!= '(' && i<strlen(ligne)){//Tant que l'on atteint pas ( qui permet de savoir que l'on atteint l'annee
					c=ligne[i];
					i++;
				}
				strncpy(teeeest,ligne+j,i-j-2);//On copie le titre dans un variable temporaire
				strcpy(titre,teeeest);// on le mets dans la variable titre. Cette opération est obligatoire, je ne sais pas pourquoi mais si l'on ne fait pas cela ça ne marche pas



				strncpy(annee,ligne+i,4);//On récupere les 4 char suivant ( 



				if(ligne[i+5]=='T'){//si après l'année on a un "T" alors c'est une TV Series 
					type=1;
				}else{
					type=0;
				}

				int test = 1;
				while(test){
					fgets(ligne,sizeof ligne, fp);
					for(i=0;i<strlen(ligne);i++){// on parcours le fichier jusqu'a obtenir une lettre
						if( (ligne[i]>='a' && ligne[i]<='z') || (ligne[i]>='A' && ligne[i]<='Z')){
							test=0;
						}
					}
					
				}


				strcpy(description,ligne);
				//getchar();
				fgets(ligne,sizeof ligne, fp);
				strncpy(testDirector,ligne,8);
				testDirector[8]='\0';

				/*if(strcmp(testDirector,"Director")==0){// si les 8 premiers char sont "Director"
					director=malloc(sizeof(char)*(strlen(ligne)-11));
					strncpy(director,ligne+11,strlen(ligne)-11);
					fgets(ligne,sizeof ligne, fp);//alors on obtient le director
				}else{
					director=(malloc(sizeof(char)*23));
					strcpy(director,"director non reference");//sinon il n'est pas référencé
				}*/
				free(teeeest);
				teeeest = malloc(1000*sizeof(char));
				if(strcmp(testDirector,"Director")==0){// si les 8 premiers char sont "Director"
					i=11;
					j=0;
					while((ligne[i]>='a' && ligne[i]<='z') || (ligne[i]>='A' && ligne[i]<='Z') || ligne[i]==' ' || (ligne[i]>127 && ligne[i]<166) || ligne[i]==45 || ligne[i]==46 ){
							i++;	
							j++;
					}
					strncpy(teeeest,ligne+11,i-11);
					teeeest[j]='\0';
					strcpy(director,teeeest);
					fgets(ligne,sizeof ligne, fp);//alors on obtient le director
				}else{
					strcpy(director,"director non reference");//sinon il n'est pas référencé
				}


				int curseur=0;
				
				c=ligne[curseur];
				while(c!=':' && curseur<strlen(ligne)){//On parcours jusqu'à obtenir les : de With :
					curseur++;
					c=ligne[curseur];
				}
				if(curseur<strlen(ligne)){
					strncpy(acteurs,ligne+curseur+1,strlen(ligne)-curseur);
					acteurs = strtok(acteurs, ",");//Le caractere de séparation est ","
				   	while( acteurs != NULL ) {//On parcours l'entiéreté des acteurs
				   		i=0;
				   		j=0;
				   		acteur=malloc(sizeof(char)*(strlen(acteurs)));
						while( i<strlen(acteurs)){
								if((acteurs[i]>='a' && acteurs[i]<='z') || (acteurs[i]>='A' && acteurs[i]<='Z') ||(i>0 && acteurs[i]==' ' && ((acteurs[i-1]>='a' && acteurs[i-1]<='z') || (acteurs[i-1]>='A' && acteurs[i-1]<='Z')))){
									acteur[j]=acteurs[i];
									j++;
								}
								i++;
						}
				   		acteur[j]='\0';
				   		f = film_ajout_acteur(f,acteur);
				      	acteurs = strtok(NULL, ",");
				      	free(acteur);
				   	}
				   	fgets(ligne,sizeof ligne, fp);
				}
				free(acteurs);



				genres = strtok(ligne, "|");
			   	while( genres != NULL ) {//Pareil que les acteurs mais avec les genres
			   		i=0;
				   	j=0;
				   	curseur=0;
			    	if(genres[strlen(genres)-2]=='.'){
			    		c=genres[curseur];
			    		while((c < '0' || c > '9') && curseur<strlen(genres)){
			    			c=genres[curseur];
							curseur++;
						}
						strncpy(duree,genres+curseur-1,strlen(genres)-curseur-5);
					}
			    	
			    	genre=malloc(sizeof(char)*(strlen(genres)));
					while((curseur==0 || i+1!=curseur) && (i<strlen(genres))){
							if((genres[i]>='a' && genres[i]<='z') || (genres[i]>='A' && genres[i]<='Z') ||(i>0 && i<strlen(genres)-1 && genres[i]==' ' && ((genres[i-1]>='a' && genres[i-1]<='z') || (genres[i-1]>='A' && genres[i-1]<='Z')))){
								genre[j]=genres[i];
								j++;
							}
							i++;
					}
				   	genre[j]='\0';
			   		f = film_ajout_genre(f,genre);
			      	genres = strtok(NULL, "|");
			      	free(genre);
				}
				



				//Test pour la strcture de données Film
				
				
				f=film_ajout(f,titre,director,description,type,duree,id);
				tf_ajoutFilm(tf,f);

				/*printf("id : %d\n",f->id);
				printf("titre : %s\n",f->titre);
				printf("director : %s\n",f->director);
				printf("description : %s\n",f->description);
				printf("type : %d\n",f->type);
				printf("duree : %d\n",f->duree);
				printf("nbAct : %d\n",f->nbAct);
				printf("Premier Acteur : %s\n",f->acteurs[0]);
				printf("Premier Genre : %s\n",f->genres[0]);*/
				//printf("Taille du Bordel : %d\n",tf_taille(tf));
				//printf("--------------------------\n");

				


				//On libére tout les pointeurs

				free(titre);
				free(testDirector);
				free(director);
				free(description);
				free(acteurs);
				free(genres);
				free(duree);
				free(teeeest);
				free(f);



			}

		}
	}
	
}




int main(){
	tableFilm* tf = createTableFilm();
	remplirListeFilm("../BDCSD.txt",tf);
	tf_voirToutFilm(tf);
}
