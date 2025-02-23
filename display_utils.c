/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:50:44 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/23 20:32:43 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_display_fractals(char **argv, int argc)
{
    if (!ft_validate_args(argv))
        ft_exit(2);
    if (!ft_strcmp(argv[1], "Mandelbrot"))
    {
        ft_mandelbrot();
    }    
    else if (!ft_strcmp(argv[1], "Julia") && (argc == 4 || argc == 2))
    {
        
    }
    else if (!ft_strcmp(argv[1], "Sierpinski"))
    {
        
    }
    else
        ft_exit(1);
}
