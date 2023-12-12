/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_p_exist(char *line, t_param *p)
{
	if (check_str_content(line, "012NEWS\n") == 1)
		ft_error2("Error\n Abnormal character found in map\n", p);
	if (p->error_found == 0)
		p->exist = 1;
}

void	read_graphic_prm(char **line, t_param *p)
{
	get_resolution(line, p);
	get_colors_floor(line, p);
	get_colors_ceil(line, p);
	get_text_spr(line, p);
}

void	get_param3(char *line, t_param *p)
{
	if (p->error_found == 0)
	{
		if (ft_strstr_cnt(line, "01") > 0 && !check_exists(p)
			&& p->error_found == 0 && p->exist == 0
			&& ft_strstr_cnt(line, "RNSWEFC") == 0)
			ft_error2("Error\n Missing input arguments\
before the map.\n", p);
		if (ft_strstr_cnt(line, "01") > 0 && check_exists(p)
			&& p->exist == 0 && p->error_found == 0)
			set_p_exist(line, p);
		if (p->exist == 1 && p->error_found == 0
				&& p->error_found == 0)
			get_map(line, p);
	}
}

void	get_param2(t_param *p, int fd, int r)
{
	char	*line;

	while (r > 0)
	{
		r = get_next_line(fd, &line, p);
		if (p->first == 0 && r == 0 && p->error_found == 0)
			ft_error2("Error\n Empty input file.\n", p);
		p->first = 1;
		if (p->error_found == 0)
			check_line_1st_char(&line, p);
		if (ft_strstr_cnt(line, "RNSWEFC") > 0 && p->exist == 0
			&& p->error_found == 0)
		{
			read_graphic_prm(&line, p);
			free(line);
			continue ;
		}
		if (p->error_found == 0)
			get_param3(line, p);
		free(line);
	}
}

void	get_param(char *filename, t_param *p)
{
	int		fd;
	int		r;
	char	*s;

	fd = open(filename, O_RDWR);
	if (fd < 0)
	{
		s = strerror(errno);
		ft_error2("Error\n", p);
		ft_error2(s, p);
		write(1, "\n", 1);
		p->error_found = 1;
	}
	r = 1;
	if (p->error_found == 0)
		get_param2(p, fd, r);
	close(fd);
}
