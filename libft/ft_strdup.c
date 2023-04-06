/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:14:20 by flcristi          #+#    #+#             */
/*   Updated: 2022/09/19 22:49:25 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;

	i = ft_strlen(s);
	ptr = malloc(i + 1);
	ft_memcpy(ptr, s, i);
	ptr[i] = '\0';
	return (ptr);
	if (s == NULL)
		return (NULL);
}
