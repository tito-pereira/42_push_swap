#include "push_swap.h"

int	next_index(list *stacka, int count) {
	int	i = 0;
	while (stacka->index != count) {
		stacka = stacka->next;
		i++;
	}
	return (i);
}

/*
void	lst_big_rotate(list **stacka, list **stackb, int total) {
	int	count;
	int	chest;
	count = 0;
	chest = 0;
	while (total > 0) {
		while (chest != 5 && total > 0) {
			next_index, calculo
			if == count;
				lst_p() //a->b
				count--
				total--
		}
		if (chest == 5 || total == 0) {
			lst_small_rotate((*stackb), (*stacka), chest, count);
			chest = 0;
		}
	}
}*/

/*
Calculos:

if b==null, push b
if b==1, push, swap ou rot
a partir dai fica organizado
if index>maxb, apenas push b
if index<minb, push b, rotate b

if middle
a cada push b, total_b++;
(next->index) > total/2
rotate cima ou baixo, push, (rotate de volta)
rodar p cima c previous index, ou rodar baixo c next index, dois calculos index
o que for mais pequeno, faz (eles vao andar juntos, vai dar ao mm)

while (stacka->index < stackb->index)
last_hook = stack->index
stackb = stackb->next;
moves++;

ver se moves estao na tabela superior ou inferior

check_b, e igual ao check_status mas descrescente
if check_b == 1, while stackb != NULL, push a

como reduzir as rotacoes de b? tentar introduzir ainda mais ao mm tempo
push b, last_hook = stacka->index

calcular: se o numero de rotacoes de volta > a proxima rotacao de stacka ate algum numero inferior ao last_hook
rotacao a (pelas metades da tabela)

a_total = total;
b_total = 0;
pushB, a_total--, b_total++

int *check_a_hook(list *stacka, int last_hook, int a_total) {
    int i;
    i = 0;
    while (stacka->index < last_hook) {
        stacka = stacka->next;
        i++;
    }
    return (i);
}

trazer o numero de rotacoes de b

check_a_hook > a_total / 2
tmp_check = a_total - check_a_hook (numero rra)
check_a_hook < a_total / 2
tmp_check = check_a_hook (numero ra)
if (tmp_check <= b_rots) {
    while (tmp_check > 0) {
        ra ou rra;
        tmp_check--;
    }
    last_hook = stacka->index;
    lst_pb();
    a_total--, b_total++;
}

calcular b_rots
iterar ate ao bmax
ver qual metade da tabela
b_rots (metade inferior), b_total - b_rots (metade superior)

criar estruturas para armazenar numeros
bmax;
bmin;
a_total;
b_total;
last_hook;
*/