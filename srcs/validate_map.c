/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:00:30 by gasselin          #+#    #+#             */
/*   Updated: 2022/02/24 10:06:14 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub.h"

int set_spawn_point(t_cub *cub, int i, int j)
{
    if (cub->player_rot == -1.0)
    {
        cub->posX = i;
        cub->posY = j;
        if (cub->map[i][j] == 'N')
            cub->player_rot = 0.0;
        else if (cub->map[i][j] == 'S')
            cub->player_rot = 180.0;
        else if (cub->map[i][j] == 'E')
            cub->player_rot = 90.0;
        else if (cub->map[i][j] == 'W')
            cub->player_rot = 270.0;
    }
    else
        return (1);
    return (0);
}

int find_spawn(t_cub *cub, size_t len)
{
    int i;
    int j;
    
    i = 0;
    while (i < ft_strarr_size(cub->map))
    {
        j = 0;
        while (j < len)
        {
            if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
                || cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
                if (set_spawn_point(cub, i, j))
                    return (printf("Error : Multiple spawn points\n"));
            j++;
        }
        i++;
    }
    if (cub->player_rot == -1.0)
        return (printf("Error : No spawn point set\n"));
    return (0);
}

int check_surroundings(char **map, int i, int j)
{
    if ((map[i - 1][j] != '1' && map[i - 1][j] != ' ')
        || (map[i - 1][j - 1] != '1' && map[i - 1][j - 1] != ' ')
        || (map[i][j - 1] != '1' && map[i][j - 1] != ' ')
        || (map[i + 1][j - 1] != '1' && map[i + 1][j - 1] != ' ')
        || (map[i + 1][j] != '1' && map[i + 1][j] != ' ')
        || (map[i + 1][j + 1] != '1' && map[i + 1][j + 1] != ' ')
        || (map[i][j + 1] != '1' && map[i][j + 1] != ' ')
        || (map[i - 1][j + 1] != '1' && map[i - 1][j + 1] != ' '))
        return (printf("Error : Map is not closed by walls on all sides\n"));
    return (0);
}

int verify_line(char *line, size_t len)
{
    if (ft_count_char(line, "1 ") != (int)len)
        return (printf("Error : Map is not closed by walls on all sides\n"));
    return (0);
}

int verify_column(char **map, size_t index)
{
    int i;

    i = 0;
    while (i < ft_strarr_size(map))
    {
        if (map[i][index] != '1' || map[i][index] != ' ')
            return (printf("Error : Map is not closed\
             by walls on all sides\n"));
        i++;
    }
    return (0);
}

int validate_lines(char **map, size_t len)
{
    int i;
    int j;
    
    i = 1;
    while (i < ft_strarr_size(map) - 1)
    {
        j = 1;
        while (j < len - 1)
        {
            if (map[i][j] == ' ')
            {
                if (check_surroundings(map, i, j))
                    return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

void    validate_map(t_cub *cub)
{
    size_t  len;

    len = ft_strlen(cub->map[0]);
    if (verify_line(cub->map[0], len)
        || verify_line(cub->map[ft_strarr_size(cub->map) - 1], len)
        || verify_column(cub->map, 0) || verify_column(cub->map, len - 1)
        || validate_lines(cub->map, len) || find_spawn(cub, len))
    {
        ft_strarr_free(cub->map);
        free_textures(cub);
        exit (1);
    }
}
