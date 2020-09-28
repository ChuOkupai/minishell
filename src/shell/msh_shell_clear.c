/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:10:33 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 21:39:13 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

static void	pwd_clear(t_pwd *p)
{
	ft_memdel(p->pwd);
	ft_memdel(p->oldpwd);
}

void		*msh_shell_clear(t_shell *shell)
{
	if (shell)
	{
		msh_env_clear(&shell->env);
		msh_readline_clear(&shell->readline);
		pwd_clear(&shell->pwd);
		ft_memdel(shell->ps1);
		free(shell);
	}
	return (NULL);
}
