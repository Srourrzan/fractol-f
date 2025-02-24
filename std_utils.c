/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:25:37 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/24 13:06:45 by rsrour           ###   ########.fr       */
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

static char	*ft_strchr(char *src, int c)
{
	while (*src != '\0' && *src != (unsigned char)c)
		src++;
	if (*src == (unsigned char)c)
		return ((char *)src);
	return (NULL);
}

static char	*ft_strrchr(char *src, int c)
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

int	ft_is_float(char *src)
{
	int	iter;
	int	status;
	int	d_check;

	iter = 0;
	status = 1;
	d_check = ft_strchr(src, '.') - ft_strrchr(src, '.');
	if (d_check)
	{
		perror("Invalid argument, multiple dots");
		return (0);
	}
	if (src[iter] == '-' || src[iter] == '+')
		iter++;
	while (src[iter])
	{
		if (src[iter] < '0' || src[iter] > '9')
		{
			status = 0;
			break ;
		}
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

	sign = 1;
	d_num = 0.0;
	iter = 0;
	ten = 10;
	if (src[iter] == '-' || src[iter] == '+')
	{
		if (src[iter] == '-')
			sign = -1;
		iter++;
	}
	while ((src[iter] >= '0' && src[iter] <= '9') || (src[iter] == '.'))
	{
		if (src[iter] == '.')
		{
			iter++;
			break ;
		}
		d_num = (d_num * 10) + (src[iter] - '0');
		iter++;
	}
	while (src[iter])
	{
		d_num = (src[iter] - '0') / ten;
		ten *= 10;
		iter++;
	}
	return (d_num * sign);
}

int	ft_validate_args(char **argv)
{
	int	iter;

	iter = 2;
	while (argv[iter])
	{
		if (!ft_is_float(argv[iter]))
			return (0);
		iter++;
	}
	return (1);
}

// int	main(void)
// {
// 	char *s1 = "9.8";

// 	printf("s1 = %f\n", ft_atof(s1));
// 	return(0);
// }