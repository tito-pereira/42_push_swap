/*
colocar header
*/

#include "push_swap.h"

//array sorting with bubble sort
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
		index[j] = i;
	}
	return (index);
}