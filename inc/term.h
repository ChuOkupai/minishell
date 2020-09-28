/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:17:35 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 14:11:52 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_H
# define TERM_H
# include <curses.h>
# include <term.h>
# include "libft.h"

/*
** Free a termcaps structure.
** Returns NULL.
*/
void	*msh_term_clear(t_term *term);

/*
** Get the next character from the file f.
** The character value is a MSH_KEY (value > 255) or a char.
** Returns the next character, or FT_EOF on error or end-of-file.
*/
int		msh_term_getc(t_file *f);

/*
** Termcaps initialization.
** Returns NULL on error.
*/
t_term	*msh_term_init(const char *termtype);

/*
** Update termcaps buffer.
*/
void	msh_term_update(t_term *term);

#endif
