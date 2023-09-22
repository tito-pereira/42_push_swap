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

/*
void	print_stack(list *stack) {
	int	i = 1;
	while (stack->next != NULL) {
		ft_printf("%d, ", stack->data);
		stack = stack->next;
		i++;
	}
	if (stack->next == NULL)
		ft_printf("%d, ", stack->data);
}*/
void	main_aux(int *array, int total)
{
	int		*sorted;
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	sorted = bubble_sort(array, total);
	sorted = put_index(array, sorted, total);
	stacka = create_stack(stacka, array, sorted, total);
	if (total < 6)
		lst_small_rotate(&stacka, &stackb, total);
	else if (total > 5)
		lst_big_rotate(&stacka, &stackb, total);
	free_stacks(stacka, stackb);
	free_arrays(array, sorted);
}

int	main_errors(char **av, int *array, int i, int args)
{
	while (i < args)
	{
		if (check_limits(av[i + 1]) == 0)
		{
			free_one(array);
			return (0);
		}
		array[i] = f_atoi(av[i + 1]);
		i++;
	}
	if (check_dup(array) == 0)
	{
		free_one(array);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	args;
	int	i;
	int	*array;

	args = 0;
	i = 1;
	if (ac >= 2)
	{
		while (av[i])
		{
			args++;
			if (check_int(av[i]) == 0)
				return (0);
			i++;
		}
		array = malloc(args * sizeof(int));
		i = 0;
		if (main_errors(av, array, i, args) == 0)
			return (0);
		main_aux(array, args);
	}
}

/*
		if (second_error(av, array, i, args) == 0)
			return (0);
		if (check_dup(array) == 0)
			return (0);
*/

/*
-----
. sorted list, 0 moves max
. 3 args, 2 ou 3 moves
. 5 args, 12 moves max
. 100 args
	- <700: 5
	- <900: 4
	- <1100: 3
	- <1300: 2
	- <1500: 1
. 500 args
	- <5500: 5
	- <7000: 4
	- <8500: 3
	- <10000: 2
	- <11500: 1
*/

/*
questao do argv e receber varios argumentos

posso receber como:
./push_swap 9 8 7 6 5 4
ou
ARG="9 8 7 6 5 4"; ./push_swap $ARG
se receber assim
./push_swap 9 8 "7 6" 5 4
tou lixado
------
- ver se makefile e printf sao assim
- erro norminette header
- testar condicoes de erro
- error display no 2 ou no 1?
*/
