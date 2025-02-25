/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:25:37 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/24 13:22:42 by rsrour           ###   ########.fr       */
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

int	ft_strlen(char *src)
{
	int	len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

char	*ft_strchr(char *src, int c)
{
	while (*src != '\0' && *src != (unsigned char)c)
		src++;
	if (*src == (unsigned char)c)
		return ((char *)src);
	return (NULL);
}

char	*ft_strrchr(char *src, int c)
{
	int	index;

	index = ft_strlen(src);
	while (index >= 0)
	{
		if (src[index] == (unsigned char)c)
			return ((char *)src + index);
		index--;
	}
	return (NULL);
}
