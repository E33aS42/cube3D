/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		run_cub(t_param *p)
{
	read_keys(p);
	p->ray.x = 0;
	while (p->ray.x < p->screen_x)
	{
		calc_raydist(p);
		draw_ceil_text_floor(p);
		p->sprite.zbuffer[p->ray.x] = p->ray.perpwalldist;
		p->ray.x++;
	}
	get_sprites(p);
	if (p->save == 1)
		save_screenshot(p);
	mlx_put_image_to_window(p->data.mlx_ptr, p->data.win_ptr,
				p->data.img_ptr, 0, 0);
	return (0);
}

void	start_cub(t_param *p)
{
	init_cub_prm(p);
	p->data.img_ptr = mlx_new_image(p->data.mlx_ptr, p->screen_x, p->screen_y);
	if (!(p->data.img_ptr))
		ft_error("Error\nProblem with mlx_new_image.\n", p);
	p->data.img_data_addr = (int *)mlx_get_data_addr(p->data.img_ptr,
		&p->data.bpp, &p->data.sizeline, &p->data.endian);
	if (!(p->data.img_data_addr))
		ft_error("Error\nProblem with mlx_get_data_addr.\n", p);
	if (p->save == 1)
		run_cub(p);
	p->data.win_ptr = mlx_new_window(p->data.mlx_ptr, p->screen_x,
					p->screen_y, "Cub3D");
	if (!(p->data.win_ptr))
		ft_error("Error\nProblem with mlx_new_window.\n", p);
	mlx_hook(p->data.win_ptr, 2, 0, key_press, (void *)p);
	mlx_hook(p->data.win_ptr, 3, 2, key_release, (void *)p);
	mlx_hook(p->data.win_ptr, 33, 1, ft_exit, (void *)p);
	mlx_loop_hook(p->data.mlx_ptr, run_cub, (void *)p);
	mlx_loop(p->data.mlx_ptr);
}

void	parse_file(char *filename, t_param *p)
{
	p->data.mlx_ptr = mlx_init();
	if (!(p->data.mlx_ptr))
		ft_error("Error\nProblem with mlx_init.\n", p);
	get_param(filename, p);
	if (p->error_found == 1)
		ft_exit(p);
	if (p->exist == 0)
		ft_error("Error\nNo map found.\n", p);
	check_map(p);
	get_sprite_position(p);
	ft_init_spr(p);
	get_textures(p);
}

int		main(int ac, char **av)
{
	t_param	p;

	ft_init(&p);
	if (ac == 3 && check_save(av[2]) == 0)
		ft_error("Error\n Incorrect second input argument.\n", &p);
	if ((ac == 2 && av[0]) || (ac == 3 && check_save(av[2]) == 1))
	{
		if (ac == 3)
			p.save = 1;
		if (check_mapname(av[1]) == 1)
		{
			parse_file(av[1], &p);
			start_cub(&p);
		}
		else
			ft_error("Error\n .cub extension of map file is incorrect.\n", &p);
	}
	else
		ft_error("Error\n Arguments are not valid.\n", &p);
	return (0);
}
