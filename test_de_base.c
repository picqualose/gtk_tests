#include <gtk/gtk.h>


////////////////// FONCTION //////////////////

// Ici ce sont ce qu'on appelle les fonctions de RAPPEL c'est a dire des fonction qui se seront appellees par gtk_main


// Quand il est appele, affiche le message note dans le terminal 
void coucou (GtkWidget *widget, gpointer data)
{
    g_print ("Et quand tu cliques j'apparais :D et ferme touuut \n");

}

void msg2 (GtkWidget *widget, gpointer data)
{
    g_print ("Moi j'affiche juste ca en boucle \n");
}

// Indique a GTK quoi faire quand le signal delete arrive (fermer la fenetre via IG.
// TRUE = on ferme la fenetre
// FALSE = on laisse la fenetre ouverte 
gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
    g_print ("le signal delete_event est survenu.\n");
    return (FALSE);
}

//Fonction permettant de quitter l'application (trivial)
void destroy (GtkWidget *widget, gpointer data)
{
    gtk_main_quit ();
}

/////////////////// MAIN //////////////////

int main (int argc, char *argv[])
    {
    //DECLARATION DES VARIABLES
        //Declaration d'un Widget, ici une fenetre puis un bouton
        GtkWidget *window;
        GtkWidget *button;
        GtkWidget *button2;
        GtkWidget *button10;
        GtkWidget *button11;
        GtkWidget *buttonquit;
        GtkWidget *box1; /* --> BOUATE */
        GtkWidget *box2; /* --> BOUATE */

       
    //TRUCS DE BASES    
        //Fonction appelee dans toutes appli GTK --> evalue parametre en ligne de commande et retournes a l'appli (param de base)
        gtk_init (&argc, &argv);

        //Creation de la fenetre 
        window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
      
        //Donne une titre a la fenetre ouverte gtk_box_pack_start(GTK_BOX(box1), button, TRUE, TRUE, 0);


        gtk_window_set_title (GTK_WINDOW (window), "BOUTOOOOONS");

        //Permet de quitter la fenetre via gestionnaire fenetre --> lie avec fonction de rappel 
        //destroy 
        gtk_signal_connect (GTK_OBJECT (window), "destroy", GTK_SIGNAL_FUNC (destroy), NULL);
        
        //Affichage de la fenetre 
        gtk_widget_show (window);
        //Definition de la largeur de la bordure du container 
        gtk_container_border_width (GTK_CONTAINER (window), 10);
    
        box1 = gtk_vbox_new(FALSE, 0);         
        box2 = gtk_hbox_new(FALSE, 0);         


        gtk_container_add (GTK_CONTAINER (window), box1);


        //Creation d'un nouveau bouton 
        button = gtk_button_new_with_label ("Je suis un bouton");
        button2 = gtk_button_new_with_label ("Et moi j'en suis un autre");
        button10 = gtk_button_new_with_label ("B10");
        button11 = gtk_toggle_button_new_with_label ("B11");
        buttonquit = gtk_button_new_with_label ("QUITTER");

        //Le bouton appelle la fonction "coucou" si on clique dessus
        gtk_signal_connect (GTK_OBJECT (button), "clicked", GTK_SIGNAL_FUNC(coucou), NULL);
        gtk_signal_connect (GTK_OBJECT (button2), "clicked", GTK_SIGNAL_FUNC(msg2), NULL);
        gtk_signal_connect (GTK_OBJECT (buttonquit), "clicked", GTK_SIGNAL_FUNC(destroy), NULL);

        //On peut aussi lui dire d'appeler une autre fonctions en meme temps, 
        //ici fermer la fenetre en plus
        gtk_signal_connect_object (GTK_OBJECT (button), "clicked", GTK_SIGNAL_FUNC (gtk_widget_destroy), GTK_OBJECT (window));


        //On met le bouton dans la fenetre 
       // gtk_container_add (GTK_CONTAINER (window), button);
        
        //Et si on le mettait dans une boite ? 
        gtk_box_pack_start(GTK_BOX(box1), button, TRUE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(box1), button2, TRUE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(box1), buttonquit, FALSE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box1), box2, FALSE, TRUE, 0);


        gtk_box_pack_start(GTK_BOX(box2), button11, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box2), button10, TRUE, TRUE, 0);

        gtk_widget_show (button);
        gtk_widget_show (button2);
        gtk_widget_show (button10);
        gtk_widget_show (button11);
        gtk_widget_show (buttonquit);
        gtk_widget_show (box1);
        gtk_widget_show (box2);
        gtk_widget_show (window);

        // On affiche d'abord le "window" pour eviter de voir d'abord la fenetre puis le bouton mais bien les deux
        // en meme temps 

        gtk_main ();
    
        return 0;
    }
