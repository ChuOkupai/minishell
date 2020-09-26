/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:25:49 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/26 16:00:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include "libft.h"
# include "termcaps.h"

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
** env:			environment
** hist:		commands history
** histcursize:	current size of history
** histsize:	max size of history
** stdin:		input file stream
** term;		structure for termcaps
** keep:		loop as long as this variable is set to true
** opt:			set of enabled options
** ps1:			primary prompt value
*/
typedef struct s_shell	t_shell;
struct	s_shell
{
	t_env		*env;
	t_list		*hist;
	size_t		histcursize;
	size_t		histsize;
	t_file		*stdin;
	t_term		*term;
	bool		keep;
	t_option	opt;
	char		*ps1;
};

/*
** Free a shell.
** Returns NULL.
*/
void	*msh_shell_clear(t_shell *shell);

/*
** Initialize a new shell.
** Returns NULL on error.
*/
t_shell	*msh_shell_new(int ac, char **av, char **env);

/*
** Execute a shell that loops indefinitely as long as the user does not exit the
** program.
** Returns the exit status.
*/
int		msh_shell_run(t_shell *shell);

#endif
