/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 07:44:05 by acosta-a          #+#    #+#             */
/*   Updated: 2022/08/12 23:37:42 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_array_min_max(t_stack *stack, int i)
{
	i = -1;
	while (i++ < stack->size - 1)
	{
		if (stack->array_a[i] > stack->max_a)
			stack->max_a = stack->array_a[i];
		if (stack->array_a[i] < stack->min_a)
			stack->min_a = stack->array_a[i];
	}
	if (stack->size <= 100)
		stack->bucket_size = (stack->max_a - stack->min_a) / BUCKETS_100;
	if (stack->size > 100)
		stack->bucket_size = (stack->max_a - stack->min_a) / BUCKETS_500;
}

void	sort_array(t_stack *stack)
{
	int			i;
	int			size_init;
	long int	j;

	j = 0;
	i = -1;
	size_init = stack->size;
	sort_array_min_max(stack, i);
	i = 0;
	j = stack->min_a + stack->bucket_size;
	while (j <= (stack->max_a + stack->bucket_size))
	{
		i = 0;
		while (i < size_init)
		{
			if (stack->array_a[stack->size - 1] <= j)
				pb(stack);
			if (stack->size > 0 && stack->array_a[stack->size - 1] > j)
				ra(stack);
			i++;
		}
		size_init = stack->size;
		j += stack->bucket_size;
	}
	sort_array_2(stack);
}

int	find_max(t_stack *stack, int max_b)
{
	int	i;

	i = -1;
	max_b = -2147483648;
	while (i++ < stack->size_b - 1)
	{
		if (stack->array_b[i] > max_b)
			max_b = stack->array_b[i];
	}
	return (max_b);
}

void	sort_array_2(t_stack *stack)
{
	int	i;
	int	j;
	int	max_b;

	j = 0;
	max_b = 0;
	while (j < stack->size_b * 1000)
	{
		max_b = find_max(stack, max_b);
		if (stack->array_b[stack->size_b - 1] == max_b)
			pa(stack);
		i = 0;
		max_b = find_max(stack, max_b);
		while (i < stack->size_b)
		{
			if (stack->array_b[i] == max_b && i >= (stack->size_b / 2))
				while (stack->array_b[stack->size_b - 1] != max_b)
					rb(stack);
			else if (stack->array_b[i] == max_b && i < (stack->size_b / 2))
				while (stack->array_b[stack->size_b - 1] != max_b)
					rrb(stack);
			i++;
		}
		j++;
	}
}
