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

static GtkButton *buttons[4][4];

static void swap_labels(GtkButton *a, GtkButton *b) {
	if(strcmp(gtk_button_get_label(a),"  ") != 0) {
		return;
	}

	gtk_button_set_label(a, gtk_button_get_label(b));
	gtk_button_set_label(b, "  ");
}

static void button_clicked(GtkButton *button, gpointer data) {
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
		  if(buttons[i][j] == button) {
				if(0 <= i-1) {
					swap_labels(buttons[i-1][j], buttons[i][j]);
				}
				if(0 <= j-1) {
					swap_labels(buttons[i][j-1], buttons[i][j]);
				}
				if(i+1 <= 3) {
					swap_labels(buttons[i+1][j], buttons[i][j]);
				}
				if(j+1 <= 3) {
					swap_labels(buttons[i][j+1], buttons[i][j]);
				}

				return;
			}
		}
	}
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

	buttons[0][0] = self->button01;
	buttons[1][0] = self->button02;
	buttons[2][0] = self->button03;
	buttons[3][0] = self->button04;
	buttons[0][1] = self->button05;
	buttons[1][1] = self->button06;
	buttons[2][1] = self->button07;
	buttons[3][1] = self->button08;
	buttons[0][2] = self->button09;
	buttons[1][2] = self->button10;
	buttons[2][2] = self->button11;
	buttons[3][2] = self->button12;
	buttons[0][3] = self->button13;
	buttons[1][3] = self->button14;
	buttons[2][3] = self->button15;
	buttons[3][3] = self->button00;

	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
		  g_signal_connect(buttons[i][j], "clicked", G_CALLBACK(button_clicked), NULL);
		}
	}
}

