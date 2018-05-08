/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 08:14:44 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/02 08:14:47 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

size_t	ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	if (!s)
		return (0);
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strdup(const char *s1)
{
	char	*src_cpy;
	char	*temp;

	src_cpy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (src_cpy == NULL)
		return (NULL);
	temp = src_cpy;
	while (*s1 != '\0')
		*temp++ = *s1++;
	*temp = '\0';
	return (src_cpy);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*ft_strcat(char *s1, const char *s2)
{
	char *cpy;

	cpy = s1;
	while (*cpy != '\0')
		cpy++;
	while (*s2 != '\0')
	{
		*cpy++ = *s2++;
	}
	*cpy = '\0';
	return (s1);
}

char	*ft_strchr(const char *s)
{
	while (*s != '\0' && *s != '\n')
	{
		s++;
	}
	if (*s == '\n')
		return ((char *)s);
	return (NULL);
}
