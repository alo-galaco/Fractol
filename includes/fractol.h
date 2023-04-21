/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:52:53 by flcristi          #+#    #+#             */
/*   Updated: 2023/04/21 15:54:33 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define MAX_INTER 50
# define CX_MAX 2
# define CX_MIN -2
# define CY_MAX 2
# define CY_MIN -2
# define ESC 65307
# define Q 113

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_image
{
	void		*new_image;
	char		*address;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
}				t_image;

typedef struct s_data
{
	void		*ptr;
	void		*window;
	t_image		image;
	int			color;
	char		fractol_set;
	double		x_julia;
	double		y_julia;
	char		julia_set_image;
}				t_data;

int		start_window(t_data *data);
void	the_image(t_data *data);
void	mandelbrot(t_data *data);
int		key_press(int keysim, t_data *data);
void	image_pixel_put(t_image *image, int x, int y, int color);
int		close_program(t_data	*data);
int		start_image(t_data	*data);
int		check_arg(int argc, char *argv[], t_data *data);
void	message_help(void);
void	julia(t_data *data);
int		mouse_zoom(int	keysim, int	x, int	y, t_data	*data);

#endif