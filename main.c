/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 06:45:16 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/23 15:39:58 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	update_and_render(void *param)
{
	t_list	*var = (t_list *)param;

	mlx_put_image_to_window(var->mlx_conn,
			var->win,
			var->character->character_image,
			var->character->x,
			var->character->y);
	return (0);
}

int	handle_keypress(int keycode, t_list *var)
{
	int	i;

	i = 0;
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(var->mlx_conn, var->character->character_image);
		mlx_destroy_window(var->mlx_conn, var->win);
		mlx_destroy_display(var->mlx_conn);
		free(var->mlx_conn);
		while (var->character->mapz[i])
			free(var->character->mapz[i++]);
		free(var->character->mapz);
		free(var->character);
		free(var);
		printf("ESC key pressed. Exiting...\n");
		exit(0);
	}/*
	if (keycode == KEY_W)
		var->game_state->character.y -= 10;
	if (keycode == KEY_S)
		var->game_state->character.y += 10;
	if (keycode == KEY_D)
		var->game_state->character.x += 10;
	if (keycode == KEY_A)
		var->game_state->character.x -= 10;
		*/
	return (0);
}

void	pop_data(t_list *var, char **av)
{
	var->character->filepath = av[1];
	var->character->character_image = NULL;
	if (var->character->character_image == NULL)
	var->character->character_image
		= mlx_xpm_file_to_image(var->mlx_conn,
				"imgs/idle2.xpm",
				&(var->character->img_width),
				&(var->character->img_height));
	parse_map(var->character->filepath, &var);
	if (var->character->character_image == NULL)
		exit(0);
	var->character->y = 100;
	var->character->x = 100;
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
	manage_map(var);
	mlx_key_hook(var->win, handle_keypress, var);

	mlx_loop_hook(var->mlx_conn, update_and_render, var);

	mlx_loop(var->mlx_conn);
}
