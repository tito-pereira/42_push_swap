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

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

typedef struct stuff
{
	int				data;
	int				index;
	struct stuff	*next;
}	t_list;

//frees
void	free_one(int *array);
void	free_arrays(int *array, int *sorted);
void	free_stacks(t_list *stacka, t_list *stackb);
//erros v
long	f_atoi(char *str);
int		check_int(char *str);
int		check_limits(char *arg);
int		check_dup(int *array, int total);
//auxiliary v
t_list	*create_node(int array, int order);
t_list	*lst_add_front(t_list *stacka, int array, int order);
t_list	*create_stack(t_list *stacka, int *array, int *sorted, int total);
int		f_lstlen(t_list *lst);
//functions v
t_list	*lst_ra(t_list *stack);
t_list	*lst_rb(t_list *stack);
t_list	*lst_rra(t_list *stack);
t_list	*lst_rrb(t_list *stack);
//functions 2
t_list	*lst_sa(t_list *stacka);
t_list	*lst_sb(t_list *stackb);
void	lst_pa(t_list **stackb, t_list **stacka);
void	lst_pb(t_list **stackb, t_list **stacka);
//bubble v
int		*f_arrdup(int *array, int total);
int		*bubble_sort(int *array, int total);
int		*put_index(int *array, int *sorted, int total);
//small rot v
int		check_status(t_list *stacka, int total);
void	lst_small_rotate(t_list **stacka, t_list **stackb, int total);
//big rot
void	lst_big_rotate(t_list **stacka, t_list **stackb, int total);
//big 2
void	chunk_divide(t_list **stacka, t_list **stackb, int total);

#endif
