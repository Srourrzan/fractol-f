/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:03:45 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/26 11:02:27 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_by_id(t_mlx *i_mlx, char **argv, int argc)
{
	if (!i_mlx)
		return ;
	if (!ft_strcmp(argv[1], "Mandelbrot"))
	{
		i_mlx->fractal.id = 1;
		ft_init_window(i_mlx);
		ft_init_mandelbrot(&i_mlx->fractal);
		ft_mandelbrot(i_mlx);
	}
	else if (!ft_strcmp(argv[1], "Julia") && (argc == 4 || argc == 2))
	{
		i_mlx->fractal.id = 2;
		ft_init_window(i_mlx);
		ft_init_julia(&i_mlx->fractal, argv, argc);
		ft_julia(i_mlx);
	}
}

void	ft_fractol(char **argv, int argc)
{
	t_mlx	i_mlx;

	ft_init_mlx(&i_mlx);
	ft_init_by_id(&i_mlx, argv, argc);
	mlx_hook(i_mlx.win, 17, 0, &close_handle, &i_mlx);
	mlx_mouse_hook(i_mlx.win, &ft_mouse_zoom, &i_mlx);
	mlx_key_hook(i_mlx.win, &ft_key_hook, &i_mlx);
	mlx_loop(i_mlx.mlx);
}
