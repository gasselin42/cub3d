/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:39:26 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/06 16:15:50 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kub.h"

void	rotate_player_left(t_kub *kub)
{
	double	old_dir_y;

	old_dir_y = kub->dir_y;
	kub->dir_y = kub->dir_y * cos(deg_to_rad(ROT_SPEED)) \
		- kub->dir_x * sin(deg_to_rad(ROT_SPEED));
	kub->dir_x = old_dir_y * sin(deg_to_rad(ROT_SPEED)) \
		+ kub->dir_x * cos(deg_to_rad(ROT_SPEED));
}

void	rotate_player_right(t_kub *kub)
{
	double	old_dir_y;

	old_dir_y = kub->dir_y;
	kub->dir_y = kub->dir_y * cos(-deg_to_rad(ROT_SPEED)) \
		- kub->dir_x * sin(-deg_to_rad(ROT_SPEED));
	kub->dir_x = old_dir_y * sin(-deg_to_rad(ROT_SPEED)) \
		+ kub->dir_x * cos(-deg_to_rad(ROT_SPEED));
}

void	rotate_player(t_kub *kub)
{
	if (kub->key.l_rotate == true)
		rotate_player_left(kub);
	if (kub->key.r_rotate == true)
		rotate_player_right(kub);
	kub->rot = player_rot(kub);
}
