#include <stdlib.h>
#include <gtk/gtk.h>
#include "interfacePrincipale.c"
#include "interfaceInsuff.c"
#include "interfaceNote.c"
#define nb_min 3

int mainII(int argc, char **argv,utilisateur* ut){
	tableFilm* tableF;//Déclaration de la table de films
	tableF= createTableFilm();//Création de la table de films
	parseFichier("../BDCSD.txt",tableF);// On remplit la table de films avec le contenu de BDCSD.txt grâce à la fonction parseFichier()

	char ** tabF[20];//Déclaration du tableau de chaines de caractère destiné à contenir les titres des 20 films sélectionnés aléatoirement

	film* iteration = malloc(sizeof(film*));//Déclaration du film iteration

	srand(time(NULL));
	int alea;
	alea=rand() % (tf_taille(tableF)-20);//Génère un entier aléatoirement entre 0 et la taille de tableF-20

	for(int it=0;it<20;it++){
		iteration=tf_getFilmByNb(tableF,alea+it);// On va chercher un filme dans tableF à l'aide de son indice et on le stocke dans iteration
		tabF[it]=iteration->titre;//On stocke le titre du film iteration dans tabF
	}

	char chemin1[70];
	char chemin2[70];
	char chemin3[70];
	char chemin4[70];
	char chemin5[70];
	char chemin6[70];
	char chemin7[70];
	char chemin8[70];
	char chemin9[70];
	char chemin10[70];
	char chemin11[70];
	char chemin12[70];
	char chemin13[70];
	char chemin14[70];
	char chemin15[70];
	char chemin16[70];
	char chemin17[70];
	char chemin18[70];
	char chemin19[70];
	char chemin20[70];// Déclaration des chaines de caractères qui vont contenir les chemins pour accèder aux images correspondant aux films sélectionnés

	strcpy(chemin1,"../PicturesFilms/");
	strcpy(chemin2,"../PicturesFilms/");
	strcpy(chemin3,"../PicturesFilms/");
	strcpy(chemin4,"../PicturesFilms/");
	strcpy(chemin5,"../PicturesFilms/");
	strcpy(chemin6,"../PicturesFilms/");
	strcpy(chemin7,"../PicturesFilms/");
	strcpy(chemin8,"../PicturesFilms/");
	strcpy(chemin9,"../PicturesFilms/");
	strcpy(chemin10,"../PicturesFilms/");
	strcpy(chemin11,"../PicturesFilms/");
	strcpy(chemin12,"../PicturesFilms/");
	strcpy(chemin13,"../PicturesFilms/");
	strcpy(chemin14,"../PicturesFilms/");
	strcpy(chemin15,"../PicturesFilms/");
	strcpy(chemin16,"../PicturesFilms/");
	strcpy(chemin17,"../PicturesFilms/");
	strcpy(chemin18,"../PicturesFilms/");
	strcpy(chemin19,"../PicturesFilms/");
	strcpy(chemin20,"../PicturesFilms/"); //On initialise chemin au folder contenant les images

	strcat(chemin1,tabF[0]);
	strcat(chemin2,tabF[1]);
	strcat(chemin3,tabF[2]);
	strcat(chemin4,tabF[3]);
	strcat(chemin5,tabF[4]);
	strcat(chemin6,tabF[5]);
	strcat(chemin7,tabF[6]);
	strcat(chemin8,tabF[7]);
	strcat(chemin9,tabF[8]);
	strcat(chemin10,tabF[9]);
	strcat(chemin11,tabF[10]);
	strcat(chemin12,tabF[11]);
	strcat(chemin13,tabF[12]);
	strcat(chemin14,tabF[13]);
	strcat(chemin15,tabF[14]);
	strcat(chemin16,tabF[15]);
	strcat(chemin17,tabF[16]);
	strcat(chemin18,tabF[17]);
	strcat(chemin19,tabF[18]);
	strcat(chemin20,tabF[19]);// On concatène le chemin avec les titres des films sélectionnés

	strcat(chemin1,".jpg");
	strcat(chemin2,".jpg");
	strcat(chemin3,".jpg");
	strcat(chemin4,".jpg");
	strcat(chemin5,".jpg");
	strcat(chemin6,".jpg");
	strcat(chemin7,".jpg");
	strcat(chemin8,".jpg");
	strcat(chemin9,".jpg");
	strcat(chemin10,".jpg");
	strcat(chemin11,".jpg");
	strcat(chemin12,".jpg");
	strcat(chemin13,".jpg");
	strcat(chemin14,".jpg");
	strcat(chemin15,".jpg");
	strcat(chemin16,".jpg");
	strcat(chemin17,".jpg");
	strcat(chemin18,".jpg");
	strcat(chemin19,".jpg");
	strcat(chemin20,".jpg");//on concatene chemin avec .jpg (ce qui donne une chaine de caractères de la forme : "../PicturesFilms/titre_du_film.jpg")

	GtkWidget* FenetreInt = NULL ; // Déclaration de la fenêtre

	GtkWidget* Button1 = NULL;
	GtkWidget* Button2 = NULL;
	GtkWidget* Button3 = NULL;
	GtkWidget* Button4 = NULL;
	GtkWidget* Button5 = NULL;
	GtkWidget* Button6 = NULL;
	GtkWidget* Button7 = NULL;
	GtkWidget* Button8 = NULL;
	GtkWidget* Button9 = NULL;
	GtkWidget* Button10 = NULL;
	GtkWidget* Button11 = NULL;
	GtkWidget* Button12 = NULL;
	GtkWidget* Button13 = NULL;
	GtkWidget* Button14 = NULL;
	GtkWidget* Button15 = NULL;
	GtkWidget* Button16 = NULL;
	GtkWidget* Button17 = NULL;
	GtkWidget* Button18 = NULL;
	GtkWidget* Button19 = NULL;
	GtkWidget* Button20 = NULL;// Déclaration de 20 boutons

	GtkWidget* Image1 =NULL;
	GtkWidget* Image2 =NULL;
	GtkWidget* Image3 =NULL;
	GtkWidget* Image4 =NULL;
	GtkWidget* Image5 =NULL;
	GtkWidget* Image6 =NULL;
	GtkWidget* Image7 =NULL;
	GtkWidget* Image8 =NULL;
	GtkWidget* Image9 =NULL;
	GtkWidget* Image10 =NULL;
	GtkWidget* Image11 =NULL;
	GtkWidget* Image12 =NULL;
	GtkWidget* Image13 =NULL;
	GtkWidget* Image14 =NULL;
	GtkWidget* Image15 =NULL;
	GtkWidget* Image16 =NULL;
	GtkWidget* Image17 =NULL;
	GtkWidget* Image18 =NULL;
	GtkWidget* Image19 =NULL;
	GtkWidget* Image20 =NULL;//Déclaration de 20 Images

	GtkWidget* ButtonFinish=NULL;//Déclaration du bouton "Confirmer"

	GtkWidget* pHBox =NULL;//Déclaration d'une boite horizontale

	GtkWidget* pVBox1 =NULL;
	GtkWidget* pVBox2=NULL;
	GtkWidget* pVBox3=NULL;
	GtkWidget* pVBox4=NULL;
	GtkWidget* pVBoxLab=NULL; //Déclaration de 5 boites verticales

	gchar* Texte  ;

	Texte = "Choisissez parmis ces films ceux que vous avez deja vus";

	gtk_init(argc,argv);

	FenetreInt = gtk_window_new(GTK_WINDOW_TOPLEVEL);


	gtk_window_set_title(GTK_WINDOW(FenetreInt),Texte);

	gtk_window_set_default_size(GTK_WINDOW(FenetreInt),900,550);

	g_signal_connect(G_OBJECT(FenetreInt), "delete-event", G_CALLBACK(gtk_main_quit),NULL); //initialisation de la fenetre

	pHBox = gtk_hbox_new(TRUE,0);//On créé une boite horizontale

	pVBox1 = gtk_vbox_new(TRUE,0);
	pVBox2 = gtk_vbox_new(TRUE,0);
	pVBox3 = gtk_vbox_new(TRUE,0);
	pVBox4 = gtk_vbox_new(TRUE,0);
	pVBoxLab = gtk_vbox_new(TRUE,0);// On créé 5 boite verticales

	gtk_container_add(GTK_CONTAINER(FenetreInt),pHBox);//On insére la boite horizontale dans la fenetre

	gtk_box_pack_start(GTK_BOX(pHBox), pVBox1, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pHBox), pVBox2, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pHBox), pVBox3, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pHBox), pVBox4, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pHBox), pVBoxLab, TRUE, FALSE,0); // On insère les 5 boites verticales dans la boite horizontale 

	Button1=gtk_toggle_button_new();
	Button2=gtk_toggle_button_new();
	Button3=gtk_toggle_button_new();
	Button4=gtk_toggle_button_new();
	Button5=gtk_toggle_button_new();
	Button6=gtk_toggle_button_new();
	Button7=gtk_toggle_button_new();
	Button8=gtk_toggle_button_new();
	Button9=gtk_toggle_button_new();
	Button10=gtk_toggle_button_new();
	Button11=gtk_toggle_button_new();
	Button12=gtk_toggle_button_new();
	Button13=gtk_toggle_button_new();
	Button14=gtk_toggle_button_new();
	Button15=gtk_toggle_button_new();
	Button16=gtk_toggle_button_new();
	Button17=gtk_toggle_button_new();
	Button18=gtk_toggle_button_new();
	Button19=gtk_toggle_button_new();
	Button20=gtk_toggle_button_new();//Creation de 20 boutons

	Image1 = gtk_image_new_from_file(chemin1);
	Image2 = gtk_image_new_from_file(chemin2);
	Image3 = gtk_image_new_from_file(chemin3);
	Image4 = gtk_image_new_from_file(chemin4);
	Image5 = gtk_image_new_from_file(chemin5);
	Image6 = gtk_image_new_from_file(chemin6);
	Image7 = gtk_image_new_from_file(chemin7);
	Image8 = gtk_image_new_from_file(chemin8);
	Image9 = gtk_image_new_from_file(chemin9);
	Image10 = gtk_image_new_from_file(chemin10);
	Image11 = gtk_image_new_from_file(chemin11);
	Image12 = gtk_image_new_from_file(chemin12);
	Image13 = gtk_image_new_from_file(chemin13);
	Image14 = gtk_image_new_from_file(chemin14);
	Image15 = gtk_image_new_from_file(chemin15);
	Image16 = gtk_image_new_from_file(chemin16);
	Image17 = gtk_image_new_from_file(chemin17);
	Image18 = gtk_image_new_from_file(chemin18);
	Image19 = gtk_image_new_from_file(chemin19);
	Image20 = gtk_image_new_from_file(chemin20); // On va chercher les images grâce à leur chemin et on le stocke dans le Widget Image

	gtk_container_add(GTK_CONTAINER(Button1),Image1);
	gtk_container_add(GTK_CONTAINER(Button2),Image2);
	gtk_container_add(GTK_CONTAINER(Button3),Image3);
	gtk_container_add(GTK_CONTAINER(Button4),Image4);
	gtk_container_add(GTK_CONTAINER(Button5),Image5);
	gtk_container_add(GTK_CONTAINER(Button6),Image6);
	gtk_container_add(GTK_CONTAINER(Button7),Image7);
	gtk_container_add(GTK_CONTAINER(Button8),Image8);
	gtk_container_add(GTK_CONTAINER(Button9),Image9);
	gtk_container_add(GTK_CONTAINER(Button10),Image10);
	gtk_container_add(GTK_CONTAINER(Button11),Image11);
	gtk_container_add(GTK_CONTAINER(Button12),Image12);
	gtk_container_add(GTK_CONTAINER(Button13),Image13);
	gtk_container_add(GTK_CONTAINER(Button14),Image14);
	gtk_container_add(GTK_CONTAINER(Button15),Image15);
	gtk_container_add(GTK_CONTAINER(Button16),Image16);
	gtk_container_add(GTK_CONTAINER(Button17),Image17);
	gtk_container_add(GTK_CONTAINER(Button18),Image18);
	gtk_container_add(GTK_CONTAINER(Button19),Image19);
	gtk_container_add(GTK_CONTAINER(Button20),Image20); //On insère les images dans les boutons

	gtk_box_pack_start(GTK_BOX(pVBox1), Button1, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox1), Button2, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox1), Button3, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox1), Button4, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox1), Button5, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox2), Button6, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox2), Button7, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox2), Button8, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox2), Button9, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox2), Button10, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox3), Button11, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox3), Button12, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox3), Button13, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox3), Button14, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox3), Button15, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox4), Button16, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox4), Button17, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox4), Button18, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox4), Button19, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBox4), Button20, TRUE, FALSE,0); //On place les boutons images dans les différentes boites verticales 


	ButtonFinish = gtk_button_new_with_label("Confirmer");// Création du bouton "Confirmer"

	gtk_box_pack_start(GTK_BOX(pVBoxLab), ButtonFinish, TRUE, FALSE,0); //bouton confirmer
	
	void selection_func1(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[0]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}

	void selection_func2(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[1]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func3(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[2]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func4(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[3]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func5(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[4]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func6(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[5]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func7(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[6]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func8(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[7]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func9(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[8]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func10(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[9]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func11(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[10]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func12(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[11]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func13(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[12]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func14(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[13]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func15(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[14]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func16(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[15]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func17(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[16]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func18(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[17]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func19(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[18]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	}
	void selection_func20(){
		int note;
		note=mainNote(argc,argv);
		film* iteration = malloc(sizeof(film*));
		iteration=tf_getFilmByTitre(tableF,tabF[19]);			
		utilisateur_ajoutFilm(ut->premierFilm,iteration,note);
	} // fonctions lançant l interface de notation de stockant la note renvoyée par cette interface dans la structure utilisateur

	void verif(){
		if(nb_film(ut)<nb_min){
			mainInsuff(argc,argv);
		}else{
			gtk_widget_destroy(GTK_CONTAINER(FenetreInt));
			mainInterPrinc(argc,argv,ut,tableF);
			gtk_main_quit();
		}
	}//fonction de vérification quand on appuie sur confirmé : a t on selectionné assez de films? si oui -> interface recomandation


	g_signal_connect(G_OBJECT(ButtonFinish), "clicked", G_CALLBACK(verif), (GtkWidget*) pVBoxLab);

	g_signal_connect(G_OBJECT(Button1), "clicked", G_CALLBACK(selection_func1), (GtkWidget*) pVBox1); 
	g_signal_connect(G_OBJECT(Button2), "clicked", G_CALLBACK(selection_func2), (GtkWidget*) pVBox1);
	g_signal_connect(G_OBJECT(Button3), "clicked", G_CALLBACK(selection_func3), (GtkWidget*) pVBox1);
	g_signal_connect(G_OBJECT(Button4), "clicked", G_CALLBACK(selection_func4), (GtkWidget*) pVBox1);
	g_signal_connect(G_OBJECT(Button5), "clicked", G_CALLBACK(selection_func5), (GtkWidget*) pVBox1);
	g_signal_connect(G_OBJECT(Button6), "clicked", G_CALLBACK(selection_func6), (GtkWidget*) pVBox2);
	g_signal_connect(G_OBJECT(Button7), "clicked", G_CALLBACK(selection_func7), (GtkWidget*) pVBox2);
	g_signal_connect(G_OBJECT(Button8), "clicked", G_CALLBACK(selection_func8), (GtkWidget*) pVBox2);
	g_signal_connect(G_OBJECT(Button9), "clicked", G_CALLBACK(selection_func9), (GtkWidget*) pVBox2);
	g_signal_connect(G_OBJECT(Button10), "clicked", G_CALLBACK(selection_func10), (GtkWidget*) pVBox2);
	g_signal_connect(G_OBJECT(Button11), "clicked", G_CALLBACK(selection_func11), (GtkWidget*) pVBox3);
	g_signal_connect(G_OBJECT(Button12), "clicked", G_CALLBACK(selection_func12), (GtkWidget*) pVBox3);
	g_signal_connect(G_OBJECT(Button13), "clicked", G_CALLBACK(selection_func13), (GtkWidget*) pVBox3);
	g_signal_connect(G_OBJECT(Button14), "clicked", G_CALLBACK(selection_func14), (GtkWidget*) pVBox3);
	g_signal_connect(G_OBJECT(Button15), "clicked", G_CALLBACK(selection_func15), (GtkWidget*) pVBox3);
	g_signal_connect(G_OBJECT(Button16), "clicked", G_CALLBACK(selection_func16), (GtkWidget*) pVBox4);
	g_signal_connect(G_OBJECT(Button17), "clicked", G_CALLBACK(selection_func17), (GtkWidget*) pVBox4);
	g_signal_connect(G_OBJECT(Button18), "clicked", G_CALLBACK(selection_func18), (GtkWidget*) pVBox4);
	g_signal_connect(G_OBJECT(Button19), "clicked", G_CALLBACK(selection_func19), (GtkWidget*) pVBox4);
	g_signal_connect(G_OBJECT(Button20), "clicked", G_CALLBACK(selection_func20), (GtkWidget*) pVBox4); 
	//On fait les connexions entre les fonctions selection_func et les boutons Button 

	gtk_widget_show_all(FenetreInt);
	gtk_main();//on lance la fenetre

	return EXIT_SUCCESS;
}
