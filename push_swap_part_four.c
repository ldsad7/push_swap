/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_part_four.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:12:47 by tsimonis          #+#    #+#             */
/*   Updated: 2019/03/04 00:39:42 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ninth_func(int (*vars)[7], t_list **top, int flfd[4])
{
	return ((*vars)[4] < 0 && !((*vars)[5] % 2)
				&& (*top)->value >= (*vars)[6] && ++flfd[2]);
}

int		tenth_func(int (*vars)[7])
{
	(*vars)[4] *= -1;
	(*vars)[5] = (*vars)[0];
	return (1);
}

int		eleventh_func(t_list **arr[2], int (*vars)[7],
					int (*flfd)[4], char (*fistse)[4])
{
	return (sixth_func(vars, flfd, fistse) &&
	((!((*flfd)[0] = 0) && !first_check(fistse, vars, arr[0], arr[1]))
	|| (((*vars)[5] == 2 && ((*fistse)[0] = 's') && swap_stack(arr[0]) &&
	(!((*fistse)[2] = 0))
	&& print_command(*fistse, *(arr[0]), *(arr[1]), *flfd))
	|| ((*vars)[5] == 3
	&& process_triple(arr[0], *(arr[1]), (*flfd)[3], vars)))));
}

void	twelfth(int (*vars)[7], t_list **arr[2],
					int (*flfd)[4], char fistse[4])
{
	if ((*flfd)[3] == 'a')
	{
		if (second_func(vars, arr[0], arr[1], flfd)
				&& ft_lstlen(*(arr[1])) == (*flfd)[2])
			merge_sort(arr[1], arr[0], vars, fistse[3]);
		else
			merge_sort_without_rr(arr[1], arr[0], vars, fistse[3]);
		tenth_func(vars);
	}
	else if (fourth_func(vars, *flfd))
	{
		if (ft_lstlen(*(arr[1])) == (*flfd)[2])
			merge_sort(arr[1], arr[0], vars, fistse[3]);
		else
			merge_sort_without_rr(arr[1], arr[0], vars, fistse[3]);
		third_func(vars, arr[0], arr[1], flfd);
	}
}

void	func_one(char (*fistse)[3], t_list **a, t_list *b, int (*flfd)[2])
{
	((*fistse)[0] = 'r') && rotate_forward(a)
		&& print_command(*fistse, *a, b, *flfd);
	((*fistse)[0] = 's') && swap_stack(a)
		&& print_command(*fistse, *a, b, *flfd);
	((*fistse)[0] = 'r') && rotate_backward(a) &&
	((*fistse)[2] = 'r') && print_command(*fistse, *a, b, *flfd);
}
