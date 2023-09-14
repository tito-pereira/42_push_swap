/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:58:36 by tibarbos          #+#    #+#             */
/*   Updated: 2023/05/16 10:48:59 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	see_if_spec(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == '%'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

int	ft_treat_spec(va_list arg, char c)
{
	int	r;

	r = 1;
	if (c == 'c')
		r = ft_c_spec(arg);
	else if (c == 's')
		r = ft_s_spec(arg);
	else if (c == 'p')
		r = ft_p_spec(arg);
	else if (c == 'd')
		r = ft_d_spec(arg);
	else if (c == 'i')
		r = ft_i_spec(arg);
	else if (c == 'u')
		r = ft_u_spec(arg);
	else if (c == 'x')
		r = ft_x_spec(arg);
	else if (c == 'X')
		r = ft_bx_spec(arg);
	else if (c == '%')
		ft_putchar('%');
	return (r);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		c;

	va_start(args, s);
	i = -1;
	c = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (see_if_spec(s[i]) == 1)
				c = c + ft_treat_spec(args, s[i]);
		}
		else
		{
			ft_putchar(s[i]);
			c++;
		}
	}
	va_end(args);
	return (c);
}

/*else if (s[i] == '\0')
{
ft_putchar('%');
c++;
break;
}*/

/*int	main()
{
	char	s[] = "string";
	int i = 42;
	char	c = 'c';
	ft_printf("so let's test my chars: %c,%c;\n", c, c);
	ft_printf("and my double string: %s,%s;\n", s, s);
	ft_printf("ok it's working, and now my int: %d\ngood, good\n", i);
	ft_printf("");
	ft_printf(s);
	ft_printf("\n%c%s%d%c%s%d\n", c, s, i, c, s, i);
	ft_printf("--------------------\n");
	int a = ft_printf("%s;\n", s);
	ft_printf("len: %d\n", a);
	a = ft_printf("number: %d%d;\n", 12345, 12345);
	ft_printf("len: %d\n", a);
}*/

/*int	main()
{
	int	c = 0xb;
	ft_printf("c: %d;\n", c);
}*/
