/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:22:45 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 11:33:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_one(int *array)
{
	if (array)
	{
		free (array);
		array = NULL;
	}
}

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
