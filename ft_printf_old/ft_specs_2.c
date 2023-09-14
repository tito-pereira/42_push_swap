/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specs_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:43:30 by tibarbos          #+#    #+#             */
/*   Updated: 2023/05/15 17:52:51 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u_spec(va_list arg)
{
	unsigned int	tmp;
	int				c;

	c = 0;
	tmp = va_arg(arg, unsigned int);
	ft_put_uns_nbr(tmp, &c);
	return (c);
}

/*
%u Prints an unsigned decimal (base 10) number.
*/

/*-----------------------------------------------*/

int	ft_x_spec(va_list arg)
{
	unsigned int	tmp;
	int				c;

	c = 0;
	tmp = va_arg(arg, unsigned int);
	ft_puthex_c(tmp, &c);
	return (c);
}

/*
%x Prints a number in hexadecimal (base 16) lowercase format.
*/

/*-----------------------------------------------*/

int	ft_bx_spec(va_list arg)
{
	unsigned int	tmp;
	int				c;

	c = 0;
	tmp = va_arg(arg, unsigned int);
	ft_putbhex_c(tmp, &c);
	return (c);
}

/*
%X Prints a number in hexadecimal (base 16) uppercase format.
*/
