/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:26:50 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/08 15:08:16 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell.h"
#include "utils.h"

t_shell	*msh_shell_init(void)
{
	t_shell *shell;

	shell = ft_calloc(1, sizeof(t_shell));
	if (!shell || !(shell->stdin = ft_fdopen(STDIN_FILENO, "r")))
		msh_abort();
	shell->keep = true;
	return (shell);
}
