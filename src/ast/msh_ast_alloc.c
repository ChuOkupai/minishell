/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:42:43 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/18 16:37:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ast.h"
#include "utils.h"

void	msh_ast_clear(t_ast *node)
{
	if (node->type == AST_PROCESS)
		ft_list_clear(&node->sequence, (t_gfunction) & msh_process_clear);
	free(node);
}

t_btree	*msh_ast_new(t_ast_type type, t_list *sequence)
{
	t_ast *a;

	if (!(a = malloc(sizeof(t_ast))))
		msh_abort("ast");
	a->type = type;
	a->sequence = type == AST_PROCESS ? sequence : NULL;
	return (ft_btree_new(a));
}
