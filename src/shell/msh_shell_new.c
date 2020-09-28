/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:00:53 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 18:01:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "const.h"
#include "shell.h"
#include "utils.h"

static void	history_init(t_history *h, t_env *env)
{
	const char *var;

	if ((var = msh_env_get(env, "HISTSIZE")))
		h->histsize = ft_strtoul(var, NULL, 10);
}

static int	line_init(t_line *l, t_env *env)
{
	l->buf = ft_calloc(MSH_LINE_BUFFERSIZE, sizeof(char));
	l->ps1 = msh_env_expand(env, MSH_PS1);
	l->stream = ft_fdopen(STDIN_FILENO, "r");
	l->alloc_size = MSH_LINE_BUFFERSIZE;
	return (-(!l->buf || !l->ps1 || !l->stream));
}

static int	terminal_init(t_terminal *t, t_env *env)
{
	struct termios termios;

	if (tcgetattr(STDIN_FILENO, &t->backup) < 0)
		return (-1);
	termios = t->backup;
	termios.c_lflag &= ~(ICANON | ECHO);
	termios.c_cc[VMIN] = 1;
	termios.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios) < 0)
		return (-1);
	if ((t->type = (char *)msh_env_get(env, "TERM")))
		t->type = ft_strdup(t->type);
	t->init = true;
	return (0);
}

static void	options_init(t_option *opt, int n, char **av)
{
	int i;

	i = 0;
	while (++i < n)
		if (!ft_strcmp(av[i], "--dump-tokens"))
			opt->dump_tokens = true;
		else if (!ft_strcmp(av[i], "--dump-ast"))
			opt->dump_ast = true;
		else
			msh_perror("warning - unrecognized option '%s'", av[i]);
}

t_shell		*msh_shell_new(int ac, char **av, char **env)
{
	t_shell *s;

	if (!(s = ft_calloc(1, sizeof(t_shell))))
		return (NULL);
	msh_env_init(&s->env, env);
	if (line_init(&s->line, &s->env) < 0 ||
	terminal_init(&s->terminal, &s->env) < 0)
		return (msh_shell_clear(s));
	history_init(&s->history, &s->env);
	options_init(&s->options, ac, av);
	return (s);
}
