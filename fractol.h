/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:59:41 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/25 22:05:45 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <unistd.h>

# define CREAL 0.0
# define CIM 0.8

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_fractal
{
	int			id;
	double		creal;
	double		cim;
	double		zreal;
	double		zim;  
	double		minreal;
	double		maxreal;
	double		min_im; 
	double		max_im;
	int			x;
	int			y;
	int			zoom;
	int			height;
	int			width;
	int			max_iter;
	int			color;
	double		offsetx;
	double		offsety;
}				t_fractal;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_fractal	fractal;
}				t_mlx;

// std functions
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strlen(char *src);
char			*ft_strchr(char *src, int c);
char			*ft_strrchr(char *src, int c);

// mlx functions
void			ft_mlx_pixel_put(t_image *data, int x_coord, int y_coord,
					int color);
void			ft_init_mlx(t_mlx *i_mlx);
int	ft_key_hook(int keycode, t_mlx *i_mlx);
void	ft_init_window(t_mlx *i_mlx);
int    ft_mouse_zoom(int key, int x, int y, t_mlx *i_mlx);

// sets functions
void			ft_init_by_id(t_mlx *i_mlx, char **argv, int argc);
void			ft_fractol(char **argv, int argc);

// finish_utils functions
void			ft_exit(int exit_num);
void			ft_clean(t_mlx *i_mlx);
void			ft_clean_and_exit(t_mlx *i_mlx, int exit_num);
int	 close_handle(t_mlx *i_mlx);

// parse_args functions
int				ft_is_float(char *src);
int				ft_validate_args(char **argv);
double			ft_atof(char *src);

// mandelbrot functions
void			ft_mandelbrot(t_mlx *i_mlx);
void			ft_coeffs(t_fractal *fractal, int id);
void			ft_init_mandelbrot(t_fractal *fractal);
int	ft_num_iters(t_fractal *fractal, double	real_p, double	imag_p);

//julia functions
void ft_julia(t_mlx *i_mlx, char **argv, int argc);

#endif