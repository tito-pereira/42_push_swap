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

/*
typedef	struct	bass {
	int	*array;
	int	*order;
	int	total;
}	le_ints;
*/

//erros v
long	f_atoi(char *str);
int	check_int(char *str);
int	check_limits(char *arg);
int	check_dup(int *array);
//auxiliary v
list	*create_node(int array, int order);
list	*lst_add_front(list *stacka, int array, int order);
list	*create_stack(list *stacka, int *array, int *sorted, int total);
//functions v
int	f_lstlen(list *lst);
void	lst_p(list **stackb, list **stacka);
list	*lst_r(list *stack);
list	*lst_rv(list *stack);
//bubble v
int	*f_arrdup(int *array, int total);
int	*bubble_sort(int *array, int total);
int	*put_index(int *array, int *sorted, int total);
//algorithm v
int	next_index(list *stacka, int count);
void	lst_smart_rotate(list **stacka, list **stackb, int total);

#endif
