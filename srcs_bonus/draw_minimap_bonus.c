/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:06:22 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/07 10:31:37 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/kub_bonus.h"

t_pos	move_pos(t_pos pos, double rot)
{
	t_pos	new_pos;

	new_pos.dx = pos.dx + sin(rot * (M_PI / 180));
	new_pos.dy = pos.dy + -cos(rot * (M_PI / 180));
	return (new_pos);
}

void	draw_player(t_kub *kub, int tile)
{
	int	div;
	int	x;
	int	y;

	div = (int)(tile / 2);
	y = -div - 1;
	while (++y < div)
	{
		x = -div - 1;
		while (++x < div)
		{
			my_mlx_pixel_put(&kub->img[1], kub->player_x * tile + x,
				kub->player_y * tile + y, RED);
		}
	}
}

// DDA qui draw le cone
void	draw_cone(t_kub *kub)
{
	int		tile;
	int		dist;
	double	rot;
	t_pos	pos;

	rot = -30.0;
	tile = (int)((WIN_WIDTH * 0.35) / kub->map_width);
	while (rot <= 30.0)
	{
		pos.dx = kub->player_x * tile;
		pos.dy = kub->player_y * tile;
		dist = 0;
		while (dist++ <= ceil(tile * 5))
		{
			if (kub->map[(int)(pos.dy / tile)][(int)(pos.dx / tile)] != '0')
				break ;
			my_mlx_pixel_put(&kub->img[1], pos.dx, pos.dy, L_BLUE);
			pos = move_pos(pos, kub->rot - rot);
		}
		rot += 0.10;
	}
	draw_player(kub, tile);
}

void	draw_minimap(t_kub *kub)
{
	int	tile;
	int	x;
	int	y;

	tile = (int)((WIN_WIDTH * 0.35) / kub->map_width);
	y = -1;
	while (++y < (kub->map_height * tile))
	{
		x = -1;
		while (++x < (kub->map_width * tile))
		{
			if (x % tile == 0 || y % tile == 0 || x == kub->map_width * tile - 1
				|| y == kub->map_height * tile - 1)
				my_mlx_pixel_put(&kub->img[1], x, y, L_RED);
			else if (kub->map[y / tile][x / tile] == '1' ||
				kub->map[y / tile][x / tile] == ' ')
				my_mlx_pixel_put(&kub->img[1], x, y, D_GREEN);
			else
				my_mlx_pixel_put(&kub->img[1], x, y, BEIGE);
		}
	}
	draw_cone(kub);
}
