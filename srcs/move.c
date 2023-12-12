/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_back(t_param *p)
{
	int	i;
	int	j;

	if (p->data.mv_backward == 1)
	{
		i = (int)(p->ray.pl_posx - p->player.dirx * p->ray.movespeed);
		j = (int)p->ray.pl_posy;
		if (p->map[i][j] == '0')
			p->ray.pl_posx -= p->player.dirx * p->ray.movespeed;
		i = (int)p->ray.pl_posx;
		j = (int)(p->ray.pl_posy - p->player.diry * p->ray.movespeed);
		if (p->map[i][j] == '0')
			p->ray.pl_posy -= p->player.diry * p->ray.movespeed;
	}
}

void	move_for(t_param *p)
{
	int	i;
	int	j;

	if (p->data.mv_forward == 1)
	{
		i = (int)(p->ray.pl_posx + p->player.dirx * p->ray.movespeed);
		j = (int)p->ray.pl_posy;
		if (p->map[i][j] == '0')
			p->ray.pl_posx += p->player.dirx * p->ray.movespeed;
		i = (int)p->ray.pl_posx;
		j = (int)(p->ray.pl_posy + p->player.diry * p->ray.movespeed);
		if (p->map[i][j] == '0')
			p->ray.pl_posy += p->player.diry * p->ray.movespeed;
	}
}

void	move_left(t_param *p)
{
	int	i;
	int	j;

	if (p->data.mv_left == 1)
	{
		i = (int)(p->ray.pl_posx - p->player.diry * p->ray.movespeed);
		j = (int)p->ray.pl_posy;
		if (p->map[i][j] == '0')
			p->ray.pl_posx -= p->player.diry * p->ray.movespeed;
		i = (int)p->ray.pl_posx;
		j = (int)(p->ray.pl_posy + p->player.dirx * p->ray.movespeed);
		if (p->map[i][j] == '0')
			p->ray.pl_posy += p->player.dirx * p->ray.movespeed;
	}
}

void	move_right(t_param *p)
{
	int	i;
	int	j;

	if (p->data.mv_right == 1)
	{
		i = (int)(p->ray.pl_posx + p->player.diry * p->ray.movespeed);
		j = (int)p->ray.pl_posy;
		if (p->map[i][j] == '0')
			p->ray.pl_posx += p->player.diry * p->ray.movespeed;
		i = (int)p->ray.pl_posx;
		j = (int)(p->ray.pl_posy - p->player.dirx * p->ray.movespeed);
		if (p->map[i][j] == '0')
			p->ray.pl_posy -= p->player.dirx * p->ray.movespeed;
	}
}
