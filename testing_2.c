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

int	array[] = {10, 4, 6, 1, 8};
int	sorted[] = {4, 1, 2, 0, 3};

//----------create / add to stack--------------------

list	*create_node(list *stacka, int array, int order) {
    list	*new;
    new = malloc(sizeof(list));
    new->data = array;
	new->index = order;
    new->next = NULL;
	return (new);
}

list	*lst_add_front(list *stacka, int array, int order) {
	list	*new;
	list	*tmp;
	tmp = stacka;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = create_node(new, array, order);
	tmp->next = new;
	return (stacka);
}

list	*create_stack(list *stacka, int *array, int *sorted) {
	int	i;
	i = 0;
	if (stacka == NULL) {
		stacka = create_node(stacka, array[i], sorted[i]);
		i++;
	}
	while (array[i]) {
		stacka = lst_add_front(stacka, array[i], sorted[i]);
		i++;
	}
	return (stacka); 
}

//--------------stack algorithm----------------------

//rotate, ultimo para primeiro
//swap
//push
list	*tmp;
int	count;
count = 0;
while ((stacka->index != count) && (stacka != NULL)) {
	tmp = stacka;
	tmp = tmp->next;
	if (stacka->data > tmp->data) {
		lst_s(stacka);
		printf("sa\n");
	}
	else {
		lst_rv(stacka);
		printf("rv\n");
	}
}
if ((stacka->index == count) && (stacka != NULL)) {
	lst_p(stackb, stacka);
	printf("pb\n");
	count++;
}
while (stackb != NULL) {
	lst_p(stacka, stackb);
	printf("pa\n");
}

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

void	print_stack(list *stack) {
	int	i = 1;
	while (stack->next != NULL) {
		printf("element:%d;\ndata:%d;\nindex:%d;\n-----\n", i, stack->data, stack->index);
		stack = stack->next;
		i++;
	}
	if (stack->next == NULL)
		printf("element:%d;\ndata:%d;\nindex:%d;\n-----\n", i, stack->data, stack->index);
}

int	main() {
	list	*stacka;
	list	*stackb;
	stacka = NULL;
	stackb = NULL;
	stacka = create_stack(stacka, array, sorted);
	print_stack(stacka);
	//ate aqui funciona top
}

//ja sei, a minha nova duvida era - eu nem sequer preciso de passar a data em si para dentro da stack,
//da estrutura, da lista, etc. eu so preciso de passar o indice, ou passo a data na mesma para dar display?
//eu acho que o push swap so da as instrucoes. pelo sim pelo nao, passar a data

/*
list	*create_node(list *stacka, int array, int order) {
    list	new;
    new = (list)malloc(sizeof(list));
    new.data = array;
	new.index = order;
    new.next = NULL;
	stacka = &new;
	return (new);
}
list	*lst_add_back(list *stacka, int array, int order) {
	list	*new;
	new = create_node(new, array, order);
	if (!new)
        return;
	new.next = &stacka;
	return (new);
}
list	*create_stack(list *stacka, int *array, int *sorted) {
	int	i;
	i = f_arrlen(array);
	if (stacka == NULL) {
		stacka = create_node(stacka, array[i], sorted[i]);
		i--;
	}
	while (i >= 0) {
		stacka = add_node(stacka, array[i], sorted[i]);
		i--;
	}
	return (stacka); 
}
*/