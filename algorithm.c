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

//ainda falta adicionar o swap aqui. se for só rotates, entao faço o calculo dos custos
//duplo rotate c custos, push B, push de volta A

void	lst_smart_rotate(list **stacka, list **stackb, int total) {
	ez;
}
int	count = 0;
while ((*stacka) != NULL)
int	path = next_index(*stacka, count);
int half = total / 2;
path > (total / 2), segunda metade, rv (rotate down)
while ((*list)->index != count), continue;
if ((*stacka)->index == count) {
	pb(&stacka, &stackb); //push a->b
}
while ((*stackb) != NULL)
	pa(&stackb, &stacka); //push b->a

int	next_index(list *stacka, int count) {
	list	*tmp;
	tmp = stacka;
	int	i = 0;
	while (tmp->index != count) {
		tmp = tmp->next;
		i++;
	}
	return (i);
}