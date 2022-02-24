/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:14:54 by gasselin          #+#    #+#             */
/*   Updated: 2022/02/24 10:29:42 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define ERR_ARG_MAIN "Error : Bad arguments!\n"
# define MISSING_PARAM "Error : Missing parameter\n"
# define ERR_CONFIG "Error : Invalid config file\n"
# define TOO_MANY_ARGS "Error : Too many arguments, line %d\n"
# define INV_PARAM "Error : Invalid parameter, line %d\n"
# define ERR_DUPLIC "Error : Duplicated parameter, line %d\n"
# define ERR_TEXT "Error : Invalid texture path or file, line %d\n"
# define ERR_COMMA "Error : Too many colors or commas, line %d\n"
# define ERR_COLOR "Error : Colors outside 0-255, line %d\n"
# define MAP_LAST "Error : Map must be last in file\n"
# define CLOSED_MAP "Error : Map is not closed by walls on all sides\n"
# define NO_SPAWN "Error : No spawn point set\n"
# define MULT_SPAWNS "Error : Multiple spawn points\n"

#endif