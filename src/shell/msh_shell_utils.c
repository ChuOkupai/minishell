/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:10:33 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/26 15:55:31 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "const.h"
#include "environment.h"
#include "shell.h"
#include "utils.h"

static void	parse_opt(t_option *opt, int n, char **av)
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

void		*msh_shell_clear(t_shell *shell)
{
	if (shell)
	{
		msh_env_clear(shell->env);
		ft_list_clear(&shell->hist, &free);
		if (shell->stdin)
			ft_fclose(shell->stdin);
		msh_termcaps_clear(shell->term);
		ft_memdel(shell->ps1);
		free(shell);
	}
	return (NULL);
}

t_shell		*msh_shell_new(int ac, char **av, char **env)
{
	t_shell	*shell;
	char	*s;

	if (!(shell = ft_calloc(1, sizeof(t_shell))))
		return (NULL);
	shell->env = msh_env_new(env);
	if (!shell->env || !(shell->stdin = ft_fdopen(STDIN_FILENO, "r")))
		return (msh_shell_clear(shell));
	shell->term = msh_termcaps_init(msh_env_get(shell->env, "TERM"));
	if (!shell->term || !(s = ft_strdup(MSH_PS1)))
		return (msh_shell_clear(shell));
	shell->ps1 = msh_env_expand(shell->env, s);
	ft_memdel(s);
	if (!shell->ps1)
		return (msh_shell_clear(shell));
	parse_opt(&shell->opt, ac, av);
	return (shell);
}
