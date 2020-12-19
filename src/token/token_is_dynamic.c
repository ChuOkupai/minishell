/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_is_dynamic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:48:29 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/08 00:49:04 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

bool	token_is_dynamic(const t_token *t)
{
	return (t->type == TOKEN_WORD || t->type == TOKEN_MULTILINE);
}
