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

//em bulk: (char *)->(atoi)->(int *)->(push stack)->(list)
//os erros verificar em passos intermedios

int	push_main(int ac, char **av) {
	if (ac >= 2) {
		int	len; //len vai ser usado para malloc(array)
		len = 0;
		//posso tentar juntar estes dois modulos, a iteracao e a mesma, e dou check a dois erros
		for (int i = 1; av[i]; i++) {
			len++;
			if (check_int(av[i]) == 0)
				return; //error message
		}
		int	*array;
		array = (int *)malloc(len * sizeof(int));
		for (int i = 1; array[i]; i++) {
			//check errors for the integers
			array[i - 1] = f_atoi(av[i]);
			if (check_limit(array[i - 1]) == 0)
				return; //error message
		}
		//dar sort ao array e retornar a ordem
		int	*sorted;
		sorted = array_algo(array);
		// adicionar array ao contrario na stack A
		list	*stacka;
		list	*stackb;
		for (int i = len; array[i]; i--) {
			add_stack(stacka, array[i]);
		}
		// enviar a stack para rodar e push
		//algo_central(stacka, stackb/*int *array*/);
		list_algo(stacka, stackb);
	}
	else
		return; //redundante, posso tirar, give prompt back
}

/*
No args:
If no parameters are specified, the program must not display anything and give the
prompt back.
-> empty return()
*/

/*
a seguir testo a parte em que recebo um sorted array
e faco as funcoes de stack usando o index
e meto ja isso a funcionar e depois so falta o algoritmo de sort com array de ints
*/
