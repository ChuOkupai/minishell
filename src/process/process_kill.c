/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_kill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:33:56 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/14 17:31:02 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "process.h"

void	process_kill(const t_process *p, int signum)
{
	if (!p->terminated && p->pid)
		kill(p->pid, signum);
}
