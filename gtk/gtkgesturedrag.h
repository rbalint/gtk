/* GTK - The GIMP Toolkit
 * Copyright (C) 2014, Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author(s): Carlos Garnacho <carlosg@gnome.org>
 */
#ifndef __GTK_GESTURE_DRAG_H__
#define __GTK_GESTURE_DRAG_H__

#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gtk/gtkwidget.h>
#include <gtk/gtkgesture.h>

G_BEGIN_DECLS

#define GTK_TYPE_GESTURE_DRAG         (gtk_gesture_drag_get_type ())
#define GTK_GESTURE_DRAG(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GTK_TYPE_GESTURE_DRAG, GtkGestureDrag))
#define GTK_GESTURE_DRAG_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST ((k), GTK_TYPE_GESTURE_DRAG, GtkGestureDragClass))
#define GTK_IS_GESTURE_DRAG(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GTK_TYPE_GESTURE_DRAG))
#define GTK_IS_GESTURE_DRAG_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), GTK_TYPE_GESTURE_DRAG))
#define GTK_GESTURE_DRAG_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GTK_TYPE_GESTURE_DRAG, GtkGestureDragClass))

typedef struct _GtkGestureDrag GtkGestureDrag;
typedef struct _GtkGestureDragClass GtkGestureDragClass;

struct _GtkGestureDrag
{
  GtkGesture parent_instance;
};

struct _GtkGestureDragClass
{
  GtkGestureClass parent_class;

  void (* drag_begin)  (GtkGestureDrag *gesture,
                        gdouble         start_x,
                        gdouble         start_y);
  void (* drag_update) (GtkGestureDrag *gesture,
                        gdouble         offset_x,
                        gdouble         offset_y);
  void (* drag_end)    (GtkGestureDrag *gesture,
                        gdouble         offset_x,
                        gdouble         offset_y);
  /*<private>*/
  gpointer padding[10];
};

GDK_AVAILABLE_IN_3_14
GType        gtk_gesture_drag_get_type          (void) G_GNUC_CONST;

GDK_AVAILABLE_IN_3_14
GtkGesture * gtk_gesture_drag_new               (GtkWidget      *widget);

GDK_AVAILABLE_IN_3_14
gboolean     gtk_gesture_drag_get_start_point   (GtkGestureDrag *gesture,
                                                 gint           *x,
                                                 gint           *y);
GDK_AVAILABLE_IN_3_14
gboolean     gtk_gesture_drag_get_current_point (GtkGestureDrag *gesture,
                                                 gint           *x,
                                                 gint           *y);

G_END_DECLS

#endif /* __GTK_GESTURE_DRAG_H__ */