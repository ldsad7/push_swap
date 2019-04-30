/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 23:50:32 by tsimonis          #+#    #+#             */
/*   Updated: 2019/02/28 03:17:15 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	char	fistse[3];
	int		flfd[2];
	int		vars[7];
	t_list	*top;
	t_list	*b;

	vars[5] = argc;
	vars[6] = 1;
	if (!over_main(&fistse, &flfd, &vars, &argv))
		return (0);
	top = ft_lstnew(ft_atoi_new(argv[1 + vars[0]]), NULL, NULL);
	if (!read_args(vars[5], argv, &top, vars[0]))
	{
		ft_lstdel(&top);
		return (final(vars[2], vars[3], argv));
	}
	if (!(b = NULL) && (!no_duplicates(top)
			|| (vars[1] = read_commands(&top, &b, vars[2], vars[4])) == -1))
		write(2, "Error\n", 6);
	else if (vars[1] && is_sorted(top, 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstdel(&top) && ft_lstdel(&b);
	return (final(vars[2], vars[3], argv));
}
