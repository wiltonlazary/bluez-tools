/*
 *
 *  bluez-tools - a set of tools to manage bluetooth devices for linux
 *
 *  Copyright (C) 2010  Alexander Orlenko <zxteam@gmail.com>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef __HELPERS_H
#define __HELPERS_H

#include <stdio.h>

#include <glib.h>

#include "bluez-api.h"
#ifdef OBEX_SUPPORT
#include "obexd-api.h"
#endif

/* DBus helpers */
gboolean intf_supported(const gchar *dbus_service_name, const gchar *dbus_object_path, const gchar *intf_name);

/* BlueZ helpers */
Adapter *find_adapter(const gchar *name, GError **error);
Device *find_device(Adapter *adapter, const gchar *name, GError **error);

/* Others helpers */
#define exit_if_error(error) G_STMT_START{ \
if (error) { \
	g_printerr("%s: %s\n", (error->domain == DBUS_GERROR && error->code == DBUS_GERROR_REMOTE_EXCEPTION && dbus_g_error_get_name(error) != NULL && strlen(dbus_g_error_get_name(error)) ? dbus_g_error_get_name(error) : "Error"), error->message); \
	exit(EXIT_FAILURE); \
}; }G_STMT_END

inline int xtoi(const gchar *str)
{
	int i = 0;
	sscanf(str, "0x%x", &i);
	return i;
}

const gchar *uuid2name(const gchar *uuid);
const gchar *name2uuid(const gchar *name);

#endif /* __HELPERS_H */

