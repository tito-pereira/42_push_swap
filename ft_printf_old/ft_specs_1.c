/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specs_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:11:07 by tibarbos          #+#    #+#             */
/*   Updated: 2023/05/15 17:43:21 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_c_spec(va_list arg)
{
	int	tmp;

	tmp = va_arg(arg, int);
	ft_putchar((char)tmp);
	return (1);
}

/*
%c Prints a single character.
*/

/*-----------------------------------------------*/

int	ft_s_spec(va_list arg)
{
	char	*tmp;
	int		c;

	tmp = va_arg(arg, char *);
	if (tmp == NULL)
	{
		c = ft_putstr_c("(null)");
		return (c);
	}
	c = ft_putstr_c(tmp);
	return (c);
}

/*
%s Prints a string (as defined by the common C convention).
*/

/*-----------------------------------------------*/

int	ft_p_spec(va_list arg)
{
	void				*tmp;
	long unsigned int	i;
	int					c;

	c = 0;
	tmp = va_arg(arg, void *);
	i = (long unsigned int) tmp;
	if (tmp == NULL)
	{
		c = ft_putstr_c("(nil)");
		return (c);
	}
	ft_putstr("0x");
	ft_putphex_c(i, &c);
	return (c + 2);
}

/*
%p The void * pointer argument has to be printed in hexadecimal format.
*/

/*-----------------------------------------------*/

int	ft_d_spec(va_list arg)
{
	int	tmp;
	int	c;

	c = 0;
	tmp = va_arg(arg, int);
	ft_putnbr_c(tmp, &c);
	return (c);
}

/*
%d Prints a decimal (base 10) number.
*/

/*-----------------------------------------------*/

int	ft_i_spec(va_list arg)
{
	int	tmp;
	int	c;

	c = 0;
	tmp = va_arg(arg, int);
	ft_putnbr_c(tmp, &c);
	return (c);
}

/*
%i Prints an integer in base 10.
*/
