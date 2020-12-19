/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:25:49 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/19 15:23:22 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include <stddef.h>
# include "env.h"
# include "readline.h"

# define MSH_PS1	"\x1B[92m$USER\x1B[0m: \x1B[94mminishell\x1B[0m $ "
# define MSH_PS2	"> "

/*
** OPT_DUMP_AST:	show the abstract syntax tree
** OPT_DUMP_EXEC:	show the arguments after expansion
** OPT_DUMP_TOKENS:	show the tokenization process
*/
enum	e_option
{
	OPT_DUMP_AST = 1,
	OPT_DUMP_EXEC = 1 << 1,
	OPT_DUMP_TOKENS = 1 << 2
};
typedef enum e_option	t_option;

/*
** env:			environment
** readline:	line buffering
** options:		set of enabled options
** asts:		list of ASTs waiting for execution
** ps1:			primary prompt value
** ps2:			secondary prompt value
** keep:		loop as long as this variable is set to true
** discard:		ctrl+C flag for readline
** showps2:		show ps2 instead of ps1 in case of Ctrl+\
** job:			current active job
*/
struct	s_shell
{
	t_env		env;
	t_readline	readline;
	t_option	options;
	t_list		*asts;
	char		*ps1;
	char		*ps2;
	bool		keep;
	bool		discard;
	bool		showps2;
	t_list		*job;
};
typedef struct s_shell	t_shell;

/*
** Initialize a new shell.
** Returns -1 on error.
*/
int		shell_init(t_shell *shell, int ac, char **av, char **env);

void	shell_clear(t_shell *shell);

/*
** Execute a shell that loops indefinitely as long as the user does not exit
** the program.
** Returns the exit status.
*/
int		shell_run(t_shell *shell);

/*
** Reset signal functions for current shell.
*/
void	shell_hook(t_shell *shell);

/*
** Returns true if the shell has been interrupted by a signal.
*/
bool	shell_interrupted(void);

/*
** Reads the next multiline command.
** Returns a valid list of tokens, or NULL if the expression was invalid.
*/
t_list	*shell_read_command(t_shell *shell);

/*
** Update the value of ps1 and ps2 (prompt values)
*/
void	shell_update_prompts(t_shell *s);

#endif
