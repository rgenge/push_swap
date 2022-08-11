/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 07:44:11 by acosta-a          #+#    #+#             */
/*   Updated: 2022/07/24 18:49:04 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack)
{
	int	temp;

	temp = stack->array_a[stack->size - 1];
	stack->array_a[stack->size - 1] = stack->array_a[(stack->size) - 2];
	stack->array_a[(stack->size) - 2] = temp;
	stack->move_count++;
	if (stack->check_double_ss == 0)
		ft_putstr_fd ("sa\n", 1);
}

void	ra(t_stack *stack)
{
	int	temp;
	int	temp2;
	int	temp3;
	int	i;

	i = 1;
	temp = stack->array_a[stack->size - 1];
	temp3 = stack->array_a[i - 1];
	while (i < (stack->size - 1))
	{
		temp2 = stack->array_a[i];
		stack->array_a[i] = temp3;
		temp3 = stack->array_a[i + 1];
		stack->array_a[i + 1] = temp2;
		i += 2;
	}
	if (stack->size % 2 == 0)
		stack->array_a[i] = temp3;
	stack->array_a[0] = temp;
	stack->move_count++;
	if (stack->check_double_rr == 0)
		ft_putstr_fd ("ra\n", 1);
}

void	rra(t_stack *stack)
{
	int	temp;
	int	temp2;
	int	temp3;
	int	i;

	i = stack->size - 2;
	temp = stack->array_a[0];
	temp3 = stack->array_a[i + 1];
	while (i > 0)
	{
		temp2 = stack->array_a[i];
		stack->array_a[i] = temp3;
		temp3 = stack->array_a[i - 1];
		stack->array_a[i - 1] = temp2;
		i -= 2;
	}
	if (stack->size % 2 == 0)
		stack->array_a[i] = temp3;
	stack->array_a[stack->size - 1] = temp;
	stack->move_count++;
	if (stack->check_double_rrr == 0)
		ft_putstr_fd ("rra\n", 1);
}

void	pb(t_stack *stack)
{
	stack->size_b++;
	stack->array_b[stack->size_b - 1] = stack->array_a[stack->size - 1];
	stack->array_a[stack->size - 1] = '\0';
	stack->size--;
	stack->move_count++;
	ft_putstr_fd ("pb\n", 1);
}
