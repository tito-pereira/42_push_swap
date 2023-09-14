/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:53:47 by tibarbos          #+#    #+#             */
/*   Updated: 2023/05/15 17:52:58 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h> /*talvez tirar porque nao uso mallocs*/
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
/*-------*/ /*utils 1*/
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_putstr_c(char *str);
void	ft_putchar(char c);
void	ft_putnbr_c(int n, int *c);
/*-------*/ /*utils 2*/
void	ft_put_uns_nbr(unsigned int n, int *c);
char	check_letter_p(long unsigned int i);
void	ft_putphex_c(long unsigned int n, int *c);
/*-------*/ /*hexadecimal*/
char	check_letter_x(unsigned int i);
void	ft_puthex_c(unsigned int n, int *c);
char	check_letter_bx(unsigned int i);
void	ft_putbhex_c(unsigned int n, int *c);
/*-------*/ /*specs 1*/
int		ft_c_spec(va_list arg);
int		ft_s_spec(va_list arg);
int		ft_p_spec(va_list arg);
int		ft_d_spec(va_list arg);
int		ft_i_spec(va_list arg);
/*-------*/ /*specs 2*/
int		ft_u_spec(va_list arg);
int		ft_x_spec(va_list arg);
int		ft_bx_spec(va_list arg);

#endif
