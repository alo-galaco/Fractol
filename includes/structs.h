#ifndef STRUCTS_H
#define STRUCTS_H

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
    t_image 	image;
	int			color;

}				t_data;

#endif