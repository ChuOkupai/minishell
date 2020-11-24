/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:25:55 by gdinet            #+#    #+#             */
/*   Updated: 2020/11/24 16:55:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "process.h"
#include "utils.h"

static char	*binpath(char *name, t_env *env)
{
	struct stat	statbuf;
	const char	*path;
	t_list		*l;
	char		*bin;

	if (!stat(name, &statbuf))
		return (name);
	path = env_get(env, "PATH");
	l = path ? ft_list_split(path, ":") : NULL;
	while (l)
	{
		bin = ft_strjoin3(l->content, "/", name);
		if (bin && !stat(bin, &statbuf))
		{
			ft_list_clear(&l, &free);
			return (bin);
		}
		ft_delete(bin);
		free(ft_list_pop(&l));
	}
	return (NULL);
}

static void	child(t_shell *s, t_list *process, int *p, int fd_in)
{
	t_process	*p_content;
	const char	*path;

	p_content = process->content;
	dup2(fd_in, STDIN_FILENO);
	if (process->next)
		dup2(p[1], STDOUT_FILENO);
	close(p[0]);
	if (redirect(p_content))
		exit(1);
	if (!(path = binpath(p_content->argv[0], &s->env)))
		exit(msh_perrorr(127, "%s: command not found", p_content->argv[0]));
	if ((execve(path, p_content->argv, s->env.array)) == -1)
		msh_abort(p_content->argv[0]);
}

static int	wait_child(pid_t pid)
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

static void	make_pipe(t_shell *s, t_list *process)
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
			child(s, process, p, fd_in);
		p_content = process->content;
		p_content->pid = s->pid;
		fd_in = p[0];
		close(p[1]);
		s->pid = 0;
		process = process->next;
	}
}

int			process_run(t_shell *s, t_list *process)
{
	int			ret;
	t_process	*p_content;

	ret = 0;
	make_pipe(s, process);
	while (process != NULL)
	{
		p_content = process->content;
		ret = wait_child(p_content->pid);
		process = process->next;
	}
	return (ret);
}
