/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/**************************************************************************
 *            callbacks.c
 *
 *  Fr Mai 26 05:26:45 2017
 *  Copyright  2017  Dirk Gottschalk
 *  <dirk.gottschalk1980@googlemail.com>
 **************************************************************************/

#include <glib.h>
#include "garmin-servertest.h"
#include "helpers.h"

void send_packet (GtkButton *send, GObject *data) {

	/* Get data from GObject */
	GtkEntry *target_input = g_object_get_data (G_OBJECT(data), "target");
	GtkEntry *port_input = g_object_get_data (G_OBJECT(data), "port");
	GtkEntry *data_input = g_object_get_data (G_OBJECT(data), "data");
	GtkStatusbar *statusbar = g_object_get_data (G_OBJECT(data), "statusbar");
	
	char *target = (char *) gtk_entry_get_text (target_input);
	char *port_tmp = (char *) gtk_entry_get_text (port_input);
	unsigned char *queue_data = (unsigned char *) gtk_entry_get_text (data_input);
	
	uint port = (uint) atoi (port_tmp);

	size_t datalen = strlen ((char *) queue_data);

	int pack_size = datalen + 7; 
	unsigned char packet[pack_size];

	int tx_datalen = datalen + 1; 

	packet[0] = 16;
	packet[1] = 217;
	packet[2] = tx_datalen;
	packet[3] = 0;
	strncpy((unsigned char *)packet[4], queue_data, datalen);
	packet[pack_size - 3] = checksum ( packet, datalen + 4 );
	packet [pack_size - 2] = 16;
	packet [pack_size - 1] = 3;
	
	GError *sockerr;
	GSocket *sock;
	GSocketAddress *dst;

	sockerr = NULL;
	sock = g_socket_new (G_SOCKET_FAMILY_IPV4, G_SOCKET_TYPE_DATAGRAM,
	                              G_SOCKET_PROTOCOL_UDP, &sockerr);	
	dst = g_inet_socket_address_new_from_string (target, port);

	/* TODO: Update statusbar with error or success */
	if ( g_socket_send_to (sock, dst, (const gchar*) packet, pack_size, NULL,
	                       &sockerr) == -1 ) {
		// gtk_statusbar_push ()
	}
}