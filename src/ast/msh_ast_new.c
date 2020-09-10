/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:51:19 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/10 18:29:43 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ast.h"
#include "utils.h"

t_ast	*msh_ast_new(t_ast_type type, t_list *commands)
{
	t_ast *a;

	if (!(a = malloc(sizeof(t_ast))))
		msh_abort();
	a->type = type;
	a->commands = commands;
	return (a);
}
