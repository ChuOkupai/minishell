/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:26:21 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/08 20:04:28 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"

void	token_print(const t_token *t)
{
	ft_printf((token_is_dynamic(t) ? "[%s]" : "%s"), t->value);
}
