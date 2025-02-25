/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:46:35 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/25 17:32:59 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_pixel_put(t_image *data, int x_coord, int y_coord, int color)
{
	int	dest;

	dest = (y_coord * data->line_length + x_coord
			* (data->bits_per_pixel / 8));
	(*(unsigned int *)(dest + data->addr ))= color;
}

void	ft_init_mlx(t_mlx *i_mlx)
{
	if (!i_mlx)
		return;
	i_mlx->mlx = mlx_init();
	if (!i_mlx->mlx)
		ft_clean_and_exit(i_mlx, 5);
	i_mlx->win = mlx_new_window(i_mlx->mlx, 1000, 1000, "Fract-ol");
	if (!i_mlx->win)
		ft_clean_and_exit(i_mlx, 6);
	i_mlx->img.img = mlx_new_image(i_mlx->mlx, 1000, 1000);
	if (!i_mlx->img.img)
		ft_clean_and_exit(i_mlx, 7);
	i_mlx->img.addr = mlx_get_data_addr(i_mlx->img.img, &i_mlx->img.bits_per_pixel,
				&i_mlx->img.line_length, &i_mlx->img.endian);
	if (!i_mlx->img.addr)
		ft_clean_and_exit(i_mlx, 8);
}

// void	map_xy_to_complex(t_fractal *fractal)
// {
// 	fractal->creal = fractal->minreal + (fractal->x / fractal->width) * (fractal->max_iter - fractal->minreal);
// 	fractal
// }