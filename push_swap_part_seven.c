/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_part_seven.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:31:25 by tsimonis          #+#    #+#             */
/*   Updated: 2019/03/04 00:56:10 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		process_triple_without_rr(t_list **a, t_list *b,
									char stack, int (*vars)[7])
{
	char	fistse[3];
	int		flfd[2];
	t_list	**arr[2];

	arr[0] = a;
	arr[1] = &b;
	flfd[0] = 0;
	flfd[1] = (*vars)[2];
	fistse[1] = stack;
	fistse[2] = 0;
	if ((*vars)[4] * (*a)->value < (*vars)[4] * (*a)->prev->value
	&& (*vars)[4] * (*a)->value < (*vars)[4] * (*a)->prev->prev->value)
		func_one(&fistse, a, b, &flfd);
	else if ((*vars)[4] * (*a)->prev->value < (*vars)[4] * (*a)->value
			&& (*vars)[4] * (*a)->prev->value
			< (*vars)[4] * (*a)->prev->prev->value)
		func_two(&fistse, arr, &flfd, vars);
	else if ((*vars)[4] * (*a)->value < (*vars)[4] * (*a)->prev->value)
		func_three(&fistse, a, b, &flfd);
	else
		func_four(&fistse, a, b, &flfd);
	return (1);
}

void	last_init(int (*vars)[7], t_list *b,
					char (*fistse)[3], int (*flfd)[2])
{
	(*vars)[0] = ft_lstlen(b);
	(*fistse)[0] = 'p';
	(*fistse)[1] = 'a';
	(*fistse)[2] = 0;
	(*flfd)[1] = (*vars)[2];
}

int		find_next_median(t_list *top, int n, int sign)
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
	return (arr[n / 4 + (sign < 0) * n / 2]);
}

void	merge_sort_addition(char (*fistse)[4], t_list **arr[2],
							int (*flfd)[4], int (*vars)[7])
{
	if ((*vars)[4] * (*(arr[0]))->value >= (*vars)[4] * ((*vars)[6]))
	{
		(*fistse)[0] = 'r';
		(*fistse)[1] = 'r';
		(*fistse)[2] = 0;
		rotate_forward(arr[0]);
		rotate_forward(arr[1]);
		print_command(*fistse, *(arr[0]), *(arr[1]), *flfd);
	}
	else
	{
		(*fistse)[0] = 'r';
		(*fistse)[1] = ((*flfd)[3] == 'a') * 'b' + 'a' * ((*flfd)[3] == 'b');
		(*fistse)[2] = 0;
		rotate_forward(arr[1])
			&& print_command(*fistse, *(arr[1]), *(arr[0]), *flfd);
	}
}
