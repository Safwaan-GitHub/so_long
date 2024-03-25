/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 06:45:16 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/25 17:04:55 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	update_and_render(void *param)
{
	t_list	*var = (t_list *)param;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (var->character->y < var->character->map_height)
	{
		while (var->character->x < var->character->map_width)
		{
			//printf("x[%d]y[%d]\n", var->character->x, var->character->y);
			manage_map(var, i, j);
			var->character->x += var->character->img_width;
			j++;
		}
		i++;
		j = 0;
		var->character->x = 0;
		var->character->y += var->character->img_height;
	}
	return (0);
}

int	handle_keypress(int keycode, t_list *var)
{
	if (keycode == XK_Escape)
	{
		destroy(var);
		free_all(var);
		printf("ESC key pressed. Exiting...\n");
		exit(0);
	}
	if (keycode == XK_w)
		move_character(var, keycode);
	if (keycode == XK_s)
		move_character(var, keycode);
	if (keycode == XK_a)
		move_character(var, keycode);
	if (keycode == XK_d)
		move_character(var, keycode);

	return (0);
}

void	pop_data(t_list *var, char **av)
{
	var->character->filepath = av[1];
	var->character->character_image = NULL;
	image_parse(var);
	parse_map(var->character->filepath, &var);
	if (var->character->character_image == NULL)
		exit(0);
	var->character->y = 0;
	var->character->x = 0;
}

int	main(int ac, char **av)
{
	t_list	*var;
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
	mlx_loop_hook(var->mlx_conn, update_and_render, var);
	mlx_loop(var->mlx_conn);
}
