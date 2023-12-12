/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

unsigned int	calc_rx(unsigned int i, char **line, t_param *p)
{
	long		n;

	n = 0;
	while ((*line)[i] != ' ' && (*line)[i] != '\t')
	{
		if (ft_isdigit((*line)[i]) == 0)
		{
			ft_error2("Error\nIncorrect resolution inputs.\n", p);
			break ;
		}
		else
			n = n * 10 + (*line)[i] - '0';
		i++;
	}
	p->screen_x = n;
	return (i);
}

unsigned int	calc_ry(unsigned int i, char **line, t_param *p)
{
	long		n;

	n = 0;
	while ((*line)[i] != ' ' && (*line)[i] != '\0' && p->error_found == 0)
	{
		if (ft_isdigit((*line)[i]) == 0)
		{
			ft_error2("Error\nIncorrect resolution inputs.\n", p);
			break ;
		}
		else
			n = n * 10 + (*line)[i++] - '0';
	}
	p->screen_y = n;
	if (check_str_content(&(*line)[i], " ,\n\t") == 1 && p->error_found == 0)
		ft_error2("Error\nToo many resolution inputs.\n", p);
	return (i);
}

void			check_resolution(t_param *p)
{
	int	rx;
	int	ry;

	rx = 0;
	ry = 0;
	if (p->error_found == 0 && (p->screen_x == 0 || p->screen_y == 0))
		ft_error2("Error\nResolution inputs cannot be null.\n", p);
	if (p->error_found == 0 && (p->screen_x < 0 || p->screen_y < 0))
		ft_error2("Error\nResolution inputs cannot be negative.\n", p);
	if (p->error_found == 0)
	{
		mlx_get_screen_size(p->data.mlx_ptr, &rx, &ry);
		if (p->screen_x > rx)
			p->screen_x = rx;
		if (p->screen_y > ry)
			p->screen_y = ry;
	}
}

void			get_resolution2(char **line, t_param *p, int i)
{
	p->exist_r = 1;
	i++;
	while ((*line)[i] == ' ' || (*line)[i] == '\t')
		i++;
	i = calc_rx(i, line, p);
	while ((*line)[i] == ' ' || (*line)[i] == '\t')
		i++;
	i = calc_ry(i, line, p);
	check_resolution(p);
}

void			get_resolution(char **line, t_param *p)
{
	unsigned int	i;

	i = 0;
	while ((*line)[i] == ' ' || (*line)[i] == '\t')
		i++;
	if ((*line)[i] == 'R')
	{
		if (check_str_content(*line, "R0123456789 ,\n\t") == 1)
			ft_error2("Error\nWrong character types found in \
resolution inputs.\n", p);
		if (p->exist_r == 1 && p->error_found == 0)
			ft_error2("Error\nAnother existing resolution input.\n", p);
		if (p->error_found == 0)
			get_resolution2(line, p, i);
	}
}
