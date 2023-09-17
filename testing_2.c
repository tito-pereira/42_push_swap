/*
teste de algoritmo de sorting principal do array e criacao do sorted
ou apenas total, max e min, wtv
mas sorted da mais jeito

criar uma struct onde ficam as arrays e o total, é mais facil assim para movimentar mais informaçao
*/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

typedef	struct	bass {
	int	*array;
	int	*order;
	int	total;
}	le_ints;

//--------ERRORS-------------------

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
	return (sign * nmb);
}

int	check_limits(char *arg) {
	long	i;
	i = f_atoi(arg);
	if (i < INT_MIN || i > INT_MAX) {
		write (2, "Error 2\n", 8);
		return 0;
	}
	return 1;
}

int	check_dup(int *array) {
	for (int i = 0; array[i]; i++) {
		//printf("array[%d]\n", i);
		int check = array[i];
		//printf("element:%d;\n", array[i]);
		for (int j = 0; array[j]; j++) {
			//printf("compare[%d]\n", j);
			if ((check == array[j]) && (i != j)) {
				//printf("counter:%d;\n", array[j]);
				write (2, "Error 3\n", 8);
				return 0;
			}
		}
	}
	return 1;
}

//--------------MAIN----------------

int	main(int ac, char **av) {
	printf("%d\n", 0);
	if (ac >= 2) {
		int	args;
		args = 0;
		for (int i = 1; av[i]; i++) {
			args++;
			if (check_int(av[i]) == 0)
				return 0;
		}
		printf("%d args:\n", args); //here
		int	*array;
		array = malloc(args * sizeof(int));
		for (int i = 0; i < args; i++) {
			if (check_limits(av[i + 1]) == 0)
				return 0;
			array[i] = f_atoi(av[i + 1]);
		}
		for (int i = 0; array[i]; i++)
			printf("%d\n", array[i]);
		if (check_dup(array) == 0)
			return 0;
	}
	else {
		printf("No arguments\n");
		return 0;
	}
	printf("Test successfull\n");
}