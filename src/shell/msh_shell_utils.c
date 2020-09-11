/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:10:33 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/11 16:15:37 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "utils.h"

void	msh_shell_clear(t_shell *shell)
{
	ft_list_clear(&shell->env, &free);
	if (shell->stdin)
		ft_fclose(shell->stdin);
	free(shell);
}

t_shell	*msh_shell_init(void)
{
	t_shell *shell;

	shell = ft_calloc(1, sizeof(t_shell));
	if (!shell || !(shell->stdin = ft_fdopen(STDIN_FILENO, "r")))
		msh_abort();
	shell->keep = true;
	return (shell);
}
