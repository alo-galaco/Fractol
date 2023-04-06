/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:22:08 by coder             #+#    #+#             */
/*   Updated: 2022/09/19 22:48:06 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ptr;

	ptr = c;
	while (*s != ptr)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
