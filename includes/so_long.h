/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:45:04 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/27 22:33:22 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_character
{
	int		x;
	int		y;
	int		exit_cox;
	int		exit_coy;
	int		prev_x;
	int		prev_y;
	int		map_x;
	int		map_y;
	int		orig_x;
	int		orig_y;
	int		img_width;
	int		img_height;
	int		map_width;
	int		map_height;
	int		nm_ofcolls;
	int		nm_ofexits;
	int		nm_ofplayers;
	int		nm_oflines;
	int		player_cox;
	int		player_coy;
	int		num;
	int		check;
	int		move_count;
	int		collect_count;
	int		screen_count;
	char	*filepath;
	char	**mapz;
	char	**char_pos;
	void	*character_image;
	void	*wall_image;
	void	*base_image;
	void	*exit_image;
	void	*em1;
	void	*em2;
	void	*em3;
	void	*collectable_image;
}	t_character;

typedef struct s_list
{
	void		*mlx_conn;
	void		*win;
	t_character	*character;
}	t_list;

char	**fill_map(char *filepath, int num, char *mline, t_list **var);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
int		error_handle(char *param, int err);
int		ft_strlen(char	*str);
int		isxtopbottom(t_list *var);
int		ismidwallvalid(t_list *var);
int		put_wall(t_list *var);
int		put_base(t_list *var);
int		put_player(t_list *var);
int		put_collectable(t_list *var);
int		put_exit(t_list *var);
int		count_coll(t_list *var);
int		isxwallvalid(t_list *var);
int		isxtopbottom(t_list *var);
int		verify_dfs(t_list *var, char **mapz, int i, int k);
int		ismidwallvalid(t_list *var);
int		put_enemy(t_list *var);
void	map_check(t_list *var, int i, char **mapz);
void	parse_map(char *filepath, t_list **var);
void	manage_map(t_list *var, int i, int j);
void	dfs(t_list *var, char **mapz, int x, int y);
void	playerpos(t_list *var, char **mapz, int i, int k);
void	image_parse(t_list *var);
void	destroy(t_list *var);
void	free_all(t_list *var);
void	move_character(t_list *var, int direction, int new_x, int new_y);
void	correct_map(t_list *var, int x, int y);
void    display_moves(t_list *var, int moves);
void	replace_tiles(t_list *var, int x, int y);
void	error_pass(t_list *var);
void	save_charcoords(t_list *var, int i, int j);
void	save_coords(t_list *var, int i, int j);
void	collect_list(t_list **var);
void	check_path(t_list **var);
void    enemy_parse(t_list *var);
void    manage_enemy(t_list *var, int i, int j);
void    destroyitall(t_list *var);

#endif
