/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:22:45 by tibarbos          #+#    #+#             */
/*   Updated: 2023/09/22 11:22:54 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arrays(int *array, int *sorted)
{
	if (array)
	{
		free (array);
		array = NULL;
	}
	if (sorted)
	{
		free (sorted);
		sorted = NULL;
	}
}
//por no fim dos errors 2 e 3, e no fim do main_aux

void	free_list(t_list *head)
{
	t_list	*delete;

	delete = NULL;
	while (head != NULL)
	{
		delete = head;
		head = head->next;
		free (delete);
	}
	delete = NULL;
}

void	free_stacks(t_list *stacka, t_list *stackb)
{
	if (stacka)
	{
		free_list(stacka);
		stacka = NULL;
	}
	if (stackb)
	{
		free_list(stackb);
		stackb = NULL;
	}
}
