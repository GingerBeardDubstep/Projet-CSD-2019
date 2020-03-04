#include <stdlib.h>
#include <gtk/gtk.h>
#include "interfaceIntermediaire.c"

int mainDepart(int argc,char **argv){
	GtkWidget* FenetreDepart = NULL ;//On déclare la fenêtre

	GtkWidget* EntryId =NULL;
	GtkWidget* EntryPassword =NULL ;//On déclare les zones d'entrées de texte

	GtkWidget* Button = NULL;//On déclare le bouton confirmer

	GtkWidget* pVBox = NULL;//On déclare une boite verticale 
	
	void connection_app1(){
	char * id ;
	id = gtk_entry_get_text(GTK_ENTRY(EntryId));//On stocke dans id ce que l'utilisateur a saisi dans l'entrée identifiant
	utilisateur* ut;//On déclare un utilisateur
	ut = createUtilisateur(id);//On créé un nouvel utilisateur
	gtk_widget_destroy(GTK_CONTAINER(FenetreDepart));//On ferme cette fenêtre

	mainII(argc,argv,ut);//on lance le main de la fenêtre de sélection avec comme urgument l'utilisateur
	gtk_main_quit();//On arrête l'algorithme quand mainII a finit de s'executer
	}
	
	gtk_init(&argc,&argv);//On initialise l'interface

	FenetreDepart = gtk_window_new(GTK_WINDOW_TOPLEVEL);//On créé la fenêtre

	gtk_window_set_title(GTK_WINDOW(FenetreDepart),"Connexion");//On la nomme

	gtk_window_set_default_size(GTK_WINDOW(FenetreDepart),400,150);//On lui donne une taille par défaut

	g_signal_connect(G_OBJECT(FenetreDepart), "delete-event", G_CALLBACK(gtk_main_quit),NULL); //On relie la croix rouge à la fonction de fermeture de 'interface'

	pVBox = gtk_vbox_new(TRUE,0);//Création d'une boite verticale
	gtk_container_add(GTK_CONTAINER(FenetreDepart),pVBox);//on inclue la boite dans la fenêtre

	EntryId= gtk_entry_new();
	EntryPassword= gtk_entry_new();//On déclare les deux entrées

	gtk_box_pack_start(GTK_BOX(pVBox), EntryId, TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(pVBox), EntryPassword, TRUE, FALSE, 0);//on insère les entrées dans la boite

	Button = gtk_button_new_with_label("Connexion");//On créé un bouton avec marqué "Connexion" dessus
	gtk_box_pack_start(GTK_BOX(pVBox), Button, TRUE, FALSE,0);//puis on insère le bouton dans la boite

	gtk_entry_set_text(EntryId,"Identifiant");
	gtk_entry_set_text(EntryPassword,"Mot de passe");//On met dans les entrées du pré-texte (pour que l'utilisateur sache quoi rentrer)

	g_signal_connect(G_OBJECT(Button), "clicked", G_CALLBACK(connection_app1), (GtkWidget*) pVBox);//on execute connection_app1 quand on clique sur Button


	gtk_widget_show_all(FenetreDepart);
	gtk_main();//On affiche la fenêtre

	return EXIT_SUCCESS;
}