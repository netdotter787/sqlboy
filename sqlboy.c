#include <gtk/gtk.h>
#include <mysql/my_global.h>
#include <mysql/mysql.h>
#include "test.c"

int main(int argc, char *argv[]) {

  GtkWidget *window;
  GtkWidget *vbox;

  GtkWidget *menubar;
  GtkWidget *fileMenu;
  GtkWidget *fileMi;
  GtkWidget *quitMi;

  GtkWidget *statusbar;

  gtk_init(&argc, &argv);

  //Createa the window
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  //Set the GTK window title
  gtk_window_set_title(GTK_WINDOW(window), "Center");

  //Set the default size of the window
  gtk_window_set_default_size(GTK_WINDOW(window), 230, 150);

  //Set the postion of the GTK window
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  menubar = gtk_menu_bar_new();
  fileMenu = gtk_menu_new();

  fileMi = gtk_menu_item_new_with_label("File");
  quitMi = gtk_menu_item_new_with_label("Quit");

  gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi);

  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

  statusbar = gtk_statusbar_new();
  gtk_box_pack_end(GTK_BOX(vbox), statusbar, FALSE, TRUE, 0);

    //Connect the destroy command of the window to the gtk_main_quit
  g_signal_connect(G_OBJECT(window), "destroy",
      G_CALLBACK(gtk_main_quit), NULL);

  g_signal_connect(G_OBJECT(quitMi), "activate",
  	G_CALLBACK(gtk_main_quit), NULL);  

  //Show the widget we created aka - window
  gtk_widget_show_all(window);

  test();
  printf("MySQL client version: %s\n", mysql_get_client_info());

  gtk_main();

  return 0;
}