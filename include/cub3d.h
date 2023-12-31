/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esommier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:12 by esommier          #+#    #+#             */
/*   Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <assert.h>
# include <errno.h>

# include "../minilibx-linux/mlx.h"
# define BUFFER_SIZE	1
# define ESC_KEY	65307
# define FORWARD_W	119
# define BACKWARD_S	115
# define MOVE_LEFT_A	97
# define MOVE_RIGHT_D	100
# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363

typedef struct		s_pixel
{
	unsigned char			r;
	unsigned char			g;
	unsigned char			b;
}					t_pixel;

typedef struct		s_image
{
	int				w;
	int				h;
	t_pixel			*dat;
}					t_image;

typedef struct		s_data_text
{
	char			*t_path;
	void			*t_img;
	int				*t_addr;
	int				t_width;
	int				t_height;
	int				t_bpp;
	int				t_sizeline;
	int				t_endian;
}					t_data_text;

typedef struct		s_prm_text
{
	double			wall_x;
	int				t_dir;
	int				t_x;
	int				t_y;
	double			t_step;
	double			t_pos;
}					t_prm_text;

typedef struct		s_sprite
{
	char			*s_path;
	double			*s_posx;
	double			*s_posy;
	int				s_cnt;
	void			*s_img;
	int				*s_addr;
	int				s_width;
	int				s_height;
	int				s_bpp;
	int				s_sizeline;
	int				s_endian;
	double			*zbuffer;
	int				*s_order;
	double			*s_distsq;
	double			s_x;
	double			s_y;
	double			invdet;
	double			transfx;
	double			transfy;
	int				s_screenx;
	int				height;
	int				width;
	int				drawstartx;
	int				drawstarty;
	int				drawendx;
	int				drawendy;
	int				stripe;
	int				texx;
	int				texy;
}					t_sprite;

typedef struct		s_floor
{
	int				f_red;
	int				f_green;
	int				f_blue;
	int				f_cnt;
}					t_floor;

typedef struct		s_ceiling
{
	int				c_red;
	int				c_green;
	int				c_blue;
	int				c_cnt;
}					t_ceiling;

typedef struct		s_player
{
	char			exist_dir;
	int				posx;
	int				posy;
	char			start_dir;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
}					t_player;

typedef	struct		s_ray
{
	int				x;
	double			camerax;
	double			pl_posx;
	double			pl_posy;
	double			raydirx;
	double			raydiry;
	double			deltax;
	double			deltay;
	int				mapx;
	int				mapy;
	double			sidex;
	double			sidey;
	int				stepx;
	int				stepy;
	int				wall_hit;
	int				sidewall_hit;
	double			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			movespeed;
	double			rotspeed;
}					t_ray;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*img_data_addr;
	int				bpp;
	int				sizeline;
	int				endian;
	int				mv_forward;
	int				mv_backward;
	int				mv_left;
	int				mv_right;
	int				rotate_left;
	int				rotate_right;
}					t_data;

typedef struct		s_param
{
	int				screen_x;
	int				screen_y;
	unsigned int	i;
	int				first;
	int				exist;
	int				empty_lines;
	int				error_found;
	int				nb_line_map;
	int				nb_col_map;
	t_data_text		t_no;
	t_data_text		t_so;
	t_data_text		t_we;
	t_data_text		t_ea;
	t_prm_text		txt;
	t_floor			fl;
	t_ceiling		cl;
	int				coma_cnt;
	t_sprite		sprite;
	int				exist_r;
	int				exist_f;
	int				exist_c;
	int				exist_no;
	int				exist_so;
	int				exist_we;
	int				exist_ea;
	int				exist_s;
	t_player		player;
	char			**map;
	int				save;
	t_data			data;
	int				cnt_cells;
	t_ray			ray;
}					t_param;

int					ft_strlen(char *s);
int					ft_isspace(int c);
int					ft_strcmp(char *s1, char *s2);
void				free_text_spr(char *s);
void				free_double(double *d);
void				free_int(int *d);
void				free_tab(char **tab);
void				free_map(t_param *p);
int					ft_exit(t_param *p);
void				ft_error2(char *s, t_param *p);
void				ft_error(char *s, t_param *p);
void				ft_init_spr(t_param *p);
void				ft_init(t_param *p);
void				ft_init_2(t_param *p);
void				ft_init_3(t_param *p);
void				init_dir(t_param *p);
void				init_dir2(t_param *p);
void				init_stepside(t_param *p);
void				init_delta(t_param *p);
void				init_move(t_param *p);
void				init_cub_prm(t_param *p);
void				init_cub_prm2(t_param *p);
void				init_texture(t_param *p);
int					check_save(char *s);
int					check_mapname(char *s);
int					get_next_line(int fd, char **line, t_param *p);
int					ft_strchr(char *str, int c);
int					ft_strstr_cnt(char *s1, char *s2);
int					check_str_content(char *s1, char *s2);
int					ft_strstr(char *s1, char *s2);
char				**ft_tabdup2(char **res, char **s, int i_max, int j_max);
char				**ft_tabdup(char **s, int i_max, int j_max, t_param *p);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(char *s);
char				*ft_substr(char *s, int start, int len);
int					ft_isdigit(char c);
unsigned int		calc_rx(unsigned int i, char **line, t_param *p);
unsigned int		calc_ry(unsigned int i, char **line, t_param *p);
void				check_resolution(t_param *p);
void				get_resolution2(char **line, t_param *p, int i);
void				get_resolution(char **line, t_param *p);
long				atoi_fc(char **line, t_param *p);
void				get_colors_floor4(char **line, t_param *p);
void				get_colors_floor3(char **line, t_param *p);
void				get_colors_floor2(char **line, t_param *p);
void				get_colors_floor(char **line, t_param *p);
void				get_colors_ceil4(char **line, t_param *p);
void				get_colors_ceil3(char **line, t_param *p);
void				get_colors_ceil2(char **line, t_param *p);
void				get_colors_ceil(char **line, t_param *p);
void				check_coma(char **line, t_param *p);
int					calc_rgb(int r, int g, int b);
void				get_path_text(char **line, char **txt, t_param *p);
void				get_text_spr2(char **line, t_param *p);
void				get_text_spr(char **line, t_param *p);
void				get_text_addr(t_param *p);
void				get_textures(t_param *p);
void				init_texture(t_param *p);
void				find_sprites(t_param *p);
void				get_sprite_position2(t_param *p, int i, int j, int k);
void				get_sprite_position(t_param *p);
void				draw_sprites4(t_param *p);
void				draw_sprites3(t_param *p);
void				draw_sprites2(t_param *p, int k);
void				draw_sprites(t_param *p);
void				sort_sprites(t_param *p);
void				get_sprites(t_param *p);
int					check_exists(t_param *p);
void				check_redund2(char **line, t_param *p);
void				check_redund(char **line, t_param *p);
void				check_line_1st_char2(int i, char **line, t_param *p);
void				check_line_1st_char(char **line, t_param *p);
void				get_map(char *line, t_param *p);
void				set_p_exist(char *line, t_param *p);
void				read_graphic_prm(char **line, t_param *p);
void				get_param3(char *line, t_param *p);
void				get_param2(t_param *p, int fd, int r);
void				get_param(char *filename, t_param *p);
void				init_map(t_param *p);
void				get_raw_map5(t_param *p, int i, int j);
char				**get_raw_map4(t_param *p, char **tmp, int it, int jt);
int					get_raw_map3(t_param *p, char **tmp, int i, int j);
int					get_raw_map2(t_param *p, char **tmp, int len);
void				get_raw_map1(char *line, t_param *p, int i);
void				get_raw_map(char *line, t_param *p);
void				get_player_position2(t_param *p, int i, int index);
void				get_player_position(t_param *p);
char				**check_pl_pos2(int x, int y, t_param *p, char **tmp);
void				check_pl_pos(int x, int y, t_param *p, char **tmp);
void				check_map(t_param *p);
void				parse_file(char *filename, t_param *p);
int					key_press(int keycode, t_param *p);
int					key_release(int keycode, t_param *p);
void				dda_algo(t_param *p);
void				calc_proj_dist(t_param *p);
void				calc_pixels_bound(t_param *p);
void				calc_raydist(t_param *p);
void				draw_textures2(t_param *p, int x, int y);
void				draw_textures(t_param *p, int x);
void				draw_ceil_text_floor(t_param *p);
void				move_for(t_param *p);
void				move_back(t_param *p);
void				move_left(t_param *p);
void				move_right(t_param *p);
void				rotate_left(t_param *p);
void				rotate_right(t_param *p);
void				read_keys(t_param *p);
void				save_screenshot(t_param *p);
int					run_cub(t_param *p);
void				start_cub(t_param *p);
#endif
