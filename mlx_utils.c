/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:46:35 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/24 16:18:38 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_pixel_put(t_image *data, int x_coord, int y_coord, int color)
{
	char	*dest;

	dest = data->addr + (y_coord * data->line_length + x_coord
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void	ft_init_mlx(t_mlx *i_mlx)
{
	if (!i_mlx)
		return;
	i_mlx->mlx = mlx_init();
	if (!i_mlx->mlx)
		ft_clean_and_exit(i_mlx, 5);
	i_mlx->win = mlx_new_window(i_mlx->mlx, 1000, 1000, "Fract-ol");
	
}
