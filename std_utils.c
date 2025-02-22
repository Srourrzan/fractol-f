/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:25:37 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/22 20:30:07 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	iter;

	iter = 0;
	while ((s1[iter] && s2[iter]) && s1[iter] == s2[iter])
		iter++;
	return (s1[iter] - s2[iter]);
}
