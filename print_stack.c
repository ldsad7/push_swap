/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:47:43 by tsimonis          #+#    #+#             */
/*   Updated: 2019/02/28 03:27:40 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	additional_func(t_list *top, char fistse[3], char *color, int fd)
{
	if (color && fistse[0] == 'p')
		write(fd, "\033[0;31m", 7);
	if (ft_printf(fd, "%d", top->value) && top->prev)
		write(fd, " ", 1);
}

void	print_stack(t_list *top, char fistse[3], char *color, int fd)
{
	int		fl;
	t_list	*lst;

	if (!(fl = 0) && !top && write(fd, "\n", 1))
		return ;
	additional_func(top, fistse, color, fd);
	if (color && fistse[0] == 'p' && write(fd, "\033[0m", 4))
		write(fd, color, 7);
	lst = top->prev;
	while (lst && lst != top)
	{
		if (color && ((((fistse[0] == 'r' && fistse[2] == 'r') ||
	fistse[0] == 's') && !fl) || (lst->prev == top && fistse[0] == 'r' &&
	!fistse[2])) && write(fd, "\033[0m", 4))
			write(fd, "\033[0;31m", 7);
		if (ft_printf(fd, "%d", lst->value) && lst->prev != top)
			write(fd, " ", 1);
		if (color && ((((fistse[0] == 'r' && fistse[2] == 'r') ||
	fistse[0] == 's') && !fl) || (lst->prev == top && fistse[0] == 'r'
	&& !fistse[2])) && write(fd, "\033[0m", 4) && (fl = 1))
			write(fd, color, 7);
		lst = lst->prev;
	}
	write(fd, "\n", 1);
}
