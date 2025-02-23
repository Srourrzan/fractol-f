/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:50:32 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/23 21:33:24 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	i_mlx;

	i_mlx.mlx = mlx_init();
	printf("start, argc = %d\n", argc);
	if (argc > 1 && argc < 5)
	{
		printf("here\n");
		ft_display_fractals(&i_mlx, argv, argc);
	}
	else
	{
		perror("Usage: COMPLETE THIS LATER");
		exit(1);
	}
	mlx_destroy_display(i_mlx.mlx);
	return (0);
}
