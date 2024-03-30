/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:46:07 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/30 12:49:00 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	put_enemy(t_list *var)
{
	static int	frame = 0;
	static int	counter = 0;
	void		*em_img;

	em_img = var->character->em1;
	if (counter++ % 1000 == 0)
		frame++;
	if (frame % 3 == 0)
		em_img = var->character->em1;
	else if (frame % 3 == 1)
		em_img = var->character->em2;
	else if (frame % 3 == 2)
		em_img = var->character->em3;
	mlx_put_image_to_window(var->mlx_conn,
		var->win,
		em_img,
		var->character->orig_x,
		var->character->orig_y);
}

void	manage_enemy(t_list *var, int i, int j)
{
	save_coords(var, i, j);
	put_enemy(var);
}
