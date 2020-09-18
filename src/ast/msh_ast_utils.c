/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:49:16 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/18 18:16:58 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ast.h"
#include "utils.h"

t_btree	*msh_astnode(t_list *element)
{
	return (element ? element->content : NULL);
}

void	msh_astnode_print(t_btree *node, int deep)
{
	t_ast *a;

	if (!node)
		return ;
	a = msh_ast(node);
	if (deep)
		ft_printf("%*c ", 2 * deep, ' ');
	if (a->type == AST_PROCESS)
	{
		ft_putendl("PROCESS");
		ft_list_print(a->sequence, (t_gprint) & msh_process_print);
	}
	else
		ft_putendl(a->type == AST_AND ? "AND" : "OR");
	msh_astnode_print(node->left, ++deep);
	msh_astnode_print(node->right, deep);
}

t_ast	*msh_ast(t_btree *element)
{
	return (element ? element->content : NULL);
}

t_ast_type	msh_ast_type(const char *value)
{
	if (!ft_strcmp(value, "&&"))
		return (AST_AND);
	else if (!ft_strcmp(value, "||"))
		return (AST_OR);
	return (AST_PROCESS);
}
