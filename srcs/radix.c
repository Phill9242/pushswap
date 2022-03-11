/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 06:13:11 by phiolive          #+#    #+#             */
/*   Updated: 2022/03/10 06:57:02 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_radix_sort(int *stack_a, int *stack_b, int numbers)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (!ft_its_ordered(stack_a, numbers))
	{
		j = 0;
		while (j < numbers)
		{
			n = stack_a[0];
			if ((n >> i) & 1)
				ft_rotate(stack_a, 'a');
			else
				ft_push (stack_b, stack_a, 'b');
			j++;
		}
		while (!ft_its_empty(stack_b))
			ft_push(stack_a, stack_b, 'a');
		i++;
	}
}
