//#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

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
		for (int i = 1; array[i]; i++) {
			//check errors for the integers
			array[i - 1] = f_atoi(av[i]);
			if (check_limit(array[i - 1]) == 0)
				return; //error message
		}
	}
}

/*int checkintmain(int ac, char **av) {
    if (ac >= 2) {
        for (int i = 1; av[i]; i++) {
			if (check_int(av[i]) == 0)
				return 0;
            else
                continue;
		}
    }
	printf("Test successfull\n");
}*/