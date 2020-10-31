/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:10:33 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/15 13:41:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

static void	pwd_clear(t_pwd *p)
{
	ft_delete(p->pwd);
	ft_delete(p->oldpwd);
}

void		msh_shell_clear(t_shell *s)
{
	msh_env_clear(&s->env);
	msh_readline_clear(&s->readline);
	msh_history_clear(&s->history);
	pwd_clear(&s->pwd);
	ft_delete(s->ps1);
	ft_delete(s->ps2);
}
