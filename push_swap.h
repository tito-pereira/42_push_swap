#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h> 
# include <stdarg.h>

/*
typedef	struct	int_array {
	int *str;
	int size = 5;
	//size = sizeof(str) / sizeof(int);
}	intarr;

typedef	struct	stuff {
	int	data;
	struct stuff	*next;
}	list;
*/

int	f_strlen(int *str);
void	f_swap(int *a, int *b);
void	f_s_ab(int *str);
void	f_ss(int *s1, int *s2);
void	f_r_ab(int *str);
void	f_rr(int *s1, int *s2);
void	f_rr_ab(int *str);
void	f_rrr(int *s1, int *s2);

#endif
