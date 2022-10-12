/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:36:57 by acalvo4           #+#    #+#             */
/*   Updated: 2022/06/22 13:37:23 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	measure_unsigned(unsigned int n)
{
	size_t	n_len;

	n_len = 1;
	while (n >= 10)
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}

char	*ft_utoa(unsigned int n)
{
	size_t	n_len;
	char	*str;

	n_len = measure_unsigned(n);
	str = malloc(n_len + 1);
	if (!str)
		return (NULL);
	str[n_len] = '\0';
	if (n == 0)
		str[0] = '0';
	str[n_len--] = '\0';
	while (n)
	{
		str[n_len--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
