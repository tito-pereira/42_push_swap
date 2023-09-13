#include "push_swap.h"

//mergesort
//dividir sempre em dois arrays em metades
//recursivo, ou seja, chama a propria funcao

//quicksort
//escolhe um pivo, menores p esquerda, maiores p direita, pivo fica sempre no sitio correto
//cria sub arrays na esquerda e direita
//recursivo, chama a propria funcao

//ou faco insertion que e mais intuitivo e natural, mas com ma complexidade
//ou faco radix/merge/quick, com adaptacoes

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

//posso receber o array aqui e trata-lo aqui
int	algo_central(list *stacka, list *stackb/*int *array*/) {
	printf("ainda nao decidi algo\n");
	printf("testar outra coisa\n");
	printf("terceiro teste\n");
}

//aqui dentro, dar print as intrucoes
//contar o numero de instrucoes sempre que dou print? ou apenas o wc -l no fim?