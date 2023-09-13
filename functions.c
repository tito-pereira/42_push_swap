/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.
*/

//o comportamento de base das listas acho que vou fazer com listas

#include "push_swap.h"

//antes de poder fazer seja o que for com isto, preciso de inicializar as listas em si
//usar new node, push list
/*You have to write a program named push_swap that takes as an argument the stack
a formatted as a list of integers. The first argument should be at the top of the
stack (be careful about the order)
ou seja, tenho que adicionar ao contrario:
ultimo indice = primeiro node, e dp add back*/
//also, o que faco se a stack b ficar vazia? posso ter um node chamado "stop"
//ou que possua data void, ou todos possuem char * entre "none" e "end"
//porque se eu tiver uma lista vazia, nao consigo adicionar nada la
//em vez de list.next != NULL, faco list.status != "end"
//ao adicionar node, todos os list status sao "none"

// -------------------------------------
//sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
//ss : sa and sb at the same time.

void	lst_s(list *stack) {
	if (f_lstlen(stack) >= 2) {
		f_lst_swap_two(stack);
	}
}

void	lst_2s(list *sta, list *stb) {
	lst_s(sta);
	lst_s(stb);
}

/*pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.*/

//list add back
void	lst_p(list *sta, list *stb) {
	if (f_lstlen(sta) > 0) //ordem errada, organizar
		sta.next = stb;
}
//adicionar condicao, se puxar para uma lista vazia

//rb (rotate b): Shift up all elements of stack b by 1.
//The first element becomes the last one.
//rr : ra and rb at the same time.

void	lst_r(list *stack) {
	// nao preciso do controlo de argumentos
	//ou elseif (vazio ou 1)
	if (f_lstlen(lst) >= 2) {
		list	tmp;
		tmp = stack;
		while (tmp.status != "end") //ou tmp.next != nulo
			tmp = tmp.next;
		stack.next = tmp.next; //ou igual a NULL
		tmp.next = stack;
	}
	else
		return; //redundante, simboliza a lista vazia ou 1 elemento
}

void	lst_2r(list *sta, list *stb) {
	lst_r(sta);
	lst_r(stb);
}

//rrb (reverse rotate b): Shift down all elements of stack b by 1.
//The last element becomes the first one.
//rrr : rra and rrb at the same time.

void	lst_rv(list *stack) {
	if (f_lstlen(lst) >= 2) {
		ez;
		//ultimo node passa a primeiro
		//tambem nao devo precisar
	}
}

void	lst_2rv(list *sta, list *stb) {
	lst_rv(sta);
	lst_rv(stb);
}

//----------------------------------------------------------

/*
old:
void	f_s_ab(int *str) {
	int i;
	i = f_strlen(str);
	if (i >= 2)
		f_swap(&str[0], &str[1]);
	else
		return;
}

void	f_ss(int *s1, int *s2) {
	f_s_ab(s1);
	f_s_ab(s2);
}
void	f_r_ab(int *str) {
	if (f_strlen(str) < 2)
		return;
	int up, down = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		down = str[i];
		str[i] = up;
		up = down;
	}
	str[0] = up;
}

void	f_rr(int *s1, int *s2) {
	f_r_ab(s1);
	f_r_ab(s2);
}
void	f_rr_ab(int *str) {
	if (f_strlen(str) < 2)
		return;
	int up, down = 0;
	for (int i = (f_strlen(str) - 1); i >= 0; i--) {
		down = str[i];
		str[i] = up;
		up = down;
	}
	str[f_strlen(str) - 1] = up;
}

void	f_rrr(int *s1, int *s2) {
	f_rr_ab(s1);
	f_rr_ab(s2);
}
*/