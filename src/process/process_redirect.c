/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:13:42 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/08 18:15:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static int	redirect(const t_list *r)
{
	if (!r)
		return (0);
	if (redir_exec(r->content) < 0)
		return (-1);
	return (redirect(r->next));
}

int			process_redirect(const t_process *p)
{
	return (redirect(p->redirection));
}
