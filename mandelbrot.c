/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:32:36 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/25 14:40:50 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * z = x + iy
 * z_(n+1) = z_(n)^2 + c
 */

void	ft_init_mandelbrot(t_fractal *fractal)
{
	fractal->x = 100;
	fractal->y = 100;
	fractal->height = 1000;
	fractal->width = 1000;
	fractal->minreal = -3.0;
	fractal->maxreal = 2.0;
	fractal->color = 0xE5989B;
	fractal->max_iter = 150;
}

void	ft_coeffs(t_fractal *fractal)
{
	double	range;

	range = fractal->maxreal - fractal->minreal;
	fractal->creal = fractal->x * (range / fractal->width) + fractal->minreal;
	range = fractal->max_im - fractal->min_im;
	fractal->cim = fractal->y * (range / fractal->height) + fractal->min_im;
}

/*
 * ft_num_iters follow the Mandelbrot set formul
 * Z(n+1) = Z_n^2 + C
 * C = Cr + Ci (the constant complex number)
 * The real and imaginary components are updated seperatly
 * temp = Zr * Zr - (Zi * Zi) + Cr
 * Zi = 2ZrZi + Ci
 * Zr = temp
 * where Zr is represented by real_p, Zi is represented by imag_p,
 * Cr represented by fractal->creal, and Ci repreented by fractal->cim.
 *
 * The escape condition (Zr * Zr) + (Zi * Zi) >= 4 where the point will go
 * outside Mandelbrot set.
 */
int	ft_num_iters(t_fractal *fractal)
{
	int		iter;
	double	real_p;
	double	imag_p;
	double	temp;
	double	escap_cond;

	real_p = 0;
	imag_p = 0;
	iter = 0;
	escap_cond = real_p * real_p + imag_p * imag_p;
	while ((iter < fractal->max_iter) && escap_cond < 4.0)
	{
		temp = (real_p * real_p) - (imag_p * imag_p) + fractal->creal;
		imag_p = 2.0 * real_p * imag_p + fractal->cim;
		real_p = temp;
		iter++;
	}
	return (iter);
}

void	ft_mandelbrot(t_mlx *i_mlx)
{
	t_fractal	fractal;
	int			n_iters;

	n_iters = 0;
	fractal = i_mlx->fractal;
	ft_init_mandelbrot(&fractal);
	mlx_string_put(i_mlx->mlx, i_mlx->win, 450, 10, 0xfefefe, "Mandelbrot");
	while (fractal.x < fractal.width)
	{
		fractal.y = 100;
		while (fractal.y < fractal.height)
		{
			ft_coeffs(&fractal);
			n_iters = ft_num_iters(&fractal);
			printf("n_iters = %d\n", n_iters);
			// ft_mlx_pixel_put(&i_mlx->img, fractal.creal,
			// fractal.cim,0xE5989B);
			fractal.y++;
		}
		fractal.x++;
	}
}
