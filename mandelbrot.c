/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:32:36 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/24 19:35:57 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//
void  ft_init_mandelbrot(t_fractal *fractal)
{
    fractal->x = 100;
    fractal->y = 100;
    fractal->height = 1000;
    fractal->width = 1000;
    fractal->minreal = -3.0;
    fractal->maxreal = 2.0;
}

double  ft_real(t_fractal fractal)
{
    double  range;

    range = fractal.maxreal - fractal.minreal;
    return (fractal.x * (range / fractal.width) + fractal.minreal);
}
/*
 * z = x + iy
*/
void ft_mandelbrot(t_mlx *i_mlx)
{
    t_fractal fractal;
    
    fractal = i_mlx->fractal;
    ft_init_mandelbrot(&fractal);
    mlx_string_put(i_mlx->mlx, i_mlx->win, 450, 10, 0xfefefe ,"Mandelbrot");
    while (fractal.x < fractal.width)
    {
        fractal.y = 100;
        while (fractal.y < fractal.height)
        {
            fractal.creal = ft_real(fractal);
            printf("%f\n", fractal.creal);
            // ft_mlx_pixel_put(&i_mlx->img.img, fractal.creal)
            fractal.y++;
        }
        fractal.x++;
    }
}