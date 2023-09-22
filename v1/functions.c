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

#include "push_swap.h"

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
		ft_printf("rra\n");
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
		ft_printf("rrb\n");
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
	ft_printf("ra\n");
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
	ft_printf("rb\n");
	return (stack);
}

// -------------------------------------
//sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
//ss : sa and sb at the same time.
/*
void	lst_s(list *stack) {
	if (f_lstlen(stack) >= 2) {
		f_lst_swap_two(stack);
	}
}

void	lst_2s(list *sta, list *stb) {
	lst_s(sta);
	lst_s(stb);
}

void	lst_2r(list *sta, list *stb) {
	lst_r(sta);
	lst_r(stb);
}

void	lst_2rv(list *sta, list *stb) {
	lst_rv(sta);
	lst_rv(stb);
}*/