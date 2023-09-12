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

//crio uma tmp list para iterar?
// vou precisar do swap para os outros moves também
//data1 = lst.data; lst = lst.next; data2 = lst.data
//a iteraçao ja sei fazer
//aquele empurrar os numeros p frente é igual; iteraçao de listas + os 2 int temporarios a mudar a data c o mesmo algo

// -------------------------------------
//sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
//ss : sa and sb at the same time.

void	lst_s(list *stack) {
	if (f_lstlen(lst) >= 2) {
		f_lstswap(lst);
	}
}

void	lst_2s(list *sta, list *stb) {
	lst_s(l1);
	lst_s(l2);
}

/*pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.*/

void	lst_p(list *stack) {
	ez;
}

void	lst_2p(list *sta, list *stb) {
	if (f_strlen(sb) == 0)
		return;
	int i = f_strlen(sb) - 1;
	ez;
}

//rb (rotate b): Shift up all elements of stack b by 1.
//The first element becomes the last one.
//rr : ra and rb at the same time.

void	f_lst_r(list *stack) {
	if (f_lstlen(lst) >= 2) {
		ez;
		//how??? nao consigo iterar listas ao contrário???
		//nao iteras, apenas mudas o pointer
		//primeiro node passa a ultimo
	}
}

void	f_lst_rr(list *sta, list *stb) {
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