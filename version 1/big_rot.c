#include "push_swap.h"

/*
- colocar nomes correctos nas funcoes;
- colocar ja as funcoes todas ();

. dividir em chunks de 20 ao mandar para a stack b (so uso rotates aqui,
com calculos intermedios do indice dentro do chunk mais proximo)
. retornar ao A usando o meu algoritmo antigo, find next, melhor caminho (rb ou rrb), porque organizado em chunks
ajuda imenso
*/

void	the_finder(list *stacka, int *first, int *last, int count)
{
	int	i;

	i = 0;
	while (!(stacka->index >= count && stacka->index <= (count + 19)))
	{
		stacka = stacka->next;
		i++;
	}
	if ((stacka->index >= count && stacka->index <= (count + 19)))
	{
		*first = i;
		*last = i;
	}
	while (stacka->next != NULL)
	{
		if ((stacka->index >= count && stacka->index <= (count + 19)))
			*last = i;
		stacka = stacka->next;
		i++;
	}
} //test

int	find_next_chunk(list *stacka, int total, int count)
{
	int	first;
	int	last;

	first = 0;
	last = 0;
	the_finder(stacka, &first, &last, count);
	if (first <= (total / 2) && last >= (total / 2))
		return (0); //primeira metade
	if (first > (total / 2) && last < (total / 2))
		return (1); //segunda metade
	if (first <= (total / 2) && last < (total / 2))
	{
		if (first > last)
			return (1);
	}
	return (0);
	//se ambos na primeira metade, roda up
	//se ambos na segunda metade, roda down
	//se um em cada, ver qual o valor mais pequeno
	//se first, roda 0, se last, roda 1
} //test

void	chunk_divide(list **stacka, list **stackb, int total)
{
	int	chest;
	int	count;

	chest = 0;
	count = 0;
	while (*stacka != NULL)
	{
		while (!((*stacka)->index >= count && (*stacka)->index <= (count + 19)))
		{
			if (find_next_chunk(*stacka, total, count) == 0)
				(*stacka) = lst_ra(*stacka);
			else if (find_next_chunk(*stacka, total, count) == 1)
				(*stacka) = lst_rra(*stacka);
		}
		if ((*stacka)->index >= count && (*stacka)->index <= (count + 19))
		{
			lst_p(stacka, stackb);
			printf("pb\n");
			total--;
			chest++;
		}
		if (chest == 20)
		{
			//printf("chest == 20\n");
			//printf("count:%d, chest:%d\n", count, chest);
			count += chest;
			chest = 0;
			//printf("count:%d, chest:%d\n", count, chest);
		}
	}
	//if (chest > 0 && *stacka == NULL), para aumentar o count? nao vale a pena
}

int	next_index(list *stackb, int idx)
{
	int	i;

	i = 0;
	while (stackb->index != idx) {
		stackb = stackb->next;
		i++;
	}
	return (i);
}

void	push_b(list **stacka, list **stackb, int total)
{
	int	count;

	count = total - 1;
	while ((*stackb) != NULL)
	{
		while ((*stackb)->index != count)
		{
			if (next_index(*stackb, count) > (total / 2))
				(*stackb) = lst_rrb((*stackb)); //verificar se a morada ta bem
			else if (next_index(*stackb, count) <= (total / 2))
				(*stackb) = lst_rb((*stackb)); //e verificar se escreve
		}
		if ((*stackb)->index == count)
		{
			lst_p(&(*stackb), &(*stacka)); //push b->a
			printf("pa\n");
			count--;
			total--;
		}
	}
}

void	lst_big_rotate(list **stacka, list **stackb, int total)
{
	chunk_divide(stacka, stackb, total);
	push_b(stacka, stackb, total);
}
