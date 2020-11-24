/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:57:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 16:38:27 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H
# include "environment.h"
# include "shell.h"

/*
** All existing redirections.
*/
enum			e_redirect_type
{
	REDIR_INPUT,
	REDIR_HEREDOC_INPUT,
	REDIR_OUTPUT,
	REDIR_APPENDING_OUTPUT
};
typedef enum e_redirect_type	t_redirect_type;

/*
** List of all redirections for one process.
** type:	type of the redirection
** path:	path to the redirected file
*/
struct			s_redirect
{
	t_redirect_type	type;
	char			*path;
};
typedef struct s_redirect	t_redirect;

/*
** Represents a single process.
** argv:		an array which contains command arguments
** redirection:	a list which contains redirections
*/
struct			s_process
{
	char	**argv;
	t_list	*redirection;
	pid_t	pid;
};
typedef struct s_process		t_process;

/*
** Free a single process.
*/
void			process_clear(t_process *p);

/*
** Creates a new single process.
*/
t_process		*process_new(char **argv, t_list *redirection);

/*
** Print a single process.
*/
void			process_print(t_process *process);

/*
** Execute a list of process.
*/
int				process_run(t_shell *shell, t_list *process);

/*
** Redirect a process
*/
int				redirect(t_process *process);

/*
** Redirect back STDIN and STDOUT to their original values
*/
void			undirect(int input, int output);

/*
** Free a single redirection.
*/
void			redirect_clear(t_redirect *r);

/*
** Creates a new redirection.
*/
t_redirect		*redirect_new(t_redirect_type type, char *path);

/*
** Get the redirection type from a string.
** Returns -1 if unknown.
*/
t_redirect_type	redirect_type(const char *value);

/*
** Execute processes
*/
int				process_exec(t_list *process, t_shell *shell);

#endif
