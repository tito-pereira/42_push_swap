/*
teste de algoritmo de sorting principal do array e criacao do sorted
ou apenas total, max e min, wtv
mas sorted da mais jeito

- bubble sort (check)
- indexing (check)
- criar uma struct onde ficam as arrays e o total, é mais facil assim para movimentar mais informaçao
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

//---------BUBBLE SORT (facil de fazer)--------------s

//eu posso trocar qualquer posição, aproveitar isso
/*
como fazer o algoritmo recursivamente? qual a condição de paragem?
acho que condicao de paragem pode ser dar sort continuo sem haver i > i + 1
neste caso tmb tenho o total
*/
void	f_swap(int *a, int *b) {
	int	tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
} //f_swap(&array[i], &array[i + 1]);

int	*f_arrdup(int *array, int total) {
	int	*new;
	new = malloc(total * sizeof(int));
	for (int i = 0; i < total; i++)
		new[i] = array[i];
	return (new);
}

int	*bubble_sort(int *array, int total) {
	int	i, tmp;
	int	*new;
	i = 0;
	new = f_arrdup(array, total);
	while (i < (total - 1)) {
		if (new[i] > new[i + 1]) {
			tmp = new[i];
			new[i] = new[i + 1];
			new[i + 1] = tmp;
			i = -1;
		}
		if (i == (total - 1))
			break;
		i++;
	}
	return (new);
}

int	*put_index(int *array, int *sorted, int total) {
	int j;
	int	*index;
	index = malloc(total * sizeof(int));
	for (int i = 0; i < total; i++) {
		j = 0;
		while (array[j] != sorted[i])
			j++;
		printf("j:%d, array[j]:%d, i:%d, sorted[i]:%d\n", j, array[j], i, sorted[i]);
		index[j] = i;
		printf("new:%d\n", index[j]);
	}
	return (index);
}


//--------------MAIN----------------

int	main(int ac, char **av) {
	//printf("%d\n", 0);
	if (ac >= 2) {
		int	args;
		args = 0;
		for (int i = 1; av[i]; i++) {
			args++;
			if (check_int(av[i]) == 0)
				return 0;
		}
		printf("%d args:\n", args);
		int	*array;
		array = malloc(args * sizeof(int));
		for (int i = 0; i < args; i++) {
			if (check_limits(av[i + 1]) == 0)
				return 0;
			array[i] = f_atoi(av[i + 1]);
		}
		if (check_dup(array) == 0)
			return 0;
		for (int i = 0; i < args; i++)
			printf("%d, ", array[i]);
		//ate aqui resulta, agr meter o sorting
		int	*sorted;
		printf("\nbubble sort\n");
		sorted = bubble_sort(array, args); //acho que ja esta a dar
		for (int i = 0; i < args; i++)
			printf("%d, ", sorted[i]);
		printf("\nold array\n");
		for (int i = 0; i < args; i++)
			printf("%d, ", array[i]); //por alguma razao esta a alterar o old array
		printf("\nindexing\n");
		sorted = put_index(array, sorted, args);
		for (int i = 0; i < args; i++)
			printf("%d, ", sorted[i]);
	}
	else {
		printf("No arguments\n");
		return 0;
	}
	printf("\nTest successfull\n");
}

/*
index ta a dar 0, 1, 2, 3, 4
tou a atribuir diretamente c a iteração
aquele problema estranho do index tinha a ver com o facto de que eu estava a alterar o array
e estragava tudo
agora acho que está a funcionar
*/