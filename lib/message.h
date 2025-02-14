/* Dia -- an diagram creation/manipulation program
 * Copyright (C) 1998 Alexander Larsson
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#pragma once

#include <stdarg.h>

G_BEGIN_DECLS

enum ShowAgainStyle {
  ALWAYS_SHOW,
  SUGGEST_SHOW_AGAIN,
  SUGGEST_NO_SHOW_AGAIN
};

typedef void (*MessageInternal) (const char          *title,
                                 enum ShowAgainStyle  showAgain,
                                 char const          *fmt,
                                 va_list              args);

void        set_message_func       (MessageInternal  func);
void        message                (const char      *title,
                                    const char      *format,
                                    ...) G_GNUC_PRINTF (2, 3);
void        message_notice         (const char      *format,
                                    ...) G_GNUC_PRINTF (1, 2);
void        message_warning        (const char      *format,
                                    ...) G_GNUC_PRINTF (1, 2);
void        message_error          (const char      *format,
                                    ...) G_GNUC_PRINTF (1, 2);
void        dia_log_message        (const char      *format,
                                    ...) G_GNUC_PRINTF (1, 2);
void        dia_log_message_enable (gboolean         yes);
/* also declared in dia_dirs.h, where I think it does not belong! --hb */
const char *dia_message_filename   (const char      *filename);

G_END_DECLS
