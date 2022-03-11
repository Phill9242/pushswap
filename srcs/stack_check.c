/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:34:23 by phiolive          #+#    #+#             */
/*   Updated: 2022/03/10 05:19:11 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_mov_up(int *stack)
{
	int	i;

	i = -1;
	while (stack[++i])
		stack[i] = stack[i + 1];
	return ;
}

void	ft_mov_down(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	return ;
}

int	ft_its_ordered(int *stack, int numbers)
{
	int	i;

	i = -1;
	while (++i < numbers - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
	}
	return (1);
}

int	ft_its_empty(int *stack)
{
	if (!stack[0])
		return (1);
	return (0);
}

int	ft_is_reversed(int *stack, int numbers)
{
	int	i;

	i = -1;
	while (++i < numbers - 1)
	{
		if (stack[i] < stack[i + 1])
			return (0);
	}
	return (1);
}
