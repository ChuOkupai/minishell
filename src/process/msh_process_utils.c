/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_process_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:24:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/19 13:57:24 by asoursou         ###   ########.fr       */
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
	size_t i;
	size_t n;

	i = 0;
	n = ft_memsize((void **)p->argv);
	ft_putchar('(');
	while (i < n)
	{
		ft_printf("%s%c", p->argv[i], (i + 1 == n ? ')' : ' '));
		++i;
	}
	ft_putchar(' ');
	ft_list_print(p->redirection, (t_gprint) & print_redirect);
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
