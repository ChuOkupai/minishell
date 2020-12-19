/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:10:33 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/18 20:22:28 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "shell.h"

void	shell_clear(t_shell *s)
{
	env_clear(&s->env);
	readline_clear(&s->readline);
	ft_list_clear(&s->asts, (t_gfunction) & astnode_clear);
	ft_free(s->ps1);
	ft_free(s->ps2);
}
