/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astnode_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:18:30 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 14:47:27 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ast.h"
#include "process.h"

static void	print_sequence(t_list *seq)
{
	while (seq)
	{
		process_print(seq->content);
		if ((seq = seq->next))
			ft_putstr(" | ");
	}
}

void		astnode_print(t_btree *node)
{
	t_ast *a;

	if ((a = ast(node))->type == AST_PROCESS)
	{
		print_sequence(a->sequence);
		return ;
	}
	ft_putstr(a->type == AST_AND ? "&&" : "||");
	ft_putchar('(');
	astnode_print(node->left);
	ft_putstr(", ");
	astnode_print(node->right);
	ft_putchar(')');
}
