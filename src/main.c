#include "main.h"

int main(int argc, char *argv[]){
	/*tableFilm* tf = createTableFilm();
	parseFichier("../BDCSD.txt",tf);
	printf("%i\n",tf_taille(tf));
	tf_voirToutFilm(tf);
	libererMemoireTableFilm(tf);*/

	char* line = (char*)malloc(sizeof(char)*1000);
	int test=0;
	int choix=-1;
	int json = 0;
	char* titre = (char*)malloc(sizeof(char)*1000);
	char* nom = (char*)malloc(sizeof(char)*1000);
	char* typ = (char*)malloc(sizeof(char)*1000);
	char* genre = (char*)malloc(sizeof(char)*1000);
	int opt;
	opt=0;

	tableFilm* tfTemp = (tableFilm*)malloc(sizeof(tableFilm *));
	utilisateur* uti;

	if (argc == 2){
		if (strcmp(argv[1], "-json") == 0){
			json = 1;
		}
	}

	printf("Bonjour et bienvenue sur notre application de recommandation de film\n");
	printf("Voulez vous lancer l'application en terminal ou en interface graphique ? (1 pour terminal et 2 pour interface)\n");
	fgets(typ,1000,stdin);
	//sscanf(typ,"%d",&genr);
	opt=atoi(typ);

	while(opt!=1&&opt!=2){
		printf("Veuillez rentrer 1 pour terminal et 2 pour interface\n");
		fgets(typ,1000,stdin);
		opt=atoi(typ);
		//sscanf(typ,"%d",&genr);
	}
	if(opt==1){
		system("clear");
		printf("Veuillez entrer votre nom d'utilisateur\n");
		fgets(nom,1000,stdin);
		tableFilm* tf = createTableFilm();
		system("clear");
		uti = createUtilisateur(nom);
		nom[strlen(nom)-1]='\0';
		parseFichier((char *)"../BDCSD.txt",tf);
		printf("%s veuillez appuyez sur:\n0 pour arreter\n1 pour voir la liste des films\n2 pour choisir d'en retirer un\n3 pour noter une serie de film\n4 pour voir la liste de note\n",nom);
		fgets(line,sizeof(line),stdin);
		sscanf(line,"%d",&choix);

		while(choix!=0 ){
			tfTemp=tf;
			if(choix==1){
				tf_voirToutFilm(tfTemp);
				printf("\n");
				choix=-1;
			}else if(choix==2){
				system("clear");
				printf("Veuillez rentrer le titre de votre film\n");
				fgets(titre,1000,stdin);
				titre[strlen(titre)-1]='\0';
				tf_suppressionFilmByTitre(tfTemp,titre);
				choix=-1;
			}else if(choix==3){
				system("clear");
				note_films_hasard(uti,tf);
				recommendations(uti,tf);
				if (json ==1){
					recommandationJson(uti);
				}
				sscanf(line,"%d",&choix);
				choix=-1;
			}else if(choix==4){
				voir_notes(uti->premierFilm);
				choix=-1;
			}
			if(choix==-1){
				printf("%s veuillez appuyez sur:\n0 pour arreter\n1 pour voir la liste des films\n2 pour choisir d'en retirer un\n3 pour noter une serie de film\n4 pour voir la liste de note\n",nom);
				fgets(line,sizeof(line),stdin);
				sscanf(line,"%d",&choix);
			}
		}
		libererMemoireTableFilm(tf);
	}
	if(opt==2){
		mainDepart(argc,argv);
	}
}
