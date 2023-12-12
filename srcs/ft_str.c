/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strstr(char *s1, char *s2)
{
	int	i1;
	int	i2;

	i1 = 0;
	while (s1[i1] != '\0')
	{
		i2 = 0;
		while (s2[i2] != '\0')
		{
			if (s1[i1] == s2[i2])
				return (i1);
			i2++;
		}
		i1++;
	}
	return (-1);
}

int	ft_strstr_cnt(char *s1, char *s2)
{
	int	i1;
	int	i2;
	int	cnt;

	i1 = 0;
	cnt = 0;
	while (s1[i1] != '\0')
	{
		i2 = 0;
		while (s2[i2] != '\0')
		{
			if (s1[i1] == s2[i2])
				cnt++;
			i2++;
		}
		i1++;
	}
	return (cnt);
}

int	check_str_content(char *s1, char *s2)
{
	char	c;

	c = 33;
	while (c <= 126)
	{
		if (ft_strchr(s1, c) > -1 && (ft_strchr(s2, c) == -1))
			return (1);
		c++;
	}
	return (0);
}
