/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:49:16 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 14:45:29 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "process.h"

t_ast		*ast(t_btree *element)
{
	return (element ? element->content : NULL);
}

void		ast_clear(t_ast *a)
{
	if (a->type == AST_PROCESS)
		ft_list_clear(&a->sequence, (t_gfunction) & process_clear);
	ft_delete(a);
}

void		ast_print(t_ast *a)
{
	if (a->type == AST_PROCESS)
		ft_putstr("SEQUENCE");
	else
		ft_putstr(a->type == AST_AND ? "AND" : "OR");
}

t_ast_type	ast_type(const char *value)
{
	if (!ft_strcmp(value, "&&"))
		return (AST_AND);
	else if (!ft_strcmp(value, "||"))
		return (AST_OR);
	return (-1);
}
