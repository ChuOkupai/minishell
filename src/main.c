/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:22:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/12 16:49:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "shell.h"
#include "utils.h"

static void	parse_opt(t_option *opt, int n, char **av)
{
	while (--n > 0)
		if (!ft_strcmp(av[n], "--dump-states"))
			opt->dump_states = true;
		else if (!ft_strcmp(av[n], "--dump-tokens"))
			opt->dump_tokens = true;
		else
			msh_perror_format("warning - unrecognized option '%s'", av[n]);
}

int			main(int ac, char **av, char **env)
{
	t_shell	*shell;
	int		ret;

	shell = msh_shell_init();
	shell->env = msh_env_copy(env);
	parse_opt(&shell->opt, ac, av);
	ret = msh_shell_run(shell);
	msh_shell_clear(shell);
	return (ret);
}
