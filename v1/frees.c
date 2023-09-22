/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:22:45 by tibarbos          #+#    #+#             */
/*   Updated: 2023/09/22 11:52:20 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
11 allocs, 8 frees
- as stacks tao a dar free, faltam os arrays
- isto pressupoe 3 arrays?
- exato, 10 allocs, 10 frees, ha um array a mais xd prai no algo

- free_one_array (para os erros), acho que ta, testar depois
o erro do duplicado da 11 mallocs, e porque nao passa como erro
e vai pra processamento de stack
*/

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
