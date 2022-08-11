/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 02:49:20 by acosta-a          #+#    #+#             */
/*   Updated: 2022/08/08 10:29:03 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_checker(const char *s)
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
	write(2, "Error\n", 7);
	exit(0);
}
