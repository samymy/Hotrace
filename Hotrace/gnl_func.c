/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hlam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 11:10:51 by dlinkin           #+#    #+#             */
/*   Updated: 2017/12/03 11:10:52 by dlinkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = (char*)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *str;

	if (s1 && s2)
	{
		str = s1;
		while (*str)
			str++;
		while (*s2 && n)
		{
			*str++ = *s2++;
			n--;
		}
		*str = '\0';
	}
	return (s1);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	if (src && dst)
	{
		while (src[i] != '\0' && i < len)
		{
			dst[i] = src[i];
			i++;
		}
		while (i < len)
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (dst);
}

void	*ft_memalloc(size_t size)
{
	char *ptr;

	if (!size)
		return (NULL);
	ptr = (char *)malloc(size);
	if (!ptr)
		return (NULL);
	while (size > 0)
	{
		ptr[size - 1] = 0;
		size--;
	}
	return ((void *)ptr);
}
