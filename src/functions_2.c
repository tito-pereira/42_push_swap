/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:41:51 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 11:33:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//push e swaps

void	lst_pa(t_list **stackb, t_list **stacka)
{
	t_list	*tmp;

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
			tmp = (*stackb)->next;
			(*stackb)->next = (*stacka);
			(*stacka) = (*stackb);
			(*stackb) = tmp;
		}
		write (1, "pa\n", 3);
	}
}

void	lst_pb(t_list **stackb, t_list **stacka)
{
	t_list	*tmp;

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
			tmp = (*stackb)->next;
			(*stackb)->next = (*stacka);
			(*stacka) = (*stackb);
			(*stackb) = tmp;
		}
		write (1, "pb\n", 3);
	}
}

t_list	*lst_sa(t_list *stacka)
{
	t_list	*tmp;

	tmp = stacka;
	tmp = tmp->next;
	stacka->next = tmp->next;
	tmp->next = stacka;
	write (1, "sa\n", 3);
	return (tmp);
}

t_list	*lst_sb(t_list *stackb)
{
	t_list	*tmp;

	tmp = stackb;
	tmp = tmp->next;
	stackb->next = tmp->next;
	tmp->next = stackb;
	write (1, "sb\n", 3);
	return (tmp);
}
