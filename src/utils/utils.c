/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:12:37 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 17:01:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libft/ft_stdio.h"
#include "const.h"

void	msh_abort(const char *section)
{
	ft_dprintf(STDERR_FILENO, MSH_ERR "%s: %s\n", section, strerror(errno));
	exit(EXIT_FAILURE);
}

void	msh_perror(const char *format, ...)
{
	va_list l;

	va_start(l, format);
	ft_vdprintf(STDERR_FILENO, format, l);
	va_end(l);
	ft_putchar_fd('\n', STDERR_FILENO);
}

int		msh_perrorr(int ret, const char *format, ...)
{
	va_list l;

	va_start(l, format);
	ft_vdprintf(STDERR_FILENO, format, l);
	va_end(l);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (ret);
}
