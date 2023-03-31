/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rt2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:24:46 by gasselin          #+#    #+#             */
/*   Updated: 2022/06/06 14:22:44 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/kub_bonus.h"

// En cas d'un rayon à un angle droit parfait, 
// donner aux variables les valeurs maximales
// pour ne pas interférer les calculs de DDA
void	set_infinity(t_kub *kub, double rot)
{
	if (rot == 0.0 || rot == 180.0)
	{
		kub->ray_x.intervals.dx = 0;
		kub->ray_x.hyp = INFINITY;
		kub->ray_x.inter.dx = INFINITY;
		kub->ray_x.inter.dy = INFINITY;
		kub->ray_x.hyp_inter = INFINITY;
		kub->ray_x.intervals.dy = INFINITY;
	}
	if (rot == 90.0 || rot == 270.0)
	{
		kub->ray_y.intervals.dy = 0;
		kub->ray_y.hyp = INFINITY;
		kub->ray_y.inter.dx = INFINITY;
		kub->ray_y.inter.dy = INFINITY;
		kub->ray_y.hyp_inter = INFINITY;
		kub->ray_y.intervals.dx = INFINITY;
	}
}

// Permet d'obtenir la distance qui peut être différente de 1 
// dans l'intervalle constant entre intersections
double	find_2nd_interval(char c, double rot)
{
	if (c == 'X' && rot < 180)
		return (-(1 / tan(deg_to_rad(rot))));
	else if (c == 'X' && rot >= 180)
		return (1 / tan(deg_to_rad(rot)));
	else if (c == 'Y' && (rot < 90 || rot >= 270))
		return (tan(deg_to_rad(rot)));
	else if (c == 'Y' && (rot >= 90 && rot < 270))
		return (-tan(deg_to_rad(rot)));
	return (0.0);
}

// Trouve la longueur des hypothénuses pour la 
// 1re intersection et les intervalles
void	find_length(t_kub *kub, double rot)
{
	double	len_x;
	double	len_y;

	kub->ray_x.intervals.dx = 1;
	kub->ray_y.intervals.dy = 1;
	if (rot >= 180)
		kub->ray_x.intervals.dx = -1;
	if (rot < 90 || rot >= 270)
		kub->ray_y.intervals.dy = -1;
	if (rot != 0.0 && rot != 180.0)
	{
		len_x = kub->ray_x.inter.dx - kub->player_x;
		len_y = kub->ray_x.inter.dy - kub->player_y;
		kub->ray_x.hyp = sqrt(pow(len_x, 2.0) + pow(len_y, 2.0));
		kub->ray_x.intervals.dy = find_2nd_interval('X', rot);
		kub->ray_x.hyp_inter = sqrt(pow(kub->ray_x.intervals.dy, 2.0) + 1);
	}
	if (rot != 90.0 && rot != 270.0)
	{
		len_x = kub->ray_y.inter.dx - kub->player_x;
		len_y = kub->ray_y.inter.dy - kub->player_y;
		kub->ray_y.hyp = sqrt(pow(len_x, 2.0) + pow(len_y, 2.0));
		kub->ray_y.intervals.dx = find_2nd_interval('Y', rot);
		kub->ray_y.hyp_inter = sqrt(pow(kub->ray_y.intervals.dx, 2.0) + 1);
	}
}

// Trouve les coordonnées de la prochaine intersection sur l'axe des X et des Y
void	find_intersections(t_kub *kub, double x, double y, double rot)
{
	if (rot < 90 || rot >= 270)
	{
		kub->ray_y.inter.dx = x + (1 - (1 - fmod(y, 1))) * tan(deg_to_rad(rot));
		kub->ray_y.inter.dy = y - fmod(y, 1);
	}
	else if (rot >= 90 && rot < 270)
	{
		kub->ray_y.inter.dx = x - (1 - fmod(y, 1)) * tan(deg_to_rad(rot));
		kub->ray_y.inter.dy = y + (1 - fmod(y, 1));
	}
	if (rot < 180)
	{
		kub->ray_x.inter.dx = x - fmod(x, 1) + 1;
		kub->ray_x.inter.dy = y - (1 - fmod(x, 1)) / tan(deg_to_rad(rot));
	}
	else if (rot >= 180)
	{
		kub->ray_x.inter.dx = x - fmod(x, 1);
		kub->ray_x.inter.dy = y + fmod(x, 1) / tan(deg_to_rad(rot));
	}
	if (fmod(rot, 90.0) == 0.0)
		set_infinity(kub, rot);
	find_length(kub, rot);
}
