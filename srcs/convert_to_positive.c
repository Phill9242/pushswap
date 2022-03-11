/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_positive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 03:52:25 by phiolive          #+#    #+#             */
/*   Updated: 2022/03/08 07:05:26 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static	int	ft_not_checked(int i, int *checker)
{
	int	x;

	x = -1;
	while (checker[++x])
	{
		if (checker[x] == i + 1)
			return (0);
	}
	return (1);
}

static void	ft_positive(long int *array, int *stack_a, int n, int *checker)
{
	long int	lesser;
	static int	value = 0;
	int			i;
	int			pos;

	pos = 0;
	i = -1;
	lesser = 2147483648;
	while (n > ++i)
	{
		if (array[i] < lesser && ft_not_checked(i, checker))
		{
			pos = i;
			lesser = array[i];
		}
	}
	checker[value] = pos + 1;
	stack_a[pos] = ++value;
	return ;
}

int	*ft_array_to_positive(long int *array, int numbers)
{
	int	*stack_a;
	int	count;
	int	*checker;

	count = -1;
	checker = calloc (sizeof (int), numbers + 1);
	stack_a = calloc (sizeof (int), numbers + 2);
	while (++count < numbers)
		ft_positive(array, stack_a, numbers, checker);
	free (array);
	free (checker);
	return (stack_a);
}
