/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_part_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:12:37 by tsimonis          #+#    #+#             */
/*   Updated: 2019/03/04 00:38:01 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_median(t_list *top, int n)
{
	int		i;
	int		j;
	int		temp;
	int		arr[n];
	t_list	*tmp;

	tmp = top;
	i = -1;
	while (++i < n)
	{
		arr[i] = tmp->value;
		j = i;
		while (j && arr[j] < arr[j - 1])
		{
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
		tmp = tmp->prev;
	}
	return (arr[n / 2]);
}

int		first_check(char (*fistse)[4], int (*vars)[7],
					t_list **top, t_list **b)
{
	int		flfd[2];

	flfd[1] = (*vars)[2];
	if (!(flfd[0] = 0) && ((*vars)[5] == 1 || is_sorted(*top, (*vars)[4])))
		return (0);
	if (!((*fistse)[2] = 0) && swap_stack(top) && is_sorted(*top, (*vars)[4])
		&& ((*fistse)[0] = 's')
		&& print_command(*fistse, *top, *b, flfd))
		return (0);
	else
		swap_stack(top);
	if (rotate_forward(top) && ((*fistse)[0] = 'r') &&
		is_sorted(*top, (*vars)[4]) && print_command(*fistse, *top, *b, flfd))
		return (0);
	else
		rotate_backward(top);
	if (rotate_backward(top) && is_sorted(*top, (*vars)[4]))
	{
		(*fistse)[0] = 'r';
		((*fistse)[2] = 'r') && print_command(*fistse, *top, *b, flfd);
		return (0);
	}
	else
		rotate_forward(top);
	return (1);
}

void	first_func(int (*vars)[7], t_list **top,
					char (*fistse)[4], int (*flfd)[4])
{
	(*vars)[6] = find_median(*top, (*vars)[5]);
	(*fistse)[3] = 'b' * ((*flfd)[3] == 'a') + 'a' * ((*flfd)[3] == 'b');
	(*flfd)[2] = 0;
	(*vars)[1] = -1;
}

int		second_func(int (*vars)[7], t_list **top,
					t_list **b, int (*flfd)[4])
{
	(*vars)[5] -= (*flfd)[2];
	merge_sort(top, b, vars, (*flfd)[3]);
	(*vars)[0] = (*vars)[5] + (*flfd)[2];
	(*vars)[5] = (*flfd)[2];
	(*vars)[4] *= -1;
	return (1);
}

void	third_func(int (*vars)[7], t_list **top,
					t_list **b, int (*flfd)[4])
{
	(*vars)[4] *= -1;
	(*vars)[5] = (*vars)[0] - (*flfd)[2];
	merge_sort(top, b, vars, (*flfd)[3]);
	(*vars)[5] += (*flfd)[2];
}
