/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:33:36 by acalvo4           #+#    #+#             */
/*   Updated: 2022/06/22 13:40:22 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		i;
	int		len;
	int		c;

	i = 0;
	len = 0;
	va_start(argptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += print_type(argptr, str[i + 1]);
			i++;
		}
		else
		{
			c = str[i];
			ft_putchar(c);
			len++;
		}
		i++;
	}
	va_end(argptr);
	return (len);
}
