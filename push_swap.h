/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:38:09 by tibarbos          #+#    #+#             */
/*   Updated: 2023/09/14 10:38:19 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h> //nao posso usar, apenas o meu proprio printf
//# include "ft_printf.h"
# include <stdlib.h> //malloc
# include <limits.h> //para os erros
# include <unistd.h> //para as mensagens de erro

typedef	struct	stuff {
	int	data;
	int	index;
	struct stuff	*next;
}	list;

//criar uma struct para armazenar os dois arrays (stack e sorted) porque posso precisar deles no algoritmo?
/*
typedef	struct	things {
	int	*array;
	int	*sorted;
	struct	things	*next;
}	le_ints;
*/

//erros
int	f_atoi(char *str);
int	check_int(char *str);
int	check_limits(int *stack);
int	check_dup(int *str);
//auxiliary
list	*create_node(list *stacka, int value, int order);
list	*add_node(list *stacka, int array, int order);
list	*create_stack(list *stacka, int *array, int *sorted);
int	f_arrlen(int *array);
void	f_swap(int *a, int *b);
void	f_lst_swap_two(list *fst);
int	*array_dup(int *array);
//stack functions
void	lst_s(list *stack);
void	lst_2s(list *sta, list *stb);
void	lst_p(list *sta, list *stb);
void	lst_r(list *stack);
void	lst_2r(list *sta, list *stb);
void	lst_rv(list *stack);
void	lst_2rv(list *sta, list *stb);
//algorithm
int	*array_algo(int *array);
void	list_algo(list *stacka, list *stackb);

#endif
