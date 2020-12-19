/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_perrorr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:22:28 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/08 18:29:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	msh_perrorr(const char *section, const char *message, int ret)
{
	msh_perror(section, message);
	return (ret);
}
