/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	find_sprites(t_param *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < p->nb_line_map)
	{
		while (j < p->nb_col_map)
		{
			if (p->map[i][j] == '2')
				p->sprite.s_cnt++;
			j++;
		}
		j = 0;
		i++;
	}
	if (p->sprite.s_cnt == 0)
		write(1, "The map does not contain any sprite\n", 36);
}

void	get_sprite_position2(t_param *p, int i, int j, int k)
{
	while (i < p->nb_line_map && p->error_found == 0)
	{
		while (j < p->nb_col_map)
		{
			if (p->map[i][j] == '2')
			{
				p->sprite.s_posx[k] = i + 0.5;
				p->sprite.s_posy[k] = j + 0.5;
				k++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	get_sprite_position(t_param *p)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	find_sprites(p);
	if (!(p->sprite.s_posx = (double *)malloc(sizeof(double)
					* (p->sprite.s_cnt))))
		ft_error2("Error\ns_posx malloc.\n", p);
	if (!(p->sprite.s_posy = (double *)malloc(sizeof(double)
					* (p->sprite.s_cnt))))
		ft_error2("Error\ns_posy malloc.\n", p);
	get_sprite_position2(p, i, j, k);
}

void	ft_init_spr(t_param *p)
{
	if (!(p->sprite.zbuffer = (double *)malloc(sizeof(double) * p->screen_x)))
		ft_error("Error\nzbuffer malloc.\n", p);
	if (!(p->sprite.s_order = (int *)malloc(sizeof(int) * p->sprite.s_cnt)))
		ft_error("Error\nsprite order malloc.\n", p);
	if (!(p->sprite.s_distsq = (double *)malloc(sizeof(double)
					* p->sprite.s_cnt)))
		ft_error("Error\nsprite distance malloc.\n", p);
	p->sprite.s_img = mlx_xpm_file_to_image(p->data.mlx_ptr,
				p->sprite.s_path, &(p->sprite.s_width),
			&(p->sprite.s_height));
	if (!(p->sprite.s_img))
		ft_error("Error\n Problem with Sprite.\n", p);
	p->sprite.s_addr = (int *)mlx_get_data_addr(p->sprite.s_img,
		&(p->sprite.s_bpp), &(p->sprite.s_sizeline), &(p->sprite.s_endian));
	if (!(p->sprite.s_addr))
		ft_error("Error\n Problem with Sprite address.\n", p);
}
