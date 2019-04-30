/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 23:42:15 by tsimonis          #+#    #+#             */
/*   Updated: 2019/02/28 02:57:40 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_list *top, int fl)
{
	t_list	*lst;
	t_list	*next;

	if (!top)
		return (1);
	next = top;
	lst = top->prev;
	while (lst && lst != top)
	{
		if (fl * next->value >= fl * lst->value)
			return (0);
		next = lst;
		lst = lst->prev;
	}
	return (1);
}

int		no_duplicates(t_list *top)
{
	t_list	*lst;
	t_list	*prev;

	lst = top->prev;
	while (lst && lst != top)
	{
		lst = lst->next;
		prev = lst->prev;
		while (prev != top)
		{
			if (prev->value == lst->value)
				return (0);
			prev = prev->prev;
		}
		lst = (lst->prev)->prev;
	}
	return (1);
}

int		read_args(int argc, char **argv, t_list **top, int fl)
{
	int		i;
	t_list	*lst;
	t_list	*next;

	lst = *top;
	next = *top;
	i = 1;
	while (++i < argc + 1)
		if (ft_atoi_new(argv[i + fl]) == 2147483648 && write(2, "Error\n", 6))
			return (0);
		else
		{
			lst = ft_lstnew(ft_atoi_new(argv[i + fl]), NULL, next);
			next->prev = lst;
			next = lst;
		}
	if (argc >= 2)
	{
		lst->prev = *top;
		(*top)->next = lst;
	}
	return (1);
}
