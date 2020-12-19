/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:59:25 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/18 16:29:06 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdbool.h>

# define MSH_ERR	"minishell: %s: %s\n"

/*
** Prints and error message using the errno variable and exit.
** Used for fatal errors handling.
*/
void		msh_abort(const char *section);

/*
** Prints and error message using the errno variable and exit.
** Used for fatal errors handling.
*/
void		msh_exit(void);

/*
** Allocates a string which contains the absolute path of the current working
** directory.
** Returns NULL on error.
*/
char		*msh_getcwd(void);

/*
** Returns true if path is pointing to a directory.
*/
bool		msh_isdir(const char *path);

/*
** NULL protected.
** Returns s1 + delim + s2, freeing s1 or s2 if necessary.
*/
char		*msh_join(char *s1, const char *delim, char *s2);

/*
** Prints and error message using the format defined by MSH_ERR.
*/
void		msh_perror(const char *section, const char *message);

/*
** Call msh_perror and returns the ret value.
*/
int			msh_perrorr(const char *section, const char *message, int ret);

/*
** Returns the message associated with the value of errno.
*/
const char	*msh_strerrno(void);

/*
** Returns the message associated with the given signal number.
** Returns NULL in case of unknown or unsupported signal.
*/
const char	*msh_strsig(int signum);

#endif
