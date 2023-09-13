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
//aqui dentro, dar print as instrucoes?
//contar o numero de instrucoes sempre que dou print? ou apenas o wc -l no fim?