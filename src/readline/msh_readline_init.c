/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_readline_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:52:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/30 17:24:55 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>
#include <unistd.h>
#include "readline.h"

int	msh_readline_init(t_readline *r, const char *termtype)
{
	t_termios termios;

	r->init = false;
	r->buf = NULL;
	r->size = 0;
	r->bufsize = 0;
	if (!(r->stream = ft_fdopen(STDIN_FILENO, "r")))
		return (-1);
	return (0);
	if (tgetent(NULL, termtype) == ERR ||
	tcgetattr(STDIN_FILENO, &r->old_termios) < 0)
		return (-1);
	r->init = true;
	termios = r->old_termios;
	termios.c_lflag &= ~(ICANON | ECHO);
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios) < 0)
		return (-1);
	return (0);
}
