/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:34:27 by acalvo4           #+#    #+#             */
/*   Updated: 2022/06/22 14:20:31 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
int		print_type(va_list argptr, char type);
int		ft_hexa_len(unsigned int dec);
void	ft_hexa(unsigned int dec, char type);
int		ft_check_hexa(unsigned int n, char type);
int		ft_ptr_len(unsigned long dec);
void	ft_hexa_ptr(unsigned long dec, char type);
int		ft_check_ptr(unsigned long n, char type);
size_t	measure_to_str(int n);
char	*ft_utoa(unsigned int n);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_nbr_u(unsigned int number);
int		ft_itoa_count(int n);
size_t	measure_unsigned(unsigned int n);

#endif