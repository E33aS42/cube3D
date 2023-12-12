/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_text_spr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_redund2(char **line, t_param *p)
{
	if ((*line)[p->i] == 'E' && (*line)[p->i + 1] == 'A')
	{
		if (p->exist_ea == 1)
			ft_error2("Error\nAnother existing EA input.\n", p);
		if (p->error_found == 0)
			p->exist_ea = 1;
	}
	else if ((*line)[p->i] == 'S' && (*line)[p->i + 1] == ' ')
	{
		if (p->exist_s == 1)
			ft_error2("Error\nAnother existing sprite input.\n", p);
		if (p->error_found == 0)
			p->exist_s = 1;
	}
}

void	check_redund(char **line, t_param *p)
{
	if ((*line)[p->i] == 'N' && (*line)[p->i + 1] == 'O')
	{
		if (p->exist_no == 1)
			ft_error2("Error\nAnother existing NO input.\n", p);
		if (p->error_found == 0)
			p->exist_no = 1;
	}
	else if ((*line)[p->i] == 'S' && (*line)[p->i + 1] == 'O')
	{
		if (p->exist_so == 1)
			ft_error2("Error\nAnother existing SO input.\n", p);
		if (p->error_found == 0)
			p->exist_so = 1;
	}
	else if ((*line)[p->i] == 'W' && (*line)[p->i + 1] == 'E')
	{
		if (p->exist_we == 1)
			ft_error2("Error\nAnother existing WE input.\n", p);
		if (p->error_found == 0)
			p->exist_we = 1;
	}
	else
		check_redund2(line, p);
}

void	get_path_text(char **line, char **txt, t_param *p)
{
	p->i += 2;
	while ((*line)[p->i] == ' ' || (*line)[p->i] == '\t')
		p->i++;
	*txt = ft_strdup(&((*line)[p->i]));
}

void	get_text_spr2(char **line, t_param *p)
{
	if ((*line)[p->i] == 'W' && (*line)[p->i + 1] == 'E' && p->error_found == 0)
	{
		check_redund(line, p);
		if (p->error_found == 0)
			get_path_text(line, &p->t_we.t_path, p);
	}
	else if ((*line)[p->i] == 'E' && (*line)[p->i + 1] == 'A'
			&& p->error_found == 0)
	{
		check_redund(line, p);
		if (p->error_found == 0)
			get_path_text(line, &p->t_ea.t_path, p);
	}
	else if ((*line)[p->i] == 'S' && ((*line)[p->i + 1] == ' '
			|| (*line)[p->i] == '\t')
		&& p->error_found == 0)
	{
		check_redund(line, p);
		if (p->error_found == 0)
			get_path_text(line, &p->sprite.s_path, p);
	}
}

void	get_text_spr(char **line, t_param *p)
{
	p->i = 0;
	while ((*line)[p->i] == ' ' || (*line)[p->i] == '\t'
			|| (*line)[p->i] == '\t')
		p->i++;
	if ((*line)[p->i] == 'N' && (*line)[p->i + 1] == 'O' && p->error_found == 0)
	{
		check_redund(line, p);
		if (p->error_found == 0)
			get_path_text(line, &p->t_no.t_path, p);
	}
	else if ((*line)[p->i] == 'S' && (*line)[p->i + 1] == 'O'
			&& p->error_found == 0)
	{
		check_redund(line, p);
		if (p->error_found == 0)
			get_path_text(line, &p->t_so.t_path, p);
	}
	else
		get_text_spr2(line, p);
}
