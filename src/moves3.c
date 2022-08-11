/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 07:44:05 by acosta-a          #+#    #+#             */
/*   Updated: 2022/07/24 18:48:24 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_stack *stack)
{
	stack->check_double_ss = 1;
	sa(stack);
	sb(stack);
	stack->move_count++;
	ft_putstr_fd ("ss\n", 1);
}

void	rr(t_stack *stack)
{
	stack->check_double_rr = 1;
	ra(stack);
	rb(stack);
	stack->move_count++;
	ft_putstr_fd ("rr\n", 1);
}

void	rrr(t_stack *stack)
{
	stack->check_double_rrr = 1;
	rra(stack);
	rrb(stack);
	stack->move_count++;
	ft_putstr_fd ("rrr\n", 1);
}
