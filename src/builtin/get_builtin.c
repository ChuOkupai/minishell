/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:08:17 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/09 00:14:09 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static t_builtin	find(const char *bin, const t_builtin_pair *pair, size_t n)
{
	if (!n)
		return (NULL);
	if (!ft_strcmp(bin, pair->bin))
		return (pair->function);
	return (find(bin, pair + 1, n - 1));
}

t_builtin			get_builtin(const char *bin)
{
	static const t_builtin_pair	lexer[] = {
		{ "cd", &builtin_cd },
		{ "echo", &builtin_echo },
		{ "env", &builtin_env },
		{ "exit", &builtin_exit },
		{ "export", &builtin_export },
		{ "pwd", &builtin_pwd },
		{ "unset", &builtin_unset }
	};

	if (!bin)
		return (NULL);
	return (find(bin, lexer, sizeof(lexer) / sizeof(*lexer)));
}
