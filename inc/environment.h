/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:44:27 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/21 18:32:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
# include "libft.h"

/*
** list:		list of environment variables
** array:		contains all the variables stored in the env list.
** status:		status of the last command ($?)
** status_val:	status converted as a string
** pwd:			pwd buffer
*/
typedef struct s_env	t_env;
struct		s_env
{
	t_list		*list;
	char		**array;
	int			status;
	char		*status_val;
	char		*pwd;
};

/*
** Free an environment.
** Returns NULL.
*/
void		*msh_env_clear(t_env *e);

/*
** Expands a string using the given environment.
** Returns a new allocated string or NULL on failure.
*/
char		*msh_env_expand(t_env *env, char *s);

/*
** Searches the environment to find the environment variable name,
** and returns a pointer to the corresponding value string.
** Returns NULL if not found.
*/
const char	*msh_env_get(t_env *env, const char *name);

/*
** Initialize a new environment from an array of environment variables.
*/
t_env		*msh_env_new(char **env);

/*
** Add or edit a variable using the given environment.
** Returns -1 on error, else 0.
*/
int			msh_env_set(t_env *env, const char *name, const char *value);

/*
** Set the $? variable.
*/
void		msh_env_setstatus(t_env *env, int status);

/*
** Deletes a variable in the environment.
*/
void		msh_env_unset(t_env *env, const char *name);

#endif
