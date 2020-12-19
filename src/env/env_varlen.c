/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_varlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:04:39 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/04 16:39:36 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isvar(int c)
{
	return (ft_isalnum(c) || c == '_');
}

size_t		env_varlen(const char *s)
{
	return (ft_strwhile(s, &isvar) - s);
}
