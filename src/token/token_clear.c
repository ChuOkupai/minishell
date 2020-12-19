/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:31:09 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/08 04:29:34 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"

void	token_clear(t_token *t)
{
	if (!token_is_dynamic(t))
		return ;
	ft_free(t->value);
	ft_free(t);
}
