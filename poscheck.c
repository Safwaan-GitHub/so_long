/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poscheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:58:31 by sanoor            #+#    #+#             */
/*   Updated: 2024/04/04 18:57:03 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	is_threelines(t_list *var)
{
	int	i;

	i = 0;
	if (!var->character->mapz[i] || var->character->mapz == NULL)
		return (1);
	while (var->character->mapz[i])
	{
		if (var->character->mapz[++i] == NULL && i < 3)
			return (1);
	}
	return (0);
}

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

int	check_ke(char c)
{
	if (c == '0' || c == 'E' || c == 'P' || c == 'C')
		return (1);
	return (0);
}

int	key_check(char c, t_list *var)
{
	if (c != 'C' && c != 'E' && c != 'P'
		&& c != 'Z' && c != '1'
		&& c != '0' && c != '\n')
	{
		var->character->unknown++;
		return (1);
	}
	return (0);
}
