/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:09:34 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/13 15:24:59 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/kub_bonus.h"

// This function split the color in maps
// It check if we got a valid color split in 3 (ft_strarr_size()
// If they arnt double they are send to be change in a INT (check_valid_color)
int	check_color(char *f_c_asset, int *f_c_clr)
{
	char	**split_f_c;

	if (*f_c_clr != -1)
		return (printf("Error\n%s\n", DOUBLE_CLR));
	split_f_c = ft_split(f_c_asset, ',');
	if (ft_count_char(f_c_asset, ",0123456789") != (int)ft_strlen(f_c_asset) || \
		ft_count_char(f_c_asset, ",") != 2 || ft_strarr_size(split_f_c) != 3 \
		|| check_valid_color(split_f_c, f_c_clr))
	{
		ft_strarr_free(split_f_c);
		return (printf("Error\n%s\n", INVALID_CLR));
	}
	ft_strarr_free(split_f_c);
	return (0);
}

// This function check the if the xpm asset file 
// If isnt empty or in double
int	check_asset(char *str_asset, char **asset)
{
	int		asset_fd;
	char	*dot_xpm;

	dot_xpm = NULL;
	if (*asset != NULL)
		return (printf("Error\n%s\n", DOUBLE_ASSET));
	asset_fd = open(str_asset, O_RDONLY);
	if (asset_fd < 0)
		return (printf("Error\n%s\n", WRONG_ASSET_FD));
	close(asset_fd);
	dot_xpm = ft_strnstr(str_asset, ".xpm", ft_strlen(str_asset));
	if (dot_xpm == NULL || ft_strlen(dot_xpm) > 4)
		return (printf("Error\n%s\n", WRONG_DOT_XPM));
	*asset = ft_strdup(str_asset);
	return (0);
}

// This function check that info in map are good (NO, SO, WE & EA) & (F & C)
// It check we got all needed asset and color (ft_strcmp)
// If its good the assets and color are send to be validate (check_function)
// Else error messge is print
int	check_map_info(t_kub *kub, char **split)
{
	if (!ft_strcmp(split[0], "NO"))
		return (check_asset(split[1], &kub->north_asset));
	if (!ft_strcmp(split[0], "SO"))
		return (check_asset(split[1], &kub->south_asset));
	if (!ft_strcmp(split[0], "WE"))
		return (check_asset(split[1], &kub->west_asset));
	if (!ft_strcmp(split[0], "EA"))
		return (check_asset(split[1], &kub->east_asset));
	if (!ft_strcmp(split[0], "F"))
		return (check_color(split[1], &kub->floor_clr));
	if (!ft_strcmp(split[0], "C"))
		return (check_color(split[1], &kub->ceiling_clr));
	return (printf("Error\n%s\n", WRONG_MAP_INFO));
}

void	parsing_info2(t_kub *kub, char **split)
{
	if (ft_strarr_size(split) != 2 && split[0][0] != '1')
		printf("Error\n%s\n", WRONG_MAP_INFO);
	if (ft_strarr_size(split) != 2 || check_map_info(kub, split))
	{
		free_asset(kub);
		ft_strarr_free(split);
		close(kub->map_fd);
		exit (0);
	}
	ft_strarr_free(split);
}

// This function parse till reach THE MAP (1 & 0)
// First "if" check if isnt a empty line
// Second "if" check if we reach the map with all info needed
// Third "if" check if we got all valid asset and color 
void	parsing_info(t_kub *kub)
{
	char	*line;
	char	**split;

	line = NULL;
	while (get_next_line(kub->map_fd, &line))
	{
		split = ft_split(line, ' ');
		if (!ft_strcmp(line, "\0") || split[0] == NULL)
		{
			ft_strarr_free(split);
			free(line);
			continue ;
		}
		if (split[0][0] == '1' || split[0][0] == '0')
		{
			ft_strarr_free(split);
			got_all_info(kub, line);
			return ;
		}
		free(line);
		parsing_info2(kub, split);
	}
	free(line);
	map_not_reached(kub);
}
