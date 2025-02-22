/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:46:35 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/22 20:46:57 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_pixel_put(t_data *data, int x_coord, int y_coord, int color)
{
	char	*dest;

	dest = data->addr + (y_coord * data->line_length + x_coord
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}
