/* puzzle15-window.c
 *
 * Copyright 2024 Todor Balabanov
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "puzzle15-config.h"
#include "puzzle15-window.h"

struct _Puzzle15Window
{
  GtkApplicationWindow  parent_instance;

  /* Template widgets */
  GtkHeaderBar        *header_bar;
};

G_DEFINE_TYPE (Puzzle15Window, puzzle15_window, GTK_TYPE_APPLICATION_WINDOW)

static void button_clicked(GtkButton *button, gpointer data) {
	g_print ("Hello World\n");
}

static void
puzzle15_window_class_init (Puzzle15WindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/eu/veldsoft/puzzle15/puzzle15-window.ui");
  gtk_widget_class_bind_template_child (widget_class, Puzzle15Window, header_bar);

	GtkWidget *button = GTK_WIDGET(gtk_builder_get_object(GTK_BUILDER(klass), "01"));
	g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), NULL);
}

static void
puzzle15_window_init (Puzzle15Window *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
