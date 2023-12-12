/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_keys_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		key_press(int keycode, t_param *p)
{
	if (keycode == FORWARD_W)
		p->data.mv_forward = 1;
	if (keycode == BACKWARD_S)
		p->data.mv_backward = 1;
	if (keycode == MOVE_LEFT_A)
		p->data.mv_left = 1;
	if (keycode == MOVE_RIGHT_D)
		p->data.mv_right = 1;
	if (keycode == ROTATE_LEFT)
		p->data.rotate_left = 1;
	if (keycode == ROTATE_RIGHT)
		p->data.rotate_right = 1;
	else if (keycode == ESC_KEY)
		ft_error("Exit game.\n", p);
	return (1);
}

int		key_release(int keycode, t_param *p)
{
	if (keycode == FORWARD_W)
		p->data.mv_forward = 0;
	if (keycode == BACKWARD_S)
		p->data.mv_backward = 0;
	if (keycode == MOVE_LEFT_A)
		p->data.mv_left = 0;
	if (keycode == MOVE_RIGHT_D)
		p->data.mv_right = 0;
	if (keycode == ROTATE_LEFT)
		p->data.rotate_left = 0;
	if (keycode == ROTATE_RIGHT)
		p->data.rotate_right = 0;
	return (1);
}

void	rotate_left(t_param *p)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = p->player.dirx;
	old_planex = p->player.planex;
	if (p->data.rotate_left == 1)
	{
		p->player.dirx = p->player.dirx * cos(p->ray.rotspeed)
				- p->player.diry * sin(p->ray.rotspeed);
		p->player.diry = old_dirx * sin(p->ray.rotspeed)
				+ p->player.diry * cos(p->ray.rotspeed);
		p->player.planex = p->player.planex * cos(p->ray.rotspeed)
				- p->player.planey * sin(p->ray.rotspeed);
		p->player.planey = old_planex * sin(p->ray.rotspeed)
				+ p->player.planey * cos(p->ray.rotspeed);
	}
}

void	rotate_right(t_param *p)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = p->player.dirx;
	old_planex = p->player.planex;
	if (p->data.rotate_right == 1)
	{
		p->player.dirx = p->player.dirx * cos(-p->ray.rotspeed)
				- p->player.diry * sin(-p->ray.rotspeed);
		p->player.diry = old_dirx * sin(-p->ray.rotspeed)
				+ p->player.diry * cos(-p->ray.rotspeed);
		p->player.planex = p->player.planex * cos(-p->ray.rotspeed)
				- p->player.planey * sin(-p->ray.rotspeed);
		p->player.planey = old_planex * sin(-p->ray.rotspeed)
				+ p->player.planey * cos(-p->ray.rotspeed);
	}
}

void	read_keys(t_param *p)
{
	move_for(p);
	move_back(p);
	move_left(p);
	move_right(p);
	rotate_left(p);
	rotate_right(p);
}
