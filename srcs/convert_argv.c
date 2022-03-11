/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:25:09 by phiolive          #+#    #+#             */
/*   Updated: 2022/03/08 06:22:33 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_check_argv(char *argv)
{
	int	i;
	int	numbers;

	i = 0;
	numbers = 0;
	while (argv[i] && argv[i] == ' ')
		i++;
	while (argv[i])
	{
		if ((argv[i] < '0' || argv [i] > '9')
			&& argv[i] != ' ' && argv[i] != '-')
			ft_exit(NULL, NULL);
		if (argv[i] == '-' && (argv[i - 1] != ' ' && i
				|| (argv[i + 1] < '0' || argv [i + 1] > '9')))
			ft_exit(NULL, NULL);
		if (argv[i] == ' ' && (argv[i + 1] != ' ' && argv[i + 1]))
			numbers++;
		i++;
	}
	return (numbers);
}

int	ft_char_to_int_negative(char *c_number, long int *stack_a, int i, int *x)
{
	int	size;

	size = 0;
	while (c_number[++i] != ' ' && c_number[i])
	{
		size++;
		if (size > 10)
			ft_exit(stack_a, x);
		stack_a[*x] += c_number[i] - 48;
		if (c_number[i + 1] != ' ' && c_number[i + 1])
			stack_a[*x] *= 10;
	}
	stack_a[*x] *= -1;
	if (stack_a[*x] < INT_MIN)
		ft_exit(stack_a, x);
	*x = *x + 1;
	if (!c_number[i])
		return (i - 1);
	return (i);
}

int	ft_char_to_int_positive(char *c_number, long int *stack_a, int i, int *x)
{
	int	size;

	size = 0;
	while (c_number[i] != ' ' && c_number[i])
	{
		size++;
		if (size > 10)
			ft_exit(stack_a, x);
		stack_a[*x] += c_number[i] - 48;
		if (c_number[i + 1] != ' ' && c_number[i + 1])
			stack_a[*x] *= 10;
		i++;
	}
	if (stack_a[*x] > __INT_MAX__)
		ft_exit(stack_a, x);
	*x = *x + 1;
	if (!c_number[i])
		return (i - 1);
	return (i);
}

void	ft_char_to_int(char *c_number, long int *stack_a, int *x)
{
	int	i;

	i = -1;
	while (c_number[++i])
	{
		if (c_number[i] == '-')
			i = ft_char_to_int_negative (c_number, stack_a, i, x);
		else if (c_number[i] >= '0' || c_number[i] <= '9')
			i = ft_char_to_int_positive (c_number, stack_a, i, x);
	}
	return ;
}

long int	*ft_convert_argv_to_array_int(char **argv, int numbers)
{
	long int	*stack_a;
	int			i;
	int			*x;

	x = calloc (1, sizeof(int));
	stack_a = (long int *) calloc (numbers + 1, sizeof (long int));
	i = 0;
	while (argv[++i])
		ft_char_to_int(argv[i], stack_a, x);
	free (x);
	return (stack_a);
}
