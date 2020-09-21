/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_process_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:07:29 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/21 17:59:48 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "process.h"
#include "utils.h"

int		msh_process_exec(t_list *process, t_env *env)
{
	pid_t	pid;
	int		p[2];
	int		fd_in;
	int		ret;

	fd_in = 0;
	while (process != NULL)
	{
		if (pipe(p) < 0 || (pid = fork()) == -1)
			msh_abort("process");
		else if (pid == 0)
		{
			dup2(fd_in, STDIN_FILENO);
			if (process->next != NULL)
				dup2(p[1], STDOUT_FILENO);
			close(p[0]);
			msh_redirect(process->content, env);
			exit(0);
		}
		wait(&ret);
		fd_in = p[0];
		close(p[1]);
		process = process->next;
	}
	return (ret);
}
