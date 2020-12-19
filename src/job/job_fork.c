/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:49:19 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/08 18:34:24 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "job.h"
#include "utils.h"

void	job_fork(t_list *j, t_shell *s, int input)
{
	int		mpipe[2];
	pid_t	pid;

	if (!j)
		return ;
	if (!j->next)
		mpipe[STDOUT_FILENO] = STDOUT_FILENO;
	else if (pipe(mpipe) < 0)
		msh_abort("pipe");
	pid = process_fork(j->content);
	job_close_fd(input, mpipe[STDOUT_FILENO], !pid);
	if (!pid)
		process_exec(j->content, s);
	job_fork(j->next, s, mpipe[STDIN_FILENO]);
}
