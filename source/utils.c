/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:31:34 by flcristi          #+#    #+#             */
/*   Updated: 2023/04/25 12:05:40 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
