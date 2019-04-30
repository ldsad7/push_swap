/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 03:18:46 by tsimonis          #+#    #+#             */
/*   Updated: 2019/02/28 02:57:54 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_list **top)
{
	t_list	*prev;
	t_list	*next;

	if (!(*top))
		return ;
	prev = (*top)->prev;
	next = (*top)->next;
	free(*top);
	if (prev == next && prev)
	{
		prev->prev = NULL;
		prev->next = NULL;
		*top = prev;
		return ;
	}
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	*top = prev;
}

int		ft_lstdel(t_list **top)
{
	while (*top)
		ft_lstdelone(top);
	top = NULL;
	return (1);
}

t_list	*ft_lstnew(int value, t_list *prev, t_list *next)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new->value = value;
	new->prev = prev;
	new->next = next;
	return (new);
}

int		ft_lstlen(t_list *top)
{
	t_list	*tmp;
	int		i;

	if (!top)
		return (0);
	i = 1;
	tmp = top->prev;
	while (tmp && tmp != top && ++i)
		tmp = tmp->prev;
	return (i);
}
