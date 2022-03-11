/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:37:16 by phiolive          #+#    #+#             */
/*   Updated: 2022/03/10 06:47:07 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	ft_sort_10(int *stack_a, int *stack_b, int numbers)
{
	int	i;
	int	min_value;

	i = -1;
	min_value = 1;
	while (!ft_its_empty(stack_a))
	{
		while (stack_a[++i])
		{
			if (stack_a[0] == min_value)
			{
				ft_push (stack_b, stack_a, 'b');
				min_value++;
			}
			else
				ft_rotate(stack_a, 'a');
		}
		i = -1;
	}
	while (numbers--)
		ft_push(stack_a, stack_b, 'a');
	return ;
}

static void	ft_check_min(int *stack_a, char c, int min_value)
{
	int	min_pos;
	int	stack_size;

	stack_size = -1;
	while (stack_a[++stack_size])
	{
		if (stack_a[stack_size] == min_value)
			min_pos = stack_size;
	}
	if (min_pos < stack_size / 2)
		ft_rotate(stack_a, 'a');
	else
		ft_rev_rotate(stack_a, 'a');
	return ;
}

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

void	ft_sort_reversed(int *stack_a, int *stack_b, int numbers)
{
	int	anchor;

	anchor = numbers;
	while (--numbers > -1)
		ft_push (stack_b, stack_a, 'b');
	numbers = anchor;
	while (--numbers > -1)
	{
		ft_rev_rotate (stack_b, 'b');
		ft_push(stack_a, stack_b, 'a');
	}
	return ;
}

void	ft_min_sort(int *stack_a, int *stack_b, int numbers)
{
	if (numbers == 2)
		ft_rotate(stack_a, 'a');
	else if (numbers <= 5)
		ft_sort_less (stack_a, stack_b, 1, numbers);
	else if (ft_is_reversed(stack_a, numbers))
		ft_sort_reversed(stack_a, stack_b, numbers);
	else
		ft_sort_10 (stack_a, stack_b, numbers);
	return ;
}
