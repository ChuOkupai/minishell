/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:51:50 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/21 14:44:31 by gdinet           ###   ########.fr       */
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

static void	msh_duplicate_fd(int fd, int fd2, const char *path)
{
	if (fd == -1 || dup2(fd, fd2) == -1)
		msh_abort(path);
	close(fd);
}

static void	msh_change_fd(t_redirection *r)
{
	if (r->type == REDIR_INPUT)
		msh_duplicate_fd(open(r->path, O_RDONLY), STDIN_FILENO, r->path);
	else if (r->type == REDIR_OUTPUT)
		msh_duplicate_fd(open(r->path, O_WRONLY | O_CREAT | O_TRUNC, 755),
		STDOUT_FILENO, r->path);
	else if (r->type == REDIR_APPENDING_OUTPUT)
		msh_duplicate_fd(open(r->path, O_WRONLY | O_CREAT | O_APPEND, 755),
		STDOUT_FILENO, r->path);
}

void		msh_redirect(t_process *process, t_list *env)
{
	t_list		*r;

	r = process->redirection;
	while (r)
	{
		msh_change_fd(r->content);
		r = r->next;
	}
	if ((execve(process->argv[0], process->argv + 1,
			(char **)(ft_list_to_array(env)))) == -1)
		msh_abort(process->argv[0]);
}
