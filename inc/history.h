/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:27:16 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/24 13:53:53 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H
# include "libft.h"

/*
** list:		list of lines in history stored as char*
** size:		current size of command history
** histsize:	max size of command history
*/
typedef struct s_history	t_history;
struct	s_history
{
	t_list	*list;
	size_t	size;
	size_t	histsize;
};

/*
** Initializes command history (histsize set to MSH_HISTORY_SIZE).
*/
void	history_init(t_history *history);

/*
** Clears command history.
*/
void	history_clear(t_history *history);

/*
** Adds a new entry into the command history.
** The function makes a copy of the string.
** Returns -1 on error, else 0.
*/
int		history_add(t_history *history, const char *string);

/*
** Replaces the entry at index i with a new string.
** The function makes a copy of the string.
** The index must be valid.
** Returns -1 on error, else 0.
*/
int		history_edit(t_history *history, const char *string, size_t i);

/*
** Sets a new size for the command history.
*/
void	history_resize(t_history *history, size_t size);

#endif
