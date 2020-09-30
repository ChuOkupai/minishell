/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:25:45 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/30 17:11:58 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H
# include <termios.h>
# include "libft.h"
# include "history.h"

/*
** old_termios:	save the old termios settings
** stream:		input file stream
** buf:			line buffer
** size:		current buffer size
** bufsize:		max buffer size
** init:		true if old_termios has been initialized
*/
typedef struct s_readline	t_readline;
typedef struct termios	t_termios;
struct	s_readline
{
	t_termios	old_termios;
	t_file		*stream;
	char		*buf;
	size_t		size;
	size_t		bufsize;
	bool		init;
};

/*
** Initialize the readline structure.
** Returns -1 on error, else 0.
*/
int		msh_readline_init(t_readline *readline, const char *termtype);

/*
** Clear the readline structure.
*/
void	msh_readline_clear(t_readline *readline);

/*
** Reads the next line.
** If history is not NULL, MSH_KEY_UP and MSH_KEY_DOWN are used to navigate
** through the command history.
** The line must be passed to free.
** Returns NULL on error.
*/
char	*msh_readline(t_readline *readline, const t_history *history,
		const char *prompt);

#endif
