/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * cdtsim.h
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

#ifndef _CDTSIM_
#define _CDTSIM_

#include "config.h"
#include <gtk/gtk.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


G_BEGIN_DECLS

#define CDTSIM_TYPE_APPLICATION             (cdtsim_get_type ())
#define CDTSIM_APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), CDTSIM_TYPE_APPLICATION, Cdtsim))
#define CDTSIM_APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), CDTSIM_TYPE_APPLICATION, CdtsimClass))
#define CDTSIM_IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CDTSIM_TYPE_APPLICATION))
#define CDTSIM_IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), CDTSIM_TYPE_APPLICATION))
#define CDTSIM_APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), CDTSIM_TYPE_APPLICATION, CdtsimClass))

typedef struct _CdtsimClass CdtsimClass;
typedef struct _Cdtsim Cdtsim;


struct _CdtsimClass
{
	GtkApplicationClass parent_class;
};

struct _Cdtsim
{
	GtkApplication parent_instance;

};

GType cdtsim_get_type (void) G_GNUC_CONST;
Cdtsim *cdtsim_new (void);

/* Callbacks */
void send_packet (GtkButton *send, GObject *data);
void quit_app (GtkButton* button, GApplication *app);

G_END_DECLS

#endif /* _APPLICATION_H_ */

