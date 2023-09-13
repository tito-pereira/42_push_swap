#include "push_swap.h"

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

// erros:
// a - algum dos argumentos não ser integer (char *)
// b - argumentos (integers) excederem os limites de integer (int *)
// c - haver argumentos (integers) duplicados (int *)

//erro a: verificar que todos os argumentos sao integers
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
} //1 se for tudo int, 0 se houver erros, parece estar a passar nos testes

//erro b: verificar que nenhum integer passa dos limites de integer
int	check_limits(int *stack) {
	for (int i = 0; stack[i]; i++) {
		if (stack[i] < INT_MIN || stack[i] > INT_MAX) {
			write (2, "Error\n", 6);
			return 0;
		}
	}
	return 1;
} //1 se estiver tudo dentro dos limites, 0 se passar dos limites
//nao sei ate que ponto esta função é necessária, se passasse dos limites ja tinha dado erro antes ou no atoi

//erro c: haver parametros/inteiros duplicados
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
} // 0 caso haja dups, 1 caso nao haja
// duplo loop
// max-min, iterar 1 a 1, 
// sort, iterar 1 a 1, ver se existe algum str[i] == str[i - 1]
// posso fazer só até metade, se nao houver dups ate iterar metade, nao vai haver na outra metade

/*
//funcao central vai receber a stack e realizar todos os testes de erro em subfuncoes
int	error_central(int *stack) {
	int	a, b, c = 0;
	a = check_int(stack);
	b = ;
	c = check_dup(stack);
	if (a == 0 || b == 0 || c == 0) {
		printf("custom error message\n");
		// ou write (2, ...), no stderror;
		return 0;
	}
	else
		return 1;
}
//write (2, "Error\n", 6);
*/

//faco as mensagens de erro nestas funcoes, ou a parte?
/*In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.*/