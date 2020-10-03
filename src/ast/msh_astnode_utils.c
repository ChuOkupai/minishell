/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_astnode_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:18:30 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/03 11:37:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ast.h"
#include "process.h"

t_btree		*msh_astnode(t_list *element)
{
	return (element ? element->content : NULL);
}

static void	print_sequence(t_list *seq)
{
	while (seq)
	{
		msh_process_print(seq->content);
		if ((seq = seq->next))
			ft_putstr(" | ");
	}
}

void		msh_astnode_print(t_btree *node)
{
	t_ast *a;

	if (!node)
		return ;
	if ((a = msh_ast(node))->type == AST_PROCESS)
	{
		print_sequence(a->sequence);
		return ;
	}
	ft_putstr(a->type == AST_AND ? "&&" : "||");
	ft_putchar('(');
	msh_astnode_print(node->left);
	ft_putstr(", ");
	msh_astnode_print(node->right);
	ft_putchar(')');
}
