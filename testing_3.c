/*
teste de criacao da stack e empurrar as arrays para dentro da stack
(check)
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

//rrb (reverse rotate b): Shift down all elements of stack b by 1.
//The last element becomes the first one.
// printf (rva) porque so uso na stack a

void	lst_rv(list *stack) {
	list	*tmp;
	list	*last;
	tmp = stack;
	i = f_lstlen(stack);
	if (i >= 2) {
		i--;
		while (i > 0) {
			tmp = tmp->next;
			i--;
		}
		//ou uso duplo pointer como loop, ou uso lstlen p saber quantas iteracoes exatas antes do ultimo elemento
		last = tmp;
		last = last.next;
		last.next = stack;
		tmp.next = NULL;
	}
}

//sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
// printf (sa) porque so uso na stack a

void	lst_s(list *stack) {
	if (f_lstlen(stack) >= 2) {
		f_lst_swap_two(stack);
	}
}

/*pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
push a = b -> a; (X if b empty)
push b = a -> b; (X if a empty)
*/

void	lst_pa(list *stb, list *sta) {
	if (f_lstlen(stb) > 0) {
		if (sta == NULL) {
			sta = stb;
			sta.next = NULL;
			stb = stb.next;//segundo elemento ou NULL
		}
		else
			stb.next = sta;
			sta = stb.next;
		printf("pa\n");
	}
}
//criar tmp para o segundo elemento
//
if (sta == NULL) {
	sta = stb;
	sta.next = NULL;
	stb = (segundo elemento)
}
//adicionar condicao, se puxar para uma lista vazia
void	lst_pb(list *sta, list *stb) {
	if (f_lstlen(sta) > 0) {
		sta.next = stb;
		printf("pb\n");
	}
}
//adicionar moradas dos pointers mesmo porque quero alterar as variaveis
//ou crio statics


void	sort_stack(list *stacka, list *stackb) {
	list	*tmp;
	int	count;
	count = 0;
	while (stacka != NULL) {
		while (stacka->index != count) {
			tmp = stacka;
			tmp = tmp->next;
			if (stacka->data > tmp->data) {
				lst_s(stacka);
				printf("sa\n");
			}
			else {
				lst_rv(stacka);
				printf("rva\n");
			}
		}
		if ((stacka->index == count) && (stacka != NULL)) {
			lst_p(stackb, stacka);
			printf("pb\n");
			count++;
		}
	}
	while (stackb != NULL) {
		lst_p(stacka, stackb);
		printf("pa\n");
	}
}
//colocar os prints dentro das proprias funcoes

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
	//sort_stack(stacka, stackb);
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