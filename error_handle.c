/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:08:34 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/25 09:15:13 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	error_handle(char *param, int err)
{
	perror(param);
	return (err);
}

void	destroy(t_list *var)
{
	mlx_destroy_image(var->mlx_conn, var->character->character_image);
	mlx_destroy_image(var->mlx_conn, var->character->wall_image);
	mlx_destroy_image(var->mlx_conn, var->character->base_image);
	mlx_destroy_image(var->mlx_conn, var->character->collectable_image);
	mlx_destroy_image(var->mlx_conn, var->character->exit_image);
	mlx_destroy_window(var->mlx_conn, var->win);
	mlx_destroy_display(var->mlx_conn);
}

void	free_all(t_list *var)
{
	int	i;

	i = 0;
	free(var->mlx_conn);
	while (var->character->mapz[i])
		free(var->character->mapz[i++]);
	free(var->character->mapz);
	free(var->character);
	free(var);
}
