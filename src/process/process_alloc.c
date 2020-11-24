/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:43:10 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 15:22:25 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "utils.h"

void		redirect_clear(t_redirect *r)
{
	ft_delete(r->path);
	ft_delete(r);
}

void		process_clear(t_process *p)
{
	ft_deletetab((void**)p->argv, ft_memsize((void **)p->argv));
	ft_list_clear(&p->redirection, (t_gfunction) & redirect_clear);
	ft_delete(p);
}

t_process	*process_new(char **argv, t_list *redirection)
{
	t_process *p;

	if (!(p = ft_new(sizeof(t_process))))
		msh_abort("process");
	p->argv = argv;
	p->redirection = redirection;
	return (p);
}

t_redirect	*redirect_new(t_redirect_type type, char *path)
{
	t_redirect *r;

	if (!(r = ft_new(sizeof(t_redirect))))
		msh_abort("process");
	r->type = type;
	r->path = path;
	return (r);
}
