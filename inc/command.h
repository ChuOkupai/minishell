/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 01:57:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/10 02:06:55 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include "libft.h"

/*
** Represents a command.
** args:         a list of arguments
** redirections: a list of redirections
** status:       exit code
*/
struct	s_command
{
	t_list	*args;
	t_list	*redirections;
	int		status;
};
typedef struct s_command	t_command;

/*
** All possible redirection operator in t_redirection.
*/
enum	e_redirection_op
{
	REDIRECTION_IN,
	REDIRECTION_IN2,
	REDIRECTION_OUT,
	REDIRECTION_OUT2
};
typedef enum e_redirection_op	t_redirection_op;

/*
** Represents a redirection.
** op:   redirection operator
** path: path to file
*/
struct	s_redirection
{
	t_redirection_op	op;
	char				*path;
};
typedef struct s_redirection	t_redirection;

#endif
