/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:57:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/19 12:30:20 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H
# include "redir.h"
# include "shell.h"

/*
** Represents a single process.
** args:		list of arguments before expansion
** argv:		array of arguments after expansion
** redirection:	a list which contains redirections
** terminated:	true if the process is terminated
** status:		return value
** pid:			current process pid
*/
struct		s_process
{
	t_list	*args;
	char	**argv;
	t_list	*redirection;
	bool	terminated;
	int		status;
	pid_t	pid;
};
typedef struct s_process	t_process;

t_process	*process_new(t_list *args, t_list *redirection);
void		process_clear(t_process *p);

/*
** Launch a process.
*/
void		process_exec(t_process *p, t_shell *s);

/*
** Expand all the arguments stored in the process.
*/
void		process_expand(t_process *p, const t_env *env);

/*
** Fork a process.
** Arguments and redirects are removed in the parent.
** Returns the value of fork.
*/
pid_t		process_fork(t_process *p);

/*
** Kill the current process using the given signal if it is not terminated.
*/
void		process_kill(const t_process *p, int signum);

/*
** Print a single process.
*/
void		process_print(const t_process *p);

/*
** Do all redirections of a process.
** Returns -1 on error, elso 0.
*/
int			process_redirect(const t_process *p);

/*
** Mark the current process as terminated with the given status.
*/
void		process_terminate(t_process *p, int status);

/*
** Returns a process structure, from a generic pointer type.
*/
t_process	*process(void *content);

#endif
