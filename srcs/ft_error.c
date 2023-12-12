/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_map(t_param *p)
{
	free_tab(p->map);
	free_text_spr(p->t_no.t_path);
	free_text_spr(p->t_so.t_path);
	free_text_spr(p->t_we.t_path);
	free_text_spr(p->t_ea.t_path);
	free_text_spr(p->sprite.s_path);
	free_double(p->sprite.zbuffer);
	free_int(p->sprite.s_order);
	free_double(p->sprite.s_distsq);
	free_double(p->sprite.s_posx);
	free_double(p->sprite.s_posy);
}

int		ft_exit(t_param *p)
{
	if (p->data.img_ptr)
		mlx_destroy_image(p->data.mlx_ptr, p->data.img_ptr);
	if (p->t_no.t_img)
		mlx_destroy_image(p->data.mlx_ptr, p->t_no.t_img);
	if (p->t_so.t_img)
		mlx_destroy_image(p->data.mlx_ptr, p->t_so.t_img);
	if (p->t_we.t_img)
		mlx_destroy_image(p->data.mlx_ptr, p->t_we.t_img);
	if (p->t_ea.t_img)
		mlx_destroy_image(p->data.mlx_ptr, p->t_ea.t_img);
	if (p->sprite.s_img)
		mlx_destroy_image(p->data.mlx_ptr, p->sprite.s_img);
	if (p->data.win_ptr)
	{
		mlx_clear_window(p->data.mlx_ptr, p->data.win_ptr);
		mlx_destroy_window(p->data.mlx_ptr, p->data.win_ptr);
	}
	if (p->data.mlx_ptr)
		mlx_destroy_display(p->data.mlx_ptr);
	if (p->data.mlx_ptr)
		free(p->data.mlx_ptr);
	free_map(p);
	exit(0);
}

void	ft_error2(char *s, t_param *p)
{
	int	len;

	len = ft_strlen(s);
	write(1, &s[0], len);
	p->error_found = 1;
}

void	ft_error(char *s, t_param *p)
{
	int	len;

	len = ft_strlen(s);
	write(1, &s[0], len);
	ft_exit(p);
	exit(0);
}
