/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:25:49 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/16 13:37:13 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include "libft.h"

/*
** dump_states: show states when tokens are checked in the finite state machine.
** dump_tokens:	show the tokenization process
*/
typedef struct s_option	t_option;
struct	s_option
{
	bool	dump_states;
	bool	dump_tokens;
};

/*
** env:		list of environment variables
** keep:	loop as long as this variable is set to true
** stdin:	input file stream
*/
typedef struct s_shell	t_shell;
struct	s_shell
{
	t_list		*env;
	bool		keep;
	t_option	opt;
	t_file		*stdin;
};

/*
** Free a shell.
*/
void	msh_shell_clear(t_shell *shell);

/*
** Initialize a new shell.
*/
t_shell	*msh_shell_init(char **env);

/*
** Execute a shell that loops indefinitely as long as the user does not exit the
** program.
** Returns the exit status.
*/
int		msh_shell_run(t_shell *shell);

#endif
