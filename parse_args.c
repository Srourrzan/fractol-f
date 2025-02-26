/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:13:32 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/26 11:00:42 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_var(int *iter, double *d_num, int *ten, int *sign)
{
	*sign = 1;
	*d_num = 0.0;
	*iter = 0;
	*ten = 10;
}

int	ft_is_float(char *src)
{
	int	iter;
	int	status;
	int	d_check;

	iter = 0;
	status = 1;
	if (src[0] == '\0')
		return (!status);
	d_check = ft_strchr(src, '.') - ft_strrchr(src, '.');
	if (d_check)
	{
		write(2, "Invalid argument, multiple dots", 32);
		return (0);
	}
	if (src[iter] == '-' || src[iter] == '+')
		iter++;
	while (src[iter])
	{
		if ((src[iter] < '0' || src[iter] > '9') && src[iter] != '.')
			return (0);
		iter++;
	}
	return (status);
}

double	ft_atof(char *src)
{
	int		iter;
	double	d_num;
	int		ten;
	int		sign;

	init_var(&iter, &d_num, &ten, &sign);
	if (src[iter] == '-' || src[iter] == '+')
	{
		if (src[iter] == '-')
			sign = -1;
		iter++;
	}
	while (src[iter] >= '0' && src[iter] <= '9')
	{
		d_num = (d_num * 10) + (src[iter] - '0');
		iter++;
	}
	if (src[iter] == '.')
		iter++;
	while (src[iter])
	{
		d_num += (double)(src[iter++] - '0') / ten;
		ten *= 10;
	}
	return (d_num * sign);
}

int	ft_validate_args(char **argv, int argc)
{
	int	iter;

	if (!ft_strcmp(argv[1], "Mandelbrot") && argc == 2)
	{
		return (1);
	}
	else if (!ft_strcmp(argv[1], "Julia") && (argc == 4 || argc == 2))
	{
		iter = 2;
		while (argv[iter])
		{
			if (!ft_is_float(argv[iter]))
			{
				write(1, "error float\n", 13);
				return (0);
			}
			iter++;
		}
		return (1);
	}
	write(2, "Usage: ./fractol Mandelbrot-Julia <real> <imaginary>\n", 53);
	return (0);
}
