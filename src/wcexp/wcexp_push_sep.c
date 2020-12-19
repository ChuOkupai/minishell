/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcexp_push_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:07:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/12 19:07:35 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wcexp.h"
#include "token.h"

void	wcexp_push_sep(t_wcexp *wc)
{
	static t_token t = { TOKEN_WILDCARD, "*" };

	ft_list_push(&wc->l, ft_list_new(&t));
}
