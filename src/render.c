/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:46:18 by leauvray          #+#    #+#             */
/*   Updated: 2025/11/24 07:26:08 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_fractol *fractol, int x, int y, int color)
{
	int	offset;

	offset = y * fractol->line_len + x * (fractol->bpp / 8);
	*(int *)(fractol->img_data + offset) = color;
}

int	mandelbrot(double c_re, double c_im, int max_iter)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		iter;
	
	z_re = 0;
	z_im = 0;
	iter = 0;
	while (iter < max_iter && (z_re * z_re + z_im * z_im) <= 4)
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = tmp;
		iter++;
	}
	return (iter);
}

int	julia(double z_re, double z_im, t_fractol *fractol)
{
	double	tmp;
	int		iter;
	
	iter = 0;
	while (iter < fractol->max_iter && (z_re * z_re + z_im * z_im) <= 4)
	{
		tmp = z_re * z_re - z_im * z_im + fractol->julia_re;
		z_im = 2 * z_re * z_im + fractol->julia_im;
		z_re = tmp;
		iter++;
	}
	return (iter);
}

int	get_color(int iterations, int max_iter)
{
	int r;
	int g;
	int b;

	r = (iterations * 255) / max_iter;
	g = (iterations * 127) / max_iter;
	b = 255 - (iterations * 255) / max_iter;
	return ((r << 16) | (g << 8) | b);
}

void	render(t_fractol *fractol)
{
	int x;
	int y;
	int iterations;
	double z_re;
	double z_im;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z_re = fractol->min_re + (x * (fractol->max_re - fractol->min_re) / WIDTH);
			z_im = fractol->min_im + (y * (fractol->max_im - fractol->min_im) / HEIGHT);
			if (fractol->fractal_type == MANDELBROT)
				iterations = mandelbrot(z_re, z_im, fractol->max_iter);
			else if (fractol->fractal_type == JULIA)
				iterations = julia(z_re, z_im, fractol);
			pixel_put(fractol, x, y, get_color(iterations, fractol->max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}
