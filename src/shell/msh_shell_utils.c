/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:10:33 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/16 20:03:41 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "environment.h"
#include "shell.h"
#include "utils.h"

static void	parse_opt(t_option *opt, int n, char **av)
{
	int i;

	i = 0;
	while (++i < n)
		if (!ft_strcmp(av[i], "--dump-states"))
			opt->dump_states = true;
		else if (!ft_strcmp(av[i], "--dump-tokens"))
			opt->dump_tokens = true;
		else
			msh_perror_format("warning - unrecognized option '%s'", av[i]);
}

void		*msh_shell_clear(t_shell *shell)
{
	if (shell)
	{
		ft_list_clear(&shell->env, &free);
		if (shell->stdin)
			ft_fclose(shell->stdin);
		msh_termcaps_clear(shell->term);
		free(shell);
	}
	return (NULL);
}

t_shell		*msh_shell_new(int ac, char **av, char **env)
{
	t_shell *shell;

	if (!(shell = ft_calloc(1, sizeof(t_shell))))
		return (NULL);
	shell->env = msh_env_new(env);
	shell->stdin = ft_fdopen(STDIN_FILENO, "r");
	if (!shell->stdin)
		return (msh_shell_clear(shell));
	shell->term = msh_termcaps_init(msh_env_get(shell->env, "TERM"));
	if (!shell->term)
		return (msh_shell_clear(shell));
	shell->keep = true;
	parse_opt(&shell->opt, ac, av);
	return (shell);
}
