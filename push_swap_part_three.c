/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_part_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:12:42 by tsimonis          #+#    #+#             */
/*   Updated: 2019/03/04 00:45:18 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		fourth_func(int (*vars)[7], int flfd[4])
{
	(*vars)[0] = (*vars)[5];
	(*vars)[5] = flfd[2];
	(*vars)[4] *= -1;
	return (1);
}

int		fifth_func(int (*vars)[7], int flfd[4], char (*fistse)[4])
{
	(*vars)[1] = flfd[2];
	(*fistse)[0] = 'p';
	(*fistse)[1] = flfd[3];
	return (1);
}

int		sixth_func(int (*vars)[7], int (*flfd)[4],
					char (*fistse)[4])
{
	(*fistse)[1] = (*flfd)[3];
	(*flfd)[1] = (*vars)[2];
	return (1);
}

int		seventh_func(char (*fistse)[4])
{
	(*fistse)[0] = 'p';
	(*fistse)[1] = (*fistse)[3];
	(*fistse)[2] = 0;
	return (1);
}

int		eighth_func(int (*vars)[7], t_list **top, int flfd[4])
{
	return (((*vars)[4] > 0 || (*vars)[5] % 2)
		&& (*vars)[4] * (*top)->value < (*vars)[4] * (*vars)[6] && ++flfd[2]);
}
