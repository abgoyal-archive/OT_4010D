/* -*- mode: C; c-file-style: "gnu" -*- */
/* dispatch.h  Message dispatcher
 *
 * Copyright (C) 2003  CodeFactory AB
 *
 * Licensed under the Academic Free License version 2.1
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef BUS_DISPATCH_H
#define BUS_DISPATCH_H

#include <dbus/dbus.h>
#include "connection.h"

dbus_bool_t bus_dispatch_add_connection    (DBusConnection *connection);
void        bus_dispatch_remove_connection (DBusConnection *connection);
dbus_bool_t bus_dispatch_matches           (BusTransaction *transaction,
                                            DBusConnection *sender,
                                            DBusConnection *recipient,
                                            DBusMessage    *message,
                                            DBusError      *error);

#endif /* BUS_DISPATCH_H */
