/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:17:35 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/26 19:24:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H
# include <curses.h>
# include <term.h>
# include "libft.h"

/*
** type:	terminal type ($TERM variable)
** buffer:	termcaps buffer
*/
typedef struct s_term	t_term;
struct	s_term
{
	char	*type;
	char	*buffer;
};

/*
** Free a termcaps structure.
** Returns NULL.
*/
void	*msh_termcaps_clear(t_term *term);

/*
** Get the next character from the file f.
** The character value is a MSH_KEY (value > 255) or a char.
** Returns the next character, or FT_EOF on error or end-of-file.
*/
int		msh_termcaps_getc(t_file *f);

/*
** Termcaps initialization.
** Returns NULL on error.
*/
t_term	*msh_termcaps_init(const char *termtype);

/*
** Update termcaps buffer.
*/
void	msh_termcaps_update(t_term *term);

#endif
