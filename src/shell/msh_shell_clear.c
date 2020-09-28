/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:10:33 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 18:00:41 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

static void	history_clear(t_history *h)
{
	ft_list_clear(&h->commands, &free);
}

static void	line_clear(t_line *l)
{
	ft_memdel(l->buf);
	ft_memdel(l->ps1);
	if (l->stream)
		ft_fclose(l->stream);
}

static void	terminal_clear(t_terminal *t)
{
	if (t->init)
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &t->backup);
	ft_memdel(t->type);
}

void		*msh_shell_clear(t_shell *shell)
{
	if (shell)
	{
		msh_env_clear(&shell->env);
		history_clear(&shell->history);
		line_clear(&shell->line);
		terminal_clear(&shell->terminal);
		free(shell);
	}
	return (NULL);
}
