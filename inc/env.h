/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:44:27 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/11 14:43:49 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "libft.h"

# define ENV_BUFSIZE	4

/*
** value:	status of the last command
** buf:		status converted as a char*
*/
typedef struct s_status	t_status;
struct		s_status
{
	int		value;
	char	*buf;
};

/*
** array:		contains all the variables.
** size:		current size of the array
** capacity:	maximum capacity of the array
** status:		status cache
*/
typedef struct s_env	t_env;
struct		s_env
{
	char		**array;
	size_t		size;
	size_t		capacity;
	t_status	status;
};

void		env_init(t_env *env, char **env_array);
void		env_clear(t_env *environment);

/*
** Get the absolute path to a binary file.
** Returns NULL if not found.
*/
char		*env_abspath(const t_env *env, const char *bin);

/*
** Appends value to a variable using the given environment.
** n MUST be less than or equal to the length of name.
*/
void		env_appendn(t_env *env, const char *name, const char *value,
			size_t n);

/*
** Searches the environment to find the environment variable name,
** and returns a pointer to the corresponding value string.
** Returns NULL if not found.
*/
const char	*env_get(const t_env *env, const char *name);

/*
** Same as env_get except it takes a maximum size for name.
** n MUST be less than or equal to the length of name.
** Returns NULL if not found.
*/
const char	*env_getn(const t_env *env, const char *name, size_t n);

/*
** Utility function.
** Finds the index at which a value is stored in the environment.
** max MUST be less than or equal to the length of name.
** Returns env->size if not found.
*/
size_t		env_index(const t_env *env, const char *name, size_t max);

/*
** Add or edit a variable using the given environment.
*/
void		env_set(t_env *env, const char *name, const char *value);

/*
** Same as env_set except it takes a maximum size for name.
** n MUST be less than or equal to the length of name.
** Returns NULL if not found.
*/
void		env_setn(t_env *env, const char *name, const char *value, size_t n);

/*
** Set and return the $? variable.
*/
int			env_setstatus(t_env *env, int value);

/*
** Deletes a variable in the environment.
*/
void		env_unset(t_env *env, const char *name);

/*
** Returns the size of a variable name.
*/
size_t		env_varlen(const char *s);

#endif
