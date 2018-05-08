/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 08:33:41 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/02 08:33:44 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "hashtable.h"
#include "get_next_line.h"
#include "func.h"

static t_pair	*init_hashtable(int size)
{
	t_pair		*hashtable;

	if (!(hashtable = (t_pair *)malloc(sizeof(t_pair) * size)))
		return (0);
	while (--size >= 0)
	{
		hashtable[size].key = 0;
		hashtable[size].value = 0;
	}
	return (hashtable);
}

void			init(int size)
{
	g_hashtable = init_hashtable(size);
	g_hashtable_size = size;
}

static int		get_pair(char **key, char **value)
{
	char	*line;

	get_next_line(0, &line);
	if (!line)
		return (0);
	if (ft_strcmp(line, "") == 0)
	{
		free(line);
		return (0);
	}
	*key = ft_strdup(line);
	free(line);
	line = 0;
	get_next_line(0, &line);
	if (!line || ft_strcmp(line, "") == 0)
	{
		if (line)
			free(line);
		return (0);
	}
	*value = ft_strdup(line);
	free(line);
	return (1);
}

void			ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}

int				main(void)
{
	char	*key;
	char	*value;
	char	*line;

	init(5000000);
	while (get_pair(&key, &value))
		insert(key, value);
	while (get_next_line(0, &line) == 1)
	{
		value = search(line);
		if (!value)
		{
			ft_putstr(line);
			ft_putstr(" Not found.\n");
			free(line);
			continue ;
		}
		ft_putstr(value);
		write(1, "\n", 1);
		free(line);
	}
	free_hashtable();
	return (0);
}
