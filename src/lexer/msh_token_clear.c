/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:34:01 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/10 00:11:50 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lexer.h"

void	msh_token_clear(t_token *t)
{
	if (t->type != TOKEN_WORD)
		return ;
	free(t->value);
	free(t);
}
