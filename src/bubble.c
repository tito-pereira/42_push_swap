/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:33:22 by tibarbos          #+#    #+#             */
/*   Updated: 2023/09/20 16:33:28 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//array sorting with bubble sort

int	*f_arrdup(int *array, int total)
{
	int	*new;
	int	i;

	i = 0;
	new = malloc(total * sizeof(int));
	while (i < total)
	{
		new[i] = array[i];
		i++;
	}
	return (new);
}

int	*bubble_sort(int *array, int total)
{
	int	i;
	int	tmp;
	int	*new;

	i = 0;
	new = f_arrdup(array, total);
	while (i < (total - 1))
	{
		if (new[i] > new[i + 1])
		{
			tmp = new[i];
			new[i] = new[i + 1];
			new[i + 1] = tmp;
			i = -1;
		}
		if (i == (total - 1))
			break ;
		i++;
	}
	return (new);
}

int	*put_index(int *array, int *sorted, int total)
{
	int	j;
	int	i;
	int	*index;

	i = 0;
	index = malloc(total * sizeof(int));
	while (i < total)
	{
		j = 0;
		while (array[j] != sorted[i])
			j++;
		index[j] = i;
		i++;
	}
	free (sorted);
	return (index);
}
