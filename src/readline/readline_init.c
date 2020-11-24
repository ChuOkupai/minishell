/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:52:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 18:05:22 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>
#include <unistd.h>
#include "readline.h"

int	readline_init(t_readline *r, const char *termtype, int fd)
{
	t_termios	termios;

	r->init = false;
	r->fd = fd;
	r->eof = false;
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
