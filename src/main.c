/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:22:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/09 18:10:00 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "shell.h"
#include "utils.h"

static void	parse_opt(t_option *opt, int ac, char **av)
{
	while (--ac > 0)
		if (!ft_strcmp(av[ac], "--dump-tokens") || !ft_strcmp(av[ac], "-t"))
			opt->dump_tokens = true;
		else
			msh_perror_format("warning - unrecognized option '%s'", av[ac]);
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
