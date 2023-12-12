/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_prm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_move(t_param *p)
{
	p->data.mv_forward = 0;
	p->data.mv_backward = 0;
	p->data.mv_left = 0;
	p->data.mv_right = 0;
	p->data.rotate_left = 0;
	p->data.rotate_right = 0;
}

void	init_cub_prm(t_param *p)
{
	init_dir(p);
	p->ray.pl_posx = (double)p->player.posx + 0.5;
	p->ray.pl_posy = (double)p->player.posy + 0.5;
	p->ray.movespeed = 0.05;
	p->ray.rotspeed = 0.02;
	init_move(p);
}
