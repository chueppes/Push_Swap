/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:57:40 by acalvo4           #+#    #+#             */
/*   Updated: 2022/10/11 21:57:44 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	size;
	int	index;
	int	*aux_array;
}		t_stack;

int		build_stack(int argc, char **argv, t_stack *stack);
t_stack	*initialize_stack(int size);
int		*bubble_sort(int n, char **argv);
int		*get_values(int *array, int argc, char **argv);
int		ft_puterror(void);
void	validate_values(char *argv, int argc);
int		check_duplicates(int *array_a, int argc);
int		is_it_ordered(int argc, int *array);
int		is_my_stack_sorted(t_stack *stack);

void	swap(t_stack *stack);
void	test(int argc, t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push(t_stack *take, t_stack *put);
void	small_sort(t_stack *stack_a);
void	medium_sort(t_stack *stack_a, t_stack *stack_b);
void	big_sort(t_stack *stack_a, t_stack *stack_b);

void	ss(t_stack *stack_a, t_stack *stack_b);
void	sb(t_stack *stack_b);
void	sa(t_stack *stack_a);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

int		is_it_empty(t_stack *stack);
int		is_it_full(t_stack *stack);

void	sort(t_stack *stack_a, t_stack *stack_b);

long	ft_atoi_mod(const char *str);
void	free_array(int *array, int *right_array);

#endif