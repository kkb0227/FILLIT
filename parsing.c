/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 16:03:18 by kykim             #+#    #+#             */
/*   Updated: 2018/05/31 10:37:59 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*fixcoor(t_tetri *coor)
{
	while (coor->hash1coor[0] >= 1 && coor->hash2coor[0] >= 1
			&& coor->hash3coor[0] >= 1 && coor->hash4coor[0] >= 1)
	{
		coor->hash1coor[0] -= 1;
		coor->hash2coor[0] -= 1;
		coor->hash3coor[0] -= 1;
		coor->hash4coor[0] -= 1;
	}
	while (coor->hash1coor[1] >= 1 && coor->hash2coor[1] >= 1
			&& coor->hash3coor[1] >= 1 && coor->hash4coor[1] >= 1)
	{
		coor->hash1coor[1] -= 1;
		coor->hash2coor[1] -= 1;
		coor->hash3coor[1] -= 1;
		coor->hash4coor[1] -= 1;
	}
	return (coor);
}

t_tetri		*getcoor(char *tetrimino)
{
	int			i;
	t_tetri		*hashcoor;

	i = 0;
	hashcoor = (t_tetri *)malloc(sizeof(t_tetri));
	while (!(tetrimino[i] >= 'A' && tetrimino[i] <= 'Z'))
		i++;
	hashcoor->hash1coor[0] = i / 5;
	hashcoor->hash1coor[1] = i % 5;
	i += 1;
	while (!(tetrimino[i] >= 'A' && tetrimino[i] <= 'Z'))
		i++;
	hashcoor->hash2coor[0] = i / 5;
	hashcoor->hash2coor[1] = i % 5;
	i += 1;
	while (!(tetrimino[i] >= 'A' && tetrimino[i] <= 'Z'))
		i++;
	hashcoor->hash3coor[0] = i / 5;
	hashcoor->hash3coor[1] = i % 5;
	i += 1;
	while (!(tetrimino[i] >= 'A' && tetrimino[i] <= 'Z'))
		i++;
	hashcoor->hash4coor[0] = i / 5;
	hashcoor->hash4coor[1] = i % 5;
	return (fixcoor(hashcoor));
}
