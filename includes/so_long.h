/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:45:04 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/21 18:10:54 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define HEIGHT 500
# define WIDTH 500
# define ESC_KEY 53
//# define ESC_KEY_LINUX XK_Escape

typedef struct s_character 
{
	int	x;
	int	y;
	int	img_width;
	int	img_height;
	void	*character_image;
} t_character;

typedef struct s_list
{
	void    *mlx_conn;
	void    *win;
	t_character	*character;
} t_list;

#endif
