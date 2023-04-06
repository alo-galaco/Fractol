/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:20:32 by flcristi          #+#    #+#             */
/*   Updated: 2022/10/05 00:13:54 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		len = 0;
		start = ft_strlen(s);
	}
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ptr = (char *) malloc (len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy (ptr, s + start, len + 1);
	return (ptr);
}
