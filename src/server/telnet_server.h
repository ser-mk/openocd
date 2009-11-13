/***************************************************************************
 *   Copyright (C) 2005 by Dominic Rath                                    *
 *   Dominic.Rath@gmx.de                                                   *
 *                                                                         *
 *   Copyright (C) 2007,2008 Øyvind Harboe                                 *
 *   oyvind.harboe@zylin.com                                               *
 *                                                                         *
 *   Copyright (C) 2008 by Spencer Oliver                                  *
 *   spen@spen-soft.co.uk                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef TELNET_SERVER_H
#define TELNET_SERVER_H

#include "server.h"

#define TELNET_BUFFER_SIZE (1024)

#define TELNET_OPTION_MAX_SIZE (128)
#define TELNET_LINE_HISTORY_SIZE (128)
#define TELNET_LINE_MAX_SIZE (256)

enum telnet_states
{
	TELNET_STATE_DATA,
	TELNET_STATE_IAC,
	TELNET_STATE_SB,
	TELNET_STATE_SE,
	TELNET_STATE_WILL,
	TELNET_STATE_WONT,
	TELNET_STATE_DO,
	TELNET_STATE_DONT,
	TELNET_STATE_ESCAPE,
};

struct telnet_connection
{
	char *prompt;
	enum telnet_states state;
	char line[TELNET_LINE_MAX_SIZE];
	int line_size;
	int line_cursor;
	char option[TELNET_OPTION_MAX_SIZE];
	int option_size;
	char last_escape;
	char *history[TELNET_LINE_HISTORY_SIZE];
	int next_history;
	int current_history;
	int closed;
};

struct telnet_service
{
	char *banner;
};

int telnet_init(char *banner);
int telnet_register_commands(command_context_t *command_context);

#endif /* TELNET_SERVER_H */
