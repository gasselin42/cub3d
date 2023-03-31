/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:39:26 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/07 10:32:34 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/kub_bonus.h"

int	mouse_move(int x, int y, t_kub *kub)
{
	(void)y;
	kub->mouse_x = x;
	if (kub->key.mouse)
		kub->mouse_move = true;
	return (0);
}

double	mouse_pos(t_kub *kub)
{
	static double	x = (double)(WIN_WIDTH / 2);
	double			change;

	change = (double)(kub->mouse_x - x) / 15;
	x = (double)kub->mouse_x;
	return (change);
}

void	rotate_player_left(t_kub *kub, double move)
{
	double	old_dir_y;

	if (move >= 0)
		move = 1;
	old_dir_y = kub->dir_y;
	kub->dir_y = kub->dir_y * cos(deg_to_rad(ROT_SPEED * fabs(move))) \
		- kub->dir_x * sin(deg_to_rad(ROT_SPEED * fabs(move)));
	kub->dir_x = old_dir_y * sin(deg_to_rad(ROT_SPEED * fabs(move))) \
		+ kub->dir_x * cos(deg_to_rad(ROT_SPEED * fabs(move)));
}

void	rotate_player_right(t_kub *kub, double move)
{
	double	old_dir_y;

	if (move <= 0)
		move = 1;
	old_dir_y = kub->dir_y;
	kub->dir_y = kub->dir_y * cos(-deg_to_rad(ROT_SPEED * fabs(move))) \
		- kub->dir_x * sin(-deg_to_rad(ROT_SPEED * fabs(move)));
	kub->dir_x = old_dir_y * sin(-deg_to_rad(ROT_SPEED * fabs(move))) \
		+ kub->dir_x * cos(-deg_to_rad(ROT_SPEED * fabs(move)));
}

void	rotate_player(t_kub *kub)
{
	double	move;

	move = 0.0;
	if (kub->mouse_move)
		move = mouse_pos(kub);
	if (kub->key.l_rotate == true || (kub->mouse_move == true && move < 0))
		rotate_player_left(kub, move);
	if (kub->key.r_rotate == true || (kub->mouse_move == true && move > 0))
		rotate_player_right(kub, move);
	kub->rot = player_rot(kub);
	kub->mouse_move = false;
}
