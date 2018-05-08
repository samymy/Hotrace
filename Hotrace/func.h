/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 08:14:39 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/02 08:14:41 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *s);

#endif
