/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:55:42 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/06 14:23:14 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/kub_bonus.h"

void	draw_floor_celling(t_kub *kub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			if (y < (WIN_HEIGHT / 2))
				my_mlx_pixel_put(&kub->img[1], x, y, kub->ceiling_clr);
			else
				my_mlx_pixel_put(&kub->img[1], x, y, kub->floor_clr);
		}
	}
}

int	draw_background(t_kub *kub)
{
	move_player(kub);
	rotate_player(kub);
	draw_floor_celling(kub);
	send_rays(kub);
	draw_minimap(kub);
	swap_img(kub);
	mlx_clear_window(kub->mlx_ptr, kub->win_ptr);
	mlx_put_image_to_window(kub->mlx_ptr, kub->win_ptr,
		kub->img->img_ptr, 0, 0);
	if (kub->key.mouse == true)
		mlx_string_put(kub->mlx_ptr, kub->win_ptr, (WIN_WIDTH - 220), 5,
			WHITE, "Mouse rotation ON");
	else
		mlx_string_put(kub->mlx_ptr, kub->win_ptr, (WIN_WIDTH - 220), 5,
			WHITE, "Mouse rotation OFF");
	mlx_string_put(kub->mlx_ptr, kub->win_ptr, (WIN_WIDTH - 250), 25,
		WHITE, "(Press M to turn ON/OFF)");
	return (0);
}
