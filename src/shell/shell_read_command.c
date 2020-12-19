/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_read_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 13:03:48 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/19 15:23:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"
#include "shell.h"
#include "utils.h"

static t_list	*parse(char *s2, t_env *env)
{
	t_list	*l;
	int		r;

	l = tokenize(s2);
	ft_free(s2);
	if ((r = is_valid(l)) < 0)
		msh_perror("parser", "Unsupported multiline commands");
	if (!r || r < 0)
	{
		env_setstatus(env, 2);
		return (ft_list_clear(&l, (t_gfunction) & token_clear));
	}
	return (l);
}

static t_list	*readline_ps1(t_shell *s)
{
	char *s2;
	char *s3;

	s2 = readline(&s->readline, s->ps1);
	if (ft_strisempty(s2) && ft_feof(s->readline.stream))
	{
		ft_free(s2);
		ft_putendl_fd(s2 = "exit", STDERR_FILENO);
		return (tokenize(s2));
	}
	while (s2 && ft_feof(s->readline.stream))
	{
		s3 = readline(&s->readline, NULL);
		if (s->discard)
		{
			readline_keep(&s->readline, s3);
			ft_free(s2);
			return (NULL);
		}
		s2 = msh_join(s2, NULL, s3);
	}
	if (!s2 || !*ft_strwhile(s2, &ft_isspace))
		return (ft_free(s2));
	return (parse(s2, &s->env));
}

t_list			*shell_read_command(t_shell *s)
{
	t_list *l;

	s->discard = false;
	l = readline_ps1(s);
	return (l);
}
