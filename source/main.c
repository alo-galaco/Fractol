/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:55:39 by flcristi          #+#    #+#             */
/*   Updated: 2023/04/25 15:25:24 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	start_image(t_data *data)
{
	data->image.new_image = mlx_newint		key_press(int keysim, t_data *data);_image(data->ptr, WIDTH, HEIGHT);
	data->image.address = mlx_get_data_addr(data->image.new_image,
			&data->image.bits_per_pixel, &data->image.line_lenght,
			&data->image.endian);
	if (data->fractol_set == 'm')
		mandelbrot(data);
	else if (data->fractol_set == 'j')
		julia(data);
	mlx_put_image_to_window(data->ptr, data->window,
		data->image.new_image, 0, 0);
	mlx_destroy_image(data->ptr, data->image.new_image);
	return (0);
}

int	close_program(t_data *data)
{
	mlx_destroy_window(data->ptr, data->window);
	mlx_destroy_display(data->ptr);
	free(data->ptr);
	free(data);
	exit(0);
	return (0);
}

void	image_pixel_put(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->address + (y * image->line_lenght + x
			* (image->bits_per_pixel / 8));
	*(int *)pixel = color;
}

int	start_window(t_data *data)
{
	data->ptr = mlx_init();
	if (!data->ptr)
		return (1);
	data->window = mlx_new_window(data->ptr, WIDTH, HEIGHT, "fractol");
	if (!data->window)
	{
		close_program(data);
		return (1);
	}
	the_image(data);
	mlx_mouse_hook(data->window, mouse_zoom, data);
	mlx_hook(data->window, 6, 1L << 6, julia_mouse, data);
	mlx_hook(data->window, 2, 1L << 0, key_press, data);
	mlx_hook(data->window, 17, 1L << 17, close_program, data);
	mlx_loop_hook(data->ptr, start_image, data);
	mlx_loop(data->ptr);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc == 2 || argc == 4)
	{
		data = (t_data *)malloc(sizeof(t_data) * 2);
		if (!data)
			return (1);
		if (check_arg(argc, argv, data))
			start_window(data);
		free(data);
	}
	else
		message_help();
	return (0);
}
