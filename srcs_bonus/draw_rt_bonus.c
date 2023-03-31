/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rt_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:02:33 by gasselin          #+#    #+#             */
/*   Updated: 2022/06/07 09:48:12 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/kub_bonus.h"

void	performs_dda2(t_kub *kub, double *map_x, double *map_y, int *side)
{
	if (kub->ray_x.hyp < kub->ray_y.hyp)
	{
		kub->ray_x.hyp += kub->ray_x.hyp_inter;
		*map_x += kub->ray_x.intervals.dx;
		kub->ray_x.inter.dx += kub->ray_x.intervals.dx;
		kub->ray_x.inter.dy += kub->ray_x.intervals.dy;
		*side = 0;
	}
	else
	{
		kub->ray_y.hyp += kub->ray_y.hyp_inter;
		*map_y += kub->ray_y.intervals.dy;
		kub->ray_y.inter.dx += kub->ray_y.intervals.dx;
		kub->ray_y.inter.dy += kub->ray_y.intervals.dy;
		*side = 1;
	}
}

// Effectuer le DDA pour trouver la distance jusqu'au mur et
// déterminer (avec le side) si le mur a été frappé 
// verticalement ou horizontalement
int	performs_dda(t_kub *kub)
{
	int		side;
	double	map_x;
	double	map_y;

	side = 0;
	map_x = (int)kub->player_x;
	map_y = (int)kub->player_y;
	while (1)
	{
		performs_dda2(kub, &map_x, &map_y, &side);
		if (kub->map[(int)map_y][(int)map_x] == '1')
			break ;
	}
	return (side);
}

// Calcule l'opposé à l'hypothénuse du triangle rectangle 
// et la hauteur du mur dans l'image
int	calculate_wall_dst(t_kub *kub, double rot)
{
	double	wall_dst;
	double	wall_x;

	if (kub->side == 0)
	{
		kub->ray_x.hyp -= kub->ray_x.hyp_inter;
		wall_dst = kub->ray_x.hyp * sin(deg_to_rad(90 - fabs(kub->rot - rot)));
		wall_x = kub->ray_x.inter.dy - kub->ray_x.intervals.dy;
	}
	else
	{
		kub->ray_y.hyp -= kub->ray_y.hyp_inter;
		wall_dst = kub->ray_y.hyp * sin(deg_to_rad(90 - fabs(kub->rot - rot)));
		wall_x = kub->ray_y.inter.dx - kub->ray_y.intervals.dx;
	}
	wall_x -= (int)(wall_x);
	kub->asset_x = (int)(kub->asset_sz * wall_x);
	if ((kub->side == 1 && (rot >= 90 && rot <= 270))
		|| (kub->side == 0 && rot > 180))
		kub->asset_x = kub->asset_sz - kub->asset_x - 1;
	return ((int)(WIN_HEIGHT / wall_dst));
}

// draw_start = Numéro du pixel où la colonne dessinée commence
// draw_end =  Numéro du pixel où la colonne dessinée termine
// asset_y = Store the X value of the ray where it hit the wall
void	draw_walls(t_kub *kub, int x, int line_ht, double rot)
{
	double	asset_y;
	int		color;

	kub->draw_start = (WIN_HEIGHT / 2 - line_ht / 2) - 1;
	if (kub->draw_start < 0)
		kub->draw_start = -1;
	kub->draw_end = (WIN_HEIGHT / 2 + line_ht / 2) - 1;
	if (kub->draw_end >= WIN_HEIGHT)
		kub->draw_end = WIN_HEIGHT - 1;
	asset_y = (kub->draw_start - WIN_HEIGHT / 2 + line_ht / 2) * \
		(kub->asset_sz / line_ht);
	while (++kub->draw_start < kub->draw_end)
	{
		if (kub->side == 1 && (rot < 90 || rot > 270))
			color = get_pixel(kub->ass[N], kub->asset_x, (int)asset_y);
		if (kub->side == 1 && (rot >= 90 && rot <= 270))
			color = get_pixel(kub->ass[S], kub->asset_x, (int)asset_y);
		if (kub->side == 0 && (rot <= 180))
			color = get_pixel(kub->ass[E], kub->asset_x, (int)asset_y);
		if (kub->side == 0 && (rot > 180))
			color = get_pixel(kub->ass[W], kub->asset_x, (int)asset_y);
		my_mlx_pixel_put(&kub->img[1], x, kub->draw_start, color);
		asset_y += (kub->asset_sz / line_ht);
	}
}

// Boucle qui envoie un "rayon" sur chaque angle dans un rayon
// de 60 degrés selon la largeur de l'écran afin de calculer
// la distance du mur le plus proche
void	send_rays(t_kub *kub)
{
	int		x;
	double	rot;
	int		line_height;

	x = -1;
	rot = kub->rot - 30.0;
	while (++x < WIN_WIDTH)
	{
		if (rot >= 360.0)
			rot -= 360.0;
		else if (rot < 0.0)
			rot += 360.0;
		find_intersections(kub, kub->player_x, kub->player_y, rot);
		kub->side = performs_dda(kub);
		line_height = calculate_wall_dst(kub, rot);
		draw_walls(kub, x, line_height, rot);
		rot += (double)(60.0 / WIN_WIDTH);
	}
}
