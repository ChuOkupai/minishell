/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_astnode_alloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:42:43 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/15 13:40:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ast.h"
#include "utils.h"

void		*msh_astnode_clear(t_list *l)
{
	t_btree *b;

	while (l)
	{
		b = msh_astnode(l);
		ft_btree_clear(&b, (t_gfunction) & msh_ast_clear);
		ft_list_pop(&l);
	}
	return (NULL);
}

t_btree		*msh_astnode_new(t_ast_type type, t_list *sequence)
{
	t_ast *a;

	if (!(a = malloc(sizeof(t_ast))))
		msh_abort("ast");
	a->type = type;
	a->sequence = type == AST_PROCESS ? sequence : NULL;
	return (ft_btree_new(a));
}
