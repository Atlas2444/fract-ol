/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:46:28 by leauvray          #+#    #+#             */
/*   Updated: 2025/11/24 03:33:54 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_error(int num_error)
{
	if (num_error == 1)
		write (1, "Insufficient number of arguments\n", 34);
	if (num_error == 2)
		write (1, "Not enough arguments\n'./fractol mandelbrot'\n", 45);
	if (num_error == 3)
		write (1, "Not enough arguments\n'./fractol julia <real> <imaginary>'\n", 57);
	if (num_error == 4)
		write (1, "invalid number\n", 16);
	if (num_error == 5)
		write (1, "Not enough arguments\n'./fractol burning_ship'\n", 47);
	if (num_error == 6)
		write (1, "fractal type not found\n", 24);
	exit(1);
}

void	malloc_error()
{
    write(2, "Error: Allocation failed\n", 25);
    exit(1);
}