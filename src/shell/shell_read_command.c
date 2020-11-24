/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_read_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 13:03:48 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 19:05:26 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const.h"
#include "parser.h"
#include "shell.h"
#include "utils.h"

static char		*join(t_shell *s, char *s1, const char *s2, const char *prompt)
{
	char	*s3;
	char	*s4;
	bool	discard;

	discard = s->discard && !s->readline.eof;
	if (discard)
		return (ft_delete(s1));
	s3 = readline(&s->readline, &s->history, prompt);
	if (s1)
	{
		s4 = ft_strjoin3((s->discard ? NULL : s1), s2, s3);
		ft_delete(s1);
		ft_delete(s3);
		return (s4);
	}
	return (s3);
}

static t_list	*parse(char *s2, char **value)
{
	t_list	*l;
	t_token	*last;
	int		r;

	if (!(l = tokenize(s2)))
	{
		ft_delete(s2);
		return (l);
	}
	if ((last = token(ft_list_last(l)))->type == TOKEN_MULTILINE)
	{
		msh_perror(MSH_UNSUPPORTED_MULTILINE);
		if (value)
			*value = last->value;
		ft_delete(s2);
		return (ft_list_clear(&l, (t_gfunction) & token_clear));
	}
	ft_delete(s2);
	if ((r = is_valid(l)) < 0)
		msh_perror(MSH_UNSUPPORTED_MULTILINE);
	if (!r || r < 0)
		return (ft_list_clear(&l, (t_gfunction) & token_clear));
	return (l);
}

static t_list	*readline_ps1(t_shell *s, char *s2)
{
	if (!s2)
		return (NULL);
	else if (s->readline.eof)
	{
		if (*s2)
			return (readline_ps1(s, join(s, s2, NULL, NULL)));
		ft_delete(s2);
		ft_putendl(s2 = "exit");
		return (tokenize(s2));
	}
	if (!*ft_strwhile(s2, &ft_isspace))
		return (ft_delete(s2));
	history_add(&s->history, s2);
	return (parse(s2, NULL));
}

t_list			*shell_read_command(t_shell *s)
{
	t_list *l;

	s->discard = false;
	l = readline_ps1(s, join(s, NULL, NULL, s->ps1));
	parse_words(l, &s->env);
	s = NULL;
	return (l);
}
