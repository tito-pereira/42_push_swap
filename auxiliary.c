#include "push_swap.h"

list	*create_node(list *stacka, int value, int order) {
    list	new;
    new = malloc(sizeof(list));
    if (!new)
        return;
    new->data = value;
	new->index = order;
    new->next = NULL;
	stacka = &new;
	return (stacka);
}

list	*add_node(list *stacka, int array, int order) {
	ez;
}
/*
void	add_front(list *begin, list new) {
	new.next = begin;
	//new.next = *begin;
	//*new.next = &begin;
}

void	ad_front(list *begin, int supply) {
	list	new;
	new = create_node(supply);
	new.next = begin;
}

void	add_back(list *begin, list new) {
	ez;
}
//o push para a stack vai usar esta funcao

void	ad_back(list) {
	ez;
}*/

list	*create_stack(list *stacka, int *array, int *sorted) {
	int	i;
	i = f_arrlen(array);
	if (stacka == NULL)
		stacka = create_node(stacka, array[i], sorted[i]);
	while (i > 0) {
		stacka = add_node(stacka, array[i], sorted[i]);
		i--;
	}
	return (stacka); 
}
/*You have to write a program named push_swap that takes as an argument the stack
a formatted as a list of integers. The first argument should be at the top of the
stack (be careful about the order).*/

//---auxiliary functions---

int	f_arrlen(int *array) {
	int i;
	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	f_swap(int *a, int *b) {
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	f_lst_swap_two(list *fst) {
	int	i1, i2;
	//list	travel;
	i1 = lst.data;
	i2 = 0; //tem que inicializar antes de entrar numa condicao
	if (lst.next != NULL) {
		lst = lst.next;
		i2 = lst.data;
		f_swap(&i1, &i2)
	}
} //as funcoes de swap vao usar isto, nao uso nenhuma para ja por isso relax

int	*array_dup(int *array) {
	int	len;
	len = 0;
	while (array[len])
		len++;
	int	*dup;
	dup = (int *)malloc(len * sizeof(int));
	for (int i = 0; array[i]; i++)
		dup[i] = array[i]
	return (dup);
}

/*int	f_lstlen(list *lst) {
	int	c;
	c = 1;
	//list	tmp;
	//tmp = lst;
	while (lst.next != NULL) {
		lst = lst.next;
		c++;
	}
	return (c);
} //posso usar libft, tipo um lstiter com contador
*/

/*void	f_swap(int *a, int *b) {
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}*/