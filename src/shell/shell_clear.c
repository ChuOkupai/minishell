/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:10:33 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 15:24:38 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

static void	pwd_clear(t_pwd *p)
{
	ft_delete(p->pwd);
	ft_delete(p->oldpwd);
}

void		shell_clear(t_shell *s)
{
	env_clear(&s->env);
	readline_clear(&s->readline);
	history_clear(&s->history);
	pwd_clear(&s->pwd);
	ft_delete(s->ps1);
	ft_delete(s->ps2);
}
