/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_astnode_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:18:30 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/19 13:28:52 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ast.h"

t_btree	*msh_astnode(t_list *element)
{
	return (element ? element->content : NULL);
}

void	msh_astnode_print(t_btree *node)
{
	t_ast *a;

	if (!node)
		return ;
	if ((a = msh_ast(node))->type == AST_PROCESS)
	{
		ft_putstr((ft_list_size(a->sequence) > 1 ? "pipeline" : "command"));
		return ;
	}
	ft_putstr(a->type == AST_AND ? "AND(" : "OR(");
	msh_astnode_print(node->left);
	ft_putstr(", ");
	msh_astnode_print(node->right);
	ft_putchar(')');
}
