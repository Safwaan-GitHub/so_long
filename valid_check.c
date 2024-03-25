/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:39:33 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/25 10:51:23 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	move_character(t_list *var, int direction)
{
	int	new_x;
	int	new_y;

	new_x = var->character->x;
	new_y = var->character->y;
	if (direction == XK_d)
	{
		new_x += 64;
		printf("[%d][%d]: moving right\n", new_x, new_y);
	}
	if (direction == XK_a)
	{
		new_x -= 64;
		printf("[%d][%d]: moving left\n", new_x, new_y);
	}
	if (direction == XK_w)
	{
		new_y -= 64;
		printf("[%d][%d]: moving up\n", new_x, new_y);
	}
	if (direction == XK_s)
	{
		new_y += 64;
		printf("[%d][%d]: moving down\n", new_x, new_y);
	}
	correct_map(var, new_x, new_y);
}

void	correct_map(t_list *var, int x, int y)
{
	int	map_x;
	int	map_y;
	int	prev_x;
	int	prev_y;

	map_x = x / 64;
	map_y = y / 64;
	prev_x = var->character->x / 64;
	prev_y = var->character->y / 64;
	printf("[%d][%d]: current map_x . map_y\n", map_x, map_y);
	printf("[%d][%d]: previous map_x . map_y\n", prev_x, prev_y);
	printf("[%d][%d]: current mapwidth . mapheight\n", var->character->map_width / 64,
			var->character->map_height /64);
	if ((map_x >= 0) && (map_x < (var->character->map_width / 64))
			&& (map_y >= 0) && (map_y < (var->character->map_height / 64))
			&& (var->character->mapz[map_y][map_x] != '1'))
	{
		var->character->mapz[prev_y][prev_x] = '0';
		printf("[%d][%d]: moving down\n", prev_x, prev_y);
		var->character->x = x;
		var->character->y = y;
		var->character->mapz[map_y][map_x] = 'P';
		printf("[%d][%d]: moving down\n", prev_x, prev_y);
	}
}
/*
int	get_char_pos_x(t_list *var)
{
	char	**mapz;
	int	i;
	int	j;

	mapz = var->character->mapz;

}*/