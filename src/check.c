/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 07:44:05 by acosta-a          #+#    #+#             */
/*   Updated: 2022/08/13 20:29:22 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	free_exit(char *message, t_stack *stack)
{
	free(stack->array_a);
	free(stack->array_b);
	ft_putstr_fd (message, 2);
	ft_putstr_fd ("\n", 2);
	exit(0);
}

void	number_check(char **argv, int i, t_stack *stack)
{
	int		k;

	k = 0;
	if (argv[i][0] == '-' || argv[i][0] == '+')
		k++;
	while (argv[i][k])
	{
		if (!ft_isdigit(argv[i][k]))
			free_exit("Error", stack);
		k++;
	}
}

void	argument_check(t_stack *stack)
{
	int		i;
	int		j;

	i = 0;
	while (i < (stack->size - 1))
	{
		j = i + 1;
		while (stack->array_a[j])
		{
			if (stack->array_a[i] == stack->array_a[j])
				free_exit("Error", stack);
			j++;
		}
		i++;
	}
	if (stack->null_check > 1)
		free_exit("Error", stack);
}

int	sorted_check(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < (stack->size - 1))
	{
		if (stack->array_a[i] >= stack->array_a[i + 1])
			i++;
		else
			return (0);
	}
	if (i == (stack->size - 1))
		no_error_msg(stack);
	return (0);
}

int	*treat_arg(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		j;

	j = 0;
	i = argc - 1;
	stack->array_a = ft_calloc((argc + 1), sizeof(int));
	stack->array_b = ft_calloc((argc + 1), sizeof(int));
	while (i > 0)
	{
		number_check(argv, i, stack);
		if (*argv[i] == '0')
		{
			stack->array_a[j] = 0;
			stack->null_check++;
		}
		else
			stack->array_a[j] = ft_atoi_checker(argv[i], stack);
		stack->size++;
		i--;
		j++;
	}
	argument_check(stack);
	sorted_check(stack);
	return (0);
}
