#include "../includes/fractol.h"
#include <X11/keysym.h>

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

int	start_window(t_data *data)
{
	data->ptr = mlx_init();
	data->window = mlx_new_window(data->ptr, WIDTH, HEIGHT, "fractol");
	if(!data->window)
	{
		mlx_destroy_display(data->ptr);
	}
	mlx_hook(data->window, 17, 1L<<17, close_program, data);
	mlx_loop_hook(data->ptr, start_image, data);
	mlx_loop(data->ptr);
	return(0);
}

int main()
{
	t_data  *data;

	data = (t_data *)malloc(sizeof(t_data) * 2);
	if (!data)
		return (1);
	start_window(data);
	return (0);
}