/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 08:50:12 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/02 08:50:14 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include <stdlib.h>
# include "func.h"

typedef struct		s_pair
{
	char	*key;
	char	*value;
}					t_pair;

t_pair				*g_hashtable;
int					g_hashtable_size;

void				init(int size);
void				insert(char *key, char *value);
char				*search(char *key);
void				free_hashtable(void);

#endif
