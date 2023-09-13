//#include "push_swap.h"
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

int	main() {
	list	*stacka;
	list	*stackb;
	//int	array[] = {10, 4, 6, 1, 8}
	//int	sorted[] = {4, 1, 2, 0, 3}
	stackb = NULL;
	stacka = create_stack(stacka, array, sorted);
	sort_stack(stacka, stackb); //e usar as funções
}

//vou testar outra parte qualquer aqui
//talvez a parte de criar listas em si, e das funções de listas

//ja sei, a minha nova duvida era - eu nem sequer preciso de passar a data em si para dentro da stack,
//da estrutura, da lista, etc. eu so preciso de passar o indice, ou passo a data na mesma para dar display?
//eu acho que o push swap so da as instrucoes. pelo sim pelo nao, passar a data