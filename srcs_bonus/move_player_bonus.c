/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:33:53 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/06 14:23:35 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/kub_bonus.h"

void	move_player_up(t_kub *kub)
{
	double	x_wkey;
	double	y_wkey;

	x_wkey = kub->player_x + kub->dir_x * (MOV_SPEED + 0.01);
	y_wkey = kub->player_y + kub->dir_y * (MOV_SPEED + 0.01);
	if (kub->map[(int)y_wkey][(int)kub->player_x] == '0')
		kub->player_y += (kub->dir_y * MOV_SPEED);
	if (kub->map[(int)kub->player_y][(int)x_wkey] == '0')
		kub->player_x += (kub->dir_x * MOV_SPEED);
}

void	move_player_down(t_kub *kub)
{
	double	x_skey;
	double	y_skey;

	x_skey = kub->player_x - kub->dir_x * (MOV_SPEED + 0.01);
	y_skey = kub->player_y - kub->dir_y * (MOV_SPEED + 0.01);
	if (kub->map[(int)y_skey][(int)kub->player_x] == '0')
		kub->player_y -= kub->dir_y * MOV_SPEED;
	if (kub->map[(int)kub->player_y][(int)x_skey] == '0')
		kub->player_x -= kub->dir_x * MOV_SPEED;
}

void	move_player_left(t_kub *kub)
{
	double	x_akey;
	double	y_akey;

	x_akey = kub->player_x + kub->dir_y * (MOV_SPEED + 0.01);
	y_akey = kub->player_y - kub->dir_x * (MOV_SPEED + 0.01);
	if (kub->map[(int)y_akey][(int)kub->player_x] == '0')
		kub->player_y -= kub->dir_x * MOV_SPEED;
	if (kub->map[(int)kub->player_y][(int)x_akey] == '0')
		kub->player_x += kub->dir_y * MOV_SPEED;
}

void	move_player_right(t_kub *kub)
{
	double	x_dkey;
	double	y_dkey;

	x_dkey = kub->player_x - kub->dir_y * (MOV_SPEED + 0.01);
	y_dkey = kub->player_y + kub->dir_x * (MOV_SPEED + 0.01);
	if (kub->map[(int)y_dkey][(int)kub->player_x] == '0')
		kub->player_y += kub->dir_x * MOV_SPEED;
	if (kub->map[(int)kub->player_y][(int)x_dkey] == '0')
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
