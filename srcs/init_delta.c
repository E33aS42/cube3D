/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_delta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_delta(t_param *p)
{
	if (p->ray.raydiry == 0)
		p->ray.deltax = 0;
	else if (p->ray.raydirx == 0)
		p->ray.deltax = 1;
	else
		p->ray.deltax = fabs(1 / p->ray.raydirx);
	if (p->ray.raydirx == 0)
		p->ray.deltay = 0;
	else if (p->ray.raydiry == 0)
		p->ray.deltay = 1;
	else
		p->ray.deltay = fabs(1 / p->ray.raydiry);
}

void	init_stepside(t_param *p)
{
	if (p->ray.raydirx < 0)
	{
		p->ray.stepx = -1;
		p->ray.sidex = (p->ray.pl_posx - (double)p->ray.mapx) * p->ray.deltax;
	}
	else
	{
		p->ray.stepx = 1;
		p->ray.sidex = ((double)p->ray.mapx + 1.0 - p->ray.pl_posx)
				* p->ray.deltax;
	}
	if (p->ray.raydiry < 0)
	{
		p->ray.stepy = -1;
		p->ray.sidey = (p->ray.pl_posy - (double)p->ray.mapy) * p->ray.deltay;
	}
	else
	{
		p->ray.stepy = 1;
		p->ray.sidey = ((double)p->ray.mapy + 1.0 - p->ray.pl_posy)
				* p->ray.deltay;
	}
}

void	init_cub_prm2(t_param *p)
{
	p->ray.wall_hit = 0;
	p->ray.perpwalldist = 0;
	p->ray.camerax = 2 * p->ray.x / (double)p->screen_x - 1;
	p->ray.raydirx = p->player.dirx + p->player.planex * p->ray.camerax;
	p->ray.raydiry = p->player.diry + p->player.planey * p->ray.camerax;
	p->ray.mapx = (int)p->ray.pl_posx;
	p->ray.mapy = (int)p->ray.pl_posy;
	init_delta(p);
}
