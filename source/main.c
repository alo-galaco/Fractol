#include "../includes/fractol.h"

int start_image(t_data *data)
{
    data->image.new_image = mlx_new_image(data->ptr, WIDTH, HEIGHT);
    data->image.address = mlx_get_data_addr(data->image.new_image, &data->image.bits_per_pixel, &data->image.line_lenght, &data->image.endian);

    mlx_put_image_to_window(data->ptr, data->window, data->image.new_image, 0, 0);
    mlx_destroy_image(data->ptr, data->image.new_image);
    return(0);
}

int	close_program(t_data *data)
{
	mlx_destroy_window(data->ptr, data->window);
	mlx_destroy_display(data->ptr);
	exit(0);
	return(0);
}

int	key_press(int keysim, t_data *data)
{
	if(keysim == ESC || keysim == Q)
		close_program(data);
	return(0);
}

void	image_pixel_put(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->address + (y * image->line_lenght + x * (image->bits_per_pixel / 8));
	*(int *)pixel = color;
}


void	the_image(t_data *data)
{
	data->image.x_max = CX_MAX;
	data->image.x_min = CX_MIN;
	data->image.y_max = CY_MAX;
	data->image.y_min = CY_MIN;
	data->color = 0xFF0000;
	start_image(data);
}

static int	set_mandelbrot(double cx, double cy, t_data *data)
{
	int		iteration;
	double	xz;
	double	yz;
	double	temp_z;

	iteration = 0;
	xz = 0;
	yz = 0;
	while(xz * xz + yz * yz < 4 && iteration < MAX_INTER)
	{
		temp_z = xz * xz - yz * yz + cx;
		yz = 2 * xz * yz + cy;
		xz = temp_z;
		iteration++;
	}
	if(iteration == MAX_INTER)
		return (0x000000);
	else
		return (data->color * iteration * iteration);
}

void	mandelbrot(t_data *data)
{
	int		x;
	int		y;
	double	cx;
	double	cy;

	y = 0;
	while(y < HEIGHT)
	{
		cy = data->image.y_min + y * (data->image.y_max - data->image.y_min) / HEIGHT;
		x = 0;
		while(x < WIDTH)
		{
			cx = data->image.x_min	+ x * (data->image.x_max - data->image.x_min) / WIDTH;
			image_pixel_put(&data->image, x, y, set_mandelbrot(cx, cy, data));
			x++;
		}
		y++;
	}
}


int	start_window(t_data *data)
{
	data->ptr = mlx_init();
	data->window = mlx_new_window(data->ptr, WIDTH, HEIGHT, "fractol");
	if(!data->window)
	{
		mlx_destroy_display(data->ptr);
		free(data);
		return(1);
	}
	the_image(data);
	mlx_hook(data->window, 2, 1L<<0, key_press, data);
	mlx_hook(data->window, 17, 1L<<17, close_program, data);
	mlx_loop_hook(data->ptr, start_image, data);
	mlx_loop(data->ptr);
	return(0);
}

int	main()
{
	t_data  *data;

	data = (t_data *)malloc(sizeof(t_data) * 2);
	if (!data)
		return (1);
	start_window(data);
	free(data);
	return (0);
}