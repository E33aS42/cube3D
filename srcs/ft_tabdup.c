/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**ft_tabdup2(char **res, char **s, int i_max, int j_max)
{
	int	i;
	int	j;

	i = 0;
	while (i < i_max)
	{
		j = 0;
		while (j < j_max)
		{
			res[i][j] = s[i][j];
			j++;
		}
		res[i][j] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_tabdup(char **s, int i_max, int j_max, t_param *p)
{
	int		i;
	char	**res;

	i = 0;
	res = NULL;
	if (!(res = (char**)malloc(sizeof(char*) * (i_max + 1))))
		ft_error2("Error\ntabdup malloc.\n", p);
	while (i < i_max && p->error_found == 0)
	{
		if (!(res[i] = (char*)malloc(sizeof(char*) * (j_max + 1))))
			ft_error2("Error\ntabdup malloc.\n", p);
		i++;
	}
	if (p->error_found == 0)
		res = ft_tabdup2(res, s, i_max, j_max);
	return (res);
}
