/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astnode_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:42:43 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/07 16:28:30 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "process.h"

static void	ast_clear(t_ast *a)
{
	if (a->type == AST_JOB)
		ft_list_clear(&a->sequence, (t_gfunction) & process_clear);
	ft_free(a);
}

void		*astnode_clear(t_btree *r)
{
	return (ft_btree_clear(&r, (t_gfunction) & ast_clear));
}

t_btree		*astnode_new(t_ast_type type, t_list *sequence)
{
	t_ast *a;

	a = ft_malloc(sizeof(t_ast));
	a->type = type;
	a->sequence = sequence;
	return (ft_btree_new(a));
}
