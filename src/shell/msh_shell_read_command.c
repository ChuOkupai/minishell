/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_read_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 13:03:48 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/04 17:23:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "parser.h"
#include "shell.h"
#include "utils.h"

static char		*join(char *s1, const char *s2, char *s3)
{
	char *s4;

	s4 = ft_strjoin3(s1, s2, s3);
	ft_memdel(s1);
	ft_memdel(s3);
	return (s4);
}

static bool		is_multiline(char *str, t_list **t, char **value)
{
	int r;

	*value = NULL;
	if (!(*t = msh_tokenize(str)))
		return (false);
	if (msh_token(ft_list_last(*t))->type == TOKEN_MULTILINE)
	{
		*value = msh_token(ft_list_last(*t))->value;
		return (!ft_list_clear(t, (t_gfunction) & msh_token_clear));
	}
	if (!(r = msh_is_valid(*t)) || r < 0)
	{
		ft_list_clear(t, (t_gfunction) & msh_token_clear);
		return (r < 0);
	}
	return (false);
}

static t_list	*tokenize(t_shell *s, char *str)
{
	t_list	*t;
	char	*val;

	while (is_multiline(str, &t, &val) && !ft_feof(s->readline.stream))
		if (!(str = join(str, "\n",
		msh_readline(&s->readline, &s->history, s->ps2))))
			return (NULL);
	if (ft_feof(s->readline.stream))
	{
		if (val)
			msh_perror("unexpected EOF while looking for matching `%s'", val);
		msh_perror("syntax error: unexpected end of file");
		ft_list_clear(&t, (t_gfunction) & msh_token_clear);
	}
	else
		msh_history_edit(&s->history, str, 0);
	ft_memdel(str);
	return (t);
}

t_list			*msh_shell_read_command(t_shell *s)
{
	char	*str;
	t_list	*tokens;

	if (!(str = msh_readline(&s->readline, &s->history, s->ps1)) ||
	(!ft_strcmp(str, "") && ft_feof(s->readline.stream)))
	{
		s->keep = false;
		ft_putendl("exit");
		ft_memdel(str);
		return (NULL);
	}
	while (ft_feof(s->readline.stream))
		if (!(str = join(str, 0, msh_readline(&s->readline, &s->history, 0))))
			return (NULL);
	if (*ft_strwhile(str, &ft_isspace))
		msh_history_add(&s->history, str);
	msh_parse_words((tokens = tokenize(s, str)), &s->env);
	if (s->options.dump_tokens)
		ft_list_print(tokens, (t_gprint) & msh_token_print);
	return (msh_ast_build(tokens));
}
