/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:50:32 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/24 15:10:29 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc > 1 && argc < 5)
	{
		if (!ft_validate_args(argv))
			ft_exit(2);
		ft_fractol(argv, argc);
	}
	else
	{
		perror("Usage: COMPLETE THIS LATER");
		exit(1);
	}
	return (0);
}
