/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:49:16 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/02 16:04:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast		*ast(t_btree *element)
{
	return (element ? element->content : NULL);
}

t_ast_type	ast_type(const char *value)
{
	if (!ft_strcmp(value, "&&"))
		return (AST_AND);
	else if (!ft_strcmp(value, "||"))
		return (AST_OR);
	return (-1);
}
