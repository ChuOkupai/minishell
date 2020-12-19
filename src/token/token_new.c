/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:10:47 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/08 04:30:28 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"

t_token	*token_new(t_token_type type, char *value)
{
	t_token *t;

	t = ft_malloc(sizeof(t_token));
	t->type = type;
	t->value = value;
	return (t);
}
