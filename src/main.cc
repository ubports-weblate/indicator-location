/*
 * Copyright 2013 Canonical Ltd.
 *
 * Authors:
 *   Charles Kerr <charles.kerr@canonical.com>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <locale.h>

#include <QtGlobal>

#include <glib/gi18n.h>
#include <glib.h>

#include "app.h"

/***
****
***/

static gboolean
on_idle (gpointer unused)
{
  Q_UNUSED (unused);

  GMainContext * context = g_main_context_default ();

  g_message ("hello world %p", context);
  return G_SOURCE_CONTINUE;
};

int
main (int argc, char ** argv)
{
  /* boilerplate i18n */
  setlocale (LC_ALL, "");
  bindtextdomain (GETTEXT_PACKAGE, GNOMELOCALEDIR);
  textdomain (GETTEXT_PACKAGE);

  g_timeout_add_seconds (2, on_idle, NULL);

  MyApp app (argc, argv);
  app.exec ();
  return 0;
}
