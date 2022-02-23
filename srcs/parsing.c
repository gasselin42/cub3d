/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:18:21 by gasselin          #+#    #+#             */
/*   Updated: 2022/02/23 12:05:38 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub.h"

void	start_parsing(t_cub *cub, char *path)
{
	char	*str;
	int		fd;
	int		ret;
	char	**split;

	fd = open(path, O_RDONLY);
	str = ft_strnstr(path, ".cub", ft_strlen(path));
	if (fd == -1 || !str || ft_strlen(str) != 4)
		exit (printf("Error : Invalid file\n"));
	while (true)
	{
		ret = get_next_line(fd, &str);
		if (str && str[0])
		{
			split = ft_split(str, ' ');
			// Compter le nombre de lignes dans le split
		}
		free (str);
		if (ret == 0)
			break;
	}
}