/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:27:16 by flcristi          #+#    #+#             */
/*   Updated: 2023/04/21 16:16:18 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	message_help(void)
{
	ft_putendl_fd("Please, choose a fractol:", 1);
	ft_putendl_fd("Maldelbrot", 1);
	ft_putendl_fd("Julia", 1);
}

int	check_arg(int argc, char *argv[], t_data *data)
{
	if (argc == 2 && ft_strncmp("Mandelbrot", argv[1], 10) == 0)
	{
		data->fractol_set = 'm';
		return (1);
	}
	else if (argc == 2 && ft_strncmp("Julia", argv[1], 5) == 0)
		return (1);
	return (0);
}
