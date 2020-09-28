/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:00:53 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 21:39:41 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <stdlib.h>
#include <term.h>
#include <unistd.h>
#include "const.h"
#include "shell.h"
#include "utils.h"

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
	t_shell		*s;
	const char	*var;

	if (!(s = ft_calloc(1, sizeof(t_shell))))
		return (NULL);
	msh_env_init(&s->env, env);
	if (msh_readline_init(&s->readline, msh_env_get(&s->env, "TERM")) < 0)
		return (msh_shell_clear(s));
	if ((var = msh_env_get(&s->env, "HISTSIZE")))
		msh_readline_set_histsize(&s->readline, ft_strtoul(var, NULL, 10));
	s->ps1 = msh_env_expand(&s->env, MSH_PS1);
	options_init(&s->options, ac, av);
	return (s);
}
