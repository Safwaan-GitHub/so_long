/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:33:23 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/27 22:31:36 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	isxtopbottom(t_list *var)
{
	int	i;
	int	j;
	int	len;

	len = -1;
	j = 0;
	i = 0;
	while (var->character->mapz[i++])
		len++;
	var->character->nm_oflines = len;
	while ((var->character->mapz[0][j] == 49
		&& var->character->mapz[len][j] == 49))
	{
		j++;
		if ((var->character->mapz[0][j] == '\n'
			&& var->character->mapz[len][j] == '\n'))
			return (1);
	}
	return (0);
}

int	ismidwallvalid(t_list *var)
{
	int	i;
	int	k;
	int	lenbase;
	int	len;

	lenbase = ft_strlen(var->character->mapz[0]);
	len = ft_strlen(var->character->mapz[0]);
	i = 1;
	k = 0;
	while (var->character->mapz[i][k] == '1'
			&& var->character->mapz[i][len - 1] == '1'
			&& lenbase == len)
	{
		len = ft_strlen(var->character->mapz[i]);
		i++;
		if ((var->character->mapz[i] == NULL))
			return (1);
	}
	return (0);
}

void	map_check(t_list *var, int i, char **mapz)
{
	int	is_xwall;
	int	is_midwall;

	is_xwall = isxtopbottom(var);
	is_midwall = ismidwallvalid(var);
	mapz = malloc(sizeof(char *) * (var->character->nm_oflines + 2));
	while (var->character->mapz[i])
	{
		mapz[i] = ft_strdup(var->character->mapz[i]);
		i++;
	}
	mapz[i] = NULL;
	i = 0;
	if (is_xwall && is_midwall)
	{
		playerpos(var, mapz, 0, 0);
		dfs(var, mapz, var->character->player_cox, var->character->player_coy);
		if (!(verify_dfs(var, mapz, 0, 0)))
			var->character->num = 1;
	}
	while (mapz[i])
		free(mapz[i++]);
	free(mapz);
}

void	dfs(t_list *var, char **mapz, int x, int y)
{
	if (mapz[y - 1][x] != '1')
	{
		mapz[y - 1][x] = '1';
		dfs(var, mapz, x, y - 1);
	}
	if (mapz[y][x + 1] != '1')
	{
		mapz[y][x + 1] = '1';
		dfs(var, mapz, x + 1, y);
	}
	if (mapz[y + 1][x] != '1')
	{
		mapz[y + 1][x] = '1';
		dfs(var, mapz, x, y + 1);
	}
	if (mapz[y][x - 1] != '1')
	{
		mapz[y][x - 1] = '1';
		dfs(var, mapz, x - 1, y);
	}
	return ;
}

void	playerpos(t_list *var, char **mapz, int i, int k)
{
	while (mapz[i][k])
	{
		k = 0;
		while (mapz[i][k])
		{
			if (mapz[i][k] == 'C')
				var->character->nm_ofcolls++;
			if (mapz[i][k] == 'E')
				var->character->nm_ofexits++;
			if (mapz[i][k] == 'P')
			{
				var->character->nm_ofplayers++;
				var->character->player_cox = k;
				var->character->player_coy = i;
			}
			k++;
		}
		i++;
		k = 0;
		if (mapz[i] == NULL)
			return ;
	}
}
