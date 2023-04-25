/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:13:55 by flcristi          #+#    #+#             */
/*   Updated: 2023/04/25 15:05:32 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	set_mandelbrot(double cx, double cy, t_data *data)
{
	int		iteration;
	double	xz;
	double	yz;
	double	temp_z;

	iteration = 0;
	xz = 0;
	yz = 0;
	while (xz * xz + yz * yz < 4 && iteration < MAX_INTER)
	{
		temp_z = xz * xz - yz * yz + cx;
		yz = 2 * xz * yz + cy;
		xz = temp_z;
		iteration++;
	}
	if (iteration == MAX_INTER)
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
	while (y < HEIGHT)
	{
		cy = data->image.y_min + y
			* (data->image.y_max - data->image.y_min) / HEIGHT;
		x = 0;
		while (x < WIDTH)
		{
			cx = data->image.x_min + x
				* (data->image.x_max - data->image.x_min) / WIDTH;
			image_pixel_put(&data->image, x, y, set_mandelbrot(cx, cy, data));
			x++;
		}
		y++;
	}
}
