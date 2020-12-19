/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_create_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:10:08 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/18 20:23:03 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include "process.h"

#define BUF_SIZE	64
#define WARN_HD		"minishell: warning: %s (wanted `%s')\n"
#define WARN_ARG0	"here-document delimited by end-of-file"

static char	*join(char *s1, char *s2, const char *delim)
{
	char *s3;

	s3 = ft_strjoin3(s1, s2, delim);
	ft_free(s1);
	ft_free(s2);
	return (s3);
}

static char	*read_heredoc(t_shell *s, char *delim)
{
	char	*s1;
	char	*s2;
	bool	eof;

	s1 = NULL;
	while (!s->discard && (s2 = readline(&s->readline, s->ps2)))
	{
		if (s->discard)
		{
			readline_keep(&s->readline, s2);
			return (ft_free(s1));
		}
		eof = ft_feof(s->readline.stream);
		if (!ft_strcmp(s2, delim))
		{
			ft_free(s2);
			break ;
		}
		else
			s1 = join(s1, s2, (eof ? NULL : "\n"));
		if (eof)
			break ;
	}
	return (s1);
}

static void	try_here_doc(t_redir *r, t_shell *s)
{
	t_u32	addr;
	char	*out;
	int		fd;

	if (r->op != REDIR_HEREDOC_INPUT)
		return ;
	ft_free(r->raw_path);
	r->raw_path = r->path;
	addr = (t_u64)r % UINT_MAX;
	ft_asprintf(&r->path, "/tmp/minishell-%016lx.%08x", ft_rand(), addr);
	out = read_heredoc(s, r->raw_path);
	if (ft_feof(s->readline.stream))
		ft_dprintf(STDERR_FILENO, WARN_HD, WARN_ARG0, r->raw_path);
	fd = open(r->path, O_CREAT | O_TRUNC | O_RDWR, 0600);
	if (fd >= 0)
	{
		ft_putstr_fd(out, fd);
		close(fd);
	}
	ft_free(out);
}

void		job_create_heredoc(t_list *j, t_shell *s)
{
	t_process	*p;
	t_list		*l;

	if (!j || s->discard)
		return ;
	p = j->content;
	l = p->redirection;
	while (!s->discard && l)
	{
		try_here_doc(l->content, s);
		l = l->next;
	}
	job_create_heredoc(j->next, s);
}
