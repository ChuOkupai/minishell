/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:56:49 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/10 18:26:41 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ast.h"

void		msh_ast_clear(t_ast *node)
{
	if (node->type == AST_COMMANDS)
		ft_list_clear(&node->commands, (t_gfunction) & msh_command_clear);
	free(node);
}
