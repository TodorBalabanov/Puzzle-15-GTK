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
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "config.h"

#include "puzzle15-window.h"

struct _Puzzle15Window
{
	GtkApplicationWindow  parent_instance;

	GtkHeaderBar        *header_bar;
  GtkButton           *button01;
  GtkButton           *button02;
  GtkButton           *button03;
  GtkButton           *button04;
  GtkButton           *button05;
  GtkButton           *button06;
  GtkButton           *button07;
  GtkButton           *button08;
  GtkButton           *button09;
  GtkButton           *button10;
  GtkButton           *button11;
  GtkButton           *button12;
  GtkButton           *button13;
  GtkButton           *button14;
  GtkButton           *button15;
  GtkButton           *button00;
};

G_DEFINE_FINAL_TYPE (Puzzle15Window, puzzle15_window, GTK_TYPE_APPLICATION_WINDOW)

static void button_clicked(GtkButton *button, gpointer data) {
	g_print ("%s\n", gtk_button_get_label(button));
}

static void
puzzle15_window_class_init (Puzzle15WindowClass *klass)
{
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

	gtk_widget_class_set_template_from_resource (widget_class, "/eu/veldsoft/puzzle15/puzzle15-window.ui");
	gtk_widget_class_bind_template_child (widget_class, Puzzle15Window, header_bar);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button01);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button02);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button03);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button04);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button05);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button06);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button07);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button08);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button09);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button10);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button11);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button12);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button13);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button14);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button15);
  gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), Puzzle15Window, button00);
}

static void
puzzle15_window_init (Puzzle15Window *self)
{
	gtk_widget_init_template (GTK_WIDGET (self));
  g_signal_connect(self->button01, "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect(self->button02, "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect(self->button03, "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect(self->button04, "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect(self->button05, "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect(self->button06, "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect(self->button07, "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect(self->button08, "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect(self->button09, "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect(self->button10, "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect(self->button11, "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect(self->button12, "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect(self->button13, "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect(self->button14, "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect(self->button15, "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect(self->button00, "clicked", G_CALLBACK(button_clicked), NULL);
}

