#include "fractol.h"

// (unsigned int*)dest-> Casts `dest` to a 4-byte integer pointer
// *(unsigned int*)dest = color; -> Writes the 32-bit color value directly
// into memory
void	ft_mlx_pixel_put(t_data *data, int x_coord, int y_coord, int color)
{
	char	*dest;

	dest = data->addr + (y_coord * data->line_length + x_coord
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	main(void)
{
	t_vars vars;
	t_data img;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		exit(1);
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "Hello wprld!");
	img.img = mlx_new_image(vars.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	printf("img.bits_per_pixel = %d\nimg.line_length = %d\nimg.endian = %d\n",
		img.bits_per_pixel, img.line_length, img.endian);
	ft_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	ft_mlx_pixel_put(&img, 6, 5, 0x00FF0000);
	ft_mlx_pixel_put(&img, 7, 5, 0x00FF0000);
	ft_mlx_pixel_put(&img, 8, 5, 0x00FF0000);
	ft_mlx_pixel_put(&img, 9, 5, 0x00FF0000);
	ft_mlx_pixel_put(&img, 5, 6, 0x00FF0000);
	printf("ree\n");
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 50, 50);
	mlx_loop(vars.mlx);
	printf("desf\n");
	mlx_destroy_image(vars.mlx, &img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	free(vars.win);
	free(img.img);
	free(img.addr);
	// free(img.endian);

	return (0);
}