/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:45:04 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/23 14:27:50 by sanoor           ###   ########.fr       */
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
	int	img_width;
	int	img_height;
	int	map_width;
	int	map_height;
	char	*filepath;
	char	**mapz;
	void	*character_image;
	void	*wall_image;
} t_character;

typedef struct s_list
{
	void    *mlx_conn;
	void    *win;
	t_character	*character;
} t_list;

void    parse_map(char *filepath, t_list **var);
char    **fill_map(char *filepath, int num, char *mline, t_list **var);
int     error_handle(char *param, int err);
int     ft_strlen(char  *str);
int     put_wall(t_list *var);
int     put_base(t_list *var);
int     put_player(t_list *var);
int     put_collectable(t_list *var);
int     put_exit(t_list *var);
void    manage_map(t_list *var, int i, int j);
void    image_parse(t_list *var);

#endif
