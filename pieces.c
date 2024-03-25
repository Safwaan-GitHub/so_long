/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:35:33 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/25 11:12:03 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	put_wall(t_list *var)
{
	mlx_put_image_to_window(var->mlx_conn,
			var->win,
			var->character->wall_image,
			var->character->x,
			var->character->y);
}

int	put_base(t_list *var)
{
	mlx_put_image_to_window(var->mlx_conn,
			var->win,
			var->character->base_image,
			var->character->x,
			var->character->y);
}

int	put_player(t_list *var)
{
	mlx_put_image_to_window(var->mlx_conn,
			var->win,
			var->character->character_image,
			var->character->x,
			var->character->y);
	
}

int	put_collectable(t_list *var)
{
	mlx_put_image_to_window(var->mlx_conn,
			var->win,
			var->character->collectable_image,
			var->character->x,
			var->character->y);
}

int	put_exit(t_list *var)
{
	mlx_put_image_to_window(var->mlx_conn,
			var->win,
			var->character->exit_image,
			var->character->x,
			var->character->y);
}
