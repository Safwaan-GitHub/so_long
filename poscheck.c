/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poscheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:58:31 by sanoor            #+#    #+#             */
/*   Updated: 2024/04/02 15:11:26 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	poscheck(t_list *var, int x, int y)
{
	var->character->mapz[var->character->prev_y]
	[var->character->prev_x] = '0';
	var->character->x = x;
	var->character->y = y;
	var->character->mapz[var->character->map_y]
	[var->character->map_x] = 'P';
	if (var->character->check == 1)
		var->character->mapz[var->character->exit_coy]
		[var->character->exit_cox] = 'E';
}
