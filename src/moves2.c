/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 07:44:05 by acosta-a          #+#    #+#             */
/*   Updated: 2022/07/24 19:08:29 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_stack *stack)
{
	int	temp;

	temp = stack->array_b[stack->size_b - 1];
	stack->array_b[stack->size_b - 1] = stack->array_b[(stack->size_b) - 2];
	stack->array_b[(stack->size_b) - 2] = temp;
	stack->move_count++;
	if (stack->check_double_ss == 0)
		ft_putstr_fd ("sb\n", 1);
	stack->check_double_ss = 0;
}

void	rb(t_stack *stack)
{
	int	temp;
	int	temp2;
	int	temp3;
	int	i;

	i = 1;
	temp = stack->array_b[stack->size_b - 1];
	temp3 = stack->array_b[i - 1];
	while (i < (stack->size_b - 1))
	{
		temp2 = stack->array_b[i];
		stack->array_b[i] = temp3;
		temp3 = stack->array_b[i + 1];
		stack->array_b[i + 1] = temp2;
		i += 2;
	}
	if (stack->size_b % 2 == 0)
		stack->array_b[i] = temp3;
	stack->array_b[0] = temp;
	stack->move_count++;
	if (stack->check_double_rr == 0)
		ft_putstr_fd ("rb\n", 1);
	stack->check_double_rr = 0;
}

void	rrb(t_stack *stack)
{
	int	temp;
	int	temp2;
	int	temp3;
	int	i;

	i = stack->size_b - 2;
	temp = stack->array_b[0];
	temp3 = stack->array_b[i + 1];
	while (i > 0)
	{
		temp2 = stack->array_b[i];
		stack->array_b[i] = temp3;
		temp3 = stack->array_b[i - 1];
		stack->array_b[i - 1] = temp2;
		i -= 2;
	}
	if (stack->size_b % 2 == 0)
		stack->array_b[i] = temp3;
	stack->array_b[stack->size_b - 1] = temp;
	stack->move_count++;
	if (stack->check_double_rrr == 0)
		ft_putstr_fd ("rrb\n", 1);
	stack->check_double_rrr = 0;
}

void	pa(t_stack *stack)
{
	stack->size++;
	stack->array_a[stack->size - 1] = stack->array_b[stack->size_b - 1];
	stack->array_b[stack->size_b - 1] = '\0';
	stack->size_b--;
	stack->move_count++;
	ft_putstr_fd ("pa\n", 1);
}
