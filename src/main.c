//#include "life.h"

#include <gtk/gtk.h>

//#include <stdio.h>
//#include <unistd.h>

void create_window(GtkWidget** window, gint width, gint height);
void create_grid(GtkWidget** grid, GtkWidget** window, const gchar* name);
void include_css();

int main(int argc, char* argv[])
{
    /*
    unsigned char field[FIELD_SIZE][FIELD_SIZE];

    unsigned char* figure;
    int nlines, nrows;
    int check_input;
    check_input = input(&figure, &nlines, &nrows);
    if (check_input == 1) {
        printf("Err input\n");
        return -1;
    }

    game_of_life(field, figure, nlines, nrows);
    */
    GtkWidget *window, *grid;

    gtk_init(&argc, &argv);

    include_css();

    create_window(&window, 800, 600);

    create_grid(&grid, &window, "grid");

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

void create_window(GtkWidget** window, gint width, gint height)
{
    /*Создание окна*/
    *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(*window), "Game of Life");
    gtk_window_set_default_size(GTK_WINDOW(*window), width, height);
    gtk_window_set_resizable(GTK_WINDOW(*window), TRUE);
    g_signal_connect(*window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
}

void create_grid(GtkWidget** grid, GtkWidget** window, const gchar* name)
{
    /*Создание сетки*/
    *grid = gtk_grid_new();
    gtk_grid_set_row_homogeneous(GTK_GRID(*grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(*grid), TRUE);
    gtk_widget_set_name(*grid, name);
    gtk_container_add(GTK_CONTAINER(*window), *grid);
}

void include_css() {
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;

    provider = gtk_css_provider_new();
    display = gdk_display_get_default();
    screen = gdk_display_get_default_screen(display);
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    const gchar *myCssFile = "grid.css";
    GError *error = 0;

    gtk_css_provider_load_from_file(provider, g_file_new_for_path(myCssFile), &error);
    g_object_unref(provider);
}
