/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_addback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:55:47 by gasselin          #+#    #+#             */
/*   Updated: 2022/05/09 13:45:26 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Gasselin this function copie lancien tableau 2D et rajoute la str at the end
char	**ft_strarr_addback(char **arr, char *str)
{
	char	**dup;
	int		i;

	i = ft_strarr_size(arr);
	dup = ft_strarr_dup(arr, 1);
	dup[i++] = ft_strdup(str);
	dup[i] = NULL;
	ft_strarr_free(arr);
	return (dup);
}
