/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:43:10 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/14 17:31:06 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

t_process	*process_new(t_list *args, t_list *redirection)
{
	t_process *p;

	p = ft_malloc(sizeof(t_process));
	p->args = args;
	p->argv = NULL;
	p->redirection = redirection;
	p->terminated = false;
	p->pid = 0;
	return (p);
}
