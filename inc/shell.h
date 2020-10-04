/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:25:49 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/04 14:16:31 by asoursou         ###   ########.fr       */
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
** ps2:			secondary prompt value
** line_no:		current line number
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
	char		*ps2;
	size_t		line_no;
	bool		keep;
};

/*
** Initialize a new shell.
** Returns -1 on error.
*/
int		msh_shell_init(t_shell *shell, int ac, char **av, char **env);

/*
** Destroy a shell.
*/
void	msh_shell_clear(t_shell *shell);

/*
** Reads the next multiline command.
** Returns a list of ASTs.
*/
t_list	*msh_shell_read_command(t_shell *shell);

/*
** Execute a shell that loops indefinitely as long as the user does not exit
** the program.
** Returns the exit status.
*/
int		msh_shell_run(t_shell *shell);

#endif
