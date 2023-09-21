/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:37:45 by tibarbos          #+#    #+#             */
/*   Updated: 2023/09/21 18:33:56 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_index(t_list *stackb, int idx)
{
	int	i;

	i = 0;
	while (stackb->index != idx)
	{
		stackb = stackb->next;
		i++;
	}
	return (i);
}

void	push_b(t_list **stacka, t_list **stackb, int total)
{
	int	count;

	count = total - 1;
	while ((*stackb) != NULL)
	{
		while ((*stackb)->index != count)
		{
			if (next_index(*stackb, count) > (total / 2))
				(*stackb) = lst_rrb((*stackb));
			else if (next_index(*stackb, count) <= (total / 2))
				(*stackb) = lst_rb((*stackb));
		}
		if ((*stackb)->index == count)
		{
			lst_pa(&(*stackb), &(*stacka));
			count--;
			total--;
		}
	}
}

void	lst_big_rotate(t_list **stacka, t_list **stackb, int total)
{
	if (check_status((*stacka), total) == 1)
		return ;
	chunk_divide(stacka, stackb, total);
	push_b(stacka, stackb, total);
}
