/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:03:45 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/24 14:04:06 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_find_id(t_mlx *i_mlx, char **argv, int argc)
{
	if (!i_mlx)
	{
		printf("mlx issue\n");
		ft_exit(3);
	}
	if (!ft_validate_args(argv))
		ft_exit(2);
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		i_mlx->fractal.id = 1;
	else if (!ft_strcmp(argv[1], "Julia") && (argc == 4 || argc == 2))
	{
		i_mlx->fractal.id = 2;
		if (argc == 4)
		{
			printf("arg[2] float? = %f\n", ft_atof(argv[2]));
		}
	}
	else if (!ft_strcmp(argv[1], "Sierpinski"))
	{
		i_mlx->fractal.id = 3;
	}
	else
		ft_exit(1);
}
