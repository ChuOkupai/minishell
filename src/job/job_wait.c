/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:41:41 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/18 21:26:25 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include "job.h"
#include "utils.h"

static int	check_sig(int status)
{
	if (status != SIGINT && status != SIGQUIT)
	{
		if (msh_strsig(status))
		{
			ft_putstr_fd(msh_strsig(status), STDERR_FILENO);
			if (status != SIGKILL)
				ft_putstr_fd(" (core dumped)", STDERR_FILENO);
			ft_putchar_fd('\n', STDERR_FILENO);
		}
		else
			ft_putendl_fd("Unknown or unsupported signal", STDERR_FILENO);
	}
	return (status);
}

void		job_wait(t_list *j)
{
	pid_t	pid;
	int		status;

	while ((pid = waitpid(-1, &status, WUNTRACED)) > 0)
		if (WIFEXITED(status))
			job_mark_process(j, pid, WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			job_mark_process(j, pid, check_sig(WTERMSIG(status)) + 128);
}
