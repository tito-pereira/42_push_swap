/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:39:19 by tibarbos          #+#    #+#             */
/*   Updated: 2023/09/14 10:39:25 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//rotates

t_list	*lst_rra(t_list *stack)
{
	t_list	*tmp;
	t_list	*last;
	int		i;

	tmp = stack;
	i = f_lstlen(stack);
	if (i >= 2)
	{
		i--;
		while (i > 1)
		{
			tmp = tmp->next;
			i--;
		}
		last = tmp;
		last = last->next;
		last->next = stack;
		tmp->next = NULL;
		write (1, "rra\n", 4);
		return (last);
	}
	return (NULL);
}

t_list	*lst_rrb(t_list *stack)
{
	t_list	*tmp;
	t_list	*last;
	int		i;

	tmp = stack;
	i = f_lstlen(stack);
	if (i >= 2)
	{
		i--;
		while (i > 1)
		{
			tmp = tmp->next;
			i--;
		}
		last = tmp;
		last = last->next;
		last->next = stack;
		tmp->next = NULL;
		write (1, "rrb\n", 4);
		return (last);
	}
	return (NULL);
}

t_list	*lst_ra(t_list *stack)
{
	t_list	*iter;
	t_list	*first;

	first = stack;
	iter = stack;
	while (iter->next != NULL)
		iter = iter->next;
	stack = stack->next;
	iter->next = first;
	first->next = NULL;
	write (1, "ra\n", 3);
	return (stack);
}

t_list	*lst_rb(t_list *stack)
{
	t_list	*iter;
	t_list	*first;

	first = stack;
	iter = stack;
	while (iter->next != NULL)
		iter = iter->next;
	stack = stack->next;
	iter->next = first;
	first->next = NULL;
	write (1, "rb\n", 3);
	return (stack);
}
