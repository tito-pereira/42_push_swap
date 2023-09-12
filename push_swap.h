#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h> //nao posso usar, apenas o meu proprio printf
# include <stdlib.h> //malloc, talvez
# include <limits.h> //talvez, para os erros

typedef	struct	stuff {
	int	data;
	struct stuff	*next;
}	list;

//auxiliary
int	f_strlen(int *str);
int	f_lstlen(list *lst);
void	f_swap(int *a, int *b); //usar libft talvez
void	f_lst_swap_two(list *fst);
//stack functions
void	lst_s(list *stack);
void	lst_2s(list *sta, list *stb);
void	lst_p(list *stack);
void	lst_2p(list *sta, list *stb);
void	lst_r(list *stack);
void	lst_2r(list *sta, list *stb);
void	lst_rv(list *stack);
void	lst_2rv(list *sta, list *stb);

#endif
