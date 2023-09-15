/*
- testar algoritmo de custos inteligentes
o proto teste deu certo, pelo menos ja ordenou os indices. agora tenho que arranjar aqueles pequenos erros
dos elementos 1 e fazer mais qq coisa q nao me lembro
ah, contar os passos
e claro, ordenar o array
- erros elemento 1
- escrever instrucoes
- usar checker e contar passos
- ordenar array, le_ints, retornar sorted e total

- push (check)
- r () testar
- rv (check) segfault c 1 elemento, resto check
----------
- aplicar le_ints
- fazer swap
*/

//--------------------------------------------------------------------
//             TEST STACK FUNCTIONS
//--------------------------------------------------------------------
//   Base elements:
//---------------------
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

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

list	*create_stack(list *stacka, int *array, int *sorted, int total) {
	int	i;
	i = 0;
    //printf("here\n");
	if (stacka == NULL) {
        //printf("create\n");
		stacka = create_node(stacka, array[i], sorted[i]);
		i++;
	}
	while (i < total) {
        //printf("add\n");
		stacka = lst_add_front(stacka, array[i], sorted[i]);
		i++;
	} //preciso duma condicao para terminar este while
	return (stacka); 
}// talvez um numero tipo "total", que vem junto com o array e o sorted numa struct

//    Functions:
//---------------------

int	f_lstlen(list *lst) {
	int	i;
	i = 0;
	if (lst == NULL)
		return 0;
	while (lst->next != NULL) {
		i++;
		lst = lst->next;
	}
    if (lst->next == NULL)
        i++;
	return (i);
}

list	*lst_rv(list *stack) {
	list	*tmp;
	list	*last;
    int i;
	tmp = stack;
	i = f_lstlen(stack);
    //printf("len:%d\n-----------------\n", i);
	if (i >= 2) {
		i--;
		while (i > 1) {
			tmp = tmp->next;
			i--;
		}
		last = tmp;
		last = last->next;
		last->next = stack;
		tmp->next = NULL;
        return (last);
	}
    return NULL;
}//roda para baixo, ultimo para primeiro

list	*lst_r(list *stack) {
	list	*iter;
	list	*first;
	first = stack;
	iter = stack;
	while (iter->next != NULL)
		iter = iter->next;
	stack = stack->next;
	iter->next = first;
	first->next = NULL;
	return (stack);
}//roda para cima, primeiro para ultimo
//acho que ja ta, testar

/*pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
push a = b -> a; (X if b empty)
push b = a -> b; (X if a empty)
*/
//enviante (B) estar vazia, salta a frente c if
//recebente (A) estar vazia, nesse caso, igualar o pointer ao node transferido, next = NULL;
void	lst_p(list **stackb, list **stacka) {
	if (f_lstlen(*stackb) > 0) {
		if (*stacka == NULL) {
			printf("receptor empty\n");
			(*stacka) = (*stackb);
			(*stackb) = (*stackb)->next;
			(*stacka)->next = NULL;
		}
		else {
			printf("receptor full\n");
			list	*tmp;
			tmp = (*stackb)->next;
			(*stackb)->next = (*stacka);
			(*stacka) = (*stackb);
			(*stackb) = tmp;
			}
	}
}//testar, acho que ta pronta

//-----TEST ALGO-----------
int	next_index(list *stacka, int count) {
	//list	*tmp;
	int	i = 0;
	while (stacka->index != count) {
		stacka = stacka->next;
		i++;
	}
	return (i);
}

void	lst_smart_rotate(list **stacka, list **stackb, int total) {
	int	count;
	//int	ttotal;
	count = 0;
	//1
	while ((*stacka) != NULL) {
		while ((*stacka)->index != count) {
			total = total - count;
			if (next_index(*stacka, count) > (total / 2))
				(*stacka) = lst_rv((*stacka));
			else
				(*stacka) = lst_r((*stacka));
		}
		if ((*stacka)->index == count) {
			lst_p(&(*stacka), &(*stackb)); //push a->b
			count++;
		}
	}
	//2
	while ((*stackb) != NULL)
		lst_p(&(*stackb), &(*stacka)); //push b->a
}
//-------------------------

//    Main:
//---------------------
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
    int	array_a[] = {10, 4, 6, 1, 8};
    int	sorted_a[] = {4, 1, 2, 0, 3};
    int	array_b[] = {10, 4, 6, 1, 8};
    int	sorted_b[] = {4, 1, 2, 0, 3};
    int total = 5;
	list	*stacka;
	list	*stackb;
	stacka = NULL;
	stackb = NULL;
	stacka = create_stack(stacka, array_a, sorted_a, total);
	//---add functions:
    //stacka = lst_rv(stacka);
    //lst_p(&stacka, &stackb);
	stacka = lst_r(stacka); //loop infinito
	stacka = lst_r(stacka); //ok acho que ja esta a dar, testar algoritmo final
	lst_smart_rotate(&stacka, &stackb, total);
	//---print results:
    print_stack(stacka);
    if (stackb) {
        printf("----------------------------------\n");
        print_stack(stackb);
    }
}


//enviante (B) NAO vazio
//recebente (A) vazio
/*
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
}*/
//criar tmp para o segundo elemento
/*
if (sta == NULL) {
	sta = stb;
	sta.next = NULL;
	stb = (segundo elemento)
}*/
//adicionar condicao, se puxar para uma lista vazia