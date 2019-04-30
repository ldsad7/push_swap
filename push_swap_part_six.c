/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_part_six.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:12:57 by tsimonis          #+#    #+#             */
/*   Updated: 2019/03/04 01:00:24 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		third_part(int (*flfd)[7], char (*fistse)[3],
					t_list **arr[2], int (*vars)[7])
{
	(*flfd)[2] = 'b' * ((*flfd)[3] == 'a') + 'a' * ((*flfd)[3] == 'b');
	if ((*vars)[5] == 4 && (*vars)[4] * (*(arr[0]))->value
			< (*vars)[4] * (*(arr[0]))->prev->value &&
	(*vars)[4] * (*(arr[0]))->value
	< (*vars)[4] * (*(arr[0]))->prev->prev->value &&
	(*vars)[4] * (*(arr[0]))->value
	< (*vars)[4] * (*(arr[0]))->prev->prev->prev->value)
	{
		(*fistse)[0] = 'p';
		(*fistse)[1] = (*flfd)[2];
		(*fistse)[2] = 0;
		push_stack(arr[1], arr[0])
			&& print_command(*fistse, *(arr[1]), *(arr[0]), *flfd);
		process_triple_without_rr(arr[0], *(arr[1]), (*flfd)[3], vars);
		(*fistse)[1] = (*flfd)[3];
		push_stack(arr[0], arr[1])
			&& print_command(*fistse, *(arr[0]), *(arr[1]), *flfd);
		return (0);
	}
	(*vars)[6] = find_median(*(arr[0]), (*vars)[5]);
	(*vars)[1] = 0;
	(*flfd)[6] = 0;
	return (1);
}

void	fourth_part(int (*flfd)[7], char (*fistse)[3],
					t_list **arr[2], int (*vars)[7])
{
	while ((*vars)[1] < (*vars)[5] && (*flfd)[6] < (*vars)[5] / 2)
	{
		(*fistse)[0] = 'p';
		(*fistse)[1] = (*flfd)[2];
		(*fistse)[2] = 0;
		if (((*vars)[4] > 0 || (*vars)[5] % 2) && (*vars)[4] *
	(*(arr[0]))->value < (*vars)[4] * (*vars)[6] && ++(*flfd)[6])
			push_stack(arr[1], arr[0]) && print_command(*fistse, *(arr[1]),
					*(arr[0]), *flfd);
		else if ((*vars)[4] < 0 && !((*vars)[5] % 2)
				&& (*(arr[0]))->value >= (*vars)[6] && ++(*flfd)[6])
			push_stack(arr[1], arr[0]) && print_command(*fistse, *(arr[1]),
					*(arr[0]), *flfd);
		else
		{
			(*fistse)[0] = 'r';
			(*fistse)[1] = (*flfd)[3];
			rotate_forward(arr[0]) && print_command(*fistse, *(arr[0]),
					*(arr[1]), *flfd);
		}
		(*vars)[1]++;
	}
	(*vars)[1] -= (*flfd)[6];
	(*fistse)[0] = 'r';
	(*fistse)[1] = (*flfd)[3];
}

void	fifth_part(int (*flfd)[7], t_list **arr[2], int (*vars)[7])
{
	(*flfd)[4] = (*vars)[5];
	(*vars)[5] = (*flfd)[6];
	(*vars)[4] *= -1;
	merge_sort_without_rr(arr[1], arr[0], vars, (*flfd)[2]);
	(*vars)[5] = (*flfd)[4];
	(*vars)[4] *= -1;
	(*vars)[5] -= (*flfd)[6];
	if (ft_lstlen(*(arr[0])) == (*vars)[5] - (*flfd)[6])
		merge_sort(arr[0], arr[1], vars, (*flfd)[3]);
	else
		merge_sort_without_rr(arr[0], arr[1], vars, (*flfd)[3]);
	(*vars)[5] += (*flfd)[6];
}

void	sixth_part(int (*flfd)[7], t_list **arr[2], int (*vars)[7])
{
	(*vars)[5] -= (*flfd)[6];
	if (ft_lstlen(*(arr[0])) == (*vars)[5] - (*flfd)[6])
		merge_sort(arr[0], arr[1], vars, (*flfd)[3]);
	else
		merge_sort_without_rr(arr[0], arr[1], vars, (*flfd)[3]);
	(*vars)[5] += (*flfd)[6];
	(*flfd)[4] = (*vars)[5];
	(*vars)[5] = (*flfd)[6];
	(*vars)[4] *= -1;
	merge_sort_without_rr(arr[1], arr[0], vars, (*flfd)[2]);
	(*vars)[5] = (*flfd)[4];
	(*vars)[4] *= -1;
}

void	seventh_part(int (*flfd)[7], char (*fistse)[3],
					t_list **arr[2], int (*vars)[7])
{
	(*fistse)[0] = 'p';
	(*fistse)[2] = 0;
	if ((*flfd)[3] == 'b')
	{
		(*fistse)[1] = (*flfd)[2];
		(*vars)[1] = (*vars)[5] - (*flfd)[6];
		if ((*flfd)[5] - (*vars)[5] != ft_lstlen(*(arr[0])))
			while ((*vars)[1]-- > 0)
				push_stack(arr[1], arr[0])
					&& print_command(*fistse, *(arr[1]), *(arr[0]), *flfd);
	}
	else
	{
		(*fistse)[1] = (*flfd)[3];
		(*vars)[1] = (*flfd)[6];
		if ((*flfd)[5] != ft_lstlen(*(arr[0])))
			while ((*vars)[1]-- > 0)
				push_stack(arr[0], arr[1])
					&& print_command(*fistse, *(arr[0]), *(arr[1]), *flfd);
	}
}
