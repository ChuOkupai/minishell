/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:25:45 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 18:05:19 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H
# include <termios.h>
# include "history.h"

/*
** old_termios:	save the old termios settings
** fd:			input file descriptor
** eof:			end-of-file indicator
** init:		true if old_termios has been initialized
*/
typedef struct s_readline	t_readline;
typedef struct termios	t_termios;
struct	s_readline
{
	t_termios	old_termios;
	int			fd;
	bool		eof;
	bool		init;
};

/*
** Initialize the readline structure.
** Returns -1 on error, else 0.
*/
int		readline_init(t_readline *readline, const char *termtype, int fd);

/*
** Clear the readline structure.
*/
void	readline_clear(t_readline *readline);

/*
** Reads the next line.
** If history is not NULL, MSH_KEY_UP and MSH_KEY_DOWN are used to navigate
** through the command history.
** The allocated line must be passed to free.
** Returns NULL on error.
*/
char	*readline(t_readline *readline, const t_history *history,
		const char *prompt);

#endif
