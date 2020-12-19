/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:54:15 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/13 15:54:23 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	process_clear(t_process *p)
{
	ft_list_clear(&p->args, (t_gfunction) & ft_free);
	ft_free(p->argv);
	ft_list_clear(&p->redirection, (t_gfunction) & redir_clear);
	ft_free(p);
}
