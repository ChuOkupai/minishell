/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_readline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:22:39 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 17:59:09 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	msh_shell_readline(t_shell *s)
{
	t_line	*l;
	int		c;

	l = &s->line;
	if (l->ps1)
		ft_putstr(l->ps1);
	l->size = 0;
	while (l->size < l->alloc_size - 1 && (c = ft_fgetc(l->stream)) != FT_EOF)
	{
		l->buf[l->size++] = c;
		ft_putchar(c);
		if (c == '\n')
			break ;
	}
	l->buf[l->size] = '\0';
	return (-(ft_feof(l->stream) || ft_ferror(l->stream)));
}
