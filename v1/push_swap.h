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

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H
# include <stdio.h> //nao posso usar, apenas o meu proprio printf
//# include "ft_printf.h"
# include <stdlib.h> //malloc
# include <limits.h> //para os erros
# include <unistd.h> //para as mensagens de erro

typedef struct stuff
{
	int				data;
	int				index;
	struct stuff	*next;
}	t_list;

//erros v
long	f_atoi(char *str);
int		check_int(char *str);
int		check_limits(char *arg);
int		check_dup(int *array);
//auxiliary v
t_list	*create_node(int array, int order);
t_list	*lst_add_front(t_list *stacka, int array, int order);
t_list	*create_stack(t_list *stacka, int *array, int *sorted, int total);
//functions v
int		f_lstlen(t_list *lst);
void	lst_p(t_list **stackb, t_list **stacka);
t_list	*lst_ra(t_list *stack);
t_list	*lst_rb(t_list *stack);
t_list	*lst_rra(t_list *stack);
t_list	*lst_rrb(t_list *stack);
t_list	*lst_s(t_list *stacka);
//bubble v
int		*f_arrdup(int *array, int total);
int		*bubble_sort(int *array, int total);
int		*put_index(int *array, int *sorted, int total);
//small rot v
int		check_status(t_list *stacka, int total);
void	lst_small_rotate(t_list **stacka, t_list **stackb, int total);
//big rot
void	lst_big_rotate(t_list **stacka, t_list **stackb, int total);

#endif
