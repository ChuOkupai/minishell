/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:10:33 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/16 13:42:22 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "environment.h"
#include "shell.h"
#include "utils.h"

void	msh_shell_clear(t_shell *shell)
{
	ft_list_clear(&shell->env, &free);
	if (shell->stdin)
		ft_fclose(shell->stdin);
	free(shell);
}

t_shell	*msh_shell_init(char **env)
{
	t_shell *shell;

	shell = ft_calloc(1, sizeof(t_shell));
	if (!shell || !(shell->stdin = ft_fdopen(STDIN_FILENO, "r")))
		msh_abort();
	shell->env = msh_env_init(env);
	shell->keep = true;
	return (shell);
}
