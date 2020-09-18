/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:57:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/18 17:59:31 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H
# include "libft.h"

/*
** All existing redirections.
*/
enum				e_redirection_type
{
	INPUT,
	HEREDOC_INPUT,
	OUTPUT,
	APPENDING_OUTPUT
};
typedef enum e_redirection_type	t_redirection_type;

/*
** List of all redirections for one process.
** type:	type of the redirection
** path:	path to the redirected file
*/
struct				s_redirection
{
	t_redirection_type	type;
	char				*path;
};
typedef struct s_redirection	t_redirection;

/*
** Represents a single process.
** argv:		an array which contains command arguments
** redirection:	a list which contains redirections
*/
struct				s_process
{
	char	**argv;
	t_list	*redirection;
};
typedef struct s_process		t_process;

/*
** Free a single redirection.
*/
void				msh_redirect_clear(t_redirection *r);

/*
** Creates a new redirection.
*/
t_redirection		*msh_redirect_new(t_redirection_type type, char *path);

/*
** Get the redirection type from a string.
** Returns -1 if unknown.
*/
t_redirection_type	msh_redirect_type(const char *value);

/*
** Free a single process.
*/
void				msh_process_clear(t_process *p);

/*
** Creates a new single process.
*/
t_process			*msh_process_new(char **argv, t_list *redirection);

/*
** Print a single process.
*/
void				msh_process_print(t_process *process);

/*
** Pipe a list of process.
*/
void				msh_pipe(t_list *process, t_list *env);

/*
** Redirect and execute a process
*/
void				msh_redirect(t_process *process, t_list *env);

#endif
