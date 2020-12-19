/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:41:02 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/08 04:30:44 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"

char	*token_pop(t_token *t)
{
	char *value;

	value = t->value;
	if (token_is_dynamic(t))
		ft_free(t);
	return (value);
}
