#include "push_swap.h"

// questao: quando os args sao passados, vêm automaticamente como char* certo? devido à funcao (int argc, char **argv) (R: sim)
// se sim, devemos fazer atoi delas acho eu. é mais fácil dar sort com ints

//em bulk: (char *)->(atoi)->(int *)->(push stack)->(list)
//os erros verificar em passos intermedios

//testar as funcoes com arrays
/*int	main(void) {
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
}*/

/*int	push_main(int ac, char **av) {
	//parametros >= 2, para garantir pelo menos um parametro para alem do titulo
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
		return;
	return 0;
}*/
//alterar a main para dar push para dentro de uma stack

int	push_2_main(int ac, char **av) {
	if (ac >= 2) {
		int	len;
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
		//dar sort ao array e retornar a ordem
		int	*sorted;
		sorted = array_algo(array);
		// adicionar array ao contrario na stack A
		list	*stacka;
		list	*stackb;
		for (int i = len; array[i]; i--) {
			add_stack(stacka, array[i]);
		}
		// enviar a stack para rodar e push
		//algo_central(stacka, stackb/*int *array*/);
		list_algo(stacka, stackb);
	}
	else
		return; //give prompt back
}

/*
No args:
If no parameters are specified, the program must not display anything and give the
prompt back.
-> empty return()
*/