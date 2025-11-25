/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:42:13 by leauvray          #+#    #+#             */
/*   Updated: 2025/11/25 00:36:18 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_fractol *fractol)
{
    if (fractol->fractal_type == MANDELBROT)
    {
        fractol->min_re = -2.5;
        fractol->max_re = 1.0;
        fractol->min_im = -1.25;
        fractol->max_im = 1.25;
    }
    else if (fractol->fractal_type == JULIA)
    {
        fractol->min_re = -2.0;
        fractol->max_re = 2.0;
        fractol->min_im = -1.5;
        fractol->max_im = 1.5;
    }
    else if (fractol->fractal_type == BURNING_SHIP)
    {
        fractol->min_re = -1.8;
        fractol->max_re = -1.7;
        fractol->min_im = -0.08;
        fractol->max_im = 0.01;
    }
    fractol->max_iter = MAX_ITER;
    fractol->color_schem = COLOR_PSYCHEDELIC;
}

void	fractal_init(t_fractol *fractol)
{
    fractol->mlx = mlx_init();
    if (fractol->mlx == NULL)
        malloc_error();
    fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, TITLE);
    if (fractol->win == NULL)
    {
        mlx_destroy_display(fractol->mlx);
        free(fractol->mlx);
        malloc_error();
    }
    fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
    if (fractol->img == NULL)
    {
        mlx_destroy_window(fractol->mlx, fractol->win);
        mlx_destroy_display(fractol->mlx);
        free(fractol->mlx);
        malloc_error();
    }
    fractol->img_data = mlx_get_data_addr(fractol->img,
        &fractol->bpp, &fractol->line_len, &fractol->endian);
    data_init(fractol);
    event_init(fractol);
}
