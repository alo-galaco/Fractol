/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:21:29 by flcristi          #+#    #+#             */
/*   Updated: 2023/04/25 14:04:22 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_press(int keysim, t_data *data)
{
	if (keysim == ESC || keysim == Q)
		close_program(data);
	return (0);
}

int	mouse_zoom(int keysim, int x, int y, t_data *data)
{
	x = 1;
	y = 1;
	if (keysim == 4 && x)
	{
		data->image.x_max -= data->image.x_max * 0.115;
		data->image.x_min -= data->image.x_min * 0.115;
		data->image.y_max -= data->image.y_max * 0.115;
		data->image.y_min -= data->image.y_min * 0.115;
	}
	if (keysim == 5 && y)
	{
		data->image.x_max += data->image.x_max * 0.115;
		data->image.x_min += data->image.x_min * 0.115;
		data->image.y_max += data->image.y_max * 0.115;
		data->image.y_min += data->image.y_min * 0.115;
	}
	return (0);
}

int	julia_mouse(int x, int y, t_data *data)
{
	if(data->fractol_set == 'j' && data->julia_set_image == 0)
	{
		data->x_julia = (data->image.x_max - data->image.x_min)
			/ WIDTH * (x - WIDTH / 2);
		data->y_julia = (data->image.y_max - data->image.y_min)
			/ HEIGHT * (y - HEIGHT / 2);
	}
	return (0);
}
