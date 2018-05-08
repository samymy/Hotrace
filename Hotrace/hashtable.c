/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 08:50:19 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/02 08:50:21 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

void			free_hashtable(void)
{
	int		idx;

	idx = 0;
	while (idx < g_hashtable_size)
	{
		if (g_hashtable[idx].key)
		{
			free(g_hashtable[idx].key);
			free(g_hashtable[idx].value);
		}
		idx++;
	}
	free(g_hashtable);
	g_hashtable = 0;
	g_hashtable_size = 0;
}

static void		resize_hashtable(int size)
{
	t_pair	*tmp_hashtable;
	int		tmp_size;
	int		idx;

	tmp_hashtable = g_hashtable;
	tmp_size = g_hashtable_size;
	init(size);
	idx = 0;
	while (idx < tmp_size)
	{
		if (tmp_hashtable[idx].key)
			insert(tmp_hashtable[idx].key, tmp_hashtable[idx].value);
		idx++;
	}
	free(tmp_hashtable);
}

static int		get_hashcode(char *key)
{
	int			hashcode;
	unsigned	idx;

	hashcode = 0;
	idx = 0;
	while (key[idx] != '\0')
	{
		hashcode = hashcode << 8;
		hashcode += key[idx];
		idx++;
	}
	hashcode %= g_hashtable_size;
	return (hashcode);
}

void			insert(char *key, char *value)
{
	int		hashcode;

	hashcode = get_hashcode(key);
	if (!g_hashtable[hashcode].key)
	{
		g_hashtable[hashcode].key = key;
		g_hashtable[hashcode].value = value;
		return ;
	}
	while (g_hashtable[hashcode].key && hashcode < g_hashtable_size)
		hashcode++;
	if (hashcode >= g_hashtable_size)
	{
		resize_hashtable(g_hashtable_size * 5);
		insert(key, value);
		return ;
	}
	g_hashtable[hashcode].key = key;
	g_hashtable[hashcode].value = value;
}

char			*search(char *key)
{
	int		hashcode;

	hashcode = get_hashcode(key);
	while (g_hashtable[hashcode].key != 0 && hashcode < g_hashtable_size)
	{
		if (ft_strcmp(key, g_hashtable[hashcode].key) == 0)
			return (g_hashtable[hashcode].value);
		hashcode++;
	}
	return (0);
}
