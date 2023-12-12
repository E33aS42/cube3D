/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		get_raw_map3(t_param *p, char **tmp, int i, int j)
{
	if (tmp[i][j])
		p->map[i][j] = tmp[i][j];
	j++;
	return (j);
}

void	get_raw_map5(t_param *p, int i, int j)
{
	while (j < p->nb_col_map)
		p->map[i][j++] = '4';
	p->map[i][j] = '\0';
}

int		get_raw_map2(t_param *p, char **tmp, int len)
{
	int	it;
	int	jt;
	int	i;
	int	j;

	i = 0;
	j = 0;
	it = p->nb_line_map;
	jt = p->nb_col_map;
	tmp = get_raw_map4(p, tmp, it, jt);
	if (p->nb_col_map < len)
		p->nb_col_map = len;
	p->nb_line_map++;
	init_map(p);
	while (i < it)
	{
		while (j < jt)
			j = get_raw_map3(p, tmp, i, j);
		get_raw_map5(p, i, j);
		j = 0;
		i++;
	}
	if (tmp)
		free_tab(tmp);
	return (i);
}

void	get_raw_map1(char *line, t_param *p, int i)
{
	int	j;

	j = 0;
	while (line[j] != '\0')
	{
		if (line[j] == ' ')
			p->map[i][j] = '0';
		else
			p->map[i][j] = line[j];
		j++;
	}
	while (j < p->nb_col_map)
		p->map[i][j++] = '0';
	p->map[i][j] = '\0';
	i++;
	p->map[i] = NULL;
}

void	get_raw_map(char *line, t_param *p)
{
	char	**tmp;
	int		len;
	int		i;

	if (ft_strchr(line, '\t') > -1)
		ft_error2("Error\n Please, do not use a map with tabs.\n", p);
	if (p->error_found == 0)
	{
		len = ft_strlen(line);
		tmp = NULL;
		p->empty_lines = 1;
		if (p->empty_lines == 1)
		{
			i = get_raw_map2(p, tmp, len);
			get_raw_map1(line, p, i);
		}
	}
}
