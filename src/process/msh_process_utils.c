/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_process_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:24:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/16 20:38:25 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "process.h"
#include "utils.h"
#include "libft.h"

void			msh_redirection_clear(t_redirection *r)
{
	free(r->path);
	free(r);
}

void			msh_process_clear(t_process *p)
{
	free(p->argv);
	ft_list_clear(&(p->redirection), (t_gfunction) & msh_redirection_clear);
	free(p);
}

t_process		*msh_process_new(char **argv, t_list *redirection)
{
	t_process *p;

	if (!(p = malloc(sizeof(t_process))))
		msh_abort("parser");
	p->argv = argv;
	p->redirection = redirection;
	return (p);
}

t_redirection	*msh_redirection_new(t_redirection_type type, char *path)
{
	t_redirection	*r;

	if (!(r = malloc(sizeof(t_redirection))))
		msh_abort("parser");
	r->type = type;
	r->path = path;
	return (r);
}
