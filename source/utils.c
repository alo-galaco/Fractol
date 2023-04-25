/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:31:34 by flcristi          #+#    #+#             */
/*   Updated: 2023/04/25 15:23:00 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	the_image(t_data *data)
{
	data->image.x_max = CX_MAX;
	data->image.x_min = CX_MIN;
	data->image.y_max = CY_MAX;
	data->image.y_min = CY_MIN;
	data->color = 0xFFFF00;
	data->julia_color = 0xFF0000;
	data->julia_set_image = 0;
	start_image(data);
}

long double	ft_atof(const char *nptr)
{
	short int		signal;
	long double		num;
	long double		decimal;

	num = 0;
	signal = (*nptr == '+' || ft_isdigit(*nptr)) - (*nptr == '-');
	nptr += (*nptr == '+' || *nptr == '-');
	while (ft_isdigit(*nptr))
		num = (num * 10) + (*nptr++ - '0');
	nptr += (*nptr == '.');
	decimal = 0.1;
	while (ft_isdigit(*nptr))
	{
		num += (*nptr++ - '0') * decimal;
		decimal /= 10;
	}
	return (num * signal);
}
