/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:44:27 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 13:58:13 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
# include "libft.h"

/*
** list:		list of environment variables
** array:		contains all the variables stored in the env list.
** status:		status of the last command
** status_val:	status converted as a char*
*/
typedef struct s_env	t_env;
struct		s_env
{
	t_list	*list;
	char	**array;
	int		status;
	char	*status_val;
};

/*
** Initialize the environment from an array of environment variables.
*/
void		env_init(t_env *env, char **env_array);

/*
** Clear the environment.
*/
void		env_clear(t_env *environment);

/*
** Expands a string using the given environment.
** Returns a new allocated string or NULL on failure.
*/
char		*env_expand(t_env *env, char *s);

/*
** Searches the environment to find the environment variable name,
** and returns a pointer to the corresponding value string.
** Returns NULL if not found.
*/
const char	*env_get(t_env *env, const char *name);

/*
** Same as env_get except it takes a maximum size for name.
** Returns NULL if not found.
*/
const char	*env_getn(t_env *env, const char *name, size_t n);

/*
** Add or edit a variable using the given environment.
*/
void		env_set(t_env *env, const char *name, const char *value);

/*
** Set and return the $? variable.
*/
int			env_setstatus(t_env *env, int value);

/*
** Deletes a variable in the environment.
*/
void		env_unset(t_env *env, const char *name);

#endif
