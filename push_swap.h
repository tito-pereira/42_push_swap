#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h> //nao posso usar, apenas o meu proprio printf
# include <stdlib.h> //malloc, talvez
# include <limits.h> //talvez, para os erros
# include <unistd.h> //para as mensagens de erro

typedef	struct	stuff {
	int	data;
	int	index;
	struct stuff	*next;
}	list;

//criar uma struct para armazenar os dois arrays (stack e sorted) porque posso precisar deles no algoritmo?
/*
typedef	struct	things {
	int	*array;
	int	*sorted;
	struct	things	*next;
}	le_ints;
*/


//auxiliary
int	f_strlen(int *str);
int	f_lstlen(list *lst);
void	f_swap(int *a, int *b); //usar libft talvez
void	f_lst_swap_two(list *fst);
int	*array_dup(int *array);
//stack functions
void	lst_s(list *stack);
void	lst_2s(list *sta, list *stb);
void	lst_p(list *sta, list *stb);
void	lst_r(list *stack);
void	lst_2r(list *sta, list *stb);
void	lst_rv(list *stack);
void	lst_2rv(list *sta, list *stb);

#endif
