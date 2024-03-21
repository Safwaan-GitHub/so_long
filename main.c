/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 06:45:16 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/21 19:00:22 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	update_and_render(void *param)
{
	t_list	*var = (t_list *)param;

	printf("hey #3\n");
	/*
	clear_character_position(var->mlx_conn,
			var->win,
			var->game_state->character.x,
			var->game_state->character.y);
			*/
	mlx_put_image_to_window(var->mlx_conn,
			var->win,
			var->character->character_image,
			var->character->x,
			var->character->y);
	return (0);
}

int	handle_keypress(int keycode, t_list *var)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(var->mlx_conn, var->character->character_image);
		mlx_destroy_window(var->mlx_conn, var->win);
		mlx_destroy_display(var->mlx_conn);
		printf("%p\n", var->character->character_image);
		free(var->mlx_conn);
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
	var->character->fd = open(av[1], O_RDONLY);
	var->character->mapz = parse_map(var->character->fd);

	var->character->character_image = NULL;
	if (var->character->character_image == NULL)
	var->character->character_image
		= mlx_xpm_file_to_image(var->mlx_conn,
				"imgs/idle2.xpm",
				&(var->character->img_width),
				&(var->character->img_height));
	
	if (var->character->character_image == NULL)
		exit(0);
	printf("hey\n");
	var->character->y = 100;
	var->character->x = 100;
	printf("hey\n");
}

int	main(int ac, char **av)
{
	t_list	var;
	t_character	character;
	
	var.mlx_conn = mlx_init();
	var.win = mlx_new_window(var.mlx_conn, WIDTH, HEIGHT, "So_long");
	if (ac != 2)
		return (1);
	var.character = &character;
	pop_data(&var, av);
	//printf("%s HELLO from MAIN\n", *(var.character->mapz));
	mlx_key_hook(var.win, handle_keypress, &var);

	mlx_loop_hook(var.mlx_conn, update_and_render, &var);

	mlx_loop(var.mlx_conn);
}
