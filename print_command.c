/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 22:51:05 by tsimonis          #+#    #+#             */
/*   Updated: 2019/02/28 05:25:56 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		fls_filling(char fistse[3], int (*fls)[2])
{
	if (fistse[1] == '1')
		(*fls)[0] = 1;
	else if (fistse[1] == '2')
	{
		(*fls)[0] = 1;
		(*fls)[1] = 1;
	}
	else if (!(*fls)[0] && !(*fls)[1])
	{
		(*fls)[0] = 0;
		(*fls)[1] = 0;
	}
	return (1);
}

char	*zeros_filling(char (*zeros)[3], int fls[2],
						int flfd[3], char fistse[3])
{
	char	*clr;

	(*zeros)[0] = 0;
	(*zeros)[1] = 0;
	(*zeros)[2] = 0;
	if (fls[1] && flfd[1] < 3)
		write(flfd[1], "\033[0;31m", 7);
	if (!flfd[0])
	{
		write(flfd[1], &(fistse[0]), 1);
		if (fistse[2])
			write(flfd[1], &(fistse[2]), 1);
		write(flfd[1], &(fistse[1]), 1);
		write(flfd[1], "\n", 1);
	}
	if (fls[1] && flfd[1] < 3)
		write(flfd[1], "\033[0m", 4);
	if (fls[0] && fls[1] && flfd[1] < 3)
		write(flfd[1], "\033[0;32m", 7);
	clr = NULL;
	if (fls[0] && write(flfd[1], "a: ", 3) && !(clr = NULL)
			&& fls[1] && flfd[1] < 3)
		clr = "\033[0;32m";
	return (clr);
}

char	*printing(int fls[2], char fistse[3], int flfd[3], t_list *top)
{
	char	*clr;

	if (fls[0] && !ft_strchr("asr", fistse[1]) && write(flfd[1], "b:", 2)
		&& top)
		write(flfd[1], " ", 1);
	clr = NULL;
	if (fls[0] && !(clr = NULL) && fls[1] && flfd[1] < 3)
		clr = "\033[0;33m";
	return (clr);
}

void	printing_one_more(int fls[2], int flfd[3])
{
	if (fls[0] && fls[1] && flfd[1] < 3 && write(flfd[1], "\033[0m", 4))
		write(flfd[1], "\033[0;33m", 7);
}

int		print_command(char fistse[3], t_list *top, t_list *b, int flfd[3])
{
	char		*clr;
	static int	fls[2];
	char		zeros[3];

	if (fistse[1] >= '0' && fistse[1] <= '2' && fls_filling(fistse, &fls))
		return (0);
	clr = zeros_filling(&zeros, fls, flfd, fistse);
	if (fls[0] && ft_strchr("asr", fistse[1]))
		print_stack(top, fistse, clr, flfd[1]);
	else if (fls[0])
		print_stack(b, zeros, clr, flfd[1]);
	printing_one_more(fls, flfd);
	if (fls[0] && ft_strchr("asr", fistse[1]) && write(flfd[1], "b:", 2) && b)
		write(flfd[1], " ", 1);
	clr = printing(fls, fistse, flfd, top);
	if (fls[0] && ft_strchr("asr", fistse[1]))
		if (fistse[1] != 's' && fistse[1] != 'r')
			print_stack(b, zeros, clr, flfd[1]);
		else
			print_stack(b, fistse, clr, flfd[1]);
	else if (fls[0])
		print_stack(top, fistse, clr, flfd[1]);
	if (fls[0] && fls[1] && flfd[1] < 3)
		write(flfd[1], "\033[0m", 4);
	return (1);
}
