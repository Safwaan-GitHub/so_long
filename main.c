/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 06:45:16 by sanoor            #+#    #+#             */
/*   Updated: 2024/04/04 16:38:05 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	update_and_render(void *param)
{
	t_list	*var;
	int		i;
	int		j;

	i = 0;
	var = (t_list *)param;
	while (i < (var->character->map_height / var->character->img_height))
	{
		j = 0;
		while (j < (var->character->map_width / var->character->img_width))
		{
			manage_map(var, i, j);
			j++;
		}
		i++;
	}
	put_player(var);
	display_moves(var, var->character->screen_count);
	return (0);
}

int	handle_keypress(int keycode, t_list *var)
{
	int	new_x;
	int	new_y;

	if (keycode == XK_Escape)
	{
		destroy(var);
		free_all(var);
		write(1, "ESC key pressed. Exiting...", 28);
		exit(0);
	}
	if (keycode == XK_w)
		move_character(var, keycode, new_x, new_y);
	if (keycode == XK_s)
		move_character(var, keycode, new_x, new_y);
	if (keycode == XK_a)
		move_character(var, keycode, new_x, new_y);
	if (keycode == XK_d)
		move_character(var, keycode, new_x, new_y);
	return (0);
}

void	collect_list(t_list **var)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while ((*var)->character->mapz[i][k])
	{
		k = 0;
		while ((*var)->character->mapz[i][k])
		{
			if ((*var)->character->mapz[i][k] == 'C')
				(*var)->character->collect_count++;
			if ((*var)->character->mapz[i][k] == 'E')
			{
				(*var)->character->exit_cox = k;
				(*var)->character->exit_coy = i;
				(*var)->character->mapz[i][k] = '0';
			}
			k++;
		}
		i++;
		k = 0;
		if ((*var)->character->mapz[i] == NULL)
			return ;
	}
}

void	pop_data(t_list *var, char **av)
{
	var->character->filepath = av[1];
	var->character->character_image = NULL;
	var->character->em1 = NULL;
	var->character->em2 = NULL;
	var->character->em3 = NULL;
	var->character->screen_count = 0;
	var->character->collect_count = 0;
	var->character->check = 0;
	var->character->player_cox = 0;
	var->character->player_coy = 0;
	var->character->move_count = 0;
	var->character->num = 0;
	var->character->nm_ofcolls = 0;
	var->character->nm_ofexits = 0;
	var->character->nm_ofplayers = 0;
	var->character->unknown = 0;
	image_parse(var);
	parse_map(var->character->filepath, &var);
	if (var->character->character_image == NULL)
		exit(0);
	var->character->y = 0;
	var->character->x = 0;
}

int	main(int ac, char **av)
{
	t_list		*var;
	t_character	*character;

	if (ac != 2)
		return (1);
	var = malloc(sizeof(t_list));
	character = malloc(sizeof(t_character));
	if (!var || !character)
		return (0);
	var->mlx_conn = mlx_init();
	var->character = character;
	pop_data(var, av);
	var->win = mlx_new_window(var->mlx_conn, var->character->map_width,
			var->character->map_height, "So_long");
	mlx_key_hook(var->win, handle_keypress, var);
	mlx_hook(var->win, DestroyNotify, ButtonReleaseMask, &destroyitall,
		(void *)var);
	mlx_loop_hook(var->mlx_conn, update_and_render, var);
	mlx_loop(var->mlx_conn);
}
