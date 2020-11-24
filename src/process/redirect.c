/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:51:50 by gdinet            #+#    #+#             */
/*   Updated: 2020/11/24 15:23:35 by asoursou         ###   ########.fr       */
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

static void	duplicate_fd(int fd, int fd2, const char *path)
{
	if (fd == -1 || dup2(fd, fd2) == -1)
		msh_abort(path);
	close(fd);
}

static void	change_fd(t_redirect *r)
{
	if (r->type == REDIR_INPUT)
		duplicate_fd(open(r->path, O_RDONLY), STDIN_FILENO, r->path);
	else if (r->type == REDIR_OUTPUT)
		duplicate_fd(open(r->path, O_WRONLY | O_CREAT | O_TRUNC, 0755),
		STDOUT_FILENO, r->path);
	else if (r->type == REDIR_APPENDING_OUTPUT)
		duplicate_fd(open(r->path, O_WRONLY | O_CREAT | O_APPEND, 0755),
		STDOUT_FILENO, r->path);
}

int			redirect(t_process *process)
{
	t_list		*l;
	t_redirect	*r;

	l = process->redirection;
	while (l)
	{
		r = l->content;
		if (!ft_strcmp(r->path, ""))
			return (msh_perrorr(1, "ambiguous redirect"));
		change_fd(l->content);
		l = l->next;
	}
	return (0);
}

void		undirect(int input, int output)
{
	dup2(input, STDIN_FILENO);
	close(input);
	dup2(output, STDOUT_FILENO);
	close(output);
}
