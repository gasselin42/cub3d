/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:31:40 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/07 09:46:52 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

// FOV position of player (fill of vue)
typedef struct s_pos
{
	double	dx;
	double	dy;
}	t_pos;

// Mlx images struct
typedef struct s_img
{
	char			*addr;
	void			*img_ptr;
	int				bpp;
	int				l_length;
	int				endian;
}	t_img;

typedef struct s_asset
{
	char			*addr;
	void			*ass_ptr;
	int				bpp;
	int				l_length;
	int				endian;
	int				x;
	int				y;
}	t_asset;

// Keys struct
typedef struct s_keys
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	l_rotate;
	bool	r_rotate;
	bool	mouse;
}	t_keys;

// Position de la 1re intersection
// L'hypothénuse jusqu'à la 1re intersection, puis incrémenté 
// du hyp_inter durant le DDA
// Les intervalles ou le déplacement en X et Y entre chaque intersection
// L'hypothénuse entre chaque intersection
typedef struct s_inters {
	t_pos	inter;
	double	hyp;
	t_pos	intervals;
	double	hyp_inter;	
}	t_inters;

// Main struct
typedef struct s_kub
{
	int			map_fd;

	char		*north_asset;
	char		*south_asset;
	char		*west_asset;
	char		*east_asset;

	char		**map;

	int			floor_clr;
	int			ceiling_clr;

	int			map_height;
	int			map_width;

	double		player_x;
	double		player_y;

	double		dir_x;
	double		dir_y;
	double		rot;

	int			mouse_x;
	bool		mouse_move;

	int			asset_x;
	int			side;

	double		asset_sz;
	int			draw_start;
	int			draw_end;

	void		*mlx_ptr;
	void		*win_ptr;
	t_keys		key;
	t_img		img[2];
	t_asset		ass[4];

	t_inters	ray_x;
	t_inters	ray_y;
}	t_kub;

#endif
