/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:22:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/08 19:50:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils.h"

static bool	want_help(int ac, char **av)
{
	if (ac < 2)
		return (false);
	if (!ft_strcmp(av[--ac], "--help"))
		return (true);
	return (want_help(ac, av));
}

static int	usage(void)
{
	ft_putendl("minishell, version 1.0");
	ft_putendl("Usage:  minishell [GNU long option] ...");
	ft_putendl("Basic command line interpreter.\n");
	ft_putendl("    --dump-all       enable all dump options");
	ft_putendl("    --dump-ast       show the abstract syntax tree");
	ft_putendl("    --dump-exec      show the arguments after expansion");
	ft_putendl("    --dump-tokens    show the list of tokens\n");
	ft_putendl("Authors:");
	ft_putendl("    - Adrien Soursou");
	ft_putendl("    - Guillaume Dinet");
	return (0);
}

int			main(int ac, char **av, char **env)
{
	t_shell	shell;
	int		ret;

	if (want_help(ac, av))
		return (usage());
	if (shell_init(&shell, ac, av, env) < 0)
		msh_abort("initialization");
	ret = shell_run(&shell);
	shell_clear(&shell);
	return (ret);
}
