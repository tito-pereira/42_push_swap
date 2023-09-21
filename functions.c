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

int	f_lstlen(list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return 0;
	while (lst->next != NULL)
	{
		i++;
		lst = lst->next;
	}
    if (lst->next == NULL)
		i++;
	return (i);
}

list	*lst_rra(list *stack)
{
	list	*tmp;
	list	*last;
    int i;

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
		printf("rra\n");
        return (last);
	}
    return NULL;
}

list	*lst_rrb(list *stack)
{
	list	*tmp;
	list	*last;
    int i;

	tmp = stack;
	i = f_lstlen(stack);
	if (i >= 2)
	{
		i--;
		while (i > 1) {
			tmp = tmp->next;
			i--;
		}
		last = tmp;
		last = last->next;
		last->next = stack;
		tmp->next = NULL;
		printf("rrb\n");
        return (last);
	}
    return NULL;
}

list	*lst_ra(list *stack)
{
	list	*iter;
	list	*first;

	first = stack;
	iter = stack;
	while (iter->next != NULL)
		iter = iter->next;
	stack = stack->next;
	iter->next = first;
	first->next = NULL;
	printf("ra\n");
	return (stack);
}

list	*lst_rb(list *stack)
{
	list	*iter;
	list	*first;

	first = stack;
	iter = stack;
	while (iter->next != NULL)
		iter = iter->next;
	stack = stack->next;
	iter->next = first;
	first->next = NULL;
	printf("rb\n");
	return (stack);
}

void	lst_p(list **stackb, list **stacka)
{
	if (f_lstlen(*stackb) > 0)
	{
		if (*stacka == NULL)
		{
			(*stacka) = (*stackb);
			(*stackb) = (*stackb)->next;
			(*stacka)->next = NULL;
		}
		else
		{
			list	*tmp;
			tmp = (*stackb)->next;
			(*stackb)->next = (*stacka);
			(*stacka) = (*stackb);
			(*stackb) = tmp;
		}
	}
}

list	*lst_s(list *stacka)
{
	list	*tmp;

	tmp = stacka;
	tmp = tmp->next;
	stacka->next = tmp->next;
	tmp->next = stacka;
	printf("sa\n");
	return (tmp);
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