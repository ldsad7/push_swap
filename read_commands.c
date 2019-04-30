/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 23:40:41 by tsimonis          #+#    #+#             */
/*   Updated: 2019/02/28 02:29:41 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		read_before_end(char ss[4], int fd, int flfd[3])
{
	char	c;

	c = '\0';
	if (!(ss[0] = 0) && !flfd[2])
	{
		while (ss[2] != '\n' && read(fd, &c, 1) && c != '\n')
			;
		return (-1);
	}
	return (1);
}

int		first_part(char ss[4], t_list **a, t_list **b, int (*flfd)[3])
{
	if (!(ss[0] == 's' && ss[1] == 's')
			&& !(ss[0] == 'r' && ss[1] == 'r' && ft_strchr("r\n", ss[2])))
		(*flfd)[2] += check_b_letter(ss, b, *a, *flfd);
	else
	{
		(*flfd)[1] = -1;
		(*flfd)[2] += check_b_letter(ss, b, *a, *flfd);
		(*flfd)[1] = 1;
	}
	(*flfd)[2] += check_a_letter(ss, a, *b, *flfd);
	return (1);
}

int		third_condition(char ss[4], t_list **b)
{
	return ((ss[2] == 'b' || (ss[2] == 'r'
				&& (ss[0] != 'r' || ss[1] != 'r'))) && rotate_backward(b));
}

int		read_commands(t_list **a, t_list **b, int fd, int f)
{
	char	ss[4];
	char	fistse[3];
	int		flfd[3];

	arrays_init(&ss, &fistse, &flfd);
	while (check_condition(fd, &ss, &fistse, &flfd))
	{
		first_part(ss, a, b, &flfd) && (!f && !(flfd[0] = f));
		init_of_vars(&flfd, &fistse, ss);
		if (!ft_strcmp(ss, "pa\n") && push_stack(a, b))
			flfd[2] += print_command(fistse, *a, *b, flfd);
		if (!ft_strcmp(ss, "pb\n") && push_stack(b, a))
			flfd[2] += print_command(fistse, *b, *a, flfd);
		if ((ss[3] = condition(ss, fd, &fistse)) && third_condition(ss, b))
			flfd[2] += print_command(fistse, *b, *a, flfd);
		else if (ss[3] && ft_strchr("br", ss[2]))
			flfd[2] += rotate_backward(b);
		if (ss[3] && ft_strchr("ar", ss[2]) && rotate_backward(a))
			flfd[2] += print_command(fistse, *a, *b, flfd);
		if (!(ss[3] = '\0') && read_before_end(ss, fd, flfd) == -1)
			return (-1);
	}
	return (read_end(ss, fd, *b));
}
