/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:33:38 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/25 20:37:20 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_init_julia(t_fractal *fractal, char **argv, int argc)
{
    if (argc == 2)
    {
        fractal->creal = CREAL;
        fractal->cim = CIM;
    }
    else if (argc == 4)
    {
        fractal->creal = ft_atof(argv[2]);
        fractal->cim = ft_atof(argv[3]);
    }
    fractal->x = 0;
	fractal->y = 0;
	fractal->height = 1000;
	fractal->width = 1000;
	fractal->minreal = -2.0;
	fractal->maxreal = 2.0;
	fractal->min_im = -2.0;
	fractal->max_im = 2.0;
	fractal->color = 0xe5989b;
	fractal->max_iter = 300;
	fractal->zoom = 50;
}

void ft_julia(t_mlx *i_mlx, char **argv, int argc)
{
    int			n_iters;

	n_iters = 0;
	ft_init_julia(&i_mlx->fractal, argv, argc);
	while (i_mlx->fractal.y < i_mlx->fractal.height)
	{
		i_mlx->fractal.x = 0;
		while (i_mlx->fractal.x < i_mlx->fractal.width)
		{
			ft_coeffs(&i_mlx->fractal, i_mlx->fractal.id);
			n_iters = ft_num_iters(&i_mlx->fractal, i_mlx->fractal.zreal, i_mlx->fractal.zim);
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
	mlx_string_put(i_mlx->mlx, i_mlx->win, 450, 10, 0xfefefe, "Julia");
}
