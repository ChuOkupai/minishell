/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:17:35 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/16 19:30:03 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H
# include <curses.h>
# include <term.h>

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
** Termcaps initialization.
** Returns NULL on error.
*/
t_term	*msh_termcaps_init(const char *termtype);

/*
** Update termcaps buffer.
*/
void	msh_termcaps_update(t_term *term);

#endif
