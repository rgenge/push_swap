/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 07:44:05 by acosta-a          #+#    #+#             */
/*   Updated: 2022/07/24 19:01:53 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max_a(t_stack *stack, int max_a)
{
	int	i;

	i = -1;
	max_a = -2147483648;
	while (i++ < stack->size - 1)
	{
		if (stack->array_a[i] > max_a)
			max_a = stack->array_a[i];
	}
	return (max_a);
}

int	find_min_a(t_stack *stack, int min_a)
{
	int	i;

	i = -1;
	min_a = 2147483647;
	while (i++ < stack->size - 1)
	{
		if (stack->array_a[i] < min_a)
			min_a = stack->array_a[i];
	}
	return (min_a);
}

void	sort_small_3(t_stack *stack)
{
	if (stack->size == 2)
		if (stack->array_a[1] > stack->array_a[0])
			sa(stack);
	if ((stack->array_a[2] < stack->array_a[0] && stack->array_a[1]
			< stack->array_a[2]) || (stack->array_a[1] < stack->array_a[2]
			&& stack->array_a[0] < stack->array_a[1]) || (stack->array_a[0]
			< stack->array_a[1] && stack->array_a[2] < stack->array_a
			[0]))
		sa(stack);
	if ((stack->array_a[0] < stack->array_a[2] && stack->array_a[1]
			<stack->array_a[0]))
		ra(stack);
	if ((stack->array_a[2] < stack->array_a[1] && stack->array_a[0]
			< stack->array_a[2]))
		rra(stack);
	if (stack->array_a[1] > stack->array_a[0])
		sa(stack);
	while (stack->size_b > 0)
	{
		pa(stack);
		while (stack->array_a[stack->size - 1] > stack->array_a[stack->size
				- 2])
			ra(stack);
	}
}

void	sort_small(t_stack *stack)
{
	int	max;
	int	min;
	int	i;

	i = 0;
	max = 0;
	min = 0;
	max = find_max_a(stack, max);
	min = find_min_a(stack, min);
	if (stack->size == 2)
		if (stack->array_a[1] > stack->array_a[0])
			sa(stack);
	if (stack->size >= 3 && stack->size <= 5)
	{
		if (stack->size == 5 || stack->size == 4)
		{
			while (i++ < 5)
				if (stack->array_a[stack->size - 1] == min || stack->array_a
					[stack->size - 1] == max)
					pb(stack);
			else
				ra(stack);
		}
		sort_small_3(stack);
	}
}
