/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:03:27 by tibarbos          #+#    #+#             */
/*   Updated: 2023/09/21 17:50:50 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_switch(t_list *stacka, int total)
{
	int	one;
	int	two;

	one = 0;
	two = 0;
	if (total > 1)
	{
		one = stacka->index;
		stacka = stacka->next;
		two = stacka->index;
		if (one > two)
			return (1);
	}
	return (0);
}

int	check_status(t_list *stacka, int total)
{
	int	one;
	int	two;

	one = 0;
	two = 0;
	if (total > 1)
	{
		while (stacka->next != NULL)
		{
			one = stacka->index;
			stacka = stacka->next;
			two = stacka->index;
			if (two == (one + 1))
				continue ;
			else
				return (0);
		}
		return (1);
	}
	else if (total == 1)
		return (1);
	return (0);
}

void	lst_small_rotate(t_list **stacka, t_list **stackb, int total)
{
	int	count;

	count = 0;
	while ((*stacka) != NULL)
	{
		if (check_status(*stacka, total) == 0)
		{
			if (check_switch(*stacka, total) == 0)
			{
				if (total < 4)
					(*stacka) = lst_rra((*stacka));
				else if (total > 3 && (*stacka)->index != count)
					(*stacka) = lst_rra((*stacka));
				else if (total > 3 && (*stacka)->index == count)
				{
					lst_pb(&(*stacka), &(*stackb));
					count++;
					total--;
				}
			}
			else if (check_switch(*stacka, total) == 1 && total < 6)
				(*stacka) = lst_sa((*stacka));
		}
		else if (check_status(*stacka, total) == 1)
			break ;
	}
	while ((*stackb) != NULL)
	{
		lst_pa(&(*stackb), &(*stacka));
	}
}
