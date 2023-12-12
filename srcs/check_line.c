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

void	check_line_1st_char2(int i, char **line, t_param *p)
{
	if ((*line)[i] == 'W' && p->error_found == 0)
	{
		if ((*line)[i + 1] != 'E')
			ft_error2("Error\n Wrong character following W\n", p);
	}
	if ((*line)[i] == 'E' && p->error_found == 0)
	{
		if ((*line)[i + 1] != 'A')
			ft_error2("Error\n Wrong character following E\n", p);
	}
}

void	check_line_1st_char(char **line, t_param *p)
{
	int	i;

	i = 0;
	while ((*line)[i] == ' ' || (*line)[i] == '\t')
		i++;
	if (ft_strchr("RNSWEFC 012\n\t", (*line)[i]) == -1
			&& p->error_found == 0)
		ft_error2("Error\n Wrong line found in input file\n", p);
	if ((*line)[i] == 'N' && p->error_found == 0)
	{
		if ((*line)[i + 1] != 'O')
			ft_error2("Error\n Wrong character following N\n", p);
	}
	if ((*line)[i] == 'S' && p->error_found == 0)
	{
		if ((*line)[i + 1] != 'O' && (*line)[i + 1] != ' ')
			ft_error2("Error\n Wrong character following S\n", p);
	}
	check_line_1st_char2(i, line, p);
}
