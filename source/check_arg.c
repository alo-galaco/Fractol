/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:27:16 by flcristi          #+#    #+#             */
/*   Updated: 2023/04/29 12:32:26 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	message_help(void)
{
	ft_putendl_fd("\n=== Please, choose a fractol ===\n", 1);
	ft_putendl_fd("1. Maldelbrot\n", 1);
	ft_putendl_fd("2. Julia number1 number2\n", 1);
	ft_putendl_fd("The numbers need to be between -2.0 and 2.0\n", 1);
	ft_putendl_fd("Suggestion: -0.8 0.156 | -0.4 0.6 | 0.285 0\n", 1);
}

int	check_arg(int argc, char *argv[], t_data *data)
{
	if (argc == 2 && ft_strcmp("Mandelbrot", argv[1]) == 0)
	{
		data->fractol_set = 'm';
		return (1);
	}
	else if (argc == 4 && ft_strcmp("Julia", argv[1]) == 0
		&& ft_atof(argv[2]) >= -2 && ft_atof(argv[2]) <= 2
		&& ft_atof(argv[3]) >= -2 && ft_atof(argv[3]) <= 2)
	{
		data->fractol_set = 'j';
		data->x_julia = ft_atof(argv[2]);
		data->y_julia = ft_atof(argv[3]);
		return (1);
	}
	message_help();
	return (0);
}
