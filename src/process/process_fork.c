/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:57:38 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/19 12:31:58 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "process.h"
#include "utils.h"

pid_t	process_fork(t_process *p)
{
	p->pid = fork();
	if (p->pid < 0)
		msh_abort("fork");
	if (p->pid)
	{
		ft_list_clear(&p->args, (t_gfunction) & ft_free);
		p->argv = ft_free(p->argv);
		ft_list_clear(&p->redirection, (t_gfunction) & redir_clear);
	}
	return (p->pid);
}
