/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:55:42 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/06 14:20:12 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kub.h"

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
	swap_img(kub);
	mlx_clear_window(kub->mlx_ptr, kub->win_ptr);
	mlx_put_image_to_window(kub->mlx_ptr, kub->win_ptr,
		kub->img->img_ptr, 0, 0);
	return (0);
}
