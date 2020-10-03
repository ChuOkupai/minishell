/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:25:55 by gdinet            #+#    #+#             */
/*   Updated: 2020/10/03 11:46:33 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "process.h"
#include "utils.h"

static void	msh_child(t_list *process, int *p, int fd_in, t_env *env)
{
	t_process	*p_content;
	char		*name;

	p_content = process->content;
	dup2(fd_in, STDIN_FILENO);
	if (process->next != NULL)
		dup2(p[1], STDOUT_FILENO);
	close(p[0]);
	msh_redirect(p_content);
	name = msh_path(p_content->argv[0], env);
	if ((execve(name, p_content->argv, env->array)) == -1)
	{
		if (name != p_content->argv[0])
			free(name);
		msh_abort(p_content->argv[0]);
	}
}

static int	msh_wait_child(pid_t pid)
{
	int		status;

	while (1)
	{
		waitpid(pid, &status, WUNTRACED | WCONTINUED);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		if (WIFSIGNALED(status))
			return (WTERMSIG(status));
		if (WIFSTOPPED(status))
			return (WSTOPSIG(status));
		if (!WIFEXITED(status) && !WIFSIGNALED(status))
			break ;
	}
	return (EXIT_SUCCESS);
}

int			msh_pipe(t_list *process, t_env *env)
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
			msh_child(process, p, fd_in, env);
		ret = msh_wait_child(pid);
		fd_in = p[0];
		close(p[1]);
		process = process->next;
	}
	return (ret);
}
