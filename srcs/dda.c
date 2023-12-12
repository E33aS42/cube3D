/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	dda_algo(t_param *p)
{
	while (p->ray.wall_hit == 0)
	{
		if (p->ray.sidex < p->ray.sidey)
		{
			p->ray.sidex += p->ray.deltax;
			p->ray.mapx += p->ray.stepx;
			p->ray.sidewall_hit = 0;
		}
		else
		{
			p->ray.sidey += p->ray.deltay;
			p->ray.mapy += p->ray.stepy;
			p->ray.sidewall_hit = 1;
		}
		if (p->ray.mapx < 0)
			p->ray.mapx = 0;
		if (p->ray.mapy < 0)
			p->ray.mapy = 0;
		if (p->map[p->ray.mapx][p->ray.mapy] == '1')
			p->ray.wall_hit = 1;
	}
}

void	calc_proj_dist(t_param *p)
{
	if (p->ray.sidewall_hit == 0)
		p->ray.perpwalldist = ((double)p->ray.mapx - p->ray.pl_posx
		+ (1.0 - (double)p->ray.stepx) / 2) / p->ray.raydirx;
	else
		p->ray.perpwalldist = ((double)p->ray.mapy - p->ray.pl_posy
		+ (1.0 - (double)p->ray.stepy) / 2) / p->ray.raydiry;
}

void	calc_pixels_bound(t_param *p)
{
	p->ray.lineheight = (int)(p->screen_y / p->ray.perpwalldist);
	p->ray.drawstart = -p->ray.lineheight / 2 + p->screen_y / 2;
	if (p->ray.drawstart < 0)
		p->ray.drawstart = 0;
	p->ray.drawend = p->ray.lineheight / 2 + p->screen_y / 2;
	if (p->ray.drawend >= p->screen_y)
		p->ray.drawend = p->screen_y - 1;
}

void	calc_raydist(t_param *p)
{
	init_cub_prm2(p);
	init_stepside(p);
	dda_algo(p);
	calc_proj_dist(p);
	calc_pixels_bound(p);
}

void	draw_ceil_text_floor(t_param *p)
{
	int	y;
	int	k;

	p->ray.drawend = p->screen_y - p->ray.drawstart;
	y = 0;
	while (y < p->ray.drawstart)
	{
		k = y * p->data.sizeline / 4 + p->ray.x;
		p->data.img_data_addr[k] = calc_rgb(p->cl.c_red, p->cl.c_green,
					p->cl.c_blue);
		y++;
	}
	if (y <= p->ray.drawend)
		draw_textures(p, p->ray.x);
	y = p->ray.drawend + 1;
	while (y < p->screen_y)
	{
		k = y * p->data.sizeline / 4 + p->ray.x;
		p->data.img_data_addr[k] = calc_rgb(p->fl.f_red, p->fl.f_green,
					p->fl.f_blue);
		y++;
	}
}
