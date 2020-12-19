/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_mark_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:49:47 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/11 15:12:26 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

void		job_mark_process(t_list *j, pid_t pid, int status)
{
	if (!j)
		return ;
	if (process(j->content)->pid == pid)
		process_terminate(j->content, status);
	else
		job_mark_process(j->next, pid, status);
}
