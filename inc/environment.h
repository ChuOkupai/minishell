/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:44:27 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/19 14:48:19 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
# include "libft.h"

/*
** Expands a string using the given environment.
** Returns a new allocated string or NULL on failure.
*/
char		*msh_env_expand(t_list *env, char *s);

/*
** Searches the environment list to find the environment variable name,
** and returns a pointer to the corresponding value string.
** Returns NULL if not found.
*/
const char	*msh_env_get(t_list *env, const char *name);

/*
** Initialize a new environment from an array of environment variables.
*/
t_list		*msh_env_new(char **env);

/*
** Add or edit a variable using the given environment list.
** Returns -1 on error, else 0.
*/
int			msh_env_set(t_list **env, const char *name, const char *value);

/*
** Deletes a variable in the environment list.
*/
void		msh_env_unset(t_list **env, const char *name);

#endif
