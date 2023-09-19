/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:03:27 by tibarbos          #+#    #+#             */
/*   Updated: 2023/09/19 17:52:09 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
. adicionei uma formula geral para (sorted, 3, 5, 100, 500)
- testar e por a funcionar
- contar os passos com aqueles limites

caso nao funcione well.. posso tentar adicionar a condicao do duplo calculo,
mas nao sei muito bem se ira funcionar..
*/

#include "push_swap.h"

void	sort_three() {
	posso ver index e index + 1
if (index == 1 && index+1 == 3)
	pb, sa, pa
if (index == 2) {
	if (index+1 == 1), 
	else if (index+1 == 3),
else if (index == 3)
	if (),
	else if (),
}
}

//stack sorting
//duplo rotate c custos, push B, push de volta A
//-----TEST ALGO-----------
int	next_index(list *stacka, int count) {
	int	i = 0;
	while (stacka->index != count) {
		stacka = stacka->next;
		i++;
	}
	return (i);
}

int	check_switch(list *stacka, int total) {
	int	one;
	int two;
	one = 0;
	two = 0;
	if (total > 1) {
		one = stacka->index;
		stacka = stacka->next;
		two = stacka->index;
		if (one > two)
			//lst_s(stacka);
			//return 1; ainda n sei
	}
	return 0;
}//test

int	check_status(list *stacka, int total) {
	int	one;
	int two;
	one = 0;
	two = 0;
	if (total > 1) {
		while (stacka->index != NULL) {
			one = stacka->index;
			stacka = stacka->next;
			two = stacka->index;
			if (two == (one + 1))
				continue;
			else
				return 0;
		}
		return 1;
	}
	else if (total == 1)
		return 1;
	return 0;
} //test

void	lst_smart_rotate(list **stacka, list **stackb, int total) {
	int	count;
	count = 0;
	while ((*stacka) != NULL) {
		if (check_status(*stacka, total) == 0) {
			if (check_switch(*stacka, total) == 0) {
				//encravei aqui
				if (total < 4)
					lst_rv();
				else if (total > 3 && (*stacka)->index != count) {
					if (next_index(*stacka, count) > (total / 2))
						(*stacka) = lst_rv((*stacka));
					else if (next_index(*stacka, count) <= (total / 2))
						(*stacka) = lst_r((*stacka));
				}
				if (total > 3 && (*stacka)->index == count) {
					lst_p(&(*stacka), &(*stackb)); //push a->b
					printf("pb\n");
					count++;
					total--;
				}
			}
			else (switch, volta ao loop)
				lst_sa;
		}
	}
	while ((*stackb) != NULL) {
		lst_p(&(*stackb), &(*stacka)); //push b->a
		printf("pa\n");
	}
}

/*
sorted list, 0 moves max
3 args, 2 ou 3 moves
5 args, 12 moves max
100 args, 1500 moves max (versao 2)
500 args, 11500 moves max (versao 2)

posso fazer assim os casos possiveis
1 2 3 (---)
1 3 2 (pb, sa, pa) (status X, switch X, rra, status X, switch V, sa, status V) (2 acoes)
2 1 3 (sa) (status X, switch V, sa, status V) (1 acao)
2 3 1 (rra) (status X, switch X, rra, status V) (1 acao)
3 2 1 (sa, rra) (status X, switch V, sa, status X, switch X, rra, status V) (2 acoes)
3 1 2 (ra) (status X, switch V, sa, status X, switch X, )

posso ver index e index + 1
if (index == 1 && index+1 == 3)
	pb, sa, pa
if (index == 2) {
	if (index+1 == 1), 
	else if (index+1 == 3),
else if (index == 3)
	if (),
	else if (),
}
*/

//-------------------------
/*
acho que o segredo grosseiro é usar o maximo de calculos de custos e funcoes e condicoes possiveis

formula 1 - algoritmo universal

1 - check_status, pega no pointer atual, ve se é a cauda final, imediatamente despeja b e acaba
(e tambem resolve ja o teste da stack ja ordenada)
(substitui aquele check_sorted inicial)
(eu acho q o check_sorted funciona como check status xd) break;
2 - verifica switch a, é sempre uma ajudinha (acho eu) se sim, volta ao inicio
3 - (total < 4) rra
3 - (total > 5) faz o calculo do proximo index normal (pelas metades)
(faco aquilo do duplo calculo c o index seguinte?)
testar o 5, ver se encaixa algum

formula 2 - casos especificos para sorted, 3, 5, 100 e 500
	s? break - status - n? ->
	s? <-    - switch - n? ->
		     - rra - 
*/

//------------------
/*
void	lst_smart_rotate(list **stacka, list **stackb, int total) {
	int	count;
	count = 0;
	while ((*stacka) != NULL) {
		//if (check_status(*stacka, total) == 0) {}
		//if (check_switch(*stacka, total) == 0) {}
		//else (switch, volta ao loop)
		while ((*stacka)->index != count) {
			if (next_index(*stacka, count) > (total / 2))
				(*stacka) = lst_rv((*stacka));
			else if (next_index(*stacka, count) <= (total / 2))
				(*stacka) = lst_r((*stacka));
		}
		if ((*stacka)->index == count) {
			lst_p(&(*stacka), &(*stackb)); //push a->b
			printf("pb\n");
			count++;
			total--;
		}
	}
	while ((*stackb) != NULL) {
		lst_p(&(*stackb), &(*stacka)); //push b->a
		printf("pa\n");
	}
}*/
//--------
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
