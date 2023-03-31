/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:58:59 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/13 15:20:16 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kub.h"

void	map_not_reached(t_kub *kub)
{
	printf("Error\n%s\n", MAP_UNREACHED);
	free_asset(kub);
	exit (0);
}

// This function check if we got a valid color and change it to a INT
int	check_valid_color(char **split_f_c, int *f_c_clr)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(split_f_c[0]);
	g = ft_atoi(split_f_c[1]);
	b = ft_atoi(split_f_c[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (1);
	*f_c_clr = (r << 16 | g << 8 | b);
	return (0);
}

size_t	get_longest_line(char **map, int size)
{
	int		i;
	size_t	length;

	i = -1;
	length = 0;
	while (++i < size)
	{
		if (ft_strlen(map[i]) > length)
			length = ft_strlen(map[i]);
	}
	return (length);
}

// This function check if we got all info needed before parsing the map
void	got_all_info(t_kub *kub, char *line)
{
	if (kub->north_asset == NULL || kub->south_asset == NULL || \
		kub->west_asset == NULL || kub->east_asset == NULL || \
		kub->floor_clr == -1 || kub->ceiling_clr == -1)
	{
		free(line);
		printf("Error\n%s\n", MISSING_ASSET);
		free_asset(kub);
		exit (0);
	}
	else
		map_reach(kub, line);
}

// This function free the asset if we got a double/error
void	free_asset(t_kub *kub)
{
	if (kub->north_asset != NULL)
		free(kub->north_asset);
	if (kub->south_asset != NULL)
		free(kub->south_asset);
	if (kub->west_asset != NULL)
		free(kub->west_asset);
	if (kub->east_asset != NULL)
		free(kub->east_asset);
}
