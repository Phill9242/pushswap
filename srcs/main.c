/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:25:06 by phiolive          #+#    #+#             */
/*   Updated: 2022/03/11 01:28:24 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_exit(long int *array, int *x)
{
	if (array)
		free (array);
	if (x)
		free (x);
	write (2, "Error\n", 6);
	exit (1);
}

static void	ft_choose_algorithm(int *stack_a, int *stack_b, int numbers)
{
	if (ft_its_ordered (stack_a, numbers))
		return ;
	if (numbers <= 10)
		ft_min_sort (stack_a, stack_b, numbers);
	else
		ft_radix_sort (stack_a, stack_b, numbers);
	return ;
}

int	main(int argc, char **argv)
{
	int			numbers;
	long int	*array;
	int			*stack_a;
	int			*stack_b;

	numbers = ft_check_args (argc, argv);
	array = ft_convert_argv_to_array_int (argv, numbers);
	ft_is_repeated (array);
	stack_a = ft_array_to_positive (array, numbers);
	stack_b = calloc (numbers + 2, sizeof (int));
	ft_choose_algorithm (stack_a, stack_b, numbers);
	free(stack_b);
	free(stack_a);
	return (0);
}
