/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:41:51 by tibarbos          #+#    #+#             */
/*   Updated: 2023/09/21 17:41:59 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//push e swaps

void	lst_p(t_list **stackb, t_list **stacka)
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
	}
}

t_list	*lst_s(t_list *stacka)
{
	t_list	*tmp;

	tmp = stacka;
	tmp = tmp->next;
	stacka->next = tmp->next;
	tmp->next = stacka;
	printf("sa\n");
	return (tmp);
}
