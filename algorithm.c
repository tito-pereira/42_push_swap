/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:03:27 by tibarbos          #+#    #+#             */
/*   Updated: 2023/09/19 12:11:09 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//array sorting with bubble sort
int	*f_arrdup(int *array, int total) {
	int	*new;
	new = malloc(total * sizeof(int));
	for (int i = 0; i < total; i++)
		new[i] = array[i];
	return (new);
}

int	*bubble_sort(int *array, int total) {
	int	i, tmp;
	int	*new;
	i = 0;
	new = f_arrdup(array, total);
	while (i < (total - 1)) {
		if (new[i] > new[i + 1]) {
			tmp = new[i];
			new[i] = new[i + 1];
			new[i + 1] = tmp;
			i = -1;
		}
		if (i == (total - 1))
			break;
		i++;
	}
	return (new);
}

int	*put_index(int *array, int *sorted, int total) {
	int j;
	int	*index;
	index = malloc(total * sizeof(int));
	for (int i = 0; i < total; i++) {
		j = 0;
		while (array[j] != sorted[i])
			j++;
		index[j] = i;
	}
	return (index);
}

//stack sorting
//duplo rotate c custos, push B, push de volta A
//-----TEST ALGO-----------
int	next_index(list *stacka, int count) {
	int	i = 0;
	while (stacka->index != count) {
		stacka = stacka->next;
		i++;
	}
	return (i);
}

void	lst_smart_rotate(list **stacka, list **stackb, int total) {
	int	count;
	count = 0;
	while ((*stacka) != NULL) {
		while ((*stacka)->index != count) {
			total = total - count;
			if (next_index(*stacka, count) > (total / 2))
				(*stacka) = lst_rv((*stacka));
			else
				(*stacka) = lst_r((*stacka));
		}
		if ((*stacka)->index == count) {
			lst_p(&(*stacka), &(*stackb)); //push a->b
			printf("pb\n");
			count++;
		}
	}
	while ((*stackb) != NULL) {
		lst_p(&(*stackb), &(*stacka)); //push b->a
		printf("pa\n");
	}
}
//-------------------------

//path > (total / 2), segunda metade, rv (rotate down)
//path < (total / 2), primeira metade, r (rotate up)
//sera que realizo (path * funcao), ou deixo o loop a calcular um a um?

/*
1- enquanto a stack A nao for nula
	1.1- enquanto nao for aquele indice
		1.1.1- calculos inteligentes:
			a- ver a distancia a q o proximo indice se encontra
			b- calcular se esta na metade superior ou inferior
		1.1.2- conclusao (r ou rv):
			a- if conditions para cada
			b- funcoes "r" ou "rv" de acordo
	1.2- encontrar o indice
		a- push a->b;

2- enquanto a stack B nao for nula
	a- push b->a;
*/
