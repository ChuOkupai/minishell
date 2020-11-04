/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_process_alloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:43:10 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/04 16:15:39 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "utils.h"

void			msh_redirect_clear(t_redirection *r)
{
	ft_delete(r->path);
	ft_delete(r);
}

void			msh_process_clear(t_process *p)
{
	ft_deletetab((void**)p->argv, ft_memsize((void **)p->argv));
	ft_list_clear(&p->redirection, (t_gfunction) & msh_redirect_clear);
	ft_delete(p);
}

t_process		*msh_process_new(char **argv, t_list *redirection)
{
	t_process *p;

	if (!(p = ft_new(sizeof(t_process))))
		msh_abort("process");
	p->argv = argv;
	p->redirection = redirection;
	return (p);
}

t_redirection	*msh_redirect_new(t_redirect_type type, char *path)
{
	t_redirection *r;

	if (!(r = ft_new(sizeof(t_redirection))))
		msh_abort("process");
	r->type = type;
	r->path = path;
	return (r);
}
