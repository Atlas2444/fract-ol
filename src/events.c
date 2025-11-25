/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:45:18 by leauvray          #+#    #+#             */
/*   Updated: 2025/11/25 03:00:26 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_destroy(t_fractol *fractol)
{
	if (fractol->img != NULL)
		mlx_destroy_image(fractol->mlx, fractol->img);
	if (fractol->win != NULL)
		mlx_destroy_window(fractol->mlx, fractol->win);
	if (fractol->mlx != NULL)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
}

void	zoom(t_fractol *fractol, double zoom_factor)
{
	double	center_re;
	double	center_im;
	double	width;
	double	height;

	center_re = (fractol->min_re + fractol->max_re) / 2;
	center_im = (fractol->min_im + fractol->max_im) / 2;
	width = fractol->max_re - fractol->min_re;
	height = fractol->max_im - fractol->min_im;
	fractol->min_re = center_re - width * zoom_factor / 2;
	fractol->max_re = center_re + width * zoom_factor / 2;
	fractol->min_im = center_im - height * zoom_factor / 2;
	fractol->max_im = center_im + height * zoom_factor / 2;
	render(fractol);
}

int mouse_press(int key, int x, int y, t_fractol *fractol)
{
	printf("%d\n", key);
	if (key == MOUSE_SCROLL_UP)
		zoom(fractol, ZOOM_UP);
	if (key == MOUSE_SCROLL_DOWN)
		zoom(fractol, ZOOM_DOWN);
	return(0);
}

int	key_press(int key, t_fractol *fractol)
{
	printf("%d\n", key);
	if (key == KEY_ESC)
	{
		fractol_destroy(fractol);
		exit(0);
	}
	if (key == KEY_LEFT)
	{
		fractol->min_re -= 0.1;
		fractol->max_re -= 0.1;
		render(fractol);
	}
	if (key == KEY_RIGHT)
	{
		fractol->min_re += 0.1;
		fractol->max_re += 0.1;
		render(fractol);
	}
	if (key == KEY_UP)
	{
		fractol->min_im -= 0.1;
		fractol->max_im -= 0.1;
		render(fractol);
	}
	if (key == KEY_DOWN)
	{
		fractol->min_im += 0.1;
		fractol->max_im += 0.1;
		render(fractol);
	}
	return (0);
}

int	close_window(t_fractol *fractol)
{
	fractol_destroy(fractol);
	exit(0);
	return (0);
}

void	event_init(t_fractol *fractol)
{
	mlx_hook(fractol->win, KEY_PRESS, KeyPressMask, key_press, fractol);
	mlx_hook(fractol->win, BUTTON_PRESS, ButtonPressMask, mouse_press, fractol);
	mlx_hook(fractol->win, DESTROY_NOTIFY, 0, close_window, fractol);
}
