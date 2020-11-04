/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:25:55 by gdinet            #+#    #+#             */
/*   Updated: 2020/11/04 17:45:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "process.h"
#include "utils.h"

static void	msh_child(t_shell *s, t_list *process, int *p, int fd_in)
{
	t_process	*p_content;
	char		*name;

	p_content = process->content;
	dup2(fd_in, STDIN_FILENO);
	if (process->next != NULL)
		dup2(p[1], STDOUT_FILENO);
	close(p[0]);
	if (msh_redirect(p_content))
		exit(1);
	if (!(name = msh_path(p_content->argv[0], &s->env)))
	{
		msh_perror("%s : command not found", p_content->argv[0]);
		exit(127);
	}
	if ((execve(name, p_content->argv, s->env.array)) == -1)
	{
		if (name != p_content->argv[0])
			free(name);
		msh_abort(p_content->argv[0]);
	}
}

static int	msh_wait_child(pid_t pid)
{
	int status;

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

static void	msh_pipe(t_shell *s, t_list *process)
{
	int			p[2];
	int			fd_in;
	t_process	*p_content;

	fd_in = 0;
	while (process)
	{
		s->pid = 0;
		if (pipe(p) < 0 || (s->pid = fork()) == -1)
			msh_abort("process");
		else if (!s->pid)
			msh_child(s, process, p, fd_in);
		p_content = process->content;
		p_content->pid = s->pid;
		fd_in = p[0];
		close(p[1]);
		s->pid = 0;
		process = process->next;
	}
}

int			msh_process(t_shell *s, t_list *process)
{
	int			ret;
	t_process	*p_content;

	ret = 0;
	msh_pipe(s, process);
	while (process != NULL)
	{
		p_content = process->content;
		ret = msh_wait_child(p_content->pid);
		process = process->next;
	}
	return (ret);
}
