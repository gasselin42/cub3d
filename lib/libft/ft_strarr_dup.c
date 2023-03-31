/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:45:44 by gasselin          #+#    #+#             */
/*   Updated: 2022/05/09 13:43:48 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// gasselin duplie le tableau , et le nombre d'espace que l'on veu add (2e para)
char	**ft_strarr_dup(char **arr, int size_plus)
{
	char	**dup;
	int		i;

	i = ft_strarr_size(arr);
	dup = (char **)ft_calloc((i + 1 + size_plus), sizeof(char *));
	if (!dup)
		return (NULL);
	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			dup[i] = ft_strdup(arr[i]);
			i++;
		}
	}
	return (dup);
}
