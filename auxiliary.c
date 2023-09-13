#include "push_swap.h"

list	create_node(int supply) {
    list    new;
    new = malloc(sizeof(list));
    if (!new)
        return;
    new.data = supply;
    new.next = NULL;
	return (new);
}

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
}

list	*add_stack(list *stacka, int *array, int *sorted) {
	ez;
}

//a minua duvida aqui era sobre usar uma tmp list para iterar ou nao
//agora ja sei que sim
//ou nao, nao e preciso

//---auxiliary functions---

int	f_strlen(int *str) {
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int	f_lstlen(list *lst) {
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
} //as funcoes de swap vao usar isto

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