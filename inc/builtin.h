/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:15:40 by gdinet            #+#    #+#             */
/*   Updated: 2020/09/21 20:07:16 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "environment.h"

/*
** The echo utility writes any specified operands, separated by single blank
** (` ') characters and followed by a newline (`\n') character, to the
** standard output.
** The following option is available:
** -n    Do not print the trailing newline character.
*/
int		msh_echo(char **argv);

/*
** Print working directory name
*/
int		msh_pwd(char **argv);

/*
** Export arguments as environment variables
*/
int		msh_export(char **argv, t_env *env);

#endif
