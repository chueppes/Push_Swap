/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:31:23 by acalvo4           #+#    #+#             */
/*   Updated: 2022/06/22 13:58:47 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_len(unsigned int dec)
{
	int	len;

	len = 0;
	while (dec != 0)
	{
		len++;
		dec = dec / 16;
	}
	return (len);
}

void	ft_hexa(unsigned int dec, char type)
{
	char	*base;

	base = NULL;
	if (type == 'X')
		base = "0123456789ABCDEF";
	else if (type == 'x')
		base = "0123456789abcdef";
	if (dec >= 16)
	{
		ft_hexa(dec / 16, type);
		ft_hexa(dec % 16, type);
	}
	else
		ft_putchar(base[dec]);
}

int	ft_check_hexa(unsigned int n, char type)
{
	int	len;

	len = 0;
	if (!n)
		return (write(1, "0", 1));
	if (n)
	{
		ft_hexa(n, type);
		len += ft_hexa_len(n);
	}
	return (len);
}
