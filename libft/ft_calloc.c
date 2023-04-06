/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 01:20:10 by flcristi          #+#    #+#             */
/*   Updated: 2022/09/27 19:51:12 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	i;
	void	*ptr;

	if (nitems == 0 || size == 0 || nitems >= 2147483647 / size)
		return (NULL);
	i = nitems * size;
	ptr = malloc(i);
	if (ptr)
		ft_bzero(ptr, i);
	return (ptr);
}
