/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:32:27 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 11:32:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	the_finder(t_list *stacka, int *first, int *last, int count)
{
	int	i;

	i = 0;
	while (!(stacka->index >= count && stacka->index <= (count + 19)))
	{
		stacka = stacka->next;
		i++;
	}
	if ((stacka->index >= count && stacka->index <= (count + 19)))
	{
		*first = i;
		*last = i;
	}
	while (stacka->next != NULL)
	{
		if ((stacka->index >= count && stacka->index <= (count + 19)))
			*last = i;
		stacka = stacka->next;
		i++;
		if (stacka->next == NULL
			&& (stacka->index >= count && stacka->index <= (count + 19)))
			*last = i;
	}
}

int	find_next_chunk(t_list *stacka, int total, int count)
{
	int	first;
	int	last;

	first = 0;
	last = 0;
	the_finder(stacka, &first, &last, count);
	last = total - last;
	if (first <= (total / 2) && last >= (total / 2))
		return (0);
	if (first > (total / 2) && last < (total / 2))
		return (1);
	if (first <= (total / 2) && last < (total / 2))
	{
		if (first > last)
			return (1);
	}
	return (0);
}

void	chunk_rotate(t_list **stacka, int *total, int *count)
{
	while (!((*stacka)->index >= *count && (*stacka)->index <= (*count + 19)))
	{
		if (find_next_chunk(*stacka, *total, *count) == 0)
			(*stacka) = lst_ra(*stacka);
		else if (find_next_chunk(*stacka, *total, *count) == 1)
			(*stacka) = lst_rra(*stacka);
	}
}

void	chunk_divide(t_list **stacka, t_list **stackb, int total)
{
	int	chest;
	int	count;

	chest = 0;
	count = 0;
	while (*stacka != NULL)
	{
		chunk_rotate(stacka, &total, &count);
		if ((*stacka)->index >= count && (*stacka)->index <= (count + 19))
		{
			lst_pb(stacka, stackb);
			total--;
			chest++;
		}
		if (chest == 20)
		{
			count += chest;
			chest = 0;
		}
	}
}
