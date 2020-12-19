/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:24:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/08 20:01:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static void	print_args(const t_list *l, bool put_space)
{
	if (!l)
		return ;
	if (put_space)
		ft_putchar(' ');
	ft_putstr(l->content);
	print_args(l->next, true);
}

static void	print_redirection(const t_list *l, bool put_space)
{
	if (!l)
		return ;
	if (put_space)
		ft_putchar(' ');
	redir_print(l->content);
	print_redirection(l->next, true);
}

void		process_print(const t_process *p)
{
	print_args(p->args, false);
	print_redirection(p->redirection, !!p->args);
}
