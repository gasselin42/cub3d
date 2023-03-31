/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handle_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:59:02 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/06 14:22:32 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/kub_bonus.h"

int	close_win(t_kub *kub)
{
	ft_strarr_free(kub->map);
	mlx_destroy_window(kub->mlx_ptr, kub->win_ptr);
	exit(0);
	return (0);
}

int	key_press(int key, t_kub *kub)
{
	if (key == ESC)
		close_win(kub);
	if (key == A_KEY)
		kub->key.left = true;
	if (key == D_KEY)
		kub->key.right = true;
	if (key == S_KEY)
		kub->key.down = true;
	if (key == W_KEY)
		kub->key.up = true;
	if (key == LEFT_KEY)
		kub->key.l_rotate = true;
	if (key == RIGHT_KEY)
		kub->key.r_rotate = true;
	if (key == M_KEY)
	{
		if (kub->key.mouse == true)
			kub->key.mouse = false;
		else
			kub->key.mouse = true;
	}
	return (0);
}

int	key_release(int key, t_kub *kub)
{
	if (key == A_KEY)
		kub->key.left = false;
	if (key == D_KEY)
		kub->key.right = false;
	if (key == S_KEY)
		kub->key.down = false;
	if (key == W_KEY)
		kub->key.up = false;
	if (key == LEFT_KEY)
		kub->key.l_rotate = false;
	if (key == RIGHT_KEY)
		kub->key.r_rotate = false;
	return (0);
}
