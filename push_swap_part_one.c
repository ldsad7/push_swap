/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_part_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:12:25 by tsimonis          #+#    #+#             */
/*   Updated: 2019/03/03 22:10:06 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	comp_condition(char (*fistse)[3], t_list **a, t_list *b, int flfd[2])
{
	if (((*fistse)[0] = 's') && swap_stack(a)
		&& !((*fistse)[2] = 0) && print_command(*fistse, *a, b, flfd))
		((*fistse)[0] = 'r') && rotate_backward(a) &&
			((*fistse)[2] = 'r') && print_command(*fistse, *a, b, flfd);
}

void	initia(int (*flfd)[2], char (*fistse)[3], char stack, int (*vars)[7])
{
	(*flfd)[0] = 0;
	(*flfd)[1] = (*vars)[2];
	(*fistse)[1] = stack;
}

int		process_triple(t_list **a, t_list *b, char stack, int (*vars)[7])
{
	char	fistse[3];
	int		flfd[2];

	initia(&flfd, &fistse, stack, vars);
	if ((*vars)[4] * (*a)->value < (*vars)[4] * (*a)->prev->value && (*vars)[4]
		* (*a)->value < (*vars)[4] * (*a)->next->value && (fistse[0] = 'r') &&
		((fistse[2] = 'r')) && rotate_backward(a)
		&& print_command(fistse, *a, b, flfd) && (!(fistse[0] = 's')))
		!(fistse[2] = 0) && swap_stack(a) && print_command(fistse, *a, b, flfd);
	else if ((*vars)[4] * (*a)->prev->value < (*vars)[4] * (*a)->value &&
		(*vars)[4] * (*a)->prev->value < (*vars)[4] * (*a)->next->value)
	{
		if (!(fistse[2] = 0) && (*vars)[4] * (*a)->value <
			(*vars)[4] * (*a)->next->value && (fistse[0] = 's'))
			swap_stack(a) && print_command(fistse, *a, b, flfd);
		else if ((fistse[0] = 'r'))
			rotate_forward(a) && print_command(fistse, *a, b, flfd);
	}
	else if ((*vars)[4] * (*a)->value < (*vars)[4] * (*a)->prev->value &&
			(fistse[0] = 'r'))
		(fistse[2] = 'r') && rotate_backward(a)
			&& print_command(fistse, *a, b, flfd);
	else
		comp_condition(&fistse, a, b, flfd);
	return (1);
}

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
