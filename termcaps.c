/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:42:54 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/28 18:39:19 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termcap.h>
#include <termios.h>
#include <unistd.h>
#include "libft.h"

void	init(struct termios	*backup)
{
	struct termios t;

	tcgetattr(STDIN_FILENO, backup);
	t = *backup;
	t.c_lflag &= ~(ICANON|ECHO);
	t.c_cc[VMIN] = 1;
	t.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &t);
}

int		main()
{
	struct termios	backup;
	t_file			*f;
	char			c;

	tgetent(NULL, getenv("TERM"));
	init(&backup);
	f = ft_fdopen(STDIN_FILENO, "r");
	ft_putendl("Press q to quit");
	while ((c = ft_fgetc(f)) != FT_EOF && c != 'q')
		ft_printf("%d\n", c);
	ft_fclose(f);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &backup);
	return (0);
}
