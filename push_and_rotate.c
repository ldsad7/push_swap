/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 03:18:35 by tsimonis          #+#    #+#             */
/*   Updated: 2019/02/07 03:24:58 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_stack_second(t_list **b, t_list *pmt)
{
	t_list	*tmp;

	if (!((*b)->prev))
	{
		free(*b);
		*b = NULL;
	}
	else if (((*b)->prev)->prev == *b)
	{
		tmp = *b;
		*b = (*b)->prev;
		free(tmp);
		(*b)->next = NULL;
		(*b)->prev = NULL;
	}
	else
	{
		tmp = (*b)->prev;
		pmt = (*b)->next;
		free(*b);
		*b = NULL;
		tmp->next = pmt;
		pmt->prev = tmp;
		*b = tmp;
	}
}

int				push_stack(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*pmt;

	if (!(*b))
		return (1);
	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		pmt = *a;
		*a = ft_lstnew((*b)->value, pmt, tmp);
		tmp->prev = *a;
		pmt->next = *a;
	}
	else if (*a)
	{
		tmp = *a;
		*a = ft_lstnew((*b)->value, tmp, tmp);
		tmp->next = *a;
		tmp->prev = *a;
	}
	else
		*a = ft_lstnew((*b)->value, NULL, NULL);
	pmt = NULL;
	push_stack_second(b, pmt);
	return (1);
}

int				rotate_forward(t_list **top)
{
	if (!(*top) || !((*top)->next))
		return (1);
	*top = (*top)->prev;
	return (1);
}

int				rotate_backward(t_list **top)
{
	if (!(*top) || !((*top)->next))
		return (1);
	*top = (*top)->next;
	return (1);
}
