/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcreate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:40:27 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/26 11:39:34 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	save_charcoords(t_list *var, int i, int j)
{
	var->character->x = j * 64;
	var->character->y = i * 64;
}

void	save_coords(t_list *var, int i, int j)
{
	var->character->orig_x = j * 64;
	var->character->orig_y = i * 64;
}

void	manage_map(t_list *var, int i, int j)
{
	if (var->character->mapz[i][j] == '1' && var->character->mapz[i][j])
	{
		save_coords(var, i, j);
		put_wall(var);
	}
	else if (var->character->mapz[i][j] == '0' && var->character->mapz[i][j])
	{
		save_coords(var, i, j);
		put_base(var);
	}
	else if (var->character->mapz[i][j] == 'C' && var->character->mapz[i][j])
	{
		save_coords(var, i, j);
		put_collectable(var);
	}
	else if (var->character->mapz[i][j] == 'E' && var->character->mapz[i][j])
	{
		save_coords(var, i, j);
		if (count_coll(var))
			put_exit(var);
	}
	else if (var->character->mapz[i][j] == 'P' && var->character->mapz[i][j])
		save_charcoords(var, i, j);
}

void	image_parse(t_list *var)
{
	var->character->character_image = mlx_xpm_file_to_image(var->mlx_conn,
			"imgs/basechar.xpm", &(var->character->img_width),
			&(var->character->img_height));
	var->character->wall_image = mlx_xpm_file_to_image(var->mlx_conn,
			"imgs/wall.xpm", &(var->character->img_width),
			&(var->character->img_height));
	var->character->base_image = mlx_xpm_file_to_image(var->mlx_conn,
			"imgs/base.xpm", &(var->character->img_width),
			&(var->character->img_height));
	var->character->collectable_image = mlx_xpm_file_to_image(var->mlx_conn,
			"imgs/basecol.xpm", &(var->character->img_width),
			&(var->character->img_height));
	var->character->exit_image = mlx_xpm_file_to_image(var->mlx_conn,
			"imgs/exit.xpm", &(var->character->img_width),
			&(var->character->img_height));
}
