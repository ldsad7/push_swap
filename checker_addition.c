/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_addition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 05:19:42 by tsimonis          #+#    #+#             */
/*   Updated: 2019/02/28 03:17:44 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		final(int fd, int faut_free, char **argv)
{
	if (fd > 2)
		close(fd);
	if (faut_free)
		free_argv(argv);
	return (0);
}

int		complex_condition(char **argv, int (*vars)[7],
							char (*fistse)[3], int flfd[2])
{
	int		fd;

	fd = -2;
	while (argv[1 + (*vars)[0]] && (!ft_strcmp(argv[1 + (*vars)[0]], "-v")
		|| !ft_strcmp(argv[1 + (*vars)[0]], "-c")
		|| !ft_strcmp(argv[1 + (*vars)[0]], "-vc")
		|| !ft_strcmp(argv[1 + (*vars)[0]], "-cv")
		|| !ft_strcmp(argv[1 + (*vars)[0]], "-f")))
	{
		if (!ft_strcmp(argv[1 + (*vars)[0]], "-v") && ((*fistse)[1] = '1'))
			print_command(*fistse, 0, 0, flfd);
		else if ((!ft_strcmp(argv[1 + (*vars)[0]], "-c") ||
			!ft_strcmp(argv[1 + (*vars)[0]], "-vc")
			|| !ft_strcmp(argv[1 + (*vars)[0]], "-cv")) && ((*fistse)[1] = '2'))
			print_command(*fistse, 0, 0, flfd);
		else if (!ft_strcmp(argv[1 + (*vars)[0]], "-f") && ++((*vars)[0]) &&
			((*vars)[2] = open(argv[1 + (*vars)[0]], O_CREAT | O_RDWR |
	O_TRUNC * !(*vars)[6], 0777)) == -1 && write(2, "Incorrect file\n", 15))
			return (final((*vars)[2], (*vars)[3], argv));
		((*vars)[0])++;
	}
	return (1);
}

int		vars_init(char (*fistse)[3], int (*flfd)[2], int (*vars)[7])
{
	(*fistse)[0] = 0;
	(*fistse)[1] = '0';
	(*fistse)[2] = 0;
	(*flfd)[0] = 0;
	(*flfd)[1] = 0;
	(*vars)[0] = 0;
	if ((*vars)[6])
		(*vars)[2] = 0;
	else
		(*vars)[2] = 1;
	(*vars)[3] = 0;
	if ((*vars)[5] == 1)
		return (0);
	return (1);
}

int		main_func(char (*fistse)[3], int (*flfd)[2],
					int (*vars)[7], char ***argv)
{
	char	**prev;

	if ((*vars)[5] == 2 && ((*vars)[3] = 1))
		*argv = ft_strsplit((*argv)[1], ' ');
	if (!complex_condition(*argv, vars, fistse, *flfd))
		return (0);
	(*vars)[4] = 1;
	if (!(*vars)[0] && !((*vars)[4] = 0))
		print_command(*fistse, 0, 0, *flfd);
	if ((*vars)[5] == 2 + (*vars)[0] && (*vars)[0])
	{
		prev = *argv;
		*argv = ft_strsplit((*argv)[1 + (*vars)[0]], ' ');
		if ((*vars)[3])
			free_argv(prev);
		(*vars)[3] = 1;
		(*vars)[0] = 0;
		if (!complex_condition(*argv, vars, fistse, *flfd))
			return (0);
		if (!(*vars)[0])
			print_command(*fistse, 0, 0, *flfd);
		else
			(*vars)[4] = 1;
	}
	return (1);
}

int		over_main(char (*fistse)[3], int (*flfd)[2],
					int (*vars)[7], char ***argv)
{
	if ((*vars)[5] == 1)
	{
		if (!ft_strcmp((*argv)[0], "./push_swap"))
			write(2,
			"usage: ./push_swap [-vc] [-f file] num ... | \"string\"\n", 54);
		else if (!ft_strcmp((*argv)[0], "./checker"))
			write(2,
			"usage: ./checker [-vc] [-f file] num ... | \"string\"\n", 52);
		return (0);
	}
	if (!vars_init(fistse, flfd, vars))
		return (0);
	if (!main_func(fistse, flfd, vars, argv))
		return (0);
	if (!(*argv)[1 + (*vars)[0]])
		return (final((*vars)[2], (*vars)[3], *argv));
	(*vars)[5] = 0;
	(*vars)[1] = (*vars)[0];
	while ((*argv)[1 + (*vars)[1]] && ++(*vars)[1])
		(*vars)[5]++;
	if (ft_atoi_new((*argv)[1 + (*vars)[0]]) == 2147483648
			&& write(2, "Error\n", 6))
		return (final((*vars)[2], (*vars)[3], *argv));
	return (1);
}
