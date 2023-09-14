/*
- rv function, falta testar com 1 elemento (da segfault) //duplo pointer como loop counter?
- adicionar rotate normal (para o proximo algoritmo)
- fazer push (testar, acho q ta)
- fazer swap
- fazer novo algoritmo? fica ja feito? depois se não der é so trocar
*/

/*ja tou a testar a minha primeira tentativa, do loop de (swap/rotate) e mandar
o indice minimo para B e depois retornar a A

caso nao de, vou testar a do calculo: rat cima ou baixo*/

/*criar listas para teste*/
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

/*typedef struct wtv {
    list    *stacka;
    list    *stackb;
}  p_list;*/

/*
int	array_a[] = {10, 4, 6, 1};
int	sorted_a[] = {4, 1, 2, 0};
int	array_b[] = {10, 4, 6, 1, 8};
int	sorted_b[] = {4, 1, 2, 0, 3};
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
    printf("here\n");
	if (stacka == NULL) {
        printf("create\n");
		stacka = create_node(stacka, array[i], sorted[i]);
		i++;
	}
	while (i < total) {
        printf("add\n");
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
    printf("len:%d\n-----------------\n", i);
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
}

/*pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
push a = b -> a; (X if b empty)
push b = a -> b; (X if a empty)
*/

//enviante (B) estar vazia, salta a frente c if
//recebente (A) estar vazia, nesse caso, igualar o pointer ao node transferido, next = NULL;
void	lst_p(list **stacka, list **stackb) {
    if (f_lstlen(*stackb) > 0) {//enviante (B) NAO vazio
        if (*stacka == NULL) {//recebente (A) vazio
			(*stacka) = (*stackb);
			(*stackb) = (*stackb)->next;
			(*stacka)->next = NULL;
		}
		else {//enviante (A) NAO vazio
			list	*tmp;
			tmp = (*stackb)->next;
			(*stackb) = (*stacka);
			(*stacka) = (*stackb);
			(*stackb) = tmp;
			}
	}
}//testar, acho que ta pronta

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
    lst_p(&stacka, &stackb); //ta a resultar tudo ate aqui, deu segfault
	//---print results:
    print_stack(stacka);
    if (stackb) {
        printf("----------------------------------\n");
        print_stack(stackb);
    }
}