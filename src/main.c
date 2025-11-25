/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:44:39 by leauvray          #+#    #+#             */
/*   Updated: 2025/11/25 02:55:14 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
    t_fractol	fractol;

    parse_arguments(argc, argv, &fractol);
    fractal_init(&fractol);
    render(&fractol);
    mlx_loop(fractol.mlx);
    return (0);
}