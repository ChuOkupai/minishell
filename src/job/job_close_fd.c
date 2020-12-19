/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_close_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:46:35 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/08 17:47:29 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

static void	close_if_necessary(int fd, int old_fd, bool restore)
{
	if (fd != old_fd)
	{
		if (restore)
			dup2(fd, old_fd);
		close(fd);
	}
}

void		job_close_fd(int input, int output, bool restore)
{
	close_if_necessary(input, STDIN_FILENO, restore);
	close_if_necessary(output, STDOUT_FILENO, restore);
}
