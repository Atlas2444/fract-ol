/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:46:06 by leauvray          #+#    #+#             */
/*   Updated: 2025/11/20 10:40:36 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_atof(char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		i;

	result = 0.0;
	decimal = 0.1;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result += (str[i++] - '0') * decimal;
		decimal *= 0.1;
	}
	return (result * sign);
}

static int is_valid_number(char *str)
{
	int i;
	int has_dot;
	int has_num;

	i = 0;
	has_dot = 0;
	has_num = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while(str[i])
	{
		if(str[i] >= '0' && str[i] <= '9')
			has_num = 1;
		else if (str[i] == '.' && !has_dot)
			has_dot = 1;
		else
			return (0);
		i++;
	}
	return (has_num);
}

void parse_arguments(int argc, char **argv, t_fractol *fractol)
{
	if (argc < 2)
		print_error(1);
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		if (argc != 2)
			print_error(2);
		fractol->fractal_type = MANDELBROT;
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 4)
			print_error(3);
		if (!is_valid_number(argv[2]) || !is_valid_number(argv[3]))
			print_error(4);
		fractol->fractal_type = JULIA;
		fractol->julia_re = ft_atof(argv[2]);
		fractol->julia_im = ft_atof(argv[3]);
	}
	else if (ft_strcmp(argv[1], "burning_ship") == 0)
	{
		if (argc != 2)
			print_error(5);
		fractol->fractal_type = BURNING_SHIP;
	}
	else
		print_error(6);
}
