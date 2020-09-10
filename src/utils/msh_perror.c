/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_perror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:01:58 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/06 14:15:54 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/ft_stdio.h"
#include "const.h"

void	msh_perror(const char *message)
{
	ft_dprintf(STDERR_FILENO, MSH ": %s\n", message);
}
