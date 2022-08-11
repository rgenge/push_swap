/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 07:44:23 by acosta-a          #+#    #+#             */
/*   Updated: 2022/08/10 21:51:32 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define ERROR 1
# define BUCKETS_100 5
# define BUCKETS_500 12

typedef struct s_stack
{
	int	*array_a;
	int	*array_b;
	int	size;
	int	size_b;
	int	move_count;
	int	max_a;
	int	min_a;
	int	bucket_size;
	int	check_double_ss;
	int	check_double_rr;
	int	check_double_rrr;
}	t_stack;

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ss(t_stack *stack);
void	rr(t_stack *stack);
void	rrr(t_stack *stack);
int		free_exit(char *message, t_stack *stack);
int		error_msg(char *message);
int		no_error_msg(t_stack *stack);
void	argument_check(t_stack *stack);
int		sorted_check(t_stack *stack);
int		*treat_arg(int argc, char **argv, t_stack *stack);
void	sort_small(t_stack *stack);
void	sort_small_3(t_stack *stack);
int		find_min_a(t_stack *stack, int min_a);
int		find_max_a(t_stack *stack, int max_a);
void	sort_array(t_stack *stack);
void	sort_array_2(t_stack *stack);
void	sort_array_3(t_stack *stack);
int		ft_atoi_checker(const char *s, t_stack *stack);

#endif
