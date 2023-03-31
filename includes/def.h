/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:05:37 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/13 15:18:22 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_H
# define DEF_H

// SIZE WINDOW MLX
# define WIN_WIDTH 1000
# define WIN_HEIGHT 700

// Asset
# define N 0
# define S 1
# define E 2
# define W 3

// Vitess de Rotation et de mouvement
# define MOV_SPEED 0.05
# define ROT_SPEED 3

// Color
# define RED 0xdf6e4d
# define WHITE 0xFFFFFF
# define D_GREEN 0x333300
# define C_GREEN 0xd3f19b
# define BEIGE 0xFFF8DC
# define D_GREY 0x566573 
# define L_GREY 0xe3e8db
# define L_BLUE 0x5499c7 
# define L_RED 0xe3afc8

// ERROR MESSAGE / INSULT
# define WRONG_ARGS "Needs to have 2 args you dump ass (./executable map_file)"
# define EMPTY_ARG "Empty map argument you fuck head"
# define WRONG_DOT_CUB "Map must be a \".cub\" you stupid cunt "
# define WRONG_FD "Fucking fucking fd of shit (cant open file)"

// MAP INFO ERROR
# define WRONG_ASSET_FD "Your fd of your asset is wrong"
# define WRONG_DOT_XPM "Map must be a \".xpm\" you stupid cunt "
# define WRONG_MAP_INFO "Info in map file is no good you dick head"
# define WRONG_NO "You got a wrong Nord asset you dirty bastard"
# define WRONG_SO "You got a wrong South asset you dirty bastard"
# define WRONG_WE "You got a wrong West asset you dirty bastard"
# define WRONG_EA "You got a wrong East asset you dirty bastard"
# define DOUBLE_ASSET "You got the same asset twice you lil cunt"
# define DOUBLE_CLR "You got the same color twice you lil bitch"
# define INVALID_CLR "You got invalid color bitch"
# define MISSING_ASSET "Missing asset or color you lil fuck"
# define INVALID_MAP "You got a wrong map you idiot"
# define SQUARE_ASSET "All assets must be squares"
# define UNEVEN_ASSET "All assets must have the same size"
# define MAP_UNREACHED "No map in .cub file"

// KEY
# ifdef __linux__

#  define ESC 65307
#  define A_KEY 97
#  define D_KEY 100
#  define S_KEY 115
#  define W_KEY 119
#  define M_KEY 109
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363

# elif __APPLE__

#  define ESC 53
#  define A_KEY 0
#  define D_KEY 2
#  define S_KEY 1
#  define W_KEY 13
#  define M_KEY 46
#  define LEFT_KEY 123
#  define RIGHT_KEY 124

# endif

#endif