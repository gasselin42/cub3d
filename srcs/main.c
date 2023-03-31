/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:43:49 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/07 11:15:16 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kub.h"

// This function check if the map is a ".cub"
void	check_dot_kub(char *av)
{
	char	*dot_cub;

	dot_cub = NULL;
	if (!av[0])
		exit (printf("Error\n%s\n", EMPTY_ARG));
	dot_cub = ft_strnstr(av, ".cub", ft_strlen(av));
	if (dot_cub == NULL || ft_strlen(dot_cub) > 4)
		exit (printf("Error\n%s\n", WRONG_DOT_CUB));
}

// This function init the variable of the main struct
void	init_kub(t_kub *kub)
{
	kub->north_asset = NULL;
	kub->south_asset = NULL;
	kub->east_asset = NULL;
	kub->west_asset = NULL;
	kub->floor_clr = -1;
	kub->ceiling_clr = -1;
	kub->map_height = 0;
	kub->map_width = 0;
	kub->player_x = -1.0;
	kub->player_y = -1.0;
	kub->key.up = false;
	kub->key.down = false;
	kub->key.left = false;
	kub->key.right = false;
	kub->key.l_rotate = false;
	kub->key.r_rotate = false;
}

// tHis FUncT0n3 Is tHe mAiN 🤪
int	main(int ac, char **av)
{
	t_kub	kub;

	if (ac != 2)
		return (printf("Error\n%s\n", WRONG_ARGS));
	check_dot_kub(av[1]);
	kub.map_fd = open(av[1], O_RDONLY);
	if (kub.map_fd < 0)
		return (printf("Error\n%s\n", WRONG_FD));
	init_kub(&kub);
	parsing_info(&kub);
	mlx_start(&kub);
	return (0);
}
