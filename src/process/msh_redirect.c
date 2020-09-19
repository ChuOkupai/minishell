/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:51:50 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/19 13:52:02 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "process.h"
#include "utils.h"

void	msh_change_fd(t_redirection *r)
{
	int fd;

	if (r->type == REDIR_INPUT)
	{
		fd = open(r->path, O_RDONLY);
		dup2(fd, 0);
		close(fd);
	}
	else if (r->type == REDIR_OUTPUT)
	{
		fd = open(r->path, O_WRONLY | O_CREAT | O_TRUNC, 00755);
		dup2(fd, 1);
		close(fd);
	}
	else if (r->type == REDIR_APPENDING_OUTPUT)
	{
		fd = open(r->path, O_WRONLY | O_CREAT | O_APPEND, 00755);
		dup2(fd, 1);
		close(fd);
	}
}

void	msh_redirect(t_process *process, t_list *env)
{
	pid_t			pid;
	t_list			*r;

	if ((pid = fork()) == -1)
		msh_abort("process");
	else if (pid == 0)
	{
		r = process->redirection;
		while (r)
		{
			msh_change_fd(r->content);
			r = r->next;
		}
		execve(process->argv[0], process->argv + 1,
				(char **)(ft_list_to_array(env)));
		exit(0);
	}
	wait(NULL);
}
