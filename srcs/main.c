/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:41:16 by gasselin          #+#    #+#             */
/*   Updated: 2022/02/23 15:02:54 by gasselin         ###   ########.fr       */
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
	cub->textN = NULL;
	cub->textS = NULL;
	cub->textE = NULL;
	cub->textW = NULL;
}

int	main(int argc, char **argv)
{
	t_cub	cub;
	
	if (argc != 2)
		return (printf("Error : Bad arguments!\n"));
	init_cub(&cub);
	start_parsing(&cub, argv[1]);

	// printf("%s\n", cub.textN);
	// printf("%s\n", cub.textS);
	// printf("%s\n", cub.textE);
	// printf("%s\n", cub.textW);

	// printf("%d = %d\n", create_rgb(220,100,0), cub.floor);
	// printf("%d = %d\n", create_rgb(225,30,0), cub.ceiling);
	
	return (0);
}
