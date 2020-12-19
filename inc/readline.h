/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:25:45 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/18 20:20:31 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H
# include "libft.h"

/*
** stream:	input file stream
** buf:		temporary buffer (in case of Ctrl+C)
*/
typedef struct s_readline	t_readline;
struct	s_readline
{
	t_file	*stream;
	char	*buf;
};

void	readline_clear(t_readline *readline);
int		readline_init(t_readline *readline);

/*
** Stores the current line to the buffer.
** This line will be automatically send for the next call to readline.
*/
void	readline_keep(t_readline *readline, char *buf);

/*
** Reads the next line.
** The allocated line must be passed to free.
** Returns NULL on error.
*/
char	*readline(t_readline *readline, const char *prompt);

#endif
