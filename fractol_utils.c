/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:03:45 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/24 15:39:52 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_find_id(t_mlx i_mlx, char **argv, int argc)
{
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		i_mlx.fractal.id = 1;
	else if (!ft_strcmp(argv[1], "Julia") && (argc == 4 || argc == 2))
	{
		i_mlx.fractal.id = 2;
	}
	else if (!ft_strcmp(argv[1], "Sierpinski"))
	{
		i_mlx.fractal.id = 3;
	}
	else
		ft_clean_and_exit(i_mlx, 4);
}

void	ft_fractol(char **argv, int argc)
{
	t_mlx	i_mlx;

	i_mlx.mlx = mlx_init();
	ft_find_id(i_mlx, argv, argc);
	ft_clean(i_mlx);
}
