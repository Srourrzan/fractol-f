/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:06:18 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/24 18:19:29 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit(int exit_num)
{
	exit(exit_num);
}

void	ft_clean(t_mlx *i_mlx)
{
	if (!i_mlx)
		return ;
	if (i_mlx->img.img)
		mlx_destroy_image(i_mlx->mlx, i_mlx->img.img);
	if (i_mlx->win)
		mlx_destroy_window(i_mlx->mlx, i_mlx->win);
	if (i_mlx->mlx)
	{
		mlx_destroy_display(i_mlx->mlx);
		free(i_mlx->mlx);
		i_mlx->mlx = NULL;
	}
}

void	ft_clean_and_exit(t_mlx *i_mlx, int exit_num)
{
	ft_clean(i_mlx);
	ft_exit(exit_num);
}
