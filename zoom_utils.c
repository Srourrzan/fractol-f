/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:52:25 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/25 22:18:12 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double value, double stop1, double start2, double stop2)
{
	return (start2 + (stop2 - start2) * ((value) / (stop1)));
}

int    ft_mouse_zoom(int key, int x, int y, t_mlx *i_mlx)
{
    double	mouse_re;
	double	mouse_im;
	double	new_mouse_re;
	double	new_mouse_im;

	mouse_re = map(x, 1000, -2.5 * i_mlx->fractal.zoom + i_mlx->fractal.offsetx,
			1.5 * i_mlx->fractal.zoom + i_mlx->fractal.offsetx);
	mouse_im = map(y, 1000, -2 * i_mlx->fractal.zoom + i_mlx->fractal.offsety,
			2 * i_mlx->fractal.zoom + i_mlx->fractal.offsety);
	if (key == 4)
		i_mlx->fractal.zoom *= 1.1;
	else if (key == 5)
		i_mlx->fractal.zoom /= 1.1;
	new_mouse_re = map(x, 1000, -2.5 * i_mlx->fractal.zoom + i_mlx->fractal.offsetx,
			1.5 * i_mlx->fractal.zoom + i_mlx->fractal.offsetx);
	new_mouse_im = map(y, 1000, -2 * i_mlx->fractal.zoom + i_mlx->fractal.offsety,
			2 * i_mlx->fractal.zoom + i_mlx->fractal.offsety);
	i_mlx->fractal.offsetx += mouse_re - new_mouse_re;
	i_mlx->fractal.offsety += mouse_im - new_mouse_im;
	if (i_mlx->fractal.id == 1)
        ft_mandelbrot(i_mlx);
    // else if (i_mlx->fractal.id == 2)
    //     ft_julia(i_mlx, )
	return (0);
}


