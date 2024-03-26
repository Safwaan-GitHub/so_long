/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:14:28 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/26 11:19:00 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	parse_map(char *filepath, t_list **var)
{
	char	*map;
	int		fd;
	int		num;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		exit(error_handle("Error bad FD (map parse)", 1));
	num = 0;
	map = get_next_line(fd);
	while (map)
	{
		if (map == NULL)
			break;
		num++;
		free(map);
		map = get_next_line(fd);
	}
	free(map);
	close(fd);
	printf("[%d]\n", num);
	(*var)->character->map_height = (num * ((*var)->character->img_height));
	(*var)->character->mapz = fill_map(filepath, num, map, var);
	collect_list(var);
}

char	**fill_map(char *filepath, int num, char *mline, t_list **var)
{
	char	**map;
	int	fd;
	int	i;

	i = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		exit(error_handle("Error bad FD (map_fill)", 1));
	map = malloc((sizeof(char *) * (num + 1)));
	if (map == NULL)
		exit(error_handle("Error Memory Issue", 1));
	mline = get_next_line(fd);
	while ((mline != NULL && i < num))
	{
		map[i++] = mline;
		mline = get_next_line(fd);
	}
	map[i] = NULL;
	(*var)->character->map_width
		= (ft_strlen(map[0]) * ((*var)->character->img_width));
	printf("[%d]\n", ft_strlen(map[0]));
	close (fd);
	return (map);
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1);
}

int	count_coll(t_list *var)
{
	if (var->character->check == 1)
	{
		return (1);
	}
	return (0);
}
