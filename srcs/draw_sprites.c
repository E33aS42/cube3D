/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_sprites4(t_param *p)
{
	int	d;
	int	y;
	int	m;
	int	n;

	y = p->sprite.drawstarty;
	while (y < p->sprite.drawendy)
	{
		d = y * 256 - p->screen_y * 128 + p->sprite.height * 128;
		p->sprite.texy = ((d * p->sprite.s_height) / p->sprite.height) / 256;
		m = y * p->data.sizeline / 4 + p->sprite.stripe;
		n = p->sprite.texy * p->sprite.s_sizeline / 4 + p->sprite.texx;
		if (n > 0)
		{
			if ((p->sprite.s_addr[n] & 0xFFFFFF) != 0)
				p->data.img_data_addr[m] = p->sprite.s_addr[n];
		}
		y++;
	}
}

void	draw_sprites3(t_param *p)
{
	while (p->sprite.stripe < p->sprite.drawendx)
	{
		p->sprite.texx = (int)(256 * (p->sprite.stripe - (-p->sprite.width / 2 +
			p->sprite.s_screenx)) * p->sprite.s_width
			/ p->sprite.width) / 256;
		if (p->sprite.transfy > 0 && p->sprite.stripe > 0
			&& p->sprite.stripe < p->screen_x
			&& p->sprite.transfy < (float)p->sprite.zbuffer[p->sprite.stripe])
			draw_sprites4(p);
		p->sprite.stripe++;
	}
}

void	draw_sprites2(t_param *p, int k)
{
	p->sprite.s_x = p->sprite.s_posx[p->sprite.s_order[k]] - p->ray.pl_posx;
	p->sprite.s_y = p->sprite.s_posy[p->sprite.s_order[k]] - p->ray.pl_posy;
	p->sprite.invdet = 1 / (p->player.planex * p->player.diry
				- p->player.dirx * p->player.planey);
	p->sprite.transfx = p->sprite.invdet * (p->player.diry * p->sprite.s_x
				- p->player.dirx * p->sprite.s_y);
	p->sprite.transfy = p->sprite.invdet * (-p->player.planey * p->sprite.s_x
				+ p->player.planex * p->sprite.s_y);
	p->sprite.s_screenx = (int)((p->screen_x / 2) *
				(1 + p->sprite.transfx / p->sprite.transfy));
	p->sprite.height = abs((int)(p->screen_y / (p->sprite.transfy)));
	p->sprite.drawstarty = -p->sprite.height / 2 + p->screen_y / 2;
	if (p->sprite.drawstarty < 0)
		p->sprite.drawstarty = 0;
}

void	draw_sprites(t_param *p)
{
	int	k;

	k = 0;
	while (k < p->sprite.s_cnt)
	{
		draw_sprites2(p, k);
		p->sprite.drawendy = p->sprite.height / 2 + p->screen_y / 2;
		if (p->sprite.drawendy >= p->screen_y)
			p->sprite.drawendy = p->screen_y - 1;
		p->sprite.width = abs((int)(p->screen_y / (p->sprite.transfy)));
		p->sprite.drawstartx = -p->sprite.width / 2 + p->sprite.s_screenx;
		if (p->sprite.drawstartx < 0)
			p->sprite.drawstartx = 0;
		p->sprite.drawendx = p->sprite.width / 2 + p->sprite.s_screenx;
		if (p->sprite.drawendx >= p->screen_x)
			p->sprite.drawendx = p->screen_x - 1;
		p->sprite.stripe = p->sprite.drawstartx;
		draw_sprites3(p);
		k++;
	}
}
