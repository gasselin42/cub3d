/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:03:11 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/06 13:18:45 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kub.h"

// This function transforme the vector of direction in angle
// N = 0, S = 180, E = 90, W = 270
double	player_rot(t_kub *kub)
{
	double	rot;

	rot = 180 - (atan2(kub->dir_x, kub->dir_y) * (180 / M_PI));
	if (rot >= 360.0)
		rot -= 360.0;
	return (rot);
}

int	get_pixel(t_asset ass, int x, int y)
{
	char	*pixel;

	pixel = ass.addr + (y * ass.l_length + x * (ass.bpp / 8));
	return (*(int *)pixel);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > img->l_length / 4)
		return ;
	dst = img->addr + (y * img->l_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

double	deg_to_rad(double deg)
{
	return (deg * (M_PI / 180));
}

void	swap_img(t_kub *kub)
{
	t_img	tmp_img;

	tmp_img = kub->img[0];
	kub->img[0] = kub->img[1];
	kub->img[1] = tmp_img;
}
