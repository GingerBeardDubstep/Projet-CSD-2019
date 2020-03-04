#include <stdlib.h>
#include <gtk/gtk.h>
#include "parseur.h"
#include "algoRecom.h"
#include "tableUtilisateur.h"

int mainInterPrinc(int argc, char **argv,utilisateur* ut, tableFilm* tf){
	int nb_film_select = 0;
	char* tabF[5];

	recommandationsInterface(ut,tf,tabF);//On lance l'algorithme de recommandation : il est quasi-similaire à l'algorithme du terminal sauf qu'il stocke les 5 films recommandés dans tabF

	free_utilisateur(ut);//On libère la mémoire de l'utilisateur

	void clse(){
		libererMemoireTableFilm(tf);
		gtk_main_quit();
	}//libère la mémoire de la table films puis ferme la fenêtre

	GtkWidget* FenetrePrinc = NULL;
	GtkWidget* pHBoxPrinc = NULL;
	GtkWidget* pVBoxPrinc1 = NULL;
	GtkWidget* pVBoxPrinc2 = NULL;
	GtkWidget* pVBoxPrinc3 = NULL;
	GtkWidget* pVBoxPrinc4 = NULL;
	GtkWidget* pVBoxPrinc5 = NULL;

	GtkWidget* ImageP1 =NULL;
	GtkWidget* ImageP2 =NULL;
	GtkWidget* ImageP3 =NULL;
	GtkWidget* ImageP4 =NULL;
	GtkWidget* ImageP5 =NULL;

	GtkWidget* ButtonP1 = NULL;
	GtkWidget* ButtonP2 = NULL;
	GtkWidget* ButtonP3 = NULL;
	GtkWidget* ButtonP4 = NULL;
	GtkWidget* ButtonP5 = NULL;

	char chemin1[50];
	char chemin2[50];
	char chemin3[50];
	char chemin4[50];
	char chemin5[50];
	
	strcpy(chemin1,"../PicturesFilms/");
	strcpy(chemin2,"../PicturesFilms/");
	strcpy(chemin3,"../PicturesFilms/");
	strcpy(chemin4,"../PicturesFilms/");
	strcpy(chemin5,"../PicturesFilms/");

	strcat(chemin1,tabF[0]);
	strcat(chemin2,tabF[1]);
	strcat(chemin3,tabF[2]);
	strcat(chemin4,tabF[3]);
	strcat(chemin5,tabF[4]);

	strcat(chemin1,".jpg");
	strcat(chemin2,".jpg");
	strcat(chemin3,".jpg");
	strcat(chemin4,".jpg");
	strcat(chemin5,".jpg");//Pareil que dans l'interface intermèdiaire sauf qu'on concatène le chemin et .jpg avec les titres des films recommandés

	gtk_init(&argc,&argv);

	FenetrePrinc = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(FenetrePrinc),"Votre recommandation");

	gtk_window_set_default_size(GTK_WINDOW(FenetrePrinc),900,550);

	pHBoxPrinc = gtk_hbox_new(TRUE,0);
	
	pVBoxPrinc1 = gtk_vbox_new(TRUE,0);
	pVBoxPrinc2 = gtk_vbox_new(TRUE,0);
	pVBoxPrinc3 = gtk_vbox_new(TRUE,0);
	pVBoxPrinc4 = gtk_vbox_new(TRUE,0);
	pVBoxPrinc5 = gtk_vbox_new(TRUE,0);

	gtk_container_add(GTK_CONTAINER(FenetrePrinc),pHBoxPrinc);
	
	gtk_box_pack_start(GTK_BOX(pHBoxPrinc), pVBoxPrinc1, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pHBoxPrinc), pVBoxPrinc2, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pHBoxPrinc), pVBoxPrinc3, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pHBoxPrinc), pVBoxPrinc4, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pHBoxPrinc), pVBoxPrinc5, TRUE, FALSE,0);

	ButtonP1=gtk_toggle_button_new();
	ButtonP2=gtk_toggle_button_new();
	ButtonP3=gtk_toggle_button_new();
	ButtonP4=gtk_toggle_button_new();
	ButtonP5=gtk_toggle_button_new();
	
	ImageP1 = gtk_image_new_from_file(chemin1);
	ImageP2 = gtk_image_new_from_file(chemin2);
	ImageP3 = gtk_image_new_from_file(chemin3);
	ImageP4 = gtk_image_new_from_file(chemin4);
	ImageP5 = gtk_image_new_from_file(chemin5);

	gtk_container_add(GTK_CONTAINER(ButtonP1),ImageP1);
	gtk_container_add(GTK_CONTAINER(ButtonP2),ImageP2);
	gtk_container_add(GTK_CONTAINER(ButtonP3),ImageP3);
	gtk_container_add(GTK_CONTAINER(ButtonP4),ImageP4);
	gtk_container_add(GTK_CONTAINER(ButtonP5),ImageP5);

	gtk_box_pack_start(GTK_BOX(pVBoxPrinc1), ButtonP1, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBoxPrinc2), ButtonP2, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBoxPrinc3), ButtonP3, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBoxPrinc4), ButtonP4, TRUE, FALSE,0);
	gtk_box_pack_start(GTK_BOX(pVBoxPrinc5), ButtonP5, TRUE, FALSE,0);
	
	g_signal_connect(G_OBJECT(FenetrePrinc), "delete-event", G_CALLBACK(clse),NULL);//Relié à clse() au lieu de gtk_main_quit()

	gtk_widget_show_all(FenetrePrinc);
	gtk_main();

	return EXIT_SUCCESS;
}
