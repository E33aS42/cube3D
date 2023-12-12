/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		check_mapname(char *s)
{
	int		len;
	char	*cub;

	cub = ".cub";
	len = ft_strlen(s);
	if (ft_strlen(&s[len - 4]) == 4)
		return (ft_strcmp(&s[len - 4], cub));
	return (0);
}

void	init_map(t_param *p)
{
	int	i;

	i = 0;
	if (!(p->map = malloc(sizeof(char *) * (p->nb_line_map + 1))))
		ft_error2("Error\np->map malloc.\n", p);
	while (i < p->nb_line_map && p->error_found == 0)
	{
		if (!(p->map[i] = malloc(sizeof(char) * (p->nb_col_map + 1))))
			ft_error2("Error\np->map malloc.\n", p);
		i++;
	}
	p->map[i] = NULL;
}

char	**get_raw_map4(t_param *p, char **tmp, int it, int jt)
{
	if (p->map)
	{
		tmp = ft_tabdup(p->map, it, jt, p);
		free_tab(p->map);
	}
	return (tmp);
}

int		check_exists(t_param *p)
{
	if (p->exist_r == 1 && p->exist_f == 1 && p->exist_c == 1 &&
		p->exist_no == 1 && p->exist_so == 1 && p->exist_we == 1 &&
		p->exist_ea == 1 && p->exist_s == 1)
		return (1);
	return (0);
}

void	get_map(char *line, t_param *p)
{
	if (check_str_content(line, "012NEWS\n") == 1)
		ft_error2("Error\n Abnormal character found in map\n", p);
	if (p->error_found == 0)
		get_raw_map(line, p);
}
