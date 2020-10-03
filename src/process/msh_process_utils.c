/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_process_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:24:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/03 11:38:22 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "process.h"

static void		print_redirect(t_redirection *r)
{
	if (r->type == REDIR_INPUT)
		ft_printf("< %s", r->path);
	else if (r->type == REDIR_HEREDOC_INPUT)
		ft_printf("<< %s", r->path);
	else if (r->type == REDIR_OUTPUT)
		ft_printf("> %s", r->path);
	else if (r->type == REDIR_APPENDING_OUTPUT)
		ft_printf(">> %s", r->path);
}

void			msh_process_print(t_process *p)
{
	size_t	i;
	size_t	n;
	t_list	*l;

	i = 0;
	n = ft_memsize((void **)p->argv);
	l = p->redirection;
	while (i < n)
	{
		ft_putstr(p->argv[i++]);
		if (i < n || l)
			ft_putchar(' ');
	}
	while (l)
	{
		print_redirect(l->content);
		if ((l = l->next))
			ft_putchar(' ');
	}
}

t_redirect_type	msh_redirect_type(const char *value)
{
	if (!ft_strcmp(value, "<"))
		return (REDIR_INPUT);
	else if (!ft_strcmp(value, "<<"))
		return (REDIR_HEREDOC_INPUT);
	else if (!ft_strcmp(value, ">"))
		return (REDIR_OUTPUT);
	else if (!ft_strcmp(value, ">>"))
		return (REDIR_APPENDING_OUTPUT);
	return (-1);
}
