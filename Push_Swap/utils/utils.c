/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:58:07 by acalvo4           #+#    #+#             */
/*   Updated: 2022/10/11 21:58:07 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_puterror(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
	return (1);
}

static void	ft_swap(int *x, int *y)
{
	int	aux;

	aux = *x;
	*x = *y;
	*y = aux;
}

int	*bubble_sort(int n, char **argv)
{
	int	i;
	int	j;
	int	*sorted_array;

	sorted_array = NULL;
	i = 0;
	sorted_array = get_values(sorted_array, n, argv);
	while (i < n)
	{
		j = 0;
		while (j < n - 1)
		{
			if (sorted_array[j] > sorted_array[j + 1])
			{
				ft_swap(&sorted_array[j], &sorted_array[j + 1]);
			}
			j++;
		}
		i++;
	}
	return (sorted_array);
}

long	ft_atoi_mod(const char *str)
{
	size_t	i;
	long	aux;
	int		j;

	aux = 0;
	i = 0;
	j = 1;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		aux = (aux * 10) + (str[i++] - '0');
	if (aux > INT_MAX || (aux * j) < INT_MIN)
		return (2147483648);
	return (aux * j);
}
