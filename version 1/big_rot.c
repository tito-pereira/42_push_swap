#include "push_swap.h"

/*
- colocar nomes correctos nas funcoes;
- colocar ja as funcoes todas ();

. dividir em chunks de 20 ao mandar para a stack b (so uso rotates aqui,
com calculos intermedios do indice dentro do chunk mais proximo)
. retornar ao A usando o meu algoritmo antigo, find next, melhor caminho (rb ou rrb), porque organizado em chunks
ajuda imenso
*/
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

int	find_next_chunk(list *stacka, int count)
{
	int	i;

	i = 0;
	while (!(stacka->index >= count && stacka->index <= (count + 20)))
	{
		stacka = stacka->next;
		i++;
	}
}

void	chunk_divide(list **stacka, list **stackb, int total)
{
	int	chest;

	chest = 0;
	while (!((*stacka)->index >= count && (*stacka)->index <= (count + 20)) && *stacka != NULL)
	{
		if (find_next_chunk(*stacka) > (total / 2))
			lst_rv();
		else if (find_next_chunk(*stacka) <= (total / 2))
			lst_r();
	}
	if ((*stacka)->index >= count && (*stacka)->index <= (count + 20))
	{
		lst_p(stacka, stackb);
		printf("pb\n");
		total--;
		chest++;
	}
	if (chest == 20)
	{
		count += chest;
		chest = 0;
	}
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
				(*stacka) = lst_rr((*stacka)); //verificar se a morada ta bem
			else if (next_index(*stackb, count) <= (total / 2))
				(*stacka) = lst_r((*stacka)); //e verificar se escreve
		}
		if ((*stacka)->index == count)
		{
			lst_p(&(*stackb), &(*stacka)); //push b->a
			printf("pa\n");
			count--;
			total--;
		}
	}
}

void	lst_big_rot(list **stacka, list **stackb, int total)
{
	chunk_divide(*stacka, *stackb, total);
	push_b(*stacka, *stackb, total);
}
