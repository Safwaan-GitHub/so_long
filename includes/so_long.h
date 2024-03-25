/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:45:04 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/25 17:58:59 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include "../gnl/get_next_line.h"

typedef struct s_character 
{
	int	x;
	int	y;
	int	orig_x;
	int	orig_y;
	int	img_width;
	int	img_height;
	int	map_width;
	int	map_height;
	int	collected_count;
	char	*filepath;
	char	**mapz;
	char	**char_pos;
	void	*character_image;
	void	*wall_image;
	void	*base_image;
	void	*exit_image;
	void	*collectable_image;
} t_character;

typedef struct s_list
{
	void    *mlx_conn;
	void    *win;
	t_character	*character;
} t_list;

char    **fill_map(char *filepath, int num, char *mline, t_list **var);
int     error_handle(char *param, int err);
int     ft_strlen(char  *str);
int     put_wall(t_list *var);
int     put_base(t_list *var);
int     put_player(t_list *var);
int     put_collectable(t_list *var);
int     put_exit(t_list *var);
void    parse_map(char *filepath, t_list **var);
void    manage_map(t_list *var, int i, int j);
void    image_parse(t_list *var);
void    destroy(t_list *var);
void    free_all(t_list *var);
void    move_character(t_list *var, int direction);
void    correct_map(t_list *var, int x, int y);
void    save_charcoords(t_list *var, int i, int j);
void    save_coords(t_list *var, int i, int j);

#endif
