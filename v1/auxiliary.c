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
