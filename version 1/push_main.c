/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:28:07 by tibarbos          #+#    #+#             */
/*   Updated: 2023/09/13 18:28:16 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(list *stack) {
	int	i = 1;
	while (stack->next != NULL) {
		//printf("element:%d;\ndata:%d;\nindex:%d;\n-----\n", i, stack->data, stack->index);
		printf("%d, ", stack->data);
		stack = stack->next;
		i++;
	}
	if (stack->next == NULL)
		//printf("element:%d;\ndata:%d;\nindex:%d;\n-----\n", i, stack->data, stack->index);
		printf("%d, ", stack->data);
}

void	main_aux(int *array, int total) {
	int	*sorted;
	sorted = bubble_sort(array, total);
	sorted = put_index(array, sorted, total);
	list	*stacka;
	list	*stackb;
	stacka = NULL;
	stackb = NULL;
	stacka = create_stack(stacka, array, sorted, total);
	if (total < 6)
		lst_small_rotate(&stacka, &stackb, total);
	else if (total > 5)
		//lst_big_rotate();
		printf("not done yet\n");
	print_stack(stacka);
}

int	main(int ac, char **av) {
	if (ac >= 2) {
		int	args;
		args = 0;
		for (int i = 1; av[i]; i++) {
			args++;
			if (check_int(av[i]) == 0)
				return 0;
		}
		int	*array;
		array = malloc(args * sizeof(int));
		for (int i = 0; i < args; i++) {
			if (check_limits(av[i + 1]) == 0)
				return 0;
			array[i] = f_atoi(av[i + 1]);
		}
		if (check_dup(array) == 0)
			return 0;
		main_aux(array, args);
	}
	else
		return 0;
}

/*
incluindo versao 1
se for preciso, meter regras especiais para casos pequenitos tipo argumentos < 10,
evitar dar duplo push a tudo
acrescentar os simple tests
- lista already sorted
- pequenos casos de swap apenas

simple version
sorted list, 0 moves max
3 args, 2 ou 3 moves
5 args, 12 moves max
100 args, 1500 moves max (versao 2)
500 args, 11500 moves max (versao 2)
-----
preciso de tentar um novo algoritmo aqui

simple version
sorted list, 0 moves max
3 args, 2 ou 3 moves
5 args, 12 moves max
100 args, 1500 moves max
500 args, 11500 moves max

um calculo duplo de custos
if (next_index)[index + 2] <= (next_index)[index + 1]
if (next_index)[index + 1] mais proximo da metade que (next_index)[index + 2]
*/