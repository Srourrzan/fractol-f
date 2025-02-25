/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:32:36 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/25 20:00:14 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->height = 1000;
	fractal->width = 1000;
	fractal->minreal = -2.0;
	fractal->maxreal = 2.0;
	fractal->min_im = -2.0;
	fractal->max_im = 2.0;
	fractal->color = 0xe5989b;
	fractal->max_iter = 200;
	fractal->zoom = 50;
}

void    ft_coeffs(t_fractal *fractal, int id)
{
	double	bound;

	if (id == 1)
	{
		bound = fractal->maxreal - fractal->minreal;
		fractal->creal = fractal->minreal + fractal->x * (bound / fractal->width);
		bound = fractal->max_im - fractal->min_im;
		fractal->cim = fractal->min_im + fractal->y * ((bound) / fractal->height);
	}
	else if (id == 2)
	{
		bound = fractal->maxreal - fractal->minreal;
		fractal->zreal = fractal->minreal + fractal->x * (bound / fractal->width);
		bound = fractal->max_im - fractal->min_im;
		fractal->zim = fractal->min_im + fractal->y * ((bound) / fractal->height);
	}
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
		escap_cond = real_p * real_p + imag_p * imag_p;
		iter++;
	}
	return (iter);
}

/*
 * When the function finds the n_iters, if the number of iters is 
 * within the range of the max_iter then this starting point did not
 * cause the rest of the points to escape to infinty and I will color
 * it black (0x000000) else if it has caused the rest of the points
 * to escape then I will color it some pinkish color (0xE5989B)
*/
void	ft_mandelbrot(t_mlx *i_mlx)
{
	int			n_iters;

	n_iters = 0;
	ft_init_mandelbrot(&i_mlx->fractal);
	while (i_mlx->fractal.y < i_mlx->fractal.height)
	{
		i_mlx->fractal.x = 0;
		while (i_mlx->fractal.x < i_mlx->fractal.width)
		{
			ft_coeffs(&i_mlx->fractal, &i_mlx->fractal.id);
			n_iters = ft_num_iters(&i_mlx->fractal);
			if (n_iters == i_mlx->fractal.max_iter)
				ft_mlx_pixel_put(&i_mlx->img, i_mlx->fractal.x, 
					i_mlx->fractal.y, 0x000000);
			else
				ft_mlx_pixel_put(&i_mlx->img, i_mlx->fractal.x, 
					i_mlx->fractal.y, i_mlx->fractal.color + (n_iters * 1000));
			i_mlx->fractal.x++;
			
		}
		i_mlx->fractal.y++;
	}
	mlx_put_image_to_window(i_mlx->mlx, i_mlx->win, i_mlx->img.img, 0, 0);
	mlx_string_put(i_mlx->mlx, i_mlx->win, 450, 10, 0xfefefe, "Mandelbrot");
}
