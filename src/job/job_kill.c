/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_kill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:33:56 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/07 18:59:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	job_kill(const t_list *j, int signum)
{
	if (!j)
		return ;
	process_kill(j->content, signum);
	job_kill(j->next, signum);
}
