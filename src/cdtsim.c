/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * cdtsim.c
 * Copyright (C) 2017 Dirk Gottschalk <dirk.gottschalk1980@googlemail.com>
 * 
 * cdtsim is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * cdtsim is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "cdtsim.h"




G_DEFINE_TYPE (Cdtsim, cdtsim, GTK_TYPE_APPLICATION);

/* ANJUTA: Macro CDTSIM_APPLICATION gets Cdtsim - DO NOT REMOVE */

/* Create a new window loading a file */
static void cdtsim_new_window (GApplication *app, GFile *file) {
	/* Create window */
	GtkWidget *window;
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), PACKAGE_STRING);	
	gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));

	/* Create vertical box */
	GtkWidget *vbox;
	vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
	gtk_container_add (GTK_CONTAINER (window), GTK_WIDGET(vbox));

	/* Destination information */
	GtkWidget *hbox1;
	hbox1 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);

	GtkWidget *target_label;
	target_label = gtk_label_new ("Target Host:");

	GtkWidget *target_input;
	target_input = gtk_entry_new();

	GtkWidget *port_label;
	port_label = gtk_label_new ("Port:");

	GtkWidget *port_input;
	port_input = gtk_entry_new();

	/* Pack hbox1 */
	gtk_box_pack_start (GTK_BOX (hbox1),
	                    GTK_WIDGET (target_label), TRUE, FALSE, 5);

	gtk_box_pack_start (GTK_BOX (hbox1),
	                    GTK_WIDGET (target_input), TRUE, FALSE, 5);

	gtk_box_pack_start (GTK_BOX (hbox1),
	                    GTK_WIDGET (port_label), TRUE, FALSE, 5);

	gtk_box_pack_start (GTK_BOX (hbox1),
	                    GTK_WIDGET (port_input), TRUE, FALSE, 5);


	/* Second row with entry for cdt packet */

	GtkWidget *hbox2;
	hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);

	GtkWidget *data_label;
	data_label = gtk_label_new ("CDT data:");

	GtkWidget *data_input;
	data_input = gtk_entry_new();


	/* Pack hbox2 */
	gtk_box_pack_start (GTK_BOX (hbox2),
	                    GTK_WIDGET (data_label), TRUE, FALSE ,5);

	gtk_box_pack_start (GTK_BOX (hbox2),
	                    GTK_WIDGET (data_input), TRUE, FALSE ,5);


	/* The buttons */
	GtkWidget *buttonbox;
	buttonbox = gtk_button_box_new ( GTK_ORIENTATION_HORIZONTAL );

	GtkWidget *send_button;
	send_button = gtk_button_new_with_label ("Send");

	GtkWidget *quit_button;
	quit_button = gtk_button_new_with_label ("Quit");

	gtk_box_pack_start (GTK_BOX (buttonbox),
	                    GTK_WIDGET (quit_button), TRUE, FALSE ,5);

	gtk_box_pack_start (GTK_BOX (buttonbox),
	                    GTK_WIDGET (send_button), TRUE, FALSE ,5);

	/* Create statusbar */
	GtkWidget *statusbar;
	statusbar = gtk_statusbar_new ();
	

		
	/* Pack vertical box */
	gtk_box_pack_start (GTK_BOX (vbox),
	                    GTK_WIDGET (hbox1), TRUE, FALSE, 5);

	gtk_box_pack_start (GTK_BOX (vbox),
	                    GTK_WIDGET (hbox2), TRUE, FALSE, 5);

	gtk_box_pack_start (GTK_BOX (vbox),
	                    GTK_WIDGET (buttonbox), TRUE, FALSE, 5);

	gtk_box_pack_start (GTK_BOX (vbox),
	                    GTK_WIDGET (statusbar), TRUE, FALSE, 5);


	/* Add data to Callback */

	g_object_set_data (G_OBJECT (send_button), "target", target_input);
	g_object_set_data (G_OBJECT (send_button), "port", port_input);
	g_object_set_data (G_OBJECT (send_button), "data", data_input);
	g_object_set_data (G_OBJECT (send_button), "statusbar", statusbar);
	

	/* Exit when the window is closed */
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	g_signal_connect (send_button, "clicked", G_CALLBACK (send_packet),
	                  send_button);

	g_signal_connect (quit_button, "clicked", G_CALLBACK (gtk_main_quit),
	                  NULL);

	gtk_widget_show_all (GTK_WIDGET (window));
}


/* GApplication implementation */
static void
cdtsim_activate (GApplication *application)
{
	cdtsim_new_window (application, NULL);
}

static void
cdtsim_open (GApplication  *application,
                     GFile        **files,
                     gint           n_files,
                     const gchar   *hint)
{
	gint i;

	for (i = 0; i < n_files; i++)
		cdtsim_new_window (application, files[i]);
}

static void
cdtsim_init (Cdtsim *object)
{
}

static void
cdtsim_finalize (GObject *object)
{
	G_OBJECT_CLASS (cdtsim_parent_class)->finalize (object);
}

static void
cdtsim_class_init (CdtsimClass *klass)
{
	G_APPLICATION_CLASS (klass)->activate = cdtsim_activate;
	G_APPLICATION_CLASS (klass)->open = cdtsim_open;

	G_OBJECT_CLASS (klass)->finalize = cdtsim_finalize;
}

Cdtsim *
cdtsim_new (void)
{
	return g_object_new (cdtsim_get_type (),
	                     "application-id", "org.gnome.cdtsim",
	                     "flags", G_APPLICATION_HANDLES_OPEN,
	                     NULL);
}

