/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:19:56 by flcristi          #+#    #+#             */
/*   Updated: 2022/10/01 16:33:31 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	n1;
	size_t	n2;

	n1 = 0;
	n2 = 0;
	while (!s1 && !s2)
		return (NULL);
	ptr = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[n1])
	{
		ptr[n1] = s1[n1];
		n1++;
	}
	while (s2[n2])
	{
		ptr[n1] = s2 [n2];
		n2++;
		n1++;
	}
	ptr[n1] = '\0';
	return (ptr);
}
