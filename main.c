/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:50:32 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/26 11:00:15 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc > 1 && argc < 5)
	{
		if (!ft_validate_args(argv, argc))
			ft_exit(2);
		ft_fractol(argv, argc);
	}
	else
	{
		write(2, "Usage: ./fractol Mandelbrot-Julia <real> <imaginary>", 53);
		exit(1);
	}
	return (0);
}
