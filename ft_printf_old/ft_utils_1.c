/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:55:42 by tibarbos          #+#    #+#             */
/*   Updated: 2023/05/15 15:50:10 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*-----------------------------------------------*/

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

/*-----------------------------------------------*/

int	ft_putstr_c(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
		c++;
	}
	return (c);
}

/*-----------------------------------------------*/

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

/*-----------------------------------------------*/

void	ft_putnbr_c(int n, int *c)
{
	if (n == -2147483648)
	{
		ft_putstr("-2");
		(*c) += 2;
		ft_putnbr_c(147483648, c);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		(*c)++;
		n *= -1;
		ft_putnbr_c(n, c);
	}
	else if (n > 9)
	{
		ft_putnbr_c((n / 10), c);
		ft_putnbr_c((n % 10), c);
	}
	else
	{
		ft_putchar(n + 48);
		(*c)++;
	}
}
