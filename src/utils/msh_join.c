/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:05:34 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/07 20:08:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*msh_join(char *s1, const char *delim, char *s2)
{
	char *s;

	s = ft_strjoin3(s1, delim, s2);
	ft_free(s1);
	ft_free(s2);
	return (s);
}
