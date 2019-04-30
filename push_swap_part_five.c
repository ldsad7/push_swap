/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_part_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:12:52 by tsimonis          #+#    #+#             */
/*   Updated: 2019/03/04 00:57:26 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	func_two(char (*fistse)[3], t_list **arr[2],
					int (*flfd)[2], int (*vars)[7])
{
	(*fistse)[0] = 's';
	swap_stack(arr[0]) && print_command(*fistse, *(arr[0]), *(arr[1]), *flfd);
	if ((*vars)[4] * (*(arr[0]))->prev->value
			> (*vars)[4] * (*(arr[0]))->prev->prev->value)
	{
		(*fistse)[0] = 'r';
		rotate_forward(arr[0])
			&& print_command(*fistse, *(arr[0]), *(arr[1]), *flfd);
		((*fistse)[0] = 's');
		swap_stack(arr[0])
			&& print_command(*fistse, *(arr[0]), *(arr[1]), *flfd);
		(*fistse)[0] = 'r';
		(*fistse)[2] = 'r';
		rotate_backward(arr[0])
			&& print_command(*fistse, *(arr[0]), *(arr[1]), *flfd);
	}
}

void	func_three(char (*fistse)[3], t_list **a, t_list *b, int (*flfd)[2])
{
	(*fistse)[0] = 'r';
	rotate_forward(a) && print_command(*fistse, *a, b, *flfd);
	(*fistse)[0] = 's';
	swap_stack(a) && print_command(*fistse, *a, b, *flfd);
	(*fistse)[0] = 'r';
	(*fistse)[2] = 'r';
	rotate_backward(a) && print_command(*fistse, *a, b, *flfd);
	(*fistse)[0] = 's';
	(*fistse)[2] = 0;
	swap_stack(a) && print_command(*fistse, *a, b, *flfd);
}

void	func_four(char (*fistse)[3], t_list **a, t_list *b, int (*flfd)[2])
{
	(*fistse)[0] = 's';
	swap_stack(a) && print_command(*fistse, *a, b, *flfd);
	(*fistse)[0] = 'r';
	rotate_forward(a) && print_command(*fistse, *a, b, *flfd);
	(*fistse)[0] = 's';
	swap_stack(a) && print_command(*fistse, *a, b, *flfd);
	rotate_backward(a) && ((*fistse)[0] = 'r') &&
	((*fistse)[2] = 'r') && print_command(*fistse, *a, b, *flfd);
	!((*fistse)[2] = 0) && swap_stack(a) &&
	((*fistse)[0] = 's') && print_command(*fistse, *a, b, *flfd);
}

int		first_part_(int (*flfd)[7], char (*fistse)[3],
					t_list **arr[2], int (*vars)[7])
{
	(*flfd)[0] = 0;
	(*flfd)[1] = (*vars)[2];
	(*fistse)[1] = (*flfd)[3];
	(*fistse)[2] = 0;
	(*vars)[1] = ft_lstlen(*(arr[1]));
	(*flfd)[5] = ft_lstlen(*(arr[0]));
	if ((*vars)[5] == 1 || is_sorted_n(*(arr[0]), (*vars)[5], (*vars)[4]))
		return (0);
	if (swap_stack(arr[0]) && is_sorted_n(*(arr[0]), (*vars)[5], (*vars)[4]) &&
		((*fistse)[0] = 's')
		&& print_command(*fistse, *(arr[0]), *(arr[1]), *flfd))
		return (0);
	else
		swap_stack(arr[0]);
	return (1);
}

int		second_part(int (*flfd)[7], char (*fistse)[3],
					t_list **arr[2], int (*vars)[7])
{
	if (rotate_forward(arr[0]) && swap_stack(arr[0]) &&
	rotate_backward(arr[0]) && is_sorted_n(*(arr[0]), (*vars)[5], (*vars)[4]))
	{
		(*fistse)[0] = 'r';
		print_command(*fistse, *(arr[0]), *(arr[1]), *flfd);
		(*fistse)[0] = 's';
		print_command(*fistse, *(arr[0]), *(arr[1]), *flfd);
		(*fistse)[0] = 'r';
		(*fistse)[2] = 'r';
		print_command(*fistse, *(arr[0]), *(arr[1]), *flfd);
		return (0);
	}
	else
		rotate_forward(arr[0]) && swap_stack(arr[0]) && rotate_backward(arr[0]);
	if ((*vars)[5] == 2 && ((*fistse)[0] = 's'))
	{
		(*fistse)[2] = 0;
		swap_stack(arr[0])
			&& print_command(*fistse, *(arr[0]), *(arr[1]), *flfd);
		return (0);
	}
	if ((*vars)[5] == 3
			&& process_triple_without_rr(arr[0], *(arr[1]), (*flfd)[3], vars))
		return (0);
	return (1);
}
