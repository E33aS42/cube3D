/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_text_addr(t_param *p)
{
	p->t_no.t_addr = (int *)mlx_get_data_addr(p->t_no.t_img, &(p->t_no.t_bpp),
			&(p->t_no.t_sizeline), &(p->t_no.t_endian));
	if (!(p->t_no.t_addr))
		ft_error("Error\n Problem with NORTH texture address.\n", p);
	p->t_so.t_addr = (int *)mlx_get_data_addr(p->t_so.t_img, &(p->t_so.t_bpp),
			&(p->t_so.t_sizeline), &(p->t_so.t_endian));
	if (!(p->t_so.t_addr))
		ft_error("Error\n Problem with SOUTH texture address.\n", p);
	p->t_we.t_addr = (int *)mlx_get_data_addr(p->t_we.t_img, &(p->t_we.t_bpp),
			&(p->t_we.t_sizeline), &(p->t_we.t_endian));
	if (!(p->t_we.t_addr))
		ft_error("Error\n Problem with WEST texture address.\n", p);
	p->t_ea.t_addr = (int *)mlx_get_data_addr(p->t_ea.t_img, &(p->t_ea.t_bpp),
			&(p->t_ea.t_sizeline), &(p->t_ea.t_endian));
	if (!(p->t_ea.t_addr))
		ft_error("Error\n Problem with EAST texture address.\n", p);
}

void	get_textures(t_param *p)
{
	p->t_no.t_img = mlx_xpm_file_to_image(p->data.mlx_ptr, p->t_no.t_path,
		&(p->t_no.t_width),
			&(p->t_no.t_height));
	if (!(p->t_no.t_img))
		ft_error("Error\n Problem with NORTH texture.\n", p);
	p->t_so.t_img = mlx_xpm_file_to_image(p->data.mlx_ptr, p->t_so.t_path,
		&(p->t_so.t_width),
			&(p->t_so.t_height));
	if (!(p->t_so.t_img))
		ft_error("Error\n Problem with SOUTH texture.\n", p);
	p->t_we.t_img = mlx_xpm_file_to_image(p->data.mlx_ptr, p->t_we.t_path,
		&(p->t_we.t_width),
			&(p->t_we.t_height));
	if (!(p->t_we.t_img))
		ft_error("Error\n Problem with WEST texture.\n", p);
	p->t_ea.t_img = mlx_xpm_file_to_image(p->data.mlx_ptr, p->t_ea.t_path,
		&(p->t_ea.t_width),
			&(p->t_ea.t_height));
	if (!(p->t_ea.t_img))
		ft_error("Error\n Problem with EAST texture.\n", p);
	get_text_addr(p);
}

void	init_texture(t_param *p)
{
	if (p->ray.sidewall_hit == 0 && p->ray.raydirx < 0)
		p->txt.t_dir = 0;
	if (p->ray.sidewall_hit == 0 && p->ray.raydirx >= 0)
		p->txt.t_dir = 1;
	if (p->ray.sidewall_hit == 1 && p->ray.raydiry < 0)
		p->txt.t_dir = 2;
	if (p->ray.sidewall_hit == 1 && p->ray.raydiry >= 0)
		p->txt.t_dir = 3;
	if (p->ray.sidewall_hit == 0)
		p->txt.wall_x = p->ray.pl_posy + p->ray.perpwalldist \
						* p->ray.raydiry;
	else
		p->txt.wall_x = p->ray.pl_posx + p->ray.perpwalldist \
						* p->ray.raydirx;
	p->txt.wall_x -= floor((p->txt.wall_x));
	p->txt.t_x = (int)(p->txt.wall_x * (double)p->t_no.t_width);
	if ((p->ray.sidewall_hit == 0 && p->ray.raydirx > 0) ||
		(p->ray.sidewall_hit == 1 && p->ray.raydiry < 0))
		p->txt.t_x = p->t_no.t_width - p->txt.t_x - 1;
	p->txt.t_step = 1.0 * p->t_no.t_height / p->ray.lineheight;
	p->txt.t_pos = (p->ray.drawstart - p->screen_y / 2 +
			p->ray.lineheight / 2) * p->txt.t_step;
}

void	draw_textures2(t_param *p, int x, int y)
{
	int	i;

	i = y * p->data.sizeline / 4 + x;
	if (p->txt.t_dir == 0)
		p->data.img_data_addr[i] = p->t_no.t_addr[p->txt.t_y *
		p->t_no.t_sizeline / 4 + p->txt.t_x];
	if (p->txt.t_dir == 1)
		p->data.img_data_addr[i] = p->t_so.t_addr[p->txt.t_y *
		p->t_so.t_sizeline / 4 + p->txt.t_x];
	if (p->txt.t_dir == 2)
		p->data.img_data_addr[i] = p->t_we.t_addr[p->txt.t_y *
		p->t_we.t_sizeline / 4 + p->txt.t_x];
	if (p->txt.t_dir == 3)
		p->data.img_data_addr[i] = p->t_ea.t_addr[p->txt.t_y *
		p->t_ea.t_sizeline / 4 + p->txt.t_x];
}

void	draw_textures(t_param *p, int x)
{
	int	y;

	init_texture(p);
	y = p->ray.drawstart;
	while (y <= p->ray.drawend)
	{
		p->txt.t_y = (int)p->txt.t_pos & (p->t_no.t_height - 1);
		p->txt.t_pos += p->txt.t_step;
		if (y < p->screen_y && x < p->screen_x)
			draw_textures2(p, x, y);
		y++;
	}
}
