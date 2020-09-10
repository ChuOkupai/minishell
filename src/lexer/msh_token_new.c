/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:04:39 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/10 00:11:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lexer.h"
#include "utils.h"

t_token	*msh_token_new(char *value, size_t size)
{
	t_token *t;

	if (!(t = malloc(sizeof(t_token))) || !value)
		msh_abort();
	t->type = TOKEN_WORD;
	t->value = value;
	t->size = size;
	return (t);
}
