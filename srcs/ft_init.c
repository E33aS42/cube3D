/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_3(t_param *p)
{
	p->data.win_ptr = NULL;
	p->data.img_ptr = NULL;
	p->sprite.s_path = NULL;
	p->sprite.s_posx = NULL;
	p->sprite.s_posy = NULL;
	p->sprite.s_img = NULL;
	p->sprite.s_addr = NULL;
	p->sprite.s_cnt = 0;
	p->sprite.zbuffer = NULL;
	p->sprite.s_order = NULL;
	p->sprite.s_distsq = NULL;
}

void	ft_init_2(t_param *p)
{
	p->exist_r = 0;
	p->exist_f = 0;
	p->exist_c = 0;
	p->exist_no = 0;
	p->exist_so = 0;
	p->exist_we = 0;
	p->exist_ea = 0;
	p->exist_s = 0;
	p->player.exist_dir = 0;
	p->player.posx = 0;
	p->player.posy = 0;
	p->cnt_cells = 0;
	p->t_no.t_img = NULL;
	p->t_so.t_img = NULL;
	p->t_we.t_img = NULL;
	p->t_ea.t_img = NULL;
	ft_init_3(p);
}

void	ft_init(t_param *p)
{
	p->screen_x = 0;
	p->screen_y = 0;
	p->i = 0;
	p->first = 0;
	p->error_found = 0;
	p->exist = 0;
	p->empty_lines = 0;
	p->t_no.t_path = NULL;
	p->t_so.t_path = NULL;
	p->t_we.t_path = NULL;
	p->t_ea.t_path = NULL;
	p->fl.f_red = -1;
	p->fl.f_green = -1;
	p->fl.f_blue = -1;
	p->cl.c_red = -1;
	p->cl.c_green = -1;
	p->cl.c_green = -1;
	p->nb_line_map = 0;
	p->nb_col_map = 0;
	p->map = NULL;
	p->save = 0;
	ft_init_2(p);
}

void	init_dir2(t_param *p)
{
	if (p->player.start_dir == 'E')
	{
		p->player.dirx = 0;
		p->player.diry = 1;
		p->player.planex = 0.66;
		p->player.planey = 0;
	}
	else if (p->player.start_dir == 'W')
	{
		p->player.dirx = 0;
		p->player.diry = -1;
		p->player.planex = -0.66;
		p->player.planey = 0;
	}
}

void	init_dir(t_param *p)
{
	if (p->player.start_dir == 'N')
	{
		p->player.dirx = -1;
		p->player.diry = 0;
		p->player.planex = 0;
		p->player.planey = 0.66;
	}
	else if (p->player.start_dir == 'S')
	{
		p->player.dirx = 1;
		p->player.diry = 0;
		p->player.planex = 0;
		p->player.planey = -0.66;
	}
	else
		init_dir2(p);
}
