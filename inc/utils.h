/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:59:25 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 14:44:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
** Prints and error message using the errno variable and exit.
** Used for fatal errors handling.
*/
void	msh_abort(const char *section);

/*
** Prints and error message using the given format.
** Used for errors handling.
*/
void	msh_perror(const char *format, ...);

/*
** Prints and error message using the given format.
** Used for errors handling.
** Returns the ret value.
*/
int		msh_perrorr(int ret, const char *format, ...);

#endif
