/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 05:20:37 by phiolive          #+#    #+#             */
/*   Updated: 2022/03/10 05:10:13 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_rotate(int *stack, char c)
{
	int	step;
	int	i;

	i = -1;
	step = stack[0];
	ft_mov_up (stack);
	while (stack[++i])
		;
	stack[i] = step;
	if (c == 'a')
		write (1, "ra\n", 3);
	else
		write (1, "rb\n", 3);
	return ;
}

void	ft_rev_rotate(int *stack, char c)
{
	int	step;
	int	i;

	i = -1;
	while (stack[++i])
		;
	step = stack[i - 1];
	stack[i - 1] = 0;
	ft_mov_down (stack);
	stack[0] = step;
	if (c == 'a')
		write (1, "rra\n", 4);
	else
		write (1, "rrb\n", 4);
	return ;
}

void	ft_swap(int *stack, int c)
{
	int	step;

	step = stack[0];
	stack[0] = stack[1];
	stack[1] = step;
	if (c == 'a')
		write (1, "sa\n", 3);
	else
		write (1, "sb\n", 3);
	return ;
}

void	ft_push(int *stack_1, int *stack_2, char c)
{
	ft_mov_down (stack_1);
	stack_1[0] = stack_2[0];
	ft_mov_up (stack_2);
	if (c == 'a')
		write (1, "pa\n", 3);
	else
		write (1, "pb\n", 3);
	return ;
}
