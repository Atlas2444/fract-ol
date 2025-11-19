/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:35:20 by leauvray          #+#    #+#             */
/*   Updated: 2025/11/19 08:45:07 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//========INCLUDE========//
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

//========DEFINE-WINDOW========//
# define WIDTH 800
# define HEIGHT 600
# define TITLE "fract'ol"

//========DEFINE-FRACTALS========//
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

# define MAX_ITER 50

//========DEFINE-COLORS========//
# define COLOR_BLACK 0x000000
# define COLOR_WHITE 0xFFFFFF
# define COLOR_PSYCHEDELIC 0
# define COLOR_FIRE 1
# define COLOR_BLUE 2

//========DEFINE-KEYS========//
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_C 99
# define KEY_PLUS 65451
# define KEY_MINUS 65453

//========DEFINE-MOUSE========//
# define MOUSE_LEFT_CLICK 1
# define MOUSE_RIGHT_CLICK 2
# define MOUSE_MIDDLE_CLICK 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

//========DEFINE-EVENTS========//
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define BUTTON_PRESS 4
# define BUTTON_RELEASE 5
# define MOTION_NOTIFY 6
# define DESTROY_NOTIFY 17

//========DEFINE-STRUCTURE========//
typedef struct s_fractol
{
	
}	t_fractol;

#endif