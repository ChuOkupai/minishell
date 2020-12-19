/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astnode_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:18:30 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/08 20:15:54 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ast.h"
#include "job.h"

void	astnode_print(t_btree *node)
{
	t_ast *a;

	ft_putchar('(');
	if ((a = ast(node))->type == AST_JOB)
		job_print(a->sequence);
	else
	{
		ft_putstr(a->type == AST_AND ? "&&" : "||");
		astnode_print(node->left);
		astnode_print(node->right);
	}
	ft_putchar(')');
}
