/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands_addition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 03:42:26 by tsimonis          #+#    #+#             */
/*   Updated: 2019/02/28 02:57:31 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arrays_init(char (*ss)[4], char (*fistse)[3],
					int (*flfd)[3])
{
	(*ss)[0] = 0;
	(*ss)[1] = 0;
	(*ss)[2] = 0;
	(*ss)[3] = 0;
	(*fistse)[0] = 0;
	(*fistse)[1] = 0;
	(*fistse)[2] = 0;
	(*flfd)[0] = 1;
	(*flfd)[1] = 1;
}

int		check_condition(int fd, char (*ss)[4],
						char (*fistse)[3], int (*flfd)[3])
{
	return (read(fd, *ss, 1) && ft_strchr("spr", (*ss)[0])
		&& read(fd, (*ss) + 1, 1)
	&& (((*ss)[0] == 's' && (*ss)[1] == 's')
	|| ((*ss)[0] == 'r' && (*ss)[1] == 'r')
	|| ft_strchr("ab", (*ss)[1])) && read(fd, (*ss) + 2, 1)
	&& !((*fistse)[2] = 0)
	&& ft_strchr("abr\n", (*ss)[2]) && !((*flfd)[2] = 0)
	&& ((*flfd)[1] = 1));
}

int		condition(char ss[4], int fd, char (*fistse)[3])
{
	char	c;

	c = '\0';
	if (ss[0] == 'r' && ss[1] == 'r' && ss[2] != '\n'
			&& read(fd, &c, 1) && c == '\n' && ((*fistse)[0] = 'r'))
	{
		(*fistse)[1] = ss[2];
		(*fistse)[2] = ss[1];
		return (1);
	}
	return (0);
}

int		init_of_vars(int (*flfd)[3], char (*fistse)[3], char ss[4])
{
	(*flfd)[0] = 1;
	(*flfd)[1] = 1;
	(*fistse)[0] = ss[0];
	(*fistse)[1] = ss[1];
	return (1);
}

int		read_end(char ss[4], int fd, t_list *b)
{
	char	c;

	c = '\0';
	if ((ss[0] && !ft_strchr("spr\n", ss[0]))
			|| (ft_strchr("spr", ss[0]) && ss[1] != '\n'))
	{
		while (read(fd, &c, 1) && c != '\n')
			;
		return (-1);
	}
	if (ss[0] && (!ft_strchr("spr", ss[0]) || !(ft_strchr("ab", ss[1])
	|| (ss[1] == 's' && ss[0] == 's') || (ss[1] == 'r' && ss[0] == 'r'))))
		return (-1);
	return (!b);
}
