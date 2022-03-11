/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:25:09 by phiolive          #+#    #+#             */
/*   Updated: 2022/03/08 17:50:17 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	numbers;

	numbers = 0;
	i = 0;
	if (argc < 2 || !argv[1])
		exit (1);
	while (argv[++i])
	{
		numbers += ft_check_argv (argv[i]);
		numbers++;
	}
	return (numbers);
}

void	ft_is_repeated(long int *stack_a)
{
	int	i;

	i = -1;
	while (stack_a[++i])
	{
		if (ft_check_repeat(stack_a, i))
			ft_exit(stack_a, NULL);
	}
	return ;
}

int	ft_check_repeat(long int *stack_a, int i)
{
	int	k;

	k = -1;
	while (stack_a[++k])
	{
		if (k == i)
			;
		else if (stack_a[k] == stack_a[i])
			return (1);
	}
	return (0);
}
