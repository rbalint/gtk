/* gtksidebarrow.h
 *
 * Copyright (C) 2015 Carlos Soriano <csoriano@gnome.org>
 *
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef GTK_SIDEBAR_ROW_H
#define GTK_SIDEBAR_ROW_H

#include <glib.h>
#include "gtklistbox.h"

G_BEGIN_DECLS

#define GTK_TYPE_SIDEBAR_ROW (gtk_sidebar_row_get_type())

G_DECLARE_FINAL_TYPE (GtkSidebarRow, gtk_sidebar_row, GTK, SIDEBAR_ROW, GtkListBoxRow)

struct _GtkSidebarRowClass
{
  GtkListBoxRowClass parent;
};

GtkSidebarRow *gtk_sidebar_row_new    (void);
GtkSidebarRow *gtk_sidebar_row_clone  (GtkSidebarRow *self);

/* Use these methods instead of gtk_widget_hide/show to use an animation */
void           gtk_sidebar_row_hide   (GtkSidebarRow *self,
                                       gboolean       inmediate);
void           gtk_sidebar_row_reveal (GtkSidebarRow *self);

G_END_DECLS

#endif /* GTK_SIDEBAR_ROW_H */
