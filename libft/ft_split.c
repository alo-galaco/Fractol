/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:19:11 by flcristi          #+#    #+#             */
/*   Updated: 2022/10/12 23:12:41 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_countwords(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c)
			|| (s[i] != c && s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**free_array(char	**str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i++]);
	}
	free (str);
	return (NULL);
}

char	**worker(char const *s, char c)
{
	char	**str;
	int		i;
	size_t	len;

	str = (char **) malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			str[i++] = ft_substr(s, 0, len);
			s += len;
		}
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	size_a;
	size_t	i;

	array = worker(s, c);
	size_a = 0;
	while (array[size_a] != NULL)
	{
		size_a++;
	}
	i = 0;
	if (size_a != ft_countwords(s, c))
	{
		free_array(array);
	}
	return (array);
}
