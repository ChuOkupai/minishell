/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:16:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/30 17:42:46 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

// gcc readl.c .build/*/*.o -I./libft/inc -I./inc -L./libft -lft -ltermcap

int		main(void)
{
	t_readline	readl;
	t_history	history;
	char		*line;
	bool		keep;

	msh_readline_init(&readl, NULL);
	msh_history_init(&history);
	keep = true;
	while (keep && (line = msh_readline(&readl, &history, "readline > ")))
	{
		if (*ft_strwhile(line, &ft_isspace))
			msh_history_add(&history, line);
		if (!ft_strcmp(line, "exit"))
			keep = false;
		else if (!ft_strncmp(line, "histsize=", 9))
			msh_history_resize(&history, ft_atoi(line + 9));
		ft_memdel(line);
		ft_list_print(history.list, (t_gprint) & ft_putstr);
	}
	msh_history_clear(&history);
	msh_readline_clear(&readl);
	return (0);
}
