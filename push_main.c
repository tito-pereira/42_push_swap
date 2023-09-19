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
	lst_smart_rotate(&stacka, &stackb, total);
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
//test 1 - erros, contagem total, criacao do array
//test 2 - array algo, criacao do sorted
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
		//ate aqui resulta, agr meter o sorting
		int	*sorted;
		sorted = bubble_sort(array, args);
		sorted = put_index(array, sorted, args);
	}
	else
		return 0;
}

//test 3 - criacao e introducao na stack
//test 4 - stack sorting
int	main(int ac, char **av) {
	//teste com 10 indices so, para o checker;
	//int	array_a[] = {9, 5, 8, 3, 2, 6, 1, 7, 4, 0};
	//int	sorted_a[] = {9, 5, 8, 3, 2, 6, 1, 7, 4, 0};
    //int total = 10;
	list	*stacka;
	list	*stackb;
	stacka = NULL;
	stackb = NULL;
	stacka = create_stack(stacka, array, sorted, args);
	lst_smart_rotate(&stacka, &stackb, total);
}*/

//-----------------------------------------
/*
No args:
If no parameters are specified, the program must not display anything and give the
prompt back.
-> empty return()
*/