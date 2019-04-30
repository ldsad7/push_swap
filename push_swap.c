/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 03:11:51 by tsimonis          #+#    #+#             */
/*   Updated: 2019/03/04 01:00:25 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort_addition_two(char (*fistse)[4], t_list **arr[2],
							int (*flfd)[4], int (*vars)[7])
{
	twelfth(vars, arr, flfd, *fistse);
	if (fifth_func(vars, *flfd, fistse) && !((*fistse)[2] = 0) &&
		ft_lstlen(*(arr[0])) == (*vars)[5] - (*flfd)[2]
		&& !(is_sorted(*(arr[0]), (*vars)[4])
		&& is_sorted(*(arr[1]), -(*vars)[4])))
		while ((*vars)[1]--)
			push_stack(arr[0], arr[1])
			&& print_command(*fistse, *(arr[0]), *(arr[1]), *flfd);
}

void	merge_sort(t_list **top, t_list **b, int (*vars)[7], char stack)
{
	t_list	**arr[2];
	char	fistse[4];
	int		flfd[4];
	int		median_fl[2];

	arr[0] = top;
	arr[1] = b;
	if ((flfd[3] = stack) && eleventh_func(arr, vars, &flfd, &fistse))
		return ;
	first_func(vars, top, &fistse, &flfd);
	median_fl[0] = find_next_median(*top, (*vars)[5], (*vars)[4]);
	if (!(median_fl[1] = 0) && !ft_lstlen(*b))
		median_fl[1] = 1;
	while (++(*vars)[1] < (*vars)[5] && flfd[2] < (*vars)[5] / 2)
		if ((seventh_func(&fistse) && eighth_func(vars, top, flfd))
			|| ninth_func(vars, top, flfd))
		{
			push_stack(b, top) && print_command(fistse, *b, *top, flfd);
			if (median_fl[1] && (*vars)[4] * (*b)->value
					< (*vars)[4] * median_fl[0] && ft_lstlen(*b) > 1)
				merge_sort_addition(&fistse, arr, &flfd, vars);
		}
		else if ((fistse[0] = 'r') && rotate_forward(top))
			(fistse[1] = flfd[3]) && print_command(fistse, *top, *b, flfd);
	merge_sort_addition_two(&fistse, arr, &flfd, vars);
}

int		is_sorted_n(t_list *top, int n, int fl)
{
	t_list	*prev;
	t_list	*tmp;

	prev = top;
	tmp = top->prev;
	while (--n)
	{
		if (fl * prev->value > fl * tmp->value && tmp != top)
			return (0);
		prev = tmp;
		tmp = tmp->prev;
	}
	return (1);
}

void	merge_sort_without_rr(t_list **top, t_list **b,
								int (*vars)[7], char stack)
{
	char	fistse[3];
	int		flfd[7];
	t_list	**arr[2];

	arr[0] = top;
	arr[1] = b;
	flfd[3] = stack;
	if (!first_part_(&flfd, &fistse, arr, vars)
		|| !second_part(&flfd, &fistse, arr, vars)
		|| !third_part(&flfd, &fistse, arr, vars))
		return ;
	fourth_part(&flfd, &fistse, arr, vars);
	fistse[2] = 'r';
	while ((*vars)[1]--)
		rotate_backward(top) && print_command(fistse, *top, *b, flfd);
	if (stack == 'b')
		fifth_part(&flfd, arr, vars);
	else
		sixth_part(&flfd, arr, vars);
	seventh_part(&flfd, &fistse, arr, vars);
}

int		main(int argc, char **argv)
{
	char	fistse[3];
	int		flfd[2];
	int		vars[7];
	t_list	*top;
	t_list	*b;

	vars[5] = argc;
	vars[6] = 0;
	if (!over_main(&fistse, &flfd, &vars, &argv))
		return (0);
	top = ft_lstnew(ft_atoi_new(argv[1 + vars[0]]), NULL, NULL);
	if (!read_args(vars[5], argv, &top, vars[0]) && ft_lstdel(&top))
		return (final(vars[2], vars[3], argv));
	if (!(b = NULL) && !no_duplicates(top))
		write(2, "Error\n", 6);
	else if ((is_sorted(top, 1) || vars[5] == 1) && ft_lstdel(&top))
		return (final(vars[2], vars[3], argv));
	else if ((vars[4] = 1))
		merge_sort(&top, &b, &vars, 'a');
	last_init(&vars, b, &fistse, &flfd);
	while (vars[0]--)
		push_stack(&top, &b) && print_command(fistse, top, b, flfd);
	ft_lstdel(&top) && ft_lstdel(&b);
	return (final(vars[2], vars[3], argv));
}
