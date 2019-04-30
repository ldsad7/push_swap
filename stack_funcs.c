/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 03:19:45 by tsimonis          #+#    #+#             */
/*   Updated: 2019/02/28 02:19:29 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		swap_stack(t_list **top)
{
	int		tmp;

	if (!(*top) || !((*top)->prev))
		return (1);
	tmp = (*top)->value;
	(*top)->value = ((*top)->prev)->value;
	((*top)->prev)->value = tmp;
	return (1);
}

int		check_a_letter(char ss[4], t_list **top,
						t_list *b, int flfd[3])
{
	int		res;
	char	fistse[3];

	res = 0;
	fistse[0] = ss[0];
	fistse[1] = ss[1];
	fistse[2] = 0;
	if (ss[0] == 's' && (ss[1] == 'a' || ss[1] == 's')
			&& (ss[2] == '\n' || ss[2] == '\0'))
	{
		res += swap_stack(top);
		if (flfd[0])
			print_command(fistse, *top, b, flfd);
	}
	if (ss[0] == 'r' && (ss[1] == 'a' || ss[1] == 'r')
			&& (ss[2] == '\n' || ss[2] == '\0'))
	{
		res += rotate_forward(top);
		if (flfd[0])
			print_command(fistse, *top, b, flfd);
	}
	return (res);
}

int		check_b_letter(char ss[4], t_list **stop,
						t_list *b, int flfd[3])
{
	int		res;
	char	fistse[3];

	res = 0;
	fistse[0] = ss[0];
	fistse[1] = ss[1];
	fistse[2] = 0;
	if (ss[0] == 's' && (ss[1] == 'b' || ss[1] == 's')
			&& (ss[2] == '\n' || ss[2] == '\0'))
	{
		res += swap_stack(stop);
		if (flfd[0] && flfd[1] >= 0)
			print_command(fistse, *stop, b, flfd);
	}
	if (ss[0] == 'r' && (ss[1] == 'b' || ss[1] == 'r')
			&& (ss[2] == '\n' || ss[2] == '\0'))
	{
		res += rotate_forward(stop);
		if (flfd[0] && flfd[1] >= 0)
			print_command(fistse, *stop, b, flfd);
	}
	return (res);
}
