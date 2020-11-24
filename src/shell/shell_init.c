/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:00:53 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 15:25:03 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

int			shell_init(t_shell *s, int ac, char **av, char **env)
{
	const char *var;

	env_init(&s->env, env);
	if (readline_init(&s->readline, env_get(&s->env, "TERM"), STDIN_FILENO) < 0)
	{
		shell_clear(s);
		return (-1);
	}
	history_init(&s->history);
	if ((var = env_get(&s->env, "HISTSIZE")))
		history_resize(&s->history, ft_atoi(var));
	s->ps1 = env_expand(&s->env, MSH_PS1);
	s->ps2 = env_expand(&s->env, MSH_PS2);
	options_init(&s->options, ac, av);
	return (0);
}
