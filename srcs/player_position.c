/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_player_position2(t_param *p, int i, int index)
{
	p->player.exist_dir = p->map[i][index];
	p->player.posx = i;
	p->player.posy = index;
	p->player.start_dir = p->map[i][index];
	p->map[i][index] = '0';
}

void	get_player_position(t_param *p)
{
	int	i;
	int	index;
	int	cnt;

	i = 0;
	index = -1;
	while (p->map[i])
	{
		index = ft_strstr(p->map[i], "NSEW");
		cnt = ft_strstr_cnt(p->map[i], "NSEW");
		if (cnt > 1)
			ft_error("Error\n More than one player position \
on the map.\n", p);
		if (index != -1)
		{
			if (p->player.exist_dir != 0)
				ft_error("Error\n More than one player \
position on the map.\n", p);
			get_player_position2(p, i, index);
		}
		i++;
	}
	if (p->player.exist_dir == 0)
		ft_error("Error\n No initial player position found.\n", p);
}

char	**check_pl_pos2(int x, int y, t_param *p, char **tmp)
{
	tmp[x][y] = 'P';
	p->cnt_cells++;
	check_pl_pos(x + 1, y, p, tmp);
	check_pl_pos(x, y + 1, p, tmp);
	check_pl_pos(x - 1, y, p, tmp);
	check_pl_pos(x, y - 1, p, tmp);
	check_pl_pos(x + 1, y + 1, p, tmp);
	check_pl_pos(x - 1, y + 1, p, tmp);
	check_pl_pos(x - 1, y - 1, p, tmp);
	check_pl_pos(x + 1, y - 1, p, tmp);
	return (tmp);
}

void	check_pl_pos(int x, int y, t_param *p, char **tmp)
{
	if (tmp[x][y] == '1' || tmp[x][y] == 'P')
		return ;
	if (tmp[x][y] == '4')
	{
		free_tab(tmp);
		ft_error("Error\n This map has holes.\n", p);
	}
	if ((tmp[x][y] == '0' || tmp[x][y] == '2') && (x == 0 || y == 0 ||\
		x == p->nb_line_map - 1 || y == p->nb_col_map - 1))
	{
		free_tab(tmp);
		ft_error("Error\n This map has holes.\n", p);
	}
	if (tmp[x][y] == '0' || tmp[x][y] == '2')
		tmp = check_pl_pos2(x, y, p, tmp);
}

void	check_map(t_param *p)
{
	char	**tmp;

	get_player_position(p);
	tmp = ft_tabdup(p->map, p->nb_line_map, p->nb_col_map, p);
	check_pl_pos(p->player.posx, p->player.posy, p, tmp);
	free_tab(tmp);
}
