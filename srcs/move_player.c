/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:33:53 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/09 10:31:24 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kub.h"

void	move_player_up(t_kub *kub)
{
	double	x_wkey;
	double	y_wkey;

	x_wkey = kub->player_x + kub->dir_x * (MOV_SPEED + 0.01);
	y_wkey = kub->player_y + kub->dir_y * (MOV_SPEED + 0.01);
	if (ceil(y_wkey) >= 2.0 && y_wkey < (double)(kub->map_height - 1.0))
		kub->player_y += (kub->dir_y * MOV_SPEED);
	if (ceil(x_wkey) >= 2.0 && x_wkey < (double)(kub->map_width - 1.0))
		kub->player_x += (kub->dir_x * MOV_SPEED);
}

void	move_player_down(t_kub *kub)
{
	double	x_skey;
	double	y_skey;

	x_skey = kub->player_x - kub->dir_x * (MOV_SPEED + 0.01);
	y_skey = kub->player_y - kub->dir_y * (MOV_SPEED + 0.01);
	if (ceil(y_skey) >= 2.0 && y_skey < (double)(kub->map_height - 1.0))
		kub->player_y -= kub->dir_y * MOV_SPEED;
	if (ceil(x_skey) >= 2.0 && x_skey < (double)(kub->map_width - 1.0))
		kub->player_x -= kub->dir_x * MOV_SPEED;
}

void	move_player_left(t_kub *kub)
{
	double	x_akey;
	double	y_akey;

	x_akey = kub->player_x + kub->dir_y * (MOV_SPEED + 0.01);
	y_akey = kub->player_y - kub->dir_x * (MOV_SPEED + 0.01);
	if (ceil(y_akey) >= 2.0 && y_akey < (double)(kub->map_height - 1.0))
		kub->player_y -= kub->dir_x * MOV_SPEED;
	if (ceil(x_akey) >= 2.0 && x_akey < (double)(kub->map_width - 1.0))
		kub->player_x += kub->dir_y * MOV_SPEED;
}

void	move_player_right(t_kub *kub)
{
	double	x_dkey;
	double	y_dkey;

	x_dkey = kub->player_x - kub->dir_y * (MOV_SPEED + 0.01);
	y_dkey = kub->player_y + kub->dir_x * (MOV_SPEED + 0.01);
	if (ceil(y_dkey) >= 2.0 && y_dkey < (double)(kub->map_height - 1.0))
		kub->player_y += kub->dir_x * MOV_SPEED;
	if (ceil(x_dkey) >= 2.0 && x_dkey < (double)(kub->map_width - 1.0))
		kub->player_x -= kub->dir_y * MOV_SPEED;
}

void	move_player(t_kub *kub)
{
	if (kub->key.up == true)
		move_player_up(kub);
	if (kub->key.down == true)
		move_player_down(kub);
	if (kub->key.left == true)
		move_player_left(kub);
	if (kub->key.right == true)
		move_player_right(kub);
}
