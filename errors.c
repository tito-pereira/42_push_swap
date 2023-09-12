#include "push_swap.h"

//a error central recebe ja como stack, como string, ou array de ints?

// erros:
// a - algum dos argumentos não ser integer (char *)
// b - argumentos (integers) excederem os limites de integer (int *)
// c - haver argumentos (integers) duplicados (int *)

//erro a: verificar que todos os argumentos sao integers
int	check_int(char *str) {
	int i = 0;
	if (str[0] == '-')
		i++;
	else if (!(str[0] >= '0' || str[0] <= '9') && str[0] != '-')
		return 0;
	while (str[i] >= '0' || str[i] <= '9' || str[i] != '\0') {
		i++;
		if (!(str[i] >= '0' || str[i] <= '9'))
			return 0;
		else if (str[i] >= '0' || str[i] <= '9')
			continue;
	}
	return 1;
}

//erro b: verificar que nenhum integer passa dos limites de integer
int	check_limits(int *stack) {
	for (int i = 0; stack[i]; i++) {
		if (stack[i] < LOW_LIMIT || stack[i] > UP_LIMIT) //ja nao me lembro da designação
			return 0;
	}
	return 1;
}
//nao sei ate que ponto esta função é necessária, se passasse dos limites ja tinha dado erro antes ou no atoi

int	f_atoi(char *str) {
	int sign = 1;
	int nmb = 0;
	int i = 0;
	if (str[0] == '-') {
		sign *= -1;
		i++
	}
	while (str[i]) {
		nmb = (nmb * 10) + (str[i] - 48);
		i++;
	}
	return (sign * nmb)
}

//erro 3: haver duplicados

int	check_dup(int *stack) {
	ez;
}

int	check_check(int *str) {
	for (int i = 0; str[i]; i++) {
		int tmp = str[i];
		int j = i;
		while (str[j]) {
			if (tmp == str[j])
				return 0;
			j++;
		}
	}
	return 1;
}

// duplo loop
// max-min, iterar 1 a 1, 
// sort, iterar 1 a 1, ver se existe algum str[i] == str[i - 1]
// posso fazer só até metade, se nao houver dups ate iterar metade, nao vai haver na outra metade

//testar coisas
void	putchar(char c) {
	write (1, &c, 1);
}

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