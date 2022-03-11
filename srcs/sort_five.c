/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:37:16 by phiolive          #+#    #+#             */
/*   Updated: 2022/03/11 01:29:16 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	ft_sort_3(int *stack_a)
{
	if (stack_a[1] == 2)
	{
		ft_swap (stack_a, 'a');
		ft_rev_rotate (stack_a, 'a');
	}
	else if (stack_a[0] == 3)
		ft_rotate(stack_a, 'a');
	else if (stack_a[2] == 3)
		ft_swap (stack_a, 'a');
	else if (stack_a[2] == 1)
		ft_rev_rotate (stack_a, 'a');
	else
	{
		ft_swap (stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	return ;
}

int	ft_size_three(int *stack_a)
{
	int	i;

	i = 0;
	while (stack_a[i])
		i++;
	if (i > 3)
		return (0);
	else
		return (1);
}

void	ft_sort_less(int *stack_a, int *stack_b, int max, int min)
{
	int	i;

	i = 0;
	while (!ft_size_three(stack_a))
	{
		if (stack_a[0] > 3)
			ft_push(stack_b, stack_a, 'b');
		else if (stack_a[max - 1] > 3)
		{
			ft_rev_rotate(stack_a, 'a');
			ft_push(stack_b, stack_a, 'b');
		}
		else
			ft_rotate (stack_a, 'a');
	}
	if (!ft_its_ordered(stack_a, 3))
		ft_sort_3 (stack_a);
	if (stack_b[0] < stack_b[1])
		ft_rotate (stack_b, 'b');
	while (!ft_its_empty(stack_b))
		ft_push(stack_a, stack_b, 'a');
	while (stack_a[0] != 1)
		ft_rotate (stack_a, 'a');
}
