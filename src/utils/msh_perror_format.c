/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_perror_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:23:23 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/08 15:28:08 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft/ft_stdio.h"
#include "const.h"

void	msh_perror_format(const char *format, ...)
{
	va_list l;

	ft_putstr_fd(MSH ": ", STDERR_FILENO);
	va_start(l, format);
	ft_vdprintf(STDERR_FILENO, format, l);
	va_end(l);
	ft_putchar_fd('\n', STDERR_FILENO);
}
