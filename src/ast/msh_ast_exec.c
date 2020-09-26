/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:45:28 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/26 20:13:42 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "process.h"
#include "shell.h"

int	msh_ast_exec(t_btree *root, t_shell *shell)
{
	t_ast	*a;
	int		r;

	a = msh_ast(root);
	if (a->type == AST_PROCESS)
		return (msh_process_exec(a->sequence, shell));
	r = msh_ast_exec(root->left, shell);
	if (a->type == AST_AND)
		return (r ? r : msh_ast_exec(root->right, shell));
	return (r ? msh_ast_exec(root->right, shell) : 0);
}
