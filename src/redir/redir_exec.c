/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:11:26 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/09 20:56:20 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "redir.h"
#include "utils.h"

static int	replace(int fd, int old_fd)
{
	if (fd < 0)
		return (fd);
	close(old_fd);
	old_fd = dup(fd);
	if (old_fd < 0)
		return (old_fd);
	close(fd);
	return (old_fd);
}

int			redir_exec(const t_redir *r)
{
	int n;

	if (redir_is_ambiguous(r))
		return (msh_perrorr(r->raw_path, ARG_AMBIGUOUS, -1));
	if (r->op == REDIR_INPUT || r->op == REDIR_HEREDOC_INPUT)
		n = replace(open(r->path, O_RDONLY), STDIN_FILENO);
	else
	{
		n = O_WRONLY | O_CREAT | (r->op == REDIR_OUTPUT ? O_TRUNC : O_APPEND);
		n = replace(open(r->path, n, 0755), STDOUT_FILENO);
	}
	return (n < 0 ? msh_perrorr(r->path, msh_strerrno(), -1) : 0);
}
