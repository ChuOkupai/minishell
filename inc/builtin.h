/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:15:40 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/26 18:28:56 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "environment.h"
# include "shell.h"

/*
** Check if a variable name is valid
*/
int		msh_check_name(char *name);

/*
** The echo utility writes any specified operands, separated by single blank
** (` ') characters and followed by a newline (`\n') character, to the
** standard output.
** The following option is available:
** -n    Do not print the trailing newline character.
*/
int		msh_echo(char **argv, t_shell *shell);

/*
** Print working directory name
*/
int		msh_pwd(char **argv, t_shell *shell);

/*
** Export arguments as environment variables
*/
int		msh_export(char **argv, t_shell *shell);

/*
** Change the current working directory
*/
int		msh_cd(char **argv, t_shell *shell);

/*
** Print the list of environment variables
*/
int		msh_env(char **argv, t_shell *shell);

/*
** Exit the minishell
*/
int		exit(char **argv, t_shell *shell);

#endif
