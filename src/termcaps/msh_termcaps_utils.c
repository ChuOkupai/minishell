/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_termcaps_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:20:46 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/16 19:55:37 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "libft.h"
#include "termcaps.h"

void	*msh_termcaps_clear(t_term *term)
{
	if (term)
	{
		ft_memdel(term->type);
		ft_memdel(term->buffer);
		free(term);
	}
	return (NULL);
}

t_term	*msh_termcaps_init(const char *termtype)
{
	t_term	*term;
	int		r;

	if (!termtype)
	{
		errno = EINVAL;
		return (NULL);
	}
	if (!(term = ft_calloc(1, sizeof(t_term))))
		return (NULL);
	term->type = ft_strdup(termtype);
	term->buffer = ft_calloc(2048, sizeof(char));
	if (!term->type || !term->buffer ||
	!(r = tgetent(term->buffer, termtype)) || r < 0)
		return (msh_termcaps_clear(term));
	return (term);
}

void	msh_termcaps_update(t_term *term)
{
	tgetent(term->buffer, term->type);
}
