/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcreate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:40:27 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/23 18:11:54 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	manage_map(t_list **var)
{
	char	**map;
	char	*line;
	t_character	*character;

	character = var->character;
	map = character->mapz;
	line = *map;
	while (*line)
	{
		if (*line == 1)
			wall_piece(var, character);
		if (*line == 0)
			ground_piece(var, character);
		if (*line == 'P')
			character_piece(var, character);
		if (*line == 'C')
			collectable_piece(var, character);
		if (*line == 'E')
			exit_piece(var, character);
	}
}

void	wall_piece(t_list **var, t_character *character)
{

}
