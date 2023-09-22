/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:39:45 by tibarbos          #+#    #+#             */
/*   Updated: 2023/09/14 10:39:52 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	f_atoi(char *str)
{
	int		sign;
	int		i;
	long	nmb;

	sign = 1;
	nmb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i])
	{
		nmb = (nmb * 10) + (str[i] - 48);
		i++;
	}
	return (sign * nmb);
}

// erros:
// a - algum dos argumentos não ser integer (char *)
// b - argumentos (integers) excederem os limites de integer (int *)
// c - haver argumentos (integers) duplicados (int *)

//erro a: verificar que todos os argumentos sao integers
int	check_int(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	else if (!(str[0] >= '0' && str[0] <= '9') && str[0] != '-')
	{
		write (2, "Error\n", 6);
		return (0);
	}
	if (str[i] == '\0')
	{
		write (2, "Error\n", 6);
		return (0);
	}
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write (2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
//while (str[i] >= '0' && str[i] <= '9') && str != \0
//este while ta mal feito "-letra", "3434letra"

//erro b: verificar que nenhum integer passa dos limites de integer
int	check_limits(char *arg)
{
	long	i;

	i = f_atoi(arg);
	if (i < INT_MIN || i > INT_MAX)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	return (1);
}

//erro c: haver parametros/inteiros duplicados
int	check_dup(int *array)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	while (array[i])
	{
		check = array[i];
		while (array[j])
		{
			if ((check == array[j]) && (i != j))
			{
				write (2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
//que erro vai para aqui