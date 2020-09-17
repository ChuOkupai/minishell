/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:59:25 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/17 17:36:53 by asoursou         ###   ########.fr       */
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
** Compares two pointer.
** Returns 0 if the two addresses are identical.
*/
int		msh_compare_pointer(const void *a, const void *b);

/*
** Prints and error message using the given format.
** Used for errors handling.
*/
void	msh_perror(const char *format, ...);

#endif
