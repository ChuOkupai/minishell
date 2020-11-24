/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:45:28 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 14:47:39 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "process.h"
#include "shell.h"

int	ast_exec(t_btree *root, t_shell *shell)
{
	t_ast	*a;
	int		r;

	a = ast(root);
	if (a->type == AST_PROCESS)
		return (process_exec(a->sequence, shell));
	r = ast_exec(root->left, shell);
	if (a->type == AST_AND)
		return (r ? r : ast_exec(root->right, shell));
	return (r ? ast_exec(root->right, shell) : 0);
}
