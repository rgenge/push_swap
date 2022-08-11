/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 07:44:08 by acosta-a          #+#    #+#             */
/*   Updated: 2022/08/10 21:41:58 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi_checker(const char *s, t_stack *stack)
{
	int				i;
	int				sign;
	long long int	number;

	sign = 1;
	i = 0;
	number = 0;
	if (number == '0')
		return (0);
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign = -1;
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		number = number * 10 + (s[i] - '0');
		i++;
	}
	if (number != 0 && number <= 2147483647 && number >= -2147483648)
		return (number * sign);
	free(stack->array_a);
	free(stack->array_b);
	write(2, "Error\n", 7);
	exit(ERROR);
}

int	error_msg(char *message)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(ERROR);
}

int	no_error_msg(t_stack *stack)
{
	if (stack->array_a[0])
	{
		free(stack->array_a);
		free(stack->array_b);
	}
	exit(0);
}

void	stack_init(t_stack *stack)
{
	stack->size = 0;
	stack->size_b = 0;
	stack->move_count = 0;
	stack->check_double_ss = 0;
	stack->check_double_rr = 0;
	stack->check_double_rrr = 0;
	stack->bucket_size = 0;
	stack->max_a = -2147483648;
	stack->min_a = 2147483647;
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack_init(&stack);
	if (argc < 2)
		no_error_msg(&stack);
	treat_arg(argc, argv, &stack);
	if (argc <= 6)
		sort_small(&stack);
	else
		sort_array(&stack);
	free(stack.array_a);
	free(stack.array_b);
	return (0);
}
