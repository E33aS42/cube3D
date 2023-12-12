/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		calc_rgb(int r, int g, int b)
{
	int rgb;

	rgb = (1 << 24) + (r << 16) + (g << 8) + b;
	return (rgb);
}

long	atoi_fc(char **line, t_param *p)
{
	long		n;

	n = 0;
	while ((*line)[p->i] != '\0' && (*line)[p->i] != ' ' && (*line)[p->i] != ','
		&& (*line)[p->i] != '\t')
	{
		if (ft_isdigit((*line)[p->i]) == 0 && p->error_found == 0)
		{
			ft_error2("Error\nIncorrect inputs type.\n", p);
			break ;
		}
		else
			n = n * 10 + (*line)[p->i++] - '0';
	}
	if (n > 255)
		ft_error2("Error\n RGB values cannot be greater than 255.\n", p);
	return (n);
}
