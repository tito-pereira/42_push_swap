//#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int	check_int(char *str) {
	int i = 0;
	if (str[0] == '-')
		i++;
	else if (!(str[0] >= '0' && str[0] <= '9') && str[0] != '-') {
		write (2, "Error 1\n", 8);
		return 0;
	}
	if (str[i] == '\0') {
		write (2, "Error 1\n", 8);
		return 0;
	}
	while (str[i] >= '0' && str[i] <= '9' || str[i] != '\0') {
		if (!(str[i] >= '0' && str[i] <= '9')) {
			write (2, "Error 1\n", 8);
			return 0;
		}
		i++;
	}
	return 1;
}

long	f_atoi(char *str) {
	int sign = 1;
	long nmb = 0;
	int i = 0;
	while (str[i] == ' ' || str[i] == '\t') //faco os whitespaces?
		i++;
	if (str[i] == '-') {
		sign *= -1;
		i++;
	}
	while (str[i]) {
		nmb = (nmb * 10) + (str[i] - 48);
		i++;
	}
	if ()
		return NULL;
	return (sign * nmb);
}

int	check_limits(long i) {
	printf("current: %lu, max: %d, min: %d\n", i, INT_MAX, INT_MIN);
	if (i < INT_MIN || i > INT_MAX) {
		write (2, "Error 2\n", 8);
		return 0;
	}
	return 1;
}

int	check_dup(int *str) {
	for (int count = 0; str[count]; count++) {
		int check = str[count];
		int iterate = count;
		while (str[iterate]) {
			if (check == str[iterate]) {
				write (2, "Error 3\n", 8);
				return 0;
			}
			iterate++;
		}
	}
	return 1;
}

//------------------------------

int	main(int ac, char **av) {
	if (ac >= 2) {
		int	args;
		args = 0;
		for (int i = 1; av[i]; i++) {
			args++;
			if (check_int(av[i]) == 0)
				return 0;
		}
		printf("%d args\n", args);
		int	*array;
		array = malloc(args * sizeof(int));
		for (int i = 0; i < args; i++) {
			if (f_atoi(av[i + 1]) == NULL)
				return 0;
			array[i] = f_atoi(av[i + 1]);
			/*if (check_limits(array[i]) == NULL)
				return 0;*/
		}
		//printf("im out\n");
		if (check_dup(array) == 0)
			return 0;
	}
	else {
		printf("No arguments\n");
		return 0;
	}
	printf("Test successfull\n");
}

/*
vou tentar testar/preparar a primeira parte do programa, de tratamento de erros
e conversao em array de ints
*/

//e se eu meter o erro dos limites dentro do atoi?

//i = index, i = args - 1
//len - V
//av[0] - V
//erro 1 - V
//erro 2 - X
//erro 3 - X
//mudar mensagens de erro

//falta adicionar o terceiro erro-duplicados
//o ideal era fazer um loop triplo, mas o check dups tem q ser no fim de tudo
//loop duplo dois primeiros erros
//segundo loop para duplicados

//se necessario, posso converter o check_limits em (int) em vez de (int *)
/*
num so loop - check int, contar len
malloc
segundo loop - atoi, check limit
terceira fase - check dups
*/

/*
primeiro loop - contar args/len
malloc
segundo loop - check int, copy atoi, check limit
terceiro - check dups
*/ 

//e faco os algoritmos e listas numa central a parte talvez
//sera que consigo enviar o char **av como argumento? se sim, processo os erros a parte