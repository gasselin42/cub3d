/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:27:57 by gasselin          #+#    #+#             */
/*   Updated: 2022/06/13 15:16:28 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KUB_H
# define KUB_H

// Library C
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>

// Library mlx & libft
# include "../lib/mlx_linux/mlx.h"
# include "../lib/mlx_mac/mlx.h"
# include "../lib/libft/libft.h"

// Other Library
# include "struct.h"
# include "def.h"

// Parsing asset & color function
int		get_next_line(int fd, char **line);
void	parsing_info(t_kub *kub);

// Parsing map function
void	map_reach(t_kub *kub, char *line);
void	fill_lines(t_kub *kub);
void	replace_spaces(t_kub *kub);
int		valid_chars(t_kub *kub);
int		check_surroundings(char **map, int i, int j);
void	map_not_reached(t_kub *kub);

// Parsing uitls
size_t	get_longest_line(char **map, int size);
int		check_valid_color(char **split_f_c, int *f_c_clr);
void	got_all_info(t_kub *kub, char *line);
void	free_asset(t_kub *kub);

// Drawing & mlx function
void	mlx_start(t_kub *kub);

// Draw  minimap function
void	draw_minimap(t_kub *kub);

void	send_rays(t_kub *kub);
void	find_intersections(t_kub *kub, double x, double y, double rot);

// Move and rotate player
void	move_player(t_kub *kub);
void	rotate_player(t_kub *kub);
int		mouse_move(int x, int y, t_kub *kub);

// Mlx utils function
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	swap_img(t_kub *kub);
int		get_pixel(t_asset ass, int x, int y);
double	player_rot(t_kub *kub);
double	deg_to_rad(double deg);

// Keys function
int		key_release(int key, t_kub *kub);
int		key_press(int key, t_kub *kub);
int		close_win(t_kub *kub);

// Draw function
int		draw_background(t_kub *kub);

// Draw rt function
void	send_rays(t_kub *kub);

#endif