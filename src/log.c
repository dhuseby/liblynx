/*
 * log.c
 * Copyright (C) David Huseby 2009 <dave@linuxprogrammer.org>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with main.c; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */

#include <stdio.h>
#include <stdarg.h>

#include "log.h"

#define MAX_LOG_MSG_SIZE (4096)

void log_msg(log_fn log, LOG_LEVEL const lvl, char const * const msg, ...)
{
    static char buf[MAX_LOG_MSG_SIZE];
    va_list ap;
    va_start(ap, msg);
    
    /* format the message */
    vsnprintf(buf, MAX_LOG_MSG_SIZE, msg, ap);

    /* log the message */
    if(log)
        (*log)(lvl, msg);

    va_end(ap);
}


