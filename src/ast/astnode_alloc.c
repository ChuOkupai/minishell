/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astnode_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:42:43 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 14:48:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "utils.h"

void		*astnode_clear(t_list *l)
{
	t_btree *b;

	while (l)
	{
		b = ft_list_pop(&l);
		ft_btree_clear(&b, (t_gfunction) & ast_clear);
	}
	return (NULL);
}

t_btree		*astnode_new(t_ast_type type, t_list *sequence)
{
	t_ast *a;

	if (!(a = ft_new(sizeof(t_ast))))
		msh_abort("ast");
	a->type = type;
	a->sequence = type == AST_PROCESS ? sequence : NULL;
	return (ft_btree_new(a));
}
