/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:49:16 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/11 16:24:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ast.h"
#include "utils.h"

t_ast	*msh_ast(t_btree *element)
{
	return (element ? element->content : NULL);
}

void	msh_ast_clear(t_ast *node)
{
	free(node);
}

t_ast	*msh_ast_new(t_ast_type type)
{
	t_ast *a;

	if (!(a = malloc(sizeof(t_ast))))
		msh_abort();
	a->type = type;
	return (a);
}
