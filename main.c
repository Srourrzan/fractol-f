/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:50:32 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/22 20:50:31 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_vars vars;
	t_data img;

	if (argc > 1 && argc < 5)
		ft_display_fractals(argv);
	else
	{
		perror("Usage: COMPLETE THIS LATER");
		exit(1);
	}
	return (0);
}
