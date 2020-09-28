/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:25:49 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 17:26:25 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include <termios.h>
# include "environment.h"

/*
** list:		list of commands (char*)
** size:		current size of history
** histsize:	max size of history ($HISTSIZE)
*/
typedef struct s_history	t_history;
struct	s_history
{
	t_list	*commands;
	size_t	size;
	size_t	histsize;
};

/*
** buf:			line buffer
** ps1:			primary prompt value
** stream:		input file stream (set to STDIN_FILENO)
** alloc_size:	max buffer size
** size:		current buffer size
*/
typedef struct s_line	t_line;
struct	s_line
{
	char		*buf;
	char		*ps1;
	t_file		*stream;
	size_t		alloc_size;
	size_t		size;
};

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
** backup:	save the old termios settings
** type:	terminal type ($TERM)
** init:	true if backup has been initialized
*/
typedef struct termios	t_termios;
typedef struct s_terminal	t_terminal;
struct	s_terminal
{
	t_termios	backup;
	char		*type;
	bool		init;
};

/*
** env:			environment
** history:		commands history cache
** line:		line editing cache
** options:		set of enabled options
** pwd:			working directory cache
** terminal:	terminal settings
** keep:		loop as long as this variable is set to true
*/
typedef struct s_shell	t_shell;
struct	s_shell
{
	t_env		env;
	t_history	history;
	t_line		line;
	t_option	options;
	t_pwd		pwd;
	t_terminal	terminal;
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
** Reads the next line.
** The line must not be passed to free.
** Returns -1 on error, else 0.
*/
int		msh_shell_readline(t_shell *shell);

/*
** Execute a shell that loops indefinitely as long as the user does not exit the
** program.
** Returns the exit status.
*/
int		msh_shell_run(t_shell *shell);

#endif
