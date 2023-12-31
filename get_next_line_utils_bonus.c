/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:14:23 by yususato          #+#    #+#             */
/*   Updated: 2023/06/08 15:14:37 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	size_t			i;
	unsigned char	*s;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	p = (void *)malloc(count * size);
	if (!p)
		return (NULL);
		s = (unsigned char *)p;
		i = 0;
	while (i < count * size)
	{
		s[i] = 0;
		i++;
	}
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s2)
		return (NULL);
	if (!s1)
	new = (char *) ft_calloc((ft_strlen(s2) + 1), sizeof(char));
	else
	new = (char *) ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!new)
		return (NULL);
	if (!s1)
		ft_strlcpy(new, s2, ft_strlen(s2) + 2);
	else
	{
		ft_strlcpy(new, s1, ft_strlen(s1) + 1);
		ft_strlcpy(new + ft_strlen(s1), s2, ft_strlen(s2) + 2);
	}
	return (new);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < n && n > 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (n > 0)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}
