/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:57:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/03 14:36:45 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H
# include "environment.h"
# include "libft.h"
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
struct			s_redirection
{
	t_redirect_type	type;
	char			*path;
};
typedef struct s_redirection	t_redirection;

/*
** Represents a single process.
** argv:		an array which contains command arguments
** redirection:	a list which contains redirections
*/
struct			s_process
{
	char	**argv;
	t_list	*redirection;
};
typedef struct s_process		t_process;

/*
** Free a single process.
*/
void			msh_process_clear(t_process *p);

/*
** Creates a new single process.
*/
t_process		*msh_process_new(char **argv, t_list *redirection);

/*
** Print a single process.
*/
void			msh_process_print(t_process *process);

/*
** Execute a pipe-lined list of process.
*/
int				msh_pipe(t_list *process, t_env *env);

/*
** Redirect a process
*/
int				msh_redirect(t_process *process);

/*
** Redirect back STDIN and STDOUT to their original values
*/
void			msh_undirect(int input, int output);

/*
** Free a single redirection.
*/
void			msh_redirect_clear(t_redirection *r);

/*
** Creates a new redirection.
*/
t_redirection	*msh_redirect_new(t_redirect_type type, char *path);

/*
** Get the redirection type from a string.
** Returns -1 if unknown.
*/
t_redirect_type	msh_redirect_type(const char *value);

/*
** Execute processes
*/
int				msh_process_exec(t_list *process, t_shell *shell);

/*
** Find for a process into the PATH
*/
char			*msh_path(char *name, t_env *env);

#endif
