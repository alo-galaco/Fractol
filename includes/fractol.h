/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:52:53 by flcristi          #+#    #+#             */
/*   Updated: 2023/04/25 15:26:57 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 950
# define HEIGHT 950
# define MAX_INTER 70
# define CX_MAX 2
# define CX_MIN -2
# define CY_MAX 2
# define CY_MIN -2
# define ESC 65307
# define Q 113
# define R 114
# define SPACE 32

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
	int			julia_color;
	int			julia_set_image;
	double		x_julia;
	double		y_julia;
}				t_data;

void		the_image(t_data *data);
void		mandelbrot(t_data *data);
void		julia(t_data *data);
void		message_help(void);
void		image_pixel_put(t_image *image, int x, int y, int color);
int			start_window(t_data *data);
int			close_program(t_data	*data);
int			start_image(t_data	*data);
int			check_arg(int argc, char *argv[], t_data *data);
int			key_press(int keysim, t_data *data);
int			mouse_zoom(int keysim, int x, int y, t_data *data);
int			julia_mouse(int x, int y, t_data *data);
long double	ft_atof(const char *nptr);

#endif