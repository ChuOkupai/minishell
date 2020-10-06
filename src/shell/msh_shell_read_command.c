/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_read_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 13:03:48 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/06 17:01:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "parser.h"
#include "shell.h"
#include "utils.h"

static bool			g_discard;
static t_env		*g_env;
static const char	*g_ps1;

static void		discard_entry(int signal)
{
	(void)signal;
	ft_putchar('\n');
	if (g_ps1)
		ft_putstr(g_ps1);
	g_discard = true;
	msh_env_setstatus(g_env, 130);
}

static char		*join(char *s1, const char *s2, char *s3)
{
	char *s4;

	s4 = ft_strjoin3((g_discard ? NULL : s1), s2, s3);
	ft_memdel(s1);
	ft_memdel(s3);
	return (s4);
}

static bool		is_multiline(char *str, t_list **t, char **value)
{
	int r;

	*value = NULL;
	if (!str || !(*t = msh_tokenize(str)))
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

static t_list	*tokenize(t_shell *s, char *s2)
{
	t_list	*t;
	char	*val;

	while (is_multiline(s2, &t, &val) && !ft_feof(s->readline.stream))
		if (!(s2 = join(s2, "\n",
		msh_readline(&s->readline, &s->history, s->ps2))))
			return (NULL);
	if (ft_feof(s->readline.stream))
	{
		if (val)
			msh_perror("unexpected EOF while looking for matching `%s'", val);
		msh_perror("syntax error: unexpected end of file");
		msh_env_setstatus(&s->env, 2);
		ft_list_clear(&t, (t_gfunction) & msh_token_clear);
	}
	else
		msh_history_edit(&s->history, s2, 0);
	ft_memdel(s2);
	msh_parse_words(t, &s->env);
	g_ps1 = NULL;
	return (t);
}

t_list			*msh_shell_read_command(t_shell *s)
{
	char	*s2;

	g_discard = false;
	g_env = &s->env;
	g_ps1 = s->ps1;
	signal(SIGINT, &discard_entry);
	if (!(s2 = msh_readline(&s->readline, &s->history, s->ps1)) ||
	(!*s2 && ft_feof(s->readline.stream)))
	{
		ft_memdel(s2);
		s2 = "exit";
		ft_putendl(s2);
		g_ps1 = NULL;
		return (msh_tokenize(s2));
	}
	while (ft_feof(s->readline.stream))
		if (!(s2 = join(s2, 0, msh_readline(&s->readline, &s->history, 0))))
			return (NULL);
	if (*ft_strwhile(s2, &ft_isspace))
		msh_history_add(&s->history, s2);
	return (tokenize(s, s2));
}
