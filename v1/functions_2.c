/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:41:51 by tibarbos          #+#    #+#             */
/*   Updated: 2023/09/22 10:38:41 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_printf("pa\n");
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
		ft_printf("pb\n");
	}
}

t_list	*lst_sa(t_list *stacka)
{
	t_list	*tmp;

	tmp = stacka;
	tmp = tmp->next;
	stacka->next = tmp->next;
	tmp->next = stacka;
	ft_printf("sa\n");
	return (tmp);
}

t_list	*lst_sb(t_list *stackb)
{
	t_list	*tmp;

	tmp = stackb;
	tmp = tmp->next;
	stackb->next = tmp->next;
	tmp->next = stackb;
	ft_printf("sb\n");
	return (tmp);
}
