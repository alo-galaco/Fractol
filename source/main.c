#include "../includes/fractol.h"
#include <X11/keysym.h>

int start_image(t_data *data)
{
    data->image.new_image = mlx_new_image(data->ptr, WIDTH, HEIGHT);
    data->image.address = mlx_get_data_addr (data->image.new_image, &data->image.bits_per_pixel, &data->image.line_lenght. &data->image.endian);

    mlx_put_image_to_window(data->ptr, data->window, data->image.new_image, 0, 0);
    mlx_destroy_image(data->ptr, data->image.new_image);
    return(0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data) * 2);
	if (!data)
		return (1);
	if (check_arg(argc, argv, data))
		start_window(data);
	else
		free(data);
	return (0);
}