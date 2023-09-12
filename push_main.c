#include "push_swap.h"

// questao: quando os args sao passados, vêm automaticamente como char* certo? devido à funcao (int argc, char **argv)
// se sim, devemos fazer atoi delas acho eu. é mais fácil dar sort com ints
// sim, os argumentos vêm como chars

//functions test main
void	p_int(int *str, int size) {
	//int size = sizeof(str) / sizeof(str[0]);
	printf("size: %d\n", size);
	//printf("size1: %ld\n", sizeof(str));
	//printf("size2: %ld\n", sizeof(str[0]));
	for (int i = 0; i < size; i++) {
		printf("%d, ", str[i]);
	}
	/*printf("\n-----\n");
	for (int i = 0; str[i]; i++) {
		printf("%d, ", str[i]);
	}*/
	printf("\n");
}

int	main(void) {
	int str[] = {23, 65, 83, 12, 3, 60, 0};
	int size = sizeof(str) / sizeof(int);
	printf("original string: ");
	p_int(str, size);
	printf("-----switch up-----\n");
	f_s_ab(str);
	p_int(str, size);
	printf("-----rotate down-----\n");
	f_r_ab(str);
	p_int(str, size);
	printf("-----rotate up-----\n");
	f_rr_ab(str);
	p_int(str, size);
}

int	push_main(int ac, char **av) {
	if (ac >= 2) {
		int	counter = 0;
		for (int i = 1; av[i]; i++)
			counter++;
		char	*str; //os parametros do programa sao recebidos como chars, criar string temporaria
		int	*stack; //criar já stack de ints vazia c o tamanho correto
		str = (char *)malloc(counter * sizeof(char)); //string temporaria q vai ser processada pelo atoi
		stack = (int *)malloc(counter * sizeof(int)); //stack final, c tamanho correto, passada pelo atoi
		for (int i = 1; av[i]; i++) {
			stack[i] = f_atoi(str[i]); //faz atoi da str para a stack
		}
		if (error_central(stack) == 0)
			printf("error messages and shut\n");
		else {
			printf("continue to algorithm");
			algorithm_central(stack);
		}
	}
	else
		printf("no args error message\n");
	return 0;
}
