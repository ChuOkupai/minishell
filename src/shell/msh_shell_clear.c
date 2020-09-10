/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:12:42 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/08 15:09:41 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

void	msh_shell_clear(t_shell *shell)
{
	ft_list_clear(&shell->env, &free);
	if (shell->stdin)
		ft_fclose(shell->stdin);
	free(shell);
}
