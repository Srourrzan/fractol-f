/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:32:36 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/24 18:53:12 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//
void  ft_init_mandelbrot(t_mlx *i_mlx)
{
    i_mlx->fractal.x = 100;
    i_mlx->fractal.y = 100;
    i_mlx->fractal.height = 1000;
    i_mlx->fractal.width = 1000;
}
/*
 * z = x + iy
*/
void ft_mandelbrot(t_mlx *i_mlx, char **argv)
{
    ft_init_mandelbrot(i_mlx);
    mlx_string_put(i_mlx->mlx, i_mlx->win, 450, 10, 0xfefefe ,"Mandelbrot");
    printf("%s\n", argv[1]);
}