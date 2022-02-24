/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:41:16 by gasselin          #+#    #+#             */
/*   Updated: 2022/02/24 10:10:54 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	init_cub(t_cub *cub)
{
	cub->floor = -1;
	cub->ceiling = -1;
	cub->player_rot = -1.0;
	cub->posX = -1;
	cub->posY = -1;
	cub->textN = NULL;
	cub->textS = NULL;
	cub->textE = NULL;
	cub->textW = NULL;
	cub->tmp_map = ft_calloc(1, sizeof(char*));
}

void	free_textures(t_cub *cub)
{
	free (cub->textN);
	free (cub->textS);
	free (cub->textE);
	free (cub->textW);	
}

void	verify_all(t_cub *cub)
{
	if (!cub->textN || !cub->textS || !cub->textE || !cub->textW
		|| cub->floor == -1 || cub->ceiling == -1 || !cub->tmp_map[0])
	{
		free_textures(cub);
		ft_strarr_free(cub->tmp_map);
		exit (printf("Error : Missing parameter\n"));
	}
}

int	main(int argc, char **argv)
{
	t_cub	cub;
	
	if (argc != 2)
		return (printf("Error : Bad arguments!\n"));
	init_cub(&cub);
	start_parsing(&cub, argv[1]);
	verify_all(&cub);
	transfer_map(&cub);
	validate_map(&cub);

	// for (int i = 0; cub.map[i]; i++)
	// 	printf("%sA\n", cub.map[i]);

	free_textures(&cub);
	
	return (0);
}
