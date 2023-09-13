//#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

int	f_atoi(char *str) {
	int sign = 1;
	int nmb = 0;
	int i = 0;
	while (str[i] == ' ' || str == '\t') //faco os whitespaces?
		i++;
	if (str[i] == '-') {
		sign *= -1;
		i++
	}
	while (str[i]) {
		nmb = (nmb * 10) + (str[i] - 48);
		i++;
	}
	return (sign * nmb)
}

//------------------------------

int	check_int(char *str) {
	int i = 0;
	if (str[0] == '-')
		i++;
	else if (!(str[0] >= '0' && str[0] <= '9') && str[0] != '-') {
		write (2, "Error\n", 6);
		return 0;
	}
	if (str[i] == '\0') {
		write (2, "Error\n", 6);
		return 0;
	}
	while (str[i] >= '0' && str[i] <= '9' || str[i] != '\0') {
		if (!(str[i] >= '0' && str[i] <= '9')) {
			write (2, "Error\n", 6);
			return 0;
		}
		i++;
	}
	return 1;
}

int	check_limits(int *stack) {
	for (int i = 0; stack[i]; i++) {
		if (stack[i] < INT_MIN || stack[i] > INT_MAX) {
			write (2, "Error\n", 6);
			return 0;
		}
	}
	return 1;
}

int	check_dup(int *str) {
	for (int count = 0; str[count]; count++) {
		int check = str[count];
		int iterate = count;
		while (str[iterate]) {
			if (check == str[iterate]) {
				write (2, "Error\n", 6);
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
		int	len; //len vai ser usado para malloc(array)
		len = 0;
		//posso tentar juntar estes dois modulos, a iteracao e a mesma, e dou check a dois erros
		for (int i = 1; av[i]; i++) {
			len++;
			if (check_int(av[i]) == 0)
				return; //error message
		}
		int	*array;
		array = (int *)malloc(len * sizeof(int));
		for (int i = 1; array[i]; i++) { //nao pode ser loop, tenho que mandar o array todo la p dentro
			//check errors for the integers
			array[i - 1] = f_atoi(av[i]);
			if (check_limit(array[i - 1]) == 0)
				return; //error message
		}
		for (int i = 0; array)
		check_dup()
	}
}

/*
vou tentar testar/preparar a primeira parte do programa, de tratamento de erros
e conversao em array de ints
*/

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