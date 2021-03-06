/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_0x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 06:17:04 by tsimonis          #+#    #+#             */
/*   Updated: 2019/02/25 04:18:06 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_0x(int flags[11], char ls[3], char *res)
{
	int		ret;

	ret = 0;
	if (flags[3] && ft_strcmp(res, "0"))
	{
		if (ls[2] == 'x')
			ret += write(1, "0x", 2);
		else
			ret += write(1, "0X", 2);
	}
	return (ret);
}
