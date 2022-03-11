/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:35:24 by phiolive          #+#    #+#             */
/*   Updated: 2022/03/10 05:20:02 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// INCLUDES ---------------------------------------------
# include <unistd.h>
# include <stdlib.h>

// DEFINES/MACRO ----------------------------------------
# define INT_MIN -2147483648

//######################################################
// ---------FUNCTIONS -----------------#################
//######################################################

//-------------------MAIN.C-----------------------------
void		ft_exit(long int *array, int *x);

//----------------CONVERT_ARGV.C------------------------
long int	*ft_convert_argv_to_array_int(char **argv, int numbers);
void		ft_char_to_int(char *c_number, long int *stack_a, int *x);
int			ft_char_to_int_positive(char *nbm, long int *s, int i, int *x);
int			ft_char_to_int_negative(char *nbm, long int *s, int i, int *x);
int			ft_check_argv(char *argv);

//------------------------CHECK_ARG.C--------------------------
int			ft_check_args(int argc, char **argv);
void		ft_is_repeated(long int *array);
int			ft_check_repeat(long int *array, int i);

//----------------CONVERT_TO_POSITIVE.C------------------------
int			*ft_array_to_positive(long int *array, int numbers);

//-------------------------OPERATIONS.C------------------------
void		ft_push(int *stack_1, int *stack_2, char c);
void		ft_rotate(int *stack, char c);
void		ft_rev_rotate(int *stack, char c);
void		ft_swap(int *stack, int c);

//-------------------------RADIX.C-----------------------------
void		ft_radix_sort(int *stack_a, int *stack_b, int numbers);

//------------------------MIN_SORT.C---------------------------
void		ft_min_sort(int *stack_a, int *stack_b, int numbers);
void		ft_sort_reversed(int *stack_a, int *stack_b, int numbers);

//-----------------------STACK_CHECK.C-------------------------
int			ft_its_ordered(int *stack, int numbers);
int			ft_its_empty(int *stack);
void		ft_mov_up(int *stack);
void		ft_mov_down(int *stack);
int			ft_is_reversed(int *stack, int numbers);

//-----------------------SORT_FIVE.C-------------------------
void		ft_sort_less(int *stack_a, int *stack_b, int max, int min);

#endif
