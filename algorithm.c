#include "push_swap.h"

//recebe array, ordena-o, mas tenho que retornar com indice
//array_dup, ordeno, comparo os numeros
//array_order, um terceiro array, que vai ter como data a ordem dos indices

int	*array_algo(int *array) {
	int	*sorted;
	//int	*order;
	int	j;
	//j = 0;
	sorted = array_dup(array);
	//order = array_dup(array);
	sorted = fazer_algoritmo(sorted);
	for (int i = 0; sorted[i]; i++) {
		j = 0;
		while (sorted[i] != array[j])
			j++;
		sorted[i] = j;
	}
	return (sorted);
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

//duplo rotate c custos, push B, push de volta A

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
		while ((*list)->index != count) {
			total = total - count;
			if (next_index(*stacka, count) > (total / 2))
				(*stacka) = lst_rv((*stacka));
			else
				(*stacka) = lst_r((*stacka));
		}
		if ((*stacka)->index == count) {
			pb(&stacka, &stackb); //push a->b
			count++;
		}
	}
	//2
	while ((*stackb) != NULL)
		pa(&stackb, &stacka); //push b->a
}

//path > (total / 2), segunda metade, rv (rotate down)
//path < (total / 2), primeira metade, r (rotate up)
//sera que realizo (path * funcao), ou deixo o loop a calcular um a um?

/*
1- enquanto a stack A nao for nula
	1.1- enquanto nao for aquele indice
		1.1.1- calculos inteligentes:
			a- ver a distancia a q o proximo indice se encontra
			b- calcular se esta na metade superior ou inferior
		1.1.2- conclusao (r ou rv):
			a- if conditions para cada
			b- funcoes "r" ou "rv" de acordo
	1.2- encontrar o indice
		a- push a->b;

2- enquanto a stack B nao for nula
	a- push b->a;
*/