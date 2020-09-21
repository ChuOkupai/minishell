/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:45:28 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/21 15:03:30 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "process.h"

int	msh_ast_exec(t_btree *root, t_list *env)
{
	t_ast	*a;
	int		r;

	a = msh_ast(root);
	if (a->type == AST_PROCESS)
		return (msh_process_exec(a->sequence, env));
	r = msh_ast_exec(root->left, env);
	if (a->type == AST_AND)
		return (r ? r : msh_ast_exec(root->right, env));
	return (r ? msh_ast_exec(root->right, env) : 0);
}
