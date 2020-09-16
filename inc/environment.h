/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:44:27 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/16 13:33:25 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
# include "libft.h"

/*
** Initialize a new environment from an array of environment variables.
*/
t_list		*msh_env_init(char **env);

/*
** Searches the environment list to find the environment variable name,
** and returns a pointer to the corresponding value string.
** Returns NULL if not found.
*/
const char	*msh_env_get(t_list *env, const char *name);

/*
** Add or edit a variable using the given environment list.
*/
void		msh_env_set(t_list **env, const char *name, const char *value);

/*
** Deletes a variable in the environment list.
*/
void		msh_env_unset(t_list **env, const char *name);

#endif
