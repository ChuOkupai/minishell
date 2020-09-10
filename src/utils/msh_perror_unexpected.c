/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_perror_unexpected.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:01:08 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/08 17:02:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/ft_stdio.h"
#include "const.h"

void	msh_perror_unexpected(char token)
{
	ft_dprintf(STDERR_FILENO, MSH ": syntax error near unexpected token `%c'\n",
	token);
}
