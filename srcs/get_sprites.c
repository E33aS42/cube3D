/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	sort_sprites(t_param *p)
{
	int		k;
	double	tmp;

	k = 0;
	while (k < p->sprite.s_cnt - 1)
	{
		if (p->sprite.s_distsq[k] < p->sprite.s_distsq[k + 1])
		{
			tmp = p->sprite.s_distsq[k];
			p->sprite.s_distsq[k] = p->sprite.s_distsq[k + 1];
			p->sprite.s_distsq[k + 1] = tmp;
			tmp = p->sprite.s_order[k];
			p->sprite.s_order[k] = p->sprite.s_order[k + 1];
			p->sprite.s_order[k + 1] = (int)tmp;
			k = -1;
		}
		k++;
	}
}

void	get_sprites(t_param *p)
{
	int	k;

	k = 0;
	while (k < p->sprite.s_cnt)
	{
		p->sprite.s_order[k] = k;
		p->sprite.s_distsq[k] = (p->ray.pl_posx - p->sprite.s_posx[k])
					* (p->ray.pl_posx - p->sprite.s_posx[k])
					+ (p->ray.pl_posy - p->sprite.s_posy[k])
					* (p->ray.pl_posy - p->sprite.s_posy[k]);
		k++;
	}
	sort_sprites(p);
	draw_sprites(p);
}
