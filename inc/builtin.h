/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:15:40 by gdinet            #+#    #+#             */
/*   Updated: 2020/12/09 03:51:05 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "shell.h"

# define INVALID_ID		"minishell: %s: `%s': not a valid identifier\n"
# define ARG_TOOMANY	"too many arguments"

typedef int	(*t_builtin)(char **, t_shell *);

typedef struct s_builtin_pair	t_builtin_pair;
struct		s_builtin_pair
{
	const char		*bin;
	const t_builtin	function;
};

/*
** The echo utility writes any specified operands, separated by single blank
** (` ') characters and followed by a newline (`\n') character, to the
** standard output.
** The following option is available:
** -n    Do not print the trailing newline character.
*/
int			builtin_echo(char **argv, t_shell *shell);

/*
** Print working directory name
*/
int			builtin_pwd(char **argv, t_shell *shell);

/*
** Export arguments as environment variables
*/
int			builtin_export(char **argv, t_shell *shell);

/*
** Change the current working directory
*/
int			builtin_cd(char **argv, t_shell *shell);

/*
** Print the list of environment variables
*/
int			builtin_env(char **argv, t_shell *shell);

/*
** Exit the minishell
*/
int			builtin_exit(char **argv, t_shell *shell);

/*
** Unset an environment variable
*/
int			builtin_unset(char **argv, t_shell *shell);

/*
** NULL protected.
** Finds the builtin function matching name.
** Return NULL if not found.
*/
t_builtin	get_builtin(const char *bin);

#endif
