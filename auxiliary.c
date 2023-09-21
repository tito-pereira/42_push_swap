/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:01:19 by tibarbos          #+#    #+#             */
/*   Updated: 2023/09/19 12:01:29 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int array, int order)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->data = array;
	new->index = order;
	new->next = NULL;
	return (new);
}

t_list	*lst_add_front(t_list *stacka, int array, int order)
{
	t_list	*new;
	t_list	*tmp;

	tmp = stacka;
	new = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = create_node(array, order);
	tmp->next = new;
	return (stacka);
}

t_list	*create_stack(t_list *stacka, int *array, int *sorted, int total)
{
	int	i;

	i = 0;
	if (stacka == NULL)
	{
		stacka = create_node(array[i], sorted[i]);
		i++;
	}
	while (i < total)
	{
		stacka = lst_add_front(stacka, array[i], sorted[i]);
		i++;
	}
	return (stacka); 
}

int	f_lstlen(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		i++;
		lst = lst->next;
	}
	if (lst->next == NULL)
		i++;
	return (i);
}

/*You have to write a program named push_swap that takes as an argument the
stack a formatted as a list of integers. The first argument should be at
the top of the stack (be careful about the order).*/

//---auxiliary functions---

/*
int	f_arrlen(int *array) {
	int i;
	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	f_swap(int *a, int *b) {
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	f_lst_swap_two(list *fst) {
	int	i1, i2;
	i1 = lst.data;
	i2 = 0;
	if (lst.next != NULL) {
		lst = lst.next;
		i2 = lst.data;
		f_swap(&i1, &i2)
	}
}

int	*array_dup(int *array) {
	int	len;
	len = 0;
	while (array[len])
		len++;
	int	*dup;
	dup = (int *)malloc(len * sizeof(int));
	for (int i = 0; array[i]; i++)
		dup[i] = array[i]
	return (dup);
}

int	f_lstlen(list *lst) {
	int	i;
	i = 0;
	while (lst->next != NULL) {
		i++;
		lst = lst->next;
	}
	if (lst->next == NULL)
        i++;
	return (i);
}
*/