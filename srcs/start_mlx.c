/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:32:49 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/09 10:30:19 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kub.h"

// This function init the global image of the Game ans also
// its init the asset image (wall images)
void	set_mlx_img(t_kub *kub)
{
	kub->img[0].img_ptr = mlx_new_image(kub->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	kub->img[0].addr = mlx_get_data_addr(kub->img[0].img_ptr, &kub->img[0].bpp, \
		&kub->img[0].l_length, &kub->img[0].endian);
	kub->img[1].img_ptr = mlx_new_image(kub->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	kub->img[1].addr = mlx_get_data_addr(kub->img[1].img_ptr, &kub->img[1].bpp, \
		&kub->img[1].l_length, &kub->img[1].endian);
	kub->ass[N].ass_ptr = mlx_xpm_file_to_image(kub->mlx_ptr, kub->north_asset, \
		&kub->ass[N].x, &kub->ass[N].y);
	kub->ass[S].ass_ptr = mlx_xpm_file_to_image(kub->mlx_ptr, kub->south_asset, \
		&kub->ass[S].x, &kub->ass[S].y);
	kub->ass[E].ass_ptr = mlx_xpm_file_to_image(kub->mlx_ptr, kub->east_asset, \
		&kub->ass[E].x, &kub->ass[E].y);
	kub->ass[W].ass_ptr = mlx_xpm_file_to_image(kub->mlx_ptr, kub->west_asset, \
		&kub->ass[W].x, &kub->ass[W].y);
	kub->ass[N].addr = mlx_get_data_addr(kub->ass[N].ass_ptr, &kub->ass[N].bpp, \
		&kub->ass[N].l_length, &kub->ass[N].endian);
	kub->ass[S].addr = mlx_get_data_addr(kub->ass[S].ass_ptr, &kub->ass[S].bpp, \
		&kub->ass[S].l_length, &kub->ass[S].endian);
	kub->ass[E].addr = mlx_get_data_addr(kub->ass[E].ass_ptr, &kub->ass[E].bpp, \
		&kub->ass[E].l_length, &kub->ass[E].endian);
	kub->ass[W].addr = mlx_get_data_addr(kub->ass[W].ass_ptr, &kub->ass[W].bpp, \
		&kub->ass[W].l_length, &kub->ass[W].endian);
	kub->asset_sz = (double)kub->ass[N].x;
}

void	validate_assets(t_kub *kub)
{
	if ((kub->ass[N].x != kub->ass[N].y) || (kub->ass[S].x != kub->ass[S].y) || \
		(kub->ass[E].x != kub->ass[E].y) || (kub->ass[W].x != kub->ass[W].y))
	{
		printf("Error\n%s\n", SQUARE_ASSET);
		ft_strarr_free(kub->map);
		mlx_destroy_window(kub->mlx_ptr, kub->win_ptr);
		exit (0);
	}
	if ((kub->ass[N].x != kub->ass[E].x) || (kub->ass[N].x != kub->ass[S].x) || \
		(kub->ass[N].x != kub->ass[W].x))
	{
		printf("Error\n%s\n", UNEVEN_ASSET);
		ft_strarr_free(kub->map);
		mlx_destroy_window(kub->mlx_ptr, kub->win_ptr);
		exit (0);
	}
}

void	mlx_start(t_kub *kub)
{
	kub->mlx_ptr = mlx_init();
	kub->win_ptr = mlx_new_window(kub->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, \
		"CUB3D");
	set_mlx_img(kub);
	validate_assets(kub);
	mlx_hook(kub->win_ptr, 02, 1L << 0, key_press, kub);
	mlx_hook(kub->win_ptr, 03, 1L << 1, key_release, kub);
	mlx_hook(kub->win_ptr, 17, 1L << 17, close_win, kub);
	mlx_loop_hook(kub->mlx_ptr, draw_background, kub);
	mlx_loop(kub->mlx_ptr);
}
