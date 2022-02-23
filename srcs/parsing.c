/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:18:21 by gasselin          #+#    #+#             */
/*   Updated: 2022/02/23 16:04:36 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub.h"

bool	line_is_map(char **split)
{
	if (ft_strcmp(split[0], "NO") && ft_strcmp(split[0], "SO")
		&& ft_strcmp(split[0], "EA") && ft_strcmp(split[0], "WE")
		&& ft_strcmp(split[0], "C") && ft_strcmp(split[0], "F"))
		return (true);
	return (false);
}

int	validate_color(char *str, int *color, int nbline)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	if (*color != -1)
		return (printf("Error : Duplicated parameter, line %d\n", nbline));
	split = ft_split(str, ',');
	if (str[0] == ',' || str[ft_strlen(str) - 1] == ',' || ft_strarr_size(split) != 3)
	{
		ft_strarr_free(split);
		return (printf("Error : Too many colors or commas, line %d\n", nbline));
	}
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	ft_strarr_free(split);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (printf("Error : Colors outside 0-255, line %d\n", nbline));
	*color = create_rgb(r, g, b);
	return (0);
}

int	validate_path(char *path, char **text, int nbline)
{
	int		fd;
	char	*str;

	if (*text != NULL)
		return (printf("Error : Duplicated parameter, line %d\n", nbline));
	fd = open(path, O_RDONLY);
	str = ft_strnstr(path, ".xpm", ft_strlen(path));
	close (fd);
	if (fd == -1 || !str || ft_strlen(str) != 4)
		return (printf("Error : Invalid texture path or file, line %d\n", nbline));
	*text = ft_strdup(path);
	return (0);
}

int	manage_args(t_cub *cub, char **split, char *line, int nbline)
{
	if (line_is_map(split))
		return (fill_map(cub, line));
	else if (ft_strarr_size(split) != 2)
		return (printf("Error : Too many arguments, line %d\n", nbline));
	else if (!ft_strcmp(split[0], "NO"))
		return (validate_path(split[1], &cub->textN, nbline));
	else if (!ft_strcmp(split[0], "SO"))
		return (validate_path(split[1], &cub->textS, nbline));
	else if (!ft_strcmp(split[0], "EA"))
		return (validate_path(split[1], &cub->textE, nbline));
	else if (!ft_strcmp(split[0], "WE"))
		return (validate_path(split[1], &cub->textW, nbline));
	else if (!ft_strcmp(split[0], "F"))
		return (validate_color(split[1], &cub->floor, nbline));
	else if (!ft_strcmp(split[0], "C"))
		return (validate_color(split[1], &cub->ceiling, nbline));
	return (printf("Error : Invalid parameter, line %d\n", nbline));
}

void	start_parsing(t_cub *cub, char *path)
{
	char	*str;
	int		ret;
	char	**split;
	int		nbline;

	nbline = 1;
	cub->fd = open(path, O_RDONLY);
	str = ft_strnstr(path, ".cub", ft_strlen(path));
	if (cub->fd == -1 || !str || ft_strlen(str) != 4)
		exit (printf("Error : Invalid config file\n"));
	while (true)
	{
		ret = get_next_line(cub->fd, &str);
		if (str && str[0])
		{
			split = ft_split(str, ' ');
			if (manage_args(cub, split, str, nbline))
			{
				free (str);
				ft_strarr_free(split);
				exit (1);
			}
			ft_strarr_free(split);
		}
		free (str);
		if (ret == 0 || (cub->tmp_map[0] && cub->tmp_map[0][0]))
			break;
		nbline++;
	}
	close (cub->fd);
}
