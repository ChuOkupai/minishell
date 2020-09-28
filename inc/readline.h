/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:25:45 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 21:37:48 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H
# include <termios.h>
# include "libft.h"

/*
** list:		list of lines in history (char*)
** size:		current size of history
** histsize:	max size of history ($HISTSIZE)
*/
typedef struct s_history	t_history;
struct	s_history
{
	t_list	*list;
	size_t	size;
	size_t	histsize;
};

/*
** old_termios:	save the old termios settings
** history:		history structure
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
	t_history	history;
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
** Sets a new history size (0 by default).
*/
void	msh_readline_set_histsize(t_readline *readline, size_t size);

/*
** Reads the next line.
** The line must be passed to free.
** Returns NULL on error.
*/
char	*msh_readline(t_readline *readline, const char *prompt);

#endif
