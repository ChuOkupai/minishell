/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:12:37 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/11 16:34:19 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libft/ft_stdio.h"
#include "const.h"
#include "utils.h"

int		msh_compare_pointer(const void *a, const void *b)
{
	return (a != b);
}

void	msh_perror(const char *message)
{
	ft_dprintf(STDERR_FILENO, MSH ": %s\n", message);
}

void	msh_abort(void)
{
	msh_perror(strerror(errno));
	exit(EXIT_FAILURE);
}

void	msh_perror_format(const char *format, ...)
{
	va_list l;

	ft_putstr_fd(MSH ": ", STDERR_FILENO);
	va_start(l, format);
	ft_vdprintf(STDERR_FILENO, format, l);
	va_end(l);
	ft_putchar_fd('\n', STDERR_FILENO);
}
