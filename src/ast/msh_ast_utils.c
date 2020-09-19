/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:49:16 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/19 13:42:02 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast		*msh_ast(t_btree *element)
{
	return (element ? element->content : NULL);
}

void		msh_ast_print(t_ast *a)
{
	if (a->type == AST_PROCESS)
		ft_putstr("SEQUENCE");
	else
		ft_putstr(a->type == AST_AND ? "AND" : "OR");
}

t_ast_type	msh_ast_type(const char *value)
{
	if (!ft_strcmp(value, "&&"))
		return (AST_AND);
	else if (!ft_strcmp(value, "||"))
		return (AST_OR);
	return (-1);
}
