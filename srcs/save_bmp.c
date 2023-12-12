/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_img_bmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			check_save(char *s)
{
	char	*cmp;

	cmp = "--save";
	if (ft_strlen(s) == 6)
		return (ft_strcmp(s, cmp));
	return (0);
}

static void	make_header(t_param *p, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + (3 * p->screen_x + 1) * p->screen_y;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 4);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &p->screen_x, 4);
	write(fd, &p->screen_y, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &p->data.bpp, 2);
	tmp = 0;
	write(fd, &tmp, 8);
	write(fd, &tmp, 8);
	write(fd, &tmp, 8);
}

void		save_screenshot(t_param *p)
{
	int	fd;
	int	x;
	int	y;

	y = p->screen_y - 1;
	if ((fd = open("screenshot.bmp", O_WRONLY |
	O_CREAT, 0777 | O_TRUNC | O_APPEND)) < 0)
		ft_error("Error\nCannot create screenshot.\n", p);
	make_header(p, fd);
	while (y >= 0)
	{
		x = 0;
		while (x < p->screen_x)
		{
			write(fd, &p->data.img_data_addr[y * p->data.sizeline / 4 + x],
				4);
			x++;
		}
		y--;
	}
	ft_error("Screenshot saved.\n", p);
}
