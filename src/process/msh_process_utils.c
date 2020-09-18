/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_process_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:24:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/18 18:15:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "process.h"
#include "utils.h"
#include "libft.h"

void				msh_redirect_clear(t_redirection *r)
{
	free(r->path);
	free(r);
}

void				msh_process_clear(t_process *p)
{
	char **argv;

	argv = p->argv;
	while (*argv)
		free(*argv++);
	free(p->argv);
	ft_list_clear(&(p->redirection), (t_gfunction) & msh_redirect_clear);
	free(p);
}

t_process			*msh_process_new(char **argv, t_list *redirection)
{
	t_process *p;

	if (!(p = malloc(sizeof(t_process))))
		msh_abort("parser");
	p->argv = argv;
	p->redirection = redirection;
	return (p);
}

t_redirection		*msh_redirect_new(t_redirection_type type, char *path)
{
	t_redirection	*r;

	if (!(r = malloc(sizeof(t_redirection))))
		msh_abort("parser");
	r->type = type;
	r->path = path;
	return (r);
}

t_redirection_type	msh_redirect_type(const char *value)
{
	if (!ft_strcmp(value, "<"))
		return (INPUT);
	else if (!ft_strcmp(value, "<<"))
		return (HEREDOC_INPUT);
	else if (!ft_strcmp(value, ">"))
		return (OUTPUT);
	else if (!ft_strcmp(value, ">>"))
		return (APPENDING_OUTPUT);
	return (-1);
}

void				msh_print_redirection(t_redirection *r)
{
	if (r->type == INPUT)
		ft_printf("< %s", r->path);
	else if (r->type == HEREDOC_INPUT)
		ft_printf("<< %s", r->path);
	else if (r->type == OUTPUT)
		ft_printf("> %s", r->path);
	else if (r->type == APPENDING_OUTPUT)
		ft_printf(">> %s", r->path);
}


void				msh_process_print(t_process *p)
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
	ft_list_print(p->redirection, (t_gprint) & msh_print_redirection);
}
