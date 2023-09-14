/*
teste de criacao da stack, funcoes e algoritmo de stack, a partir dos dois arrays
*/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

typedef	struct	stuff {
	int	data;
	int	index;
	struct stuff	*next;
}	list;

//criar dois (int *) ja completos
int	array[] = {10, 4, 6, 1, 8}
int	sorted[] = {4, 1, 2, 0, 3}

//----------create / add to stack--------------------

list	*create_node(list *stacka, int array, int order) {
    list	new;
    new = malloc(sizeof(list));
    if (!new)
        return;
    new.data = array;
	new.index = order;
    new.next = NULL;
	stacka = &new;
	return (stacka);
}

list	*add_node(list *stacka, int array, int order) {
	list	*new;
	new = create_node(new, array, order);
	if (!new)
        return;
	new.next = &stacka;
	return (new);
}

list	*create_stack(list *stacka, int *array, int *sorted) {
	int	i;
	i = f_arrlen(array); //para comecar a adicionar a stack ao contrario, lst_add_back
	if (stacka == NULL)
		stacka = create_node(stacka, array[i], sorted[i]);
	while (i > 0) {
		stacka = add_node(stacka, array[i], sorted[i]);
		i--;
	}
	return (stacka); 
}
//ou posso adicionar direto com um list_add_front

//--------------stack algorithm----------------------

//rotate, swap, push
void	list_algo(list *stacka, list *stackb) {
	for (int i = 0; (stacka->index != 0) && (stacka != NULL); i++) {
		while (stacka->index != i) {
			lst_r(stacka);
			printf("ra\n");
		}
		if (stacka->index == i) {
			lst_p(a->b);
			printf("pb\n");
		}
	}
	while (stackb != NULL) {
		lst_p(b->a);
		printf("pa\n");
	}
}

//----------------main central-----------------------

int	main() {
	list	*stacka;
	list	*stackb;
	//int	array[] = {10, 4, 6, 1, 8}
	//int	sorted[] = {4, 1, 2, 0, 3}
	stackb = NULL;
	stacka = create_stack(stacka, array, sorted);
	list_algo(stacka, stackb);
}

//vou testar outra parte qualquer aqui
//talvez a parte de criar listas em si, e das funções de listas

//ja sei, a minha nova duvida era - eu nem sequer preciso de passar a data em si para dentro da stack,
//da estrutura, da lista, etc. eu so preciso de passar o indice, ou passo a data na mesma para dar display?
//eu acho que o push swap so da as instrucoes. pelo sim pelo nao, passar a data