/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:13:42 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/09 19:02:26 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOB_H
# define JOB_H
# include "process.h"

/*
** Close input and output if necessary to prevent file descriptor leaks.
*/
void	job_close_fd(int input, int output, bool restore);

/*
** Creates a temporary file for all heredoc redirections.
*/
void	job_create_heredoc(t_list *j, t_shell *s);

/*
** Execute a sequence of processes.
** Returns the status of the last process.
*/
int		job_exec(t_list *job, t_shell *shell);

/*
** Expands all arguments in the sequence of processes.
*/
void	job_expand(t_list *j, t_env *env);

/*
** Fork a sequence of processes connected with pipe.
*/
void	job_fork(t_list *j, t_shell *s, int input);

/*
** Kill all non terminated process using the given signal.
*/
void	job_kill(const t_list *job, int signum);

/*
** Marks the process has terminated.
*/
void	job_mark_process(t_list *j, pid_t pid, int status);

/*
** Prints a sequence of processes.
*/
void	job_print(const t_list *j);

/*
** Wait until all processes are completed.
** Returns the status of the last process.
*/
void	job_wait(t_list *j);

#endif
