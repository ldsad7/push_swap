/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <tsimonis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:38:38 by tsimonis          #+#    #+#             */
/*   Updated: 2019/02/27 00:56:17 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int			ft_atoi_new(const char *str)
{
	long long int	fl;
	long long int	result;

	if ((fl = 1) && (*str == '-' || *str == '+') && ++str && *(str - 1) == '-')
		fl = -1;
	result = 0;
	if (*str >= '0' && *str <= '9')
	{
		while (*str >= '0' && *str <= '9')
		{
			result = 10 * result + (*str - '0') * fl;
			if (result > 2147483647 || result < -2147483648)
				return (2147483648);
			str++;
		}
		if (*str)
			return (2147483648);
		return (result);
	}
	return (2147483648);
}
