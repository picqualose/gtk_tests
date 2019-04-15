#include <gtk/gtk.h>


////////////////// FONCTION //////////////////

void coucou (GtkWidget *widget, gpointer data)
{
    g_print ("Et quand tu cliques j'apparais :D \n");

}
/////////////////// MAIN //////////////////

int main (int argc, char *argv[])
    {

        //Declaration d'un Widget, ici une fenetre puis un bouton
        GtkWidget *window;
        GtkWidget *button;
    
        //Fonction appelee dans toutes appli GTK --> evalue parametre en ligne de commande et retournes a l'appli (param de base)
        gtk_init (&argc, &argv);
    
        //Creation de la fenetre 
        window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
        //Affichage de la fenetre 
        gtk_widget_show (window);
        //Definition de la largeur de la bordure du container 
        gtk_container_border_width (GTK_CONTAINER (window), 10);
    
        //Creation d'un nouveau bouton 
        button = gtk_button_new_with_label ("Je suis un bouton");
        
        gtk_signal_connect (GTK_OBJECT (button), "clicked", GTK_SIGNAL_FUNC(coucou), NULL);
        
        //On met le bouton dans la fenetre 
        gtk_container_add (GTK_CONTAINER (window), button);

        gtk_widget_show (button);
        gtk_widget_show (window);


        gtk_main ();
    
        return 0;
    }
