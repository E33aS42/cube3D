/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_ceil.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_colors_ceil4(char **line, t_param *p)
{
	while ((*line)[p->i] == ' ' || (*line)[p->i] == ','
		|| (*line)[p->i] == '\t')
	{
		check_coma(line, p);
		p->i++;
	}
}

void	get_colors_ceil3(char **line, t_param *p)
{
	if (p->error_found == 0)
	{
		while (((*line)[p->i] == ' ' || (*line)[p->i] == ','
			|| (*line)[p->i] == '\t'))
		{
			check_coma(line, p);
			p->i++;
		}
		if (p->coma_cnt == 0)
			ft_error2("Error\nA coma is missing.\n", p);
		if ((*line)[p->i] == '\0' && p->error_found == 0)
			ft_error2("Error\nMissing 1 ceiling inputs.\n", p);
		else
			p->cl.c_blue = atoi_fc(line, p);
		p->coma_cnt = 1;
		if (p->error_found == 0)
		{
			get_colors_ceil4(line, p);
			if (ft_isdigit((*line)[p->i]) && p->error_found == 0)
				ft_error2("Error\nToo many ceiling inputs.\n", p);
		}
	}
}

void	check_coma(char **line, t_param *p)
{
	if ((*line)[p->i] == ',')
		p->coma_cnt++;
	if (p->coma_cnt == 2 && p->error_found == 0)
		ft_error2("Error\nExtra coma found\n", p);
}

void	get_colors_ceil2(char **line, t_param *p)
{
	p->exist_c = 1;
	p->i++;
	while ((*line)[p->i] == ' ' || (*line)[p->i] == '\t')
		p->i++;
	p->cl.c_red = atoi_fc(line, p);
	while ((*line)[p->i] == ' ' || (*line)[p->i] == ','
		|| (*line)[p->i] == '\t')
	{
		check_coma(line, p);
		p->i++;
	}
	if (p->coma_cnt == 0)
		ft_error2("Error\nA coma is missing.\n", p);
	if (p->error_found == 0)
	{
		p->coma_cnt = 0;
		if ((*line)[p->i] == '\0' && p->error_found == 0)
			ft_error2("Error\nMissing ceiling inputs.\n", p);
		if ((*line)[p->i] != '\0' && p->error_found == 0)
			p->cl.c_green = atoi_fc(line, p);
		get_colors_ceil3(line, p);
	}
}

void	get_colors_ceil(char **line, t_param *p)
{
	p->i = 0;
	p->coma_cnt = 0;
	while ((*line)[p->i] == ' ' || (*line)[p->i] == '\t')
		p->i++;
	if ((*line)[p->i] == 'C' && p->error_found == 0)
	{
		if (check_str_content(*line, "0123456789C ,\n\t") == 1)
			ft_error2("Error\nWrong character types found \
in ceiling inputs.\n", p);
		if (p->exist_c == 1 && p->error_found == 0)
			ft_error2("Error\nAnother existing ceiling input.\n", p);
		if (p->error_found == 0)
			get_colors_ceil2(line, p);
	}
}
