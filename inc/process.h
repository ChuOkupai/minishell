/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:57:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/11 17:42:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H
# include "libft.h"

/*
** Represents a single process.
** argv:	an array which contains command arguments
*/
struct		s_process
{
	char **argv;
};
typedef struct s_process	t_process;

/*
** Free a single process.
*/
void		msh_process_clear(t_process *p);

/*
** Creates a new single process.
*/
t_process	*msh_process_new(char **argv);

#endif
