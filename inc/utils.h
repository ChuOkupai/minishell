/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:59:25 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/08 17:02:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
** Prints and error message using the errno variable and exit.
** Used for fatal errors handling (such as a failed malloc).
*/
void	msh_abort(void);

/*
** Prints and error message.
** Used for error handling.
*/
void	msh_perror(const char *message);

/*
** Prints and error message using the given format.
** Used for error handling.
*/
void	msh_perror_format(const char *format, ...);

/*
** Prints and unexpected token error message.
** Used for error handling.
*/
void	msh_perror_unexpected(char token);

#endif
