/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:39:33 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/26 12:17:41 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	move_character(t_list *var, int direction, int new_x, int new_y)
{
	new_x = var->character->x;
	new_y = var->character->y;
	if (direction == XK_d)
		new_x += 64;
	if (direction == XK_a)
		new_x -= 64;
	if (direction == XK_w)
		new_y -= 64;
	if (direction == XK_s)
		new_y += 64;
	correct_map(var, new_x, new_y);
}

void	replace_tiles(t_list *var, int x, int y)
{
	if (var->character->mapz[var->character->map_y]
		[var->character->map_x] == 'C')
	{
		var->character->collect_count--;
		if (var->character->collect_count == 0)
		{
			var->character->check = 1;
			var->character->mapz[var->character->exit_coy]
			[var->character->exit_cox] = 'E';
		}
	}
	if (var->character->mapz[var->character->map_y]
		[var->character->map_x] == 'E')
	{
		destroy(var);
		free_all(var);
		write(1, "Game Complete", 13);
		exit(0);
	}
	var->character->mapz[var->character->prev_y]
	[var->character->prev_x] = '0';
	var->character->x = x;
	var->character->y = y;
	var->character->mapz[var->character->map_y]
	[var->character->map_x] = 'P';
}

void	correct_map(t_list *var, int x, int y)
{
	var->character->map_x = x / 64;
	var->character->map_y = y / 64;
	var->character->prev_x = var->character->x / 64;
	var->character->prev_y = var->character->y / 64;
	if ((var->character->map_x >= 0) && (var->character->map_x
			< (var->character->map_width / 64))
		&& (var->character->map_y >= 0)
		&& (var->character->map_y
			< (var->character->map_height / 64))
		&& (var->character->mapz[var->character->map_y]
			[var->character->map_x] != '1'))
	{
		var->character->move_count++;
		replace_tiles(var, x, y);
	}
}
