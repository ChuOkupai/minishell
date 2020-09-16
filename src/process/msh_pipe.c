/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:07:29 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/16 20:41:33 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "process.h"
#include "utils.h"

void	msh_pipe(t_list *process)
{
	pid_t	pid;
	int		p[2];
	int		fd_in;

	fd_in = 0;
	while (process != NULL)
	{
		pipe(p);
		if ((pid = fork()) == -1)
			msh_abort("process");
		else if (pid == 0)
		{
			dup2(fd_in, 0);
			if (process->next != NULL)
				dup2(p[1], 1);
			close(p[0]);
			msh_redirect(process->content);
			exit(0);
		}
		wait(NULL);
		fd_in = p[0];
		close(p[1]);
		process = process->next;
	}
}
