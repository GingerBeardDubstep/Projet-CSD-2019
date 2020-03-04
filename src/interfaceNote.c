#include <stdlib.h>
#include <gtk/gtk.h>

int mainNote(int argc, char **argv){
	GtkWidget* FenetreNote = NULL ;
	GtkWidget* EntryNote = NULL;
	GtkWidget* Bouton = NULL;
	GtkWidget* pVBoxNote = NULL;//Déclaration Widgets

	gtk_init(&argc,&argv);

	FenetreNote = gtk_window_new(GTK_WINDOW_TOPLEVEL);



	gtk_window_set_title(GTK_WINDOW(FenetreNote),"Note");

	gtk_window_set_default_size(GTK_WINDOW(FenetreNote),400,150);//Initialisation fenêtre

	int mark;

	pVBoxNote = gtk_vbox_new(TRUE,0);

	gtk_container_add(GTK_CONTAINER(FenetreNote),pVBoxNote);

	EntryNote = gtk_entry_new();

	gtk_box_pack_start(GTK_BOX(pVBoxNote), EntryNote, TRUE, FALSE, 0);

	gtk_entry_set_text(EntryNote,"Entrez une note entre 1 et 10");

	Bouton = gtk_button_new_with_label("Confirmer");

	gtk_box_pack_start(GTK_BOX(pVBoxNote), Bouton, TRUE, FALSE, 0);

	g_signal_connect(G_OBJECT(FenetreNote), "delete-event", G_CALLBACK(gtk_main_quit),NULL);

	void nonEntier(){
		gtk_entry_set_text(EntryNote,"J'ai dit une note entre 1 et 10 ...");
	}//Indique dans la zone de texte que l'entrée de l'utilisateur est incorrecte

	void confirmationNote(){
		int nt;
		nt=atoi(gtk_entry_get_text(GTK_ENTRY(EntryNote)));
		if(nt!=1&&nt!=2&&nt!=3&&nt!=4&&nt!=5&&nt!=6&&nt!=7&&nt!=8&&nt!=9&&nt!=10){
			nonEntier();
		}else{
			mark=nt;
			gtk_widget_destroy(GTK_CONTAINER(FenetreNote));
			gtk_main_quit();			
		}
	}//verifie si l'entrée est un entier lorqu'on appuie sur confirmer, ferme la fenetre si c est le cas, redemande une valeur sinon.

	g_signal_connect(G_OBJECT(Bouton), "clicked", G_CALLBACK(confirmationNote), (GtkWidget*) pVBoxNote);//connexion bouton/confirmationNote()

	gtk_widget_show_all(FenetreNote);
	gtk_main();//afficher la fenetre

	return(mark);//renvoie la note en sortie
}