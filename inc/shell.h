/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:25:49 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/30 16:40:15 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include "environment.h"
# include "readline.h"

/*
** dump_tokens:	show the tokenization process
** dump_ast:	show the AST before execution
*/
typedef struct s_option	t_option;
struct	s_option
{
	bool	dump_tokens;
	bool	dump_ast;
};

/*
** pwd:		pwd buffer
** oldpwd:	old pwd buffer
** size:	size of pwd buffer
*/
typedef struct s_pwd	t_pwd;
struct	s_pwd
{
	char	*pwd;
	char	*oldpwd;
	size_t	size;
};

/*
** env:			environment
** readline:	line editing
** history:		command history
** options:		set of enabled options
** pwd:			working directory cache
** ps1:			primary prompt value
** keep:		loop as long as this variable is set to true
*/
typedef struct s_shell	t_shell;
struct	s_shell
{
	t_env		env;
	t_readline	readline;
	t_history	history;
	t_option	options;
	t_pwd		pwd;
	char		*ps1;
	bool		keep;
};

/*
** Initialize a new shell.
** Returns NULL on error.
*/
t_shell	*msh_shell_new(int ac, char **av, char **env);

/*
** Free a shell.
** Returns NULL.
*/
void	*msh_shell_clear(t_shell *shell);

/*
** Execute a shell that loops indefinitely as long as the user does not exit
** the program.
** Returns the exit status.
*/
int		msh_shell_run(t_shell *shell);

#endif
