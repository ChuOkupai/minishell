/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:51:50 by gdinet            #+#    #+#             */
/*   Updated: 2020/10/03 15:20:17 by gdinet           ###   ########.fr       */
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
		msh_duplicate_fd(open(r->path, O_WRONLY | O_CREAT | O_TRUNC, 0755),
		STDOUT_FILENO, r->path);
	else if (r->type == REDIR_APPENDING_OUTPUT)
		msh_duplicate_fd(open(r->path, O_WRONLY | O_CREAT | O_APPEND, 0755),
		STDOUT_FILENO, r->path);
}

int			msh_redirect(t_process *process)
{
	t_list			*l;
	t_redirection	*r;

	l = process->redirection;
	r = l->content;
	while (l)
	{
		if (!ft_strcmp(r->path, ""))
			return (msh_perrorr(1, "ambiguous redirect"));
		msh_change_fd(l->content);
		l = l->next;
	}
	return (0);
}

void		msh_undirect(int input, int output)
{
	dup2(input, STDIN_FILENO);
	close(input);
	dup2(output, STDOUT_FILENO);
	close(output);
}
