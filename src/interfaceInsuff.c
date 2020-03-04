#include <stdlib.h>
#include <gtk/gtk.h>

int mainInsuff(int argc, char **argv){
	GtkWidget* FenetreIns = NULL;

	GtkWidget* LabelIns = NULL;

	gchar* Text;

	GtkWidget* ButtonIns = NULL;

	GtkWidget* pVBoxIns = NULL;// On déclare les Widgets

	Text="Pas assez de films selectionnes";

	gtk_init(&argc,&argv);

	LabelIns=gtk_label_new(Text);

	FenetreIns = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(FenetreIns),"Erreur");

	gtk_window_set_default_size(GTK_WINDOW(FenetreIns),400,150);//Initialisation fenêtre

	pVBoxIns = gtk_vbox_new(TRUE,0);
	gtk_container_add(GTK_CONTAINER(FenetreIns),pVBoxIns);//initialisation/insertion boite verticale

	ButtonIns = gtk_button_new_with_label("Fermer");//Création du bouton "fermer"

	gtk_box_pack_start(GTK_BOX(pVBoxIns), LabelIns, TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(pVBoxIns), ButtonIns, TRUE, FALSE, 0); //on met le bouton "fermer" et le label dans la boite

	void quitter(){
		gtk_widget_destroy(GTK_CONTAINER(FenetreIns));
		gtk_main_quit();
	}//quite la fenetre

	g_signal_connect(G_OBJECT(FenetreIns), "delete-event", G_CALLBACK(gtk_main_quit),NULL);
	
	g_signal_connect(G_OBJECT(ButtonIns), "clicked", G_CALLBACK(quitter),(GtkWidget*) pVBoxIns);//connexion du bouton a la fonction quitter()

	gtk_widget_show_all(FenetreIns);
	gtk_main();//on affiche la fenetre
}