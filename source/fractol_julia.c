/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:28:43 by flcristi          #+#    #+#             */
/*   Updated: 2023/04/25 15:06:51 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	set_julia(double cx, double cy, t_data *data)
{
	int		iteration;
	double	xz;
	double	yz;
	double	temp_z;

	iteration = 0;
	xz = cx;
	yz = cy;
	while (xz * xz + yz * yz < 4 && iteration < MAX_INTER)
	{
		temp_z = xz * xz - yz * yz + data->x_julia;
		yz = 2 * xz * yz - data->y_julia;
		xz = temp_z;
		iteration++;
	}
	if (iteration == MAX_INTER)
		return (0x000000);
	else if (iteration == 0)
		return (data->julia_color * 15);
	else
		return (data->julia_color * iteration * 15);
}

void	julia(t_data *data)
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
			image_pixel_put(&data->image, x, y, set_julia(cx, cy, data));
			x++;
		}
		y++;
	}
}
