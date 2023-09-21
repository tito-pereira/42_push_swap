/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:37:45 by tibarbos          #+#    #+#             */
/*   Updated: 2023/09/21 15:37:51 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
- colocar nomes correctos nas funcoes;
- colocar ja as funcoes todas ();

- experimentar outros chunks para 500
*/

void	the_finder(list *stacka, int *first, int *last, int count)
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

int	find_next_chunk(list *stacka, int total, int count)
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

void	chunk_divide(list **stacka, list **stackb, int total)
{
	int	chest;
	int	count;

	chest = 0;
	count = 0;
	while (*stacka != NULL)
	{
		while (!((*stacka)->index >= count && (*stacka)->index <= (count + 19)))
		{
			if (find_next_chunk(*stacka, total, count) == 0)
				(*stacka) = lst_ra(*stacka);
			else if (find_next_chunk(*stacka, total, count) == 1)
				(*stacka) = lst_rra(*stacka);
		}
		if ((*stacka)->index >= count && (*stacka)->index <= (count + 19))
		{
			lst_p(stacka, stackb);
			printf("pb\n");
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

int	next_index(list *stackb, int idx)
{
	int	i;

	i = 0;
	while (stackb->index != idx) {
		stackb = stackb->next;
		i++;
	}
	return (i);
}

void	push_b(list **stacka, list **stackb, int total)
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
			lst_p(&(*stackb), &(*stacka));
			printf("pa\n");
			count--;
			total--;
		}
	}
}

void	lst_big_rotate(list **stacka, list **stackb, int total)
{
	if (check_status((*stacka), total) == 1)
		return;
	chunk_divide(stacka, stackb, total);
	push_b(stacka, stackb, total);
}
